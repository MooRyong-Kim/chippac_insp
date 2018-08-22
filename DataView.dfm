object DataViewForm: TDataViewForm
  Left = 152
  Top = 45
  BorderIcons = [biSystemMenu]
  BorderStyle = bsSingle
  Caption = 'System Data View Form'
  ClientHeight = 613
  ClientWidth = 712
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  FormStyle = fsStayOnTop
  Icon.Data = {
    0000010001002020100000000000E80200001600000028000000200000004000
    0000010004000000000080020000000000000000000000000000000000000000
    000000008000008000000080800080000000800080008080000080808000C0C0
    C0000000FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF009999
    999999999999999999999999999994444F00F40F444444444444444444499C44
    4F00F40F444444444444444444499CC44F0F0F0F444444440000004444499CCC
    4F0F0F0F444440008888880044499CCCCF04F00F444008888888888804499CCC
    CF00000F4008F8F8F8F8888804499CCCCF04F00F0F8F88888888800004499CCC
    CF0F0040F8F8F8F8F800078804499CCCCCF0040F8F888F880077787804499CCC
    CCCFC0F8F8F8F8F00787878044499CCCCCCC0F8F8F8F80070878788044499CCC
    CCC0F8F8F8F807770787880444499CCCCCC0FFFF8F8077780878780444499CCC
    CC08F8F8F80F77870787804444499CCCCC0FFF8F80F0F7780878044444499CCC
    C0F8F8F8078F0F870787044444499CCCC0FF8FF07777F0F80880444444499CCC
    C0F8F8F077878F0F0804444444499CCC0FFFFF07777878F00044444444499CCC
    0FF8F000000000000F4F444444499CCC0FFFF07778787880F0F0F44444499CCC
    0FF807878787870CCF00F44444499CCC0FFF0778787870CCF000F44444499CCC
    0FF8078787800CCCCFFF0F4444499CCC0FF07878780CCCCCCCCCFF4444499CCC
    C0F0777700CCCCCCCCCCCC4444499CCCC0F07700CCCCCCCCCCCCCCC444499CCC
    CC0000CCCCCCCCCCCCCCCCCC44499CCCCCCCCCCCCCCCCCCCCCCCCCCCC4499CCC
    CCCCCCCCCCCCCCCCCCCCCCCCCC49999999999999999999999999999999990000
    0000000000000000000000000000000000000000000000000000000000000000
    0000000000000000000000000000000000000000000000000000000000000000
    0000000000000000000000000000000000000000000000000000000000000000
    000000000000000000000000000000000000000000000000000000000000}
  OldCreateOrder = False
  Position = poMainFormCenter
  OnClose = FormClose
  OnCreate = FormCreate
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object DataViewPage: TPageControl
    Left = 0
    Top = 0
    Width = 712
    Height = 613
    ActivePage = TabSheet1
    Align = alClient
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    HotTrack = True
    ParentFont = False
    TabHeight = 25
    TabIndex = 0
    TabOrder = 0
    TabWidth = 150
    object TabSheet1: TTabSheet
      Caption = 'System Log'
      object PageControl2: TPageControl
        Left = 12
        Top = 117
        Width = 704
        Height = 493
        Style = tsButtons
        TabOrder = 2
      end
      object Panel2: TPanel
        Left = 0
        Top = 0
        Width = 704
        Height = 85
        Align = alTop
        BorderStyle = bsSingle
        TabOrder = 0
        object Label1: TLabel
          Left = 16
          Top = 20
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
        object Label2: TLabel
          Left = 16
          Top = 52
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
        object SysLogSearchBtn: TBitBtn
          Left = 284
          Top = 16
          Width = 89
          Height = 53
          Cancel = True
          Caption = '&Search'
          Font.Charset = ANSI_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'Tahoma'
          Font.Style = []
          ParentFont = False
          TabOrder = 1
          OnClick = BitBtnClick
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
          Layout = blGlyphTop
        end
        object SysLogTextFileBtn: TBitBtn
          Left = 380
          Top = 16
          Width = 137
          Height = 53
          Caption = 'Make &Text File'
          Font.Charset = ANSI_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'Tahoma'
          Font.Style = []
          ParentFont = False
          TabOrder = 2
          OnClick = BitBtnClick
          Glyph.Data = {
            76010000424D7601000000000000760000002800000020000000100000000100
            04000000000000010000120B0000120B00001000000000000000000000000000
            800000800000008080008000000080008000808000007F7F7F00BFBFBF000000
            FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00500000000055
            555557777777775F55550FFFFFFFFF0555557F5555555F7FFF5F0FEEEEEE0000
            05007F555555777775770FFFFFF0BFBFB00E7F5F5557FFF557770F0EEEE000FB
            FB0E7F75FF57775555770FF00F0FBFBFBF0E7F57757FFFF555770FE0B00000FB
            FB0E7F575777775555770FFF0FBFBFBFBF0E7F5575FFFFFFF5770FEEE0000000
            FB0E7F555777777755770FFFFF0B00BFB0007F55557577FFF7770FEEEEE0B000
            05557F555557577775550FFFFFFF0B0555557FF5F5F57575F55500F0F0F0F0B0
            555577F7F7F7F7F75F5550707070700B055557F7F7F7F7757FF5507070707050
            9055575757575757775505050505055505557575757575557555}
          Layout = blGlyphTop
          NumGlyphs = 2
        end
        object SysLogStartDatePicker: TDateTimePicker
          Left = 88
          Top = 14
          Width = 186
          Height = 24
          CalAlignment = dtaLeft
          Date = 37733.5936064005
          Time = 37733.5936064005
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
        object SysLogEndDatePicker: TDateTimePicker
          Left = 88
          Top = 46
          Width = 186
          Height = 24
          CalAlignment = dtaLeft
          Date = 37733.5936225116
          Time = 37733.5936225116
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
          TabOrder = 3
        end
      end
      object SysLogPage: TPageControl
        Left = 0
        Top = 85
        Width = 704
        Height = 493
        ActivePage = TabSheet3
        Align = alClient
        Font.Charset = ANSI_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'Tahoma'
        Font.Style = []
        ParentFont = False
        TabIndex = 0
        TabOrder = 1
        object TabSheet3: TTabSheet
          Caption = 'Logged List'
          object SysLogListBox: TListBox
            Left = 0
            Top = 0
            Width = 696
            Height = 465
            Style = lbOwnerDrawFixed
            Align = alClient
            Color = clWhite
            Font.Charset = ANSI_CHARSET
            Font.Color = clWindowText
            Font.Height = -11
            Font.Name = 'Tahoma'
            Font.Style = []
            ImeName = #54620#44397#50612' '#51077#47141' '#49884#49828#53596' (IME 2000)'
            ItemHeight = 15
            ParentFont = False
            TabOrder = 0
            OnDrawItem = SysLogListBoxDrawItem
          end
        end
        object TabSheet4: TTabSheet
          Caption = 'Error Graph'
          ImageIndex = 1
          object ErrViewPanel: TPanel
            Left = 0
            Top = 0
            Width = 696
            Height = 29
            Align = alTop
            BevelInner = bvLowered
            BevelOuter = bvLowered
            Caption = 'Alarm Contens'
            Color = clWhite
            Font.Charset = ANSI_CHARSET
            Font.Color = clRed
            Font.Height = -12
            Font.Name = 'Tahoma'
            Font.Style = []
            ParentFont = False
            TabOrder = 0
          end
          object ErrGraph: TChart
            Left = 0
            Top = 29
            Width = 696
            Height = 436
            AllowPanning = pmNone
            AllowZoom = False
            BackWall.Brush.Color = clWhite
            BackWall.Brush.Style = bsClear
            Gradient.EndColor = clWhite
            Gradient.StartColor = clYellow
            Gradient.Visible = True
            MarginBottom = 7
            MarginLeft = 2
            MarginTop = 2
            Title.Alignment = taRightJustify
            Title.Font.Charset = ANSI_CHARSET
            Title.Font.Color = clBlack
            Title.Font.Height = -11
            Title.Font.Name = 'MS Sans Serif'
            Title.Font.Style = [fsBold, fsUnderline]
            Title.Text.Strings = (
              'Error Analysis Graph')
            BottomAxis.ExactDateTime = False
            BottomAxis.Title.Caption = 'Error Code Number'
            BottomAxis.Title.Font.Charset = DEFAULT_CHARSET
            BottomAxis.Title.Font.Color = clRed
            BottomAxis.Title.Font.Height = -12
            BottomAxis.Title.Font.Name = 'Arial'
            BottomAxis.Title.Font.Style = [fsBold]
            LeftAxis.ExactDateTime = False
            LeftAxis.Title.Caption = 'Event Count'
            LeftAxis.Title.Font.Charset = DEFAULT_CHARSET
            LeftAxis.Title.Font.Color = clBlue
            LeftAxis.Title.Font.Height = -13
            LeftAxis.Title.Font.Name = 'Arial'
            LeftAxis.Title.Font.Style = [fsBold]
            Legend.Visible = False
            ScaleLastPage = False
            Align = alClient
            BevelInner = bvLowered
            BevelOuter = bvLowered
            TabOrder = 1
            OnMouseMove = ErrGraphMouseMove
            object Panel3: TPanel
              Left = 2
              Top = 412
              Width = 692
              Height = 22
              Align = alBottom
              BevelOuter = bvNone
              TabOrder = 0
              object GraphRightSizePanel: TPanel
                Left = 668
                Top = 0
                Width = 24
                Height = 22
                Align = alRight
                BevelOuter = bvNone
                Color = clYellow
                TabOrder = 2
              end
              object GraphLeftSizePanel: TPanel
                Left = 0
                Top = 0
                Width = 52
                Height = 22
                Align = alLeft
                BevelOuter = bvNone
                Color = clYellow
                TabOrder = 0
              end
              object ErrScrollBar: TScrollBar
                Left = 52
                Top = 0
                Width = 616
                Height = 22
                Align = alClient
                Max = 279
                PageSize = 0
                TabOrder = 1
                OnChange = ErrScrollBarChange
              end
            end
            object Series1: TBarSeries
              HorizAxis = aBothHorizAxis
              Marks.ArrowLength = 20
              Marks.Style = smsValue
              Marks.Visible = True
              SeriesColor = clRed
              Title = 'AlarmGraph'
              BarStyle = bsRectGradient
              BarWidthPercent = 95
              XValues.DateTime = False
              XValues.Name = 'X'
              XValues.Multiplier = 1
              XValues.Order = loAscending
              YValues.DateTime = False
              YValues.Name = 'Bar'
              YValues.Multiplier = 1
              YValues.Order = loNone
            end
          end
        end
      end
    end
    object TabSheet2: TTabSheet
      Caption = 'System Run Data'
      ImageIndex = 1
      object PdtDataPanel: TPanel
        Left = 0
        Top = 0
        Width = 704
        Height = 578
        Align = alClient
        BevelWidth = 2
        BorderStyle = bsSingle
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -16
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
        TabOrder = 0
      end
    end
    object TabSheet5: TTabSheet
      Caption = #48708#51260' '#45936#51060#53440
      ImageIndex = 2
      TabVisible = False
    end
  end
  object TextFileSaveDlg: TSaveDialog
    DefaultExt = 'txt'
    Filter = 'Text files (*.txt)|*.txt|All Files(*.*)|*.*'
    InitialDir = 'c:\'
    Title = 'Text File Save Dialog'
    Left = 636
    Top = 8
  end
  object TickTimer: TTimer
    Enabled = False
    Interval = 30
    OnTimer = TickTimerTimer
    Left = 668
    Top = 8
  end
end
