//---------------------------------------------------------------------------

#include <vcl.h>
#include <stdio.h>
#pragma hdrstop

#include "SubmapViwer.h"
#include "ConstDefine.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "LMDBackPanel"
#pragma link "LMDControl"
#pragma link "LMDCustomBevelPanel"
#pragma link "LMDCustomControl"
#pragma link "LMDCustomPanel"
#pragma link "LMDCustomParentPanel"
#pragma link "LMDCustomScrollBox"
#pragma link "LMDListBox"
#pragma link "LMDCustomPanelFill"
#pragma link "LMDCustomSheetControl"
#pragma link "LMDPageControl"
#pragma resource "*.dfm"
TFormSubMapViewer *FormSubMapViewer;
//---------------------------------------------------------------------------
__fastcall TFormSubMapViewer::TFormSubMapViewer(TComponent* Owner)
    : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFormSubMapViewer::FormShow(TObject *Sender)
{
    SysLogStartDatePicker->Date = Date();
    SysLogEndDatePicker->Date = Date();
}
//---------------------------------------------------------------------------

void __fastcall TFormSubMapViewer::LMDListBox1Select(TObject *Sender)
{
    String data = LMDListBox1->Items->Strings[LMDListBox1->ItemIndex];

    TStringList *sl = new TStringList;
    ExtractStrings(TSysCharSet()<<';', TSysCharSet(), data.c_str(), sl);

    int row = StrToIntDef( sl->Strings[2], 1 );
    int col = StrToIntDef( sl->Strings[3], 1 );
    String submap = sl->Strings[4];
    DrawSubmap( StringGrid1, row, col, submap, CELL_GRADE );

    String submapRes = sl->Strings[5];
    DrawSubmap( StringGrid2, row, col, submapRes, CELL_STATUS );

    delete sl;

}
//---------------------------------------------------------------------------

void __fastcall TFormSubMapViewer::StringGridDrawCell(TObject *Sender,
      int ACol, int ARow, TRect &Rect, TGridDrawState State)
{
    TCanvas* Canvas = ((TStringGrid*)Sender)->Canvas;

    if(State.Contains(gdFixed)) {
        /* Fixed Row 또는 Fixed Column 일 경우에는 그리지 않는다. */
    } else {
        /* Objects 프로퍼티의 값을 이용해서 브러시의 색을 설정한다. */
        Canvas->Brush->Color = (TColor)((TStringGrid*)Sender)->Objects[ACol][ARow];
        Canvas->FillRect(Rect);
    }
}
//---------------------------------------------------------------------------

void __fastcall TFormSubMapViewer::DrawSubmap( TStringGrid *target, int row, int col, String Submap ,SUB_MAP_ID id )
{
    if( row <= 1 )
        row = 2;
    if( col <= 1 )
        col = 2;

    target->RowCount = row+1;
    target->ColCount = col+1;

    TStringList *lstCol=new TStringList;
    for( int i = 0; i < col+1; i++ ) {
        if( i != 0 )
            lstCol->Add( IntToStr(col+1-i) );
        else
            lstCol->Add( "" );

        target->ColWidths[i] = 30;
    }
    TStringList *lstRow=new TStringList;
    for( int i = 0; i < row+1; i++ ) {
        if( i != 0 )
            lstRow->Add( (char)('@' + i) );
        else
            lstRow->Add( "" );
    }
    target->Rows[0]->Assign( lstCol );
    target->Cols[0]->Assign( lstRow );

    char *strSubmap = Submap.c_str();

    for(int Row = 0; Row < target->RowCount-1; Row++) {
        for(int Col = 0; Col < target->ColCount-1; Col++) {
            TColor color = clWhite;
            int subIndex = (col - (Col)) * row + (Row-row);

            if( Submap.Length() <= subIndex ) {
                //None
            }
            else {
                int status = StrToIntDef( strSubmap[subIndex*2], -1 );
                if( id == CELL_GRADE ) {
                    switch( status ) {
                    case 0:
                        color = clLime;
                        break;
                    case 1:
                        color = clGreen;
                        break;
                    case 2:
                        color = clRed;
                        break;
                    default:
                        color = clYellow;
                        break;
                    }
                }
                else {
                    switch( status ) {
                    case 0:
                        color = clLime;
                        break;
                    case 1:
                        color = clRed;
                        break;
                    case 2:
                        color = clWhite;
                        break;
                    default:
                        color = clYellow;
                        break;
                    }
                }

            }
            target->Objects[Col+1][Row+1] = (TObject*)color;
        }
    }

    delete lstCol;
    delete lstRow;

    target->Refresh();
}
//---------------------------------------------------------------------------

