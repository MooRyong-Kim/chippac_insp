object FormSubMapViewer: TFormSubMapViewer
  Left = 137
  Top = 208
  Width = 734
  Height = 640
  Caption = 'Substrate MapData Viewer'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  FormStyle = fsStayOnTop
  OldCreateOrder = False
  Position = poScreenCenter
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object LMDBackPanel1: TLMDBackPanel
    Left = 0
    Top = 0
    Width = 718
    Height = 257
    Align = alTop
    Bevel.Mode = bmCustom
    TabOrder = 0
    object LMDListBox1: TLMDListBox
      Left = 249
      Top = 0
      Width = 469
      Height = 257
      Align = alClient
      Color = clWindow
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      TabOrder = 0
      HeaderFont.Charset = DEFAULT_CHARSET
      HeaderFont.Color = clWindowText
      HeaderFont.Height = -11
      HeaderFont.Name = 'MS Sans Serif'
      HeaderFont.Style = []
      HeaderSections = <
        item
          ImageIndex = -1
          Text = 'Date'
          Width = 60
        end
        item
          ImageIndex = -1
          Text = 'Time'
          Width = 60
        end
        item
          ImageIndex = -1
          Text = 'Sub ID'
          Width = 89
        end
        item
          ImageIndex = -1
          Text = 'Row'
          Width = 50
        end
        item
          ImageIndex = -1
          Text = 'Column'
          Width = 50
        end
        item
          ImageIndex = -1
          Text = 'CellStatus'
          Width = 170
        end
        item
          ImageIndex = -1
          Text = 'CellGrade'
          Width = 172
        end
        item
          ImageIndex = -1
          Text = 'Result'
          Width = 50
        end>
      ImeName = 'Microsoft IME 2010'
      ItemHeight = 16
      OnSelect = LMDListBox1Select
    end
    object LMDBackPanel5: TLMDBackPanel
      Left = 0
      Top = 0
      Width = 249
      Height = 257
      Align = alLeft
      Bevel.Mode = bmCustom
      TabOrder = 1
      object Label2: TLabel
        Left = 16
        Top = 108
        Width = 44
        Height = 13
        Caption = 'End Date'
        Font.Charset = ANSI_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'Tahoma'
        Font.Style = []
        ParentFont = False
      end
      object Label1: TLabel
        Left = 16
        Top = 76
        Width = 50
        Height = 13
        Caption = 'Start Date'
        Font.Charset = ANSI_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'Tahoma'
        Font.Style = []
        ParentFont = False
      end
      object SysLogEndDatePicker: TDateTimePicker
        Left = 88
        Top = 102
        Width = 145
        Height = 24
        CalAlignment = dtaLeft
        Date = 36526.5936225116
        Time = 36526.5936225116
        Color = clWhite
        DateFormat = dfShort
        DateMode = dmComboBox
        Font.Charset = ANSI_CHARSET
        Font.Color = clWindowText
        Font.Height = -13
        Font.Name = 'Tahoma'
        Font.Style = []
        ImeName = #54620#44397#50612' '#51077#47141' '#49884#49828#53596' (IME 2000)'
        Kind = dtkDate
        ParseInput = False
        ParentFont = False
        TabOrder = 0
      end
      object SysLogStartDatePicker: TDateTimePicker
        Left = 88
        Top = 70
        Width = 145
        Height = 24
        CalAlignment = dtaLeft
        Date = 36526.5936064005
        Time = 36526.5936064005
        Color = clWhite
        DateFormat = dfShort
        DateMode = dmComboBox
        Font.Charset = ANSI_CHARSET
        Font.Color = clWindowText
        Font.Height = -13
        Font.Name = 'Tahoma'
        Font.Style = []
        ImeName = #54620#44397#50612' '#51077#47141' '#49884#49828#53596' (IME 2000)'
        Kind = dtkDate
        ParseInput = False
        ParentFont = False
        TabOrder = 1
      end
      object SysLogSearchBtn: TBitBtn
        Left = 16
        Top = 136
        Width = 217
        Height = 53
        Cancel = True
        Caption = '&Search'
        Font.Charset = ANSI_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'Tahoma'
        Font.Style = []
        ParentFont = False
        TabOrder = 2
        OnClick = SysLogSearchBtnClick
        Glyph.Data = {
          66030000424D6603000000000000360000002800000010000000110000000100
          1800000000003003000000000000000000000000000000000000FFFFFFFFFFFF
          FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
          FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
          FFFFFFFFFFFFFFFFFFFFFFFFFFFF000000000000FFFFFFFFFFFFFFFFFFFFFFFF
          FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF800000FFFF
          00FF0000000000FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
          FFFFFFFFFFFFFFFF800000FFFF00FF0000FF0000000000FFFFFFFFFFFF000000
          000000000000000000000000000000000000000000800000FFFF00FF0000FF00
          00000000FFFFFFFFFFFF80808000808000808000808000808000808000808000
          8080800000FFFF00FF0000FF0000008080008080000000FFFFFF808080FFFFFF
          00FFFFC0C0C0808080000000000000808080C0C0C0FF0000FF000000808000FF
          FF008080000000FFFFFF808080FFFFFFC0C0C0808080C0C0C0FFFF00C0C0C000
          000080808000808000808000FFFFC0C0C0008080000000FFFFFF808080FFFFFF
          808080FFFFFFFFFF00C0C0C0FFFF00C0C0C000000000808000FFFFC0C0C000FF
          FF008080000000FFFFFF808080FFFFFF808080FFFF00FFFFFFFFFF00C0C0C0FF
          FF00000000008080C0C0C000FFFFC0C0C0008080000000FFFFFF808080FFFFFF
          808080FFFFFFFFFF00FFFFFFFFFF00C0C0C000000080808000FFFFC0C0C000FF
          FF008080000000FFFFFF808080FFFFFFC0C0C0808080FFFFFFFFFF00FFFFFF00
          000080808000FFFFC0C0C000FFFFC0C0C0008080000000FFFFFF808080FFFFFF
          00FFFFC0C0C080808080808000000080808000FFFFC0C0C000FFFFC0C0C000FF
          FF008080000000FFFFFF808080FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
          FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF008080000000FFFFFF808080C0C0C0
          00FFFFC0C0C000FFFFC0C0C000FFFFC0C0C08080808080808080808080808080
          80808080FFFFFFFFFFFFFFFFFF808080C0C0C000FFFFC0C0C000FFFFC0C0C080
          8080FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
          808080808080808080808080808080FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
          FFFFFFFFFFFFFFFFFFFF}
      end
    end
  end
  object LMDBackPanel2: TLMDBackPanel
    Left = 0
    Top = 257
    Width = 718
    Height = 345
    Align = alClient
    Bevel.Mode = bmCustom
    TabOrder = 1
    object LMDBackPanel3: TLMDBackPanel
      Left = 0
      Top = 276
      Width = 718
      Height = 69
      Align = alBottom
      Bevel.Mode = bmCustom
      TabOrder = 0
    end
    object LMDBackPanel4: TLMDBackPanel
      Left = 0
      Top = 0
      Width = 718
      Height = 276
      Align = alClient
      Bevel.Mode = bmCustom
      TabOrder = 1
      object LMDPageControl1: TLMDPageControl
        Left = 0
        Top = 0
        Width = 718
        Height = 276
        Align = alClient
        TabOrder = 0
        Options = [toNoTabIfEmpty, toShowBorder, toShowFocusRect, toShowAccelChar]
        DockOrientation = doNoOrient
        ActivePage = LMDTabSheet1
        object LMDTabSheet1: TLMDTabSheet
          Left = 4
          Top = 28
          Width = 710
          Height = 244
          Bevel.Mode = bmCustom
          Caption = 'Cell Status'
          object StringGrid1: TStringGrid
            Left = 0
            Top = 0
            Width = 710
            Height = 244
            Align = alClient
            TabOrder = 0
            OnDrawCell = StringGridDrawCell
          end
        end
        object LMDTabSheet2: TLMDTabSheet
          Left = 4
          Top = 28
          Width = 710
          Height = 244
          Bevel.Mode = bmCustom
          Caption = 'Cell Grade'
          object StringGrid2: TStringGrid
            Left = 0
            Top = 0
            Width = 718
            Height = 248
            Align = alClient
            TabOrder = 0
            OnDrawCell = StringGridDrawCell
          end
        end
      end
    end
  end
end