void __fastcall TFormSubMapViewer::SaveSubmapLogFile( SUB_MAP_INFO data )
{
    String sFileName, sTmp, sList;
    int nIdx;

    sFileName = SYSLOG_FILE_PATH+"SubmapLog\\";
    if(!DirectoryExists(sFileName))
        CreateDir(sFileName);

    sFileName = sFileName+FormatDateTime("yyyy-mm-dd", Now())+".Log";
    FILE *fp;
    fp=fopen(sFileName.c_str(),"a+");

    fseek(fp,0,2);
    String Str = FormatDateTime("yyyy/mm/dd;hh:nn:ss;", Now());
    //    String text = "2015/12/16;14:00:01;SUBID0000;5;5;1000001000001000001000001;1000001000001000001000001;OK;";
    Str += data.SubID + ";";
    Str += IntToStr(data.row) + ";";
    Str += IntToStr(data.col) + ";";
    Str += data.CellStatus + ";";
    Str += data.CellGrade + ";";
    Str += data.Result + ";";
    Str += "\n";

    fprintf(fp, "%s", Str.c_str());

    fclose(fp);
}
//---------------------------------------------------------------------------

String __fastcall TFormSubMapViewer::LoadSubmapLogFile()
{
    Screen->Cursor = crHourGlass;

    String retStr;

    TStringList *pFileList = new TStringList;
    TStringList *pLogList = new TStringList;

    TSearchRec sr;
    try {
        if(FindFirst(SYSLOG_FILE_PATH+"SubmapLog\\*.Log", faAnyFile, sr) == 0) {
            do {
                if(sr.Name != "." && sr.Name != ".." && sr.Attr != faDirectory) {
                    sr.Name = sr.Name.SubString(1, sr.Name.Pos(".Log")-1);
                    pFileList->Add(sr.Name);
                }
            }
            while(FindNext(sr) == 0);
        }
    }
    __finally
    {
        FindClose(sr);
    }

    pFileList->Sort();

    TDateTime StartDate = SysLogStartDatePicker->DateTime;
    TDateTime EndDate = SysLogEndDatePicker->DateTime;

    for(int i=0; i<pFileList->Count ; i++) {
        if(pFileList->Strings[i] != "") {
            int nYear = StrToInt(pFileList->Strings[i].SubString(1,4));
            int nMonth = StrToInt(pFileList->Strings[i].SubString(6,2));
            int nDay = StrToInt(pFileList->Strings[i].SubString(9,2));
            AnsiString sDate = EncodeDate(nYear, nMonth, nDay);
            if(StrToDate(sDate) >= StartDate-1 && StrToDate(sDate) <= EndDate) {
                AnsiString sLogFile = SYSLOG_FILE_PATH+"SubmapLog\\"+pFileList->Strings[i]+".Log";
                if(FileExists(sLogFile)) {
                    pLogList->Clear();
                    pLogList->LoadFromFile(sLogFile);
                }
            }
        }
    }

    int count = pLogList->Count;

    if( count >= 1 ) {
        LMDListBox1->Items->AddStrings( pLogList );
    }

    Screen->Cursor = crDefault;

    delete pFileList;
    delete pLogList;

    return retStr;
}
//---------------------------------------------------------------------------

void __fastcall TFormSubMapViewer::SysLogSearchBtnClick(TObject *Sender)
{
    LMDListBox1->Clear();
//
//    SUB_MAP_INFO a;
//    a.row = 5;
//    a.col = 5;
//    a.SubID = "asdf";
//    a.CellStatus = "000000000001";
//    a.CellGrade = "000000000001";
//    a.Result = "NG";
//    SaveSubmapLogFile(a);
    LoadSubmapLogFile();
}
//---------------------------------------------------------------------------

