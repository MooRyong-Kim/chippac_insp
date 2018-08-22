object SysSetupForm: TSysSetupForm
  Left = 362
  Top = 143
  Width = 1072
  Height = 752
  BiDiMode = bdLeftToRight
  BorderIcons = []
  Caption = 'System Setup'
  Color = clBtnFace
  Font.Charset = ANSI_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  KeyPreview = True
  OldCreateOrder = False
  ParentBiDiMode = False
  Position = poDefault
  WindowState = wsMaximized
  OnClose = FormClose
  OnCreate = FormCreate
  OnKeyPress = FormKeyPress
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object Panel5: TPanel
    Left = 237
    Top = 0
    Width = 819
    Height = 714
    Align = alClient
    BorderStyle = bsSingle
    TabOrder = 1
    object Panel1: TPanel
      Left = 1
      Top = 1
      Width = 813
      Height = 30
      Align = alTop
      TabOrder = 0
      object ModifyTimePanel: TPanel
        Left = 1
        Top = 1
        Width = 385
        Height = 28
        Align = alLeft
        Alignment = taLeftJustify
        BevelOuter = bvNone
        BevelWidth = 2
        BorderStyle = bsSingle
        Caption = '  Modified: '
        Color = 16744448
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
        TabOrder = 0
      end
      object FileNamePanel: TPanel
        Left = 386
        Top = 1
        Width = 426
        Height = 28
        Align = alClient
        Alignment = taLeftJustify
        BevelOuter = bvNone
        BevelWidth = 2
        BorderStyle = bsSingle
        Caption = '  File Path: '
        Color = 16744448
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
        TabOrder = 1
      end
    end
    object PageControl1: TPageControl
      Left = 0
      Top = 24
      Width = 825
      Height = 689
      ActivePage = TabSheet4
      Style = tsFlatButtons
      TabIndex = 2
      TabOrder = 1
      object TabSheet2: TTabSheet
        Caption = 'TabSheet2'
        object OprPageCtrl: TPageControl
          Left = 7
          Top = 3
          Width = 746
          Height = 586
          ActivePage = OprPage1
          TabIndex = 1
          TabOrder = 0
          TabPosition = tpBottom
          Visible = False
          object OperPage0: TTabSheet
            Caption = 'OperPage0'
            ImageIndex = 4
            object Panel4: TPanel
              Left = 0
              Top = 0
              Width = 738
              Height = 560
              Align = alClient
              BevelOuter = bvNone
              Caption = 'Operator Setup'
              Color = 16119543
              Font.Charset = ANSI_CHARSET
              Font.Color = clRed
              Font.Height = -64
              Font.Name = 'Tahoma'
              Font.Style = [fsBold]
              ParentFont = False
              TabOrder = 0
            end
          end
          object OprPage1: TTabSheet
            Caption = 'OprPage1'
            object Panel7: TPanel
              Left = 0
              Top = 0
              Width = 738
              Height = 560
              Align = alClient
              BevelOuter = bvNone
              Color = 16119543
              Font.Charset = ANSI_CHARSET
              Font.Color = clBlack
              Font.Height = -11
              Font.Name = 'Tahoma'
              Font.Style = []
              ParentFont = False
              TabOrder = 0
              object UnitVsnErrSetRdoGrp: TRadioGroup
                Left = 376
                Top = 10
                Width = 350
                Height = 75
                Caption = 'Inspection Process: '
                ItemIndex = 0
                Items.Strings = (
                  'Stop'
                  'Message->Use Select->Continue'
                  'Auto Skip')
                TabOrder = 1
                OnClick = DataChange
              end
              object GroupBox5: TGroupBox
                Left = 12
                Top = 8
                Width = 350
                Height = 85
                Caption = 'Message Box: '
                TabOrder = 0
                object Label8: TLabel
                  Left = 16
                  Top = 56
                  Width = 68
                  Height = 13
                  Caption = 'Continue Time'
                end
                object MsgBoxBuzzChkBox: TCheckBox
                  Left = 16
                  Top = 24
                  Width = 229
                  Height = 17
                  Caption = 'Buzzer On After Message Box Appear'
                  TabOrder = 0
                  OnClick = DataChange
                end
                object MsgBoxBuzzTimeSpinEdit: TLMDSpinEdit
                  Left = 224
                  Top = 48
                  Width = 100
                  Height = 25
                  Bevel.Mode = bmWindows
                  Caret.BlinkRate = 530
                  ImeName = '???(??) (MS-IME98)'
                  TabOrder = 1
                  OnChange = DataChange
                  OnClick = DataChange
                  Font.Charset = ANSI_CHARSET
                  Font.Color = clWindowText
                  Font.Height = -13
                  Font.Name = 'Tahoma'
                  Font.Style = []
                  AutoSelect = True
                  ParentFont = False
                  CustomButtons = <>
                  CustomButtonParentCtlXP = False
                  Suffix = ' ms'
                  MaxValue = 10000
                  Value = 0
                end
              end
              object PkgIdxDelaySetGrpBox: TGroupBox
                Left = 12
                Top = 100
                Width = 350
                Height = 285
                Caption = 'Time Delay: '
                TabOrder = 3
                object Label7: TLabel
                  Left = 20
                  Top = 103
                  Width = 84
                  Height = 13
                  Caption = 'After Boat Arrival'
                end
                object Label66: TLabel
                  Left = 20
                  Top = 203
                  Width = 124
                  Height = 13
                  Caption = 'After Unloader Pusher On'
                end
                object Label67: TLabel
                  Left = 20
                  Top = 173
                  Width = 75
                  Height = 13
                  Caption = 'After Unloading'
                end
                object Label31: TLabel
                  Left = 20
                  Top = 233
                  Width = 151
                  Height = 13
                  Caption = 'Stopper Up After Boat Transfer'
                end
                object Label13: TLabel
                  Left = 20
                  Top = 71
                  Width = 111
                  Height = 13
                  Caption = 'After Block Vacuum Off'
                end
                object Label23: TLabel
                  Left = 20
                  Top = 39
                  Width = 68
                  Height = 13
                  Caption = 'After Block Up'
                end
                object Label26: TLabel
                  Left = 20
                  Top = 136
                  Width = 89
                  Height = 13
                  Caption = 'Before Vacuum On'
                end
                object TransferDlySpinEdit: TLMDSpinEdit
                  Left = 212
                  Top = 97
                  Width = 125
                  Height = 25
                  Bevel.Mode = bmWindows
                  Caret.BlinkRate = 530
                  ImeName = '???(??) (MS-IME98)'
                  TabOrder = 2
                  OnChange = DataChange
                  OnClick = DataChange
                  Font.Charset = ANSI_CHARSET
                  Font.Color = clWindowText
                  Font.Height = -13
                  Font.Name = 'Tahoma'
                  Font.Style = []
                  AutoSelect = True
                  ParentFont = False
                  CustomButtons = <>
                  CustomButtonParentCtlXP = False
                  Step = 10
                  Suffix = ' ms'
                  LineSize = 10
                  MaxValue = 10000
                  Value = 1000
                  Value = 1000
                end
                object UnloadingDlySpinEdit: TLMDSpinEdit
                  Left = 212
                  Top = 167
                  Width = 125
                  Height = 25
                  Bevel.Mode = bmWindows
                  Caret.BlinkRate = 530
                  ImeName = '???(??) (MS-IME98)'
                  TabOrder = 3
                  OnChange = DataChange
                  OnClick = DataChange
                  Font.Charset = ANSI_CHARSET
                  Font.Color = clWindowText
                  Font.Height = -13
                  Font.Name = 'Tahoma'
                  Font.Style = []
                  AutoSelect = True
                  ParentFont = False
                  CustomButtons = <>
                  CustomButtonParentCtlXP = False
                  Step = 10
                  Suffix = ' ms'
                  LineSize = 10
                  MaxValue = 10000
                  Value = 1000
                  Value = 1000
                end
                object UlPusherOnDlySpinEdit: TLMDSpinEdit
                  Left = 212
                  Top = 197
                  Width = 125
                  Height = 25
                  Bevel.Mode = bmWindows
                  Caret.BlinkRate = 530
                  ImeName = '???(??) (MS-IME98)'
                  TabOrder = 4
                  OnChange = DataChange
                  OnClick = DataChange
                  Font.Charset = ANSI_CHARSET
                  Font.Color = clWindowText
                  Font.Height = -13
                  Font.Name = 'Tahoma'
                  Font.Style = []
                  AutoSelect = True
                  ParentFont = False
                  CustomButtons = <>
                  CustomButtonParentCtlXP = False
                  Step = 10
                  Suffix = ' ms'
                  LineSize = 10
                  MaxValue = 10000
                  Value = 1000
                  Value = 1000
                end
                object StprUpDlySpinEdit: TLMDSpinEdit
                  Left = 212
                  Top = 227
                  Width = 125
                  Height = 25
                  Bevel.Mode = bmWindows
                  Caret.BlinkRate = 530
                  ImeName = '???(??) (MS-IME98)'
                  TabOrder = 5
                  OnChange = DataChange
                  OnClick = DataChange
                  Font.Charset = ANSI_CHARSET
                  Font.Color = clWindowText
                  Font.Height = -13
                  Font.Name = 'Tahoma'
                  Font.Style = []
                  AutoSelect = True
                  ParentFont = False
                  CustomButtons = <>
                  CustomButtonParentCtlXP = False
                  Step = 10
                  Suffix = ' ms'
                  LineSize = 10
                  MaxValue = 10000
                  Value = 1000
                  Value = 1000
                end
                object BlkVacOffDlySpinEdit: TLMDSpinEdit
                  Left = 212
                  Top = 65
                  Width = 125
                  Height = 25
                  Bevel.Mode = bmWindows
                  Caret.BlinkRate = 530
                  ImeName = '???(??) (MS-IME98)'
                  TabOrder = 1
                  OnChange = DataChange
                  OnClick = DataChange
                  Font.Charset = ANSI_CHARSET
                  Font.Color = clWindowText
                  Font.Height = -13
                  Font.Name = 'Tahoma'
                  Font.Style = []
                  AutoSelect = True
                  ParentFont = False
                  CustomButtons = <>
                  CustomButtonParentCtlXP = False
                  Step = 10
                  Suffix = ' ms'
                  LineSize = 10
                  MaxValue = 10000
                  Value = 1000
                  Value = 1000
                end
                object BlkUpDlySpinEdit: TLMDSpinEdit
                  Left = 212
                  Top = 33
                  Width = 125
                  Height = 25
                  Bevel.Mode = bmWindows
                  Caret.BlinkRate = 530
                  ImeName = '???(??) (MS-IME98)'
                  TabOrder = 0
                  OnChange = DataChange
                  OnClick = DataChange
                  Font.Charset = ANSI_CHARSET
                  Font.Color = clWindowText
                  Font.Height = -13
                  Font.Name = 'Tahoma'
                  Font.Style = []
                  AutoSelect = True
                  ParentFont = False
                  CustomButtons = <>
                  CustomButtonParentCtlXP = False
                  Step = 10
                  Suffix = ' ms'
                  LineSize = 10
                  MaxValue = 10000
                  Value = 1000
                  Value = 1000
                end
                object VacOnDelaySpinEdit: TLMDSpinEdit
                  Left = 212
                  Top = 130
                  Width = 125
                  Height = 25
                  Bevel.Mode = bmWindows
                  Caret.BlinkRate = 530
                  ImeName = '???(??) (MS-IME98)'
                  TabOrder = 6
                  OnChange = DataChange
                  OnClick = DataChange
                  Font.Charset = ANSI_CHARSET
                  Font.Color = clWindowText
                  Font.Height = -13
                  Font.Name = 'Tahoma'
                  Font.Style = []
                  AutoSelect = True
                  ParentFont = False
                  CustomButtons = <>
                  CustomButtonParentCtlXP = False
                  Step = 10
                  Suffix = ' ms'
                  LineSize = 10
                  MaxValue = 10000
                  Value = 1000
                  Value = 1000
                end
              end
              object GroupBox7: TGroupBox
                Left = 376
                Top = 88
                Width = 350
                Height = 161
                Caption = 'Inspection Option: '
                TabOrder = 2
                object Label93: TLabel
                  Left = 18
                  Top = 50
                  Width = 59
                  Height = 13
                  Caption = 'Retry Count'
                end
                object Label22: TLabel
                  Left = 18
                  Top = 82
                  Width = 53
                  Height = 13
                  Caption = 'Grab Delay'
                end
                object Label92: TLabel
                  Left = 18
                  Top = 125
                  Width = 101
                  Height = 13
                  Caption = 'Barcode Retry Count'
                end
                object InspErrCollectChkBox: TCheckBox
                  Left = 16
                  Top = 20
                  Width = 237
                  Height = 17
                  Caption = 'Shown Error After All Inspection Comleted'
                  TabOrder = 0
                  OnClick = DataChange
                end
                object VsnAutoRtyCntSpinEdit: TLMDSpinEdit
                  Left = 136
                  Top = 44
                  Width = 105
                  Height = 25
                  Bevel.Mode = bmWindows
                  Caret.BlinkRate = 530
                  ImeName = '???(??) (MS-IME98)'
                  TabOrder = 1
                  OnChange = DataChange
                  OnClick = DataChange
                  Font.Charset = ANSI_CHARSET
                  Font.Color = clWindowText
                  Font.Height = -13
                  Font.Name = 'Tahoma'
                  Font.Style = []
                  AutoSelect = True
                  ParentFont = False
                  CustomButtons = <>
                  CustomButtonParentCtlXP = False
                  Value = 0
                end
                object InspDlySpinEdit: TLMDSpinEdit
                  Left = 136
                  Top = 76
                  Width = 105
                  Height = 25
                  Bevel.Mode = bmWindows
                  Caret.BlinkRate = 530
                  ImeName = '???(??) (MS-IME98)'
                  TabOrder = 2
                  OnChange = DataChange
                  OnClick = DataChange
                  Font.Charset = ANSI_CHARSET
                  Font.Color = clWindowText
                  Font.Height = -13
                  Font.Name = 'Tahoma'
                  Font.Style = []
                  AutoSelect = True
                  ParentFont = False
                  CustomButtons = <>
                  CustomButtonParentCtlXP = False
                  Step = 10
                  Suffix = ' ms'
                  LineSize = 10
                  MaxValue = 3000
                  Value = 300
                  Value = 300
                end
                object SpinBcrRetryCnt: TLMDSpinEdit
                  Left = 136
                  Top = 119
                  Width = 105
                  Height = 25
                  Bevel.Mode = bmWindows
                  Caret.BlinkRate = 530
                  ImeName = '???(??) (MS-IME98)'
                  TabOrder = 3
                  OnChange = DataChange
                  OnClick = DataChange
                  Font.Charset = ANSI_CHARSET
                  Font.Color = clWindowText
                  Font.Height = -13
                  Font.Name = 'Tahoma'
                  Font.Style = []
                  AutoSelect = True
                  ParentFont = False
                  CustomButtons = <>
                  CustomButtonParentCtlXP = False
                  Value = 0
                end
              end
            end
          end
        end
      end
      object TabSheet3: TTabSheet
        Caption = 'TabSheet3'
        ImageIndex = 1
        object EngPageCtrl: TPageControl
          Left = 8
          Top = 1
          Width = 745
          Height = 620
          ActivePage = EngPage4
          MultiLine = True
          TabIndex = 3
          TabOrder = 0
          TabPosition = tpBottom
          Visible = False
          object EngPage0: TTabSheet
            Caption = 'EngPage0'
            ImageIndex = 13
            object Panel2: TPanel
              Left = 0
              Top = 0
              Width = 737
              Height = 594
              Align = alClient
              BevelOuter = bvNone
              Caption = 'Engneer Setup'
              Color = 16119543
              Font.Charset = ANSI_CHARSET
              Font.Color = clRed
              Font.Height = -64
              Font.Name = 'Tahoma'
              Font.Style = [fsBold]
              ParentFont = False
              TabOrder = 0
            end
          end
          object EngPage1: TTabSheet
            Caption = 'EngPage1'
            object Panel8: TPanel
              Left = 0
              Top = 0
              Width = 737
              Height = 594
              Align = alClient
              BevelOuter = bvNone
              Color = 16119543
              Font.Charset = ANSI_CHARSET
              Font.Color = clBlack
              Font.Height = -11
              Font.Name = 'Tahoma'
              Font.Style = []
              ParentFont = False
              TabOrder = 0
              object GroupBox89: TGroupBox
                Left = 16
                Top = 8
                Width = 350
                Height = 73
                Caption = 'Operator: '
                Color = 16119543
                ParentColor = False
                TabOrder = 0
                object StaticText1: TStaticText
                  Left = 16
                  Top = 20
                  Width = 50
                  Height = 17
                  Caption = 'Passward'
                  Color = 16119543
                  ParentColor = False
                  TabOrder = 2
                end
                object StaticText2: TStaticText
                  Left = 16
                  Top = 44
                  Width = 41
                  Height = 17
                  Caption = 'Confirm'
                  Color = 16119543
                  ParentColor = False
                  TabOrder = 4
                end
                object OprPswdChangeEdit: TEdit
                  Left = 84
                  Top = 16
                  Width = 170
                  Height = 21
                  ImeName = '???(??) (MS-IME98)'
                  MaxLength = 16
                  PasswordChar = '*'
                  TabOrder = 0
                  Text = '1111'
                  OnChange = DataChange
                end
                object OprPswdConfirmEdit: TEdit
                  Left = 84
                  Top = 40
                  Width = 170
                  Height = 21
                  ImeName = '???(??) (MS-IME98)'
                  MaxLength = 16
                  PasswordChar = '*'
                  TabOrder = 3
                  OnChange = DataChange
                end
                object OprPswdSetBtn: TBitBtn
                  Left = 256
                  Top = 17
                  Width = 81
                  Height = 41
                  Caption = 'Set'
                  TabOrder = 1
                  OnClick = BitBtnClick
                  Glyph.Data = {
                    36080000424D3608000000000000360400002800000020000000200000000100
                    0800000000000004000000000000000000000001000000000000000000000000
                    80000080000000808000800000008000800080800000C0C0C000C0DCC000F0CA
                    A600CCFFFF0099FFFF0066FFFF0033FFFF00FFCCFF00CCCCFF0099CCFF0066CC
                    FF0033CCFF0000CCFF00FF99FF00CC99FF009999FF006699FF003399FF000099
                    FF00FF66FF00CC66FF009966FF006666FF003366FF000066FF00FF33FF00CC33
                    FF009933FF006633FF003333FF000033FF00CC00FF009900FF006600FF003300
                    FF00FFFFCC00CCFFCC0099FFCC0066FFCC0066FFCC0033FFCC0000FFCC00FFCC
                    CC00CCCCCC0099CCCC0066CCCC0033CCCC0000CCCC00FF99CC00CC99CC009999
                    CC006699CC003399CC000099CC00FF66CC00CC66CC009966CC006666CC003366
                    CC000066CC00FF33CC00CC33CC009933CC006633CC003333CC000033CC00FF00
                    CC00CC00CC009900CC006600CC003300CC000000CC00FFFF9900CCFF990099FF
                    990066FF990033FF990000FF9900FFCC9900CCCC990099CC990066CC990033CC
                    990000CC9900FF999900CC99990099999900669999003399990000999900FF66
                    9900CC66990099669900666699003366990000669900FF339900CC3399009933
                    9900663399003333990000339900FF009900CC00990099009900660099003300
                    990000009900FFFF6600CCFF660099FF660066FF660033FF660000FF6600FFCC
                    6600CCCC660099CC660066CC660033CC660000CC6600FF996600CC9966009999
                    6600669966003399660000996600FF666600CC66660099666600666666003366
                    660000666600FF336600CC33660099336600663366003333660000336600FF00
                    6600CC00660099006600660066003300660000006600FFFF3300CCFF330099FF
                    330066FF330033FF330000FF3300FFCC3300CCCC330099CC330066CC330033CC
                    330000CC3300FF993300CC99330099993300669933003399330000993300FF66
                    3300CC66330099663300666633003366330000663300FF333300CC3333009933
                    3300663333003333330000333300FF003300CC00330099003300660033003300
                    330000003300CCFF000099FF000066FF000033FF0000FFCC0000CCCC000099CC
                    000066CC000033CC000000CC0000FF990000CC99000099990000669900003399
                    000000990000FF660000CC66000099660000666600000066000033660000FF33
                    0000CC33000099330000663300003333000000330000CC000000990000006600
                    0000330000000000DD000000BB000000AA000000880000007700000055000000
                    44000000220000DD000000BB000000AA00000088000000770000005500000044
                    000000220000DDDDDD0055555500777777007777770044444400222222001111
                    110077000000550000004400000022000000F0FBFF00A4A0A000808080000000
                    FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00FDFDFDFDFDFD
                    FDFDFDFDFDFD89FDFDFDFDFDFDFDFDFDFDFDFDFDFDFDFDFDFDFDFDFDFDFDFDFD
                    FDFDFDFDFD89008989EBEBEB89FDFDFDFDFDFDFDFDFDFDFDFDFDFDFDFDFDFDFD
                    FDFDFDFD89000C00008989898989FDFDFDFDFDFDFDFDFDFDFDFDFDFDFDFDFDFD
                    FDFDFD89000C0C0C0C000089008989FDFDFDFDFDFDFDFDFDFDFDFDFDFDFDFDFD
                    FDFD89000C0C33335E5E0000FB008989FDFDFDFDFDFDFDFDFDFDFDFDFDFDFDFD
                    FD89000C33335E5E0000FBFBFBFB008989FDFDFDFDFDFDFDFDFDFDFDFDFDFDFD
                    890033335E5E0000FBFBFBFBFBFBFB00008989FDFDFDFDFDFDFDFDFDFDFDFD89
                    00335E5E00000D0D0D0D0D0D0D0D0D0D0000008989FDFDFDFDFDFDFDFDFD8900
                    5E5E00000C0C0C0C0C0C0C0C0C0C0C0C0C003300008989FDFDFDFDFDFD89005E
                    00000B0B0B0B0B0B0B0B0B890B0B0B0B0B0B003333F5008989FDFDFD89000000
                    0B0B0B0B0B0B0000890089890089898989898900898989000089FD8900000A0A
                    0A0A0A0A0A0AEC0000890089890089898989898900898900898900000A0A0A0A
                    0A0A0A0A0A890AECEF0000893333895E5E5E5E5E5E0000898989FD00FF0A0A0A
                    0A0A0A890AFF89ECEF171700000A0A890A0A0A0A0A0A008989FDFDFD00FFFF0A
                    FF0AFF0A890AFFECFF1617171700FF0A330AFF0AFF0A0A00FDFDFDFDFD00FFFF
                    0AFF0AFF0A5E0AFFECFFEC00000000FF0AFF0AFF0AFF0A0A00FDFDFDFDFD00FF
                    FF0AFF0AFF0A890AECFFECFBEF181800FF0AFF0AFF0A0000FDFDFDFDFDFDFD00
                    FFFF0AFF0AFF0A89ECECECFFFBEF181800FF0AFF0000FDFDFDFDFDFDFDFDFDFD
                    00FFFFFFFFFFFFFF33EC0B5DFFFBEF1818000000FDFDFDFDFDFDFDFDFDFDFDFD
                    FD00FFFF0AFF0AFF0AEC180B5DFFFBEF181800FDFDFDFDFDFDFDFDFDFDFDFDFD
                    FDFD00FFFFFFFFFFFFFFEC180B5DFFFBEF181800FDFDFDFDFDFDFDFDFDFDFDFD
                    FDFDFD00FFFF0AFF0AFF0AEC180B5DFFFBEF181800FDFDFDFDFDFDFDFDFDFDFD
                    FDFDFDFD00FFFFFFFF0A0000EC180B5DFFFBEF181800FDFDFDFDFDFDFDFDFDFD
                    FDFDFDFDFD00FFFF0000FDFDFDEC180B5DFFFBEF181800FDFDFDFDFDFDFDFDFD
                    FDFDFDFDFDFD0000FDFDFDFDFDFDEC180B5DFFFBEFEFEF00FDFDFDFDFDFDFDFD
                    FDFDFDFDFDFDFDFDFDFDFDFDFDFDFDEC180B5DFFEF40406B00FDFDFDFDFDFDFD
                    FDFDFDFDFDFDFDFDFDFDFDFDFDFDFDFDEC180BECFF4040EFEF00FDFDFDFDFDFD
                    FDFDFDFDFDFDFDFDFDFDFDFDFDFDFDFDFDEC18EC16FFEF161600FDFDFDFDFDFD
                    FDFDFDFDFDFDFDFDFDFDFDFDFDFDFDFDFDFDECEC16ECFF161600FDFDFDFDFDFD
                    FDFDFDFDFDFDFDFDFDFDFDFDFDFDFDFDFDFDFDEC16ECFF161600FDFDFDFDFDFD
                    FDFDFDFDFDFDFDFDFDFDFDFDFDFDFDFDFDFDFDFDECECFF16ECFDFDFDFDFDFDFD
                    FDFDFDFDFDFDFDFDFDFDFDFDFDFDFDFDFDFDFDFDFDECECECFDFD}
                end
              end
              object GroupBox3: TGroupBox
                Left = 16
                Top = 236
                Width = 349
                Height = 129
                Caption = 'System Event Log Setting: '
                Color = 16119543
                ParentColor = False
                TabOrder = 4
                object SysLogItemChkListBox: TCheckListBox
                  Left = 2
                  Top = 15
                  Width = 345
                  Height = 112
                  Align = alClient
                  BorderStyle = bsNone
                  Color = 16119543
                  Columns = 2
                  Flat = False
                  ImeName = '???(??) (MS-IME98)'
                  ItemHeight = 18
                  Items.Strings = (
                    'Power On'
                    'Power Off'
                    'System Initialize'
                    'System Warm Up'
                    'Alarm Event'
                    'Model File Open'
                    'Model File Modify '
                    'Product Start'
                    'Product Stop'
                    'Lot Start'
                    'System Config Modify')
                  Style = lbOwnerDrawFixed
                  TabOrder = 0
                  OnClick = DataChange
                end
              end
              object Panel9: TPanel
                Left = 380
                Top = 12
                Width = 350
                Height = 361
                BevelInner = bvRaised
                BevelOuter = bvLowered
                Color = 16119543
                TabOrder = 1
                object StaticText5: TStaticText
                  Left = 8
                  Top = 8
                  Width = 83
                  Height = 17
                  Caption = '*Machine Status'
                  Color = 16119543
                  ParentColor = False
                  TabOrder = 0
                end
                object TwrLmpComboBox: TComboBox
                  Left = 12
                  Top = 28
                  Width = 329
                  Height = 24
                  Style = csDropDownList
                  Font.Charset = ANSI_CHARSET
                  Font.Color = clWindowText
                  Font.Height = -13
                  Font.Name = 'Tahoma'
                  Font.Style = []
                  ImeName = '???(??) (MS-IME98)'
                  ItemHeight = 16
                  ParentFont = False
                  TabOrder = 1
                  OnChange = TwrLmpComboBoxChange
                  Items.Strings = (
                    'Select Machine Status'
                    'Idle Mode'
                    'Start'
                    'Stop'
                    'Alarm'
                    'Material Change'
                    'Work Completed')
                end
                object GroupBox11: TGroupBox
                  Left = 8
                  Top = 60
                  Width = 333
                  Height = 293
                  Caption = 'Tower Lamp Condition: '
                  Color = 16119543
                  ParentColor = False
                  TabOrder = 2
                  object GrnLmpRdoGrp: TRadioGroup
                    Left = 8
                    Top = 16
                    Width = 315
                    Height = 65
                    Caption = 'Green Lamp: '
                    Columns = 5
                    Items.Strings = (
                      'Off'
                      'On'
                      'Flash')
                    TabOrder = 0
                    OnClick = DataChange
                  end
                  object GrnLmpFlashTimeSpinEdit: TLMDSpinEdit
                    Left = 212
                    Top = 40
                    Width = 100
                    Height = 25
                    Bevel.Mode = bmWindows
                    Caret.BlinkRate = 530
                    ImeName = '???(??) (MS-IME98)'
                    TabOrder = 1
                    OnChange = DataChange
                    Font.Charset = ANSI_CHARSET
                    Font.Color = clWindowText
                    Font.Height = -13
                    Font.Name = 'Tahoma'
                    Font.Style = []
                    AutoSelect = True
                    ParentFont = False
                    CustomButtons = <>
                    CustomButtonParentCtlXP = False
                    Step = 100
                    Suffix = ' msec'
                    LineSize = 100
                    PageSize = 100
                    MinValue = 100
                    MaxValue = 10000
                    Value = 100
                    Value = 100
                  end
                  object YlwLmpRdoGrp: TRadioGroup
                    Left = 8
                    Top = 88
                    Width = 315
                    Height = 65
                    Caption = 'Yellow Lamp: '
                    Columns = 5
                    Items.Strings = (
                      'Off'
                      'On'
                      'Flash')
                    TabOrder = 2
                    OnClick = DataChange
                  end
                  object RedLmpRdoGrp: TRadioGroup
                    Left = 8
                    Top = 160
                    Width = 315
                    Height = 65
                    Caption = 'Red Lamp: '
                    Columns = 5
                    Items.Strings = (
                      'Off'
                      'On'
                      'Flash')
                    TabOrder = 4
                    OnClick = DataChange
                  end
                  object YlwLmpFlashTimeSpinEdit: TLMDSpinEdit
                    Left = 212
                    Top = 112
                    Width = 100
                    Height = 25
                    Bevel.Mode = bmWindows
                    Caret.BlinkRate = 530
                    ImeName = '???(??) (MS-IME98)'
                    TabOrder = 3
                    OnChange = DataChange
                    Font.Charset = ANSI_CHARSET
                    Font.Color = clWindowText
                    Font.Height = -13
                    Font.Name = 'Tahoma'
                    Font.Style = []
                    AutoSelect = True
                    ParentFont = False
                    CustomButtons = <>
                    CustomButtonParentCtlXP = False
                    Step = 100
                    Suffix = ' msec'
                    LineSize = 100
                    PageSize = 100
                    MinValue = 100
                    MaxValue = 10000
                    Value = 100
                    Value = 100
                  end
                  object RedLmpFlashTimeSpinEdit: TLMDSpinEdit
                    Left = 212
                    Top = 184
                    Width = 100
                    Height = 25
                    Bevel.Mode = bmWindows
                    Caret.BlinkRate = 530
                    ImeName = '???(??) (MS-IME98)'
                    TabOrder = 5
                    OnChange = DataChange
                    Font.Charset = ANSI_CHARSET
                    Font.Color = clWindowText
                    Font.Height = -13
                    Font.Name = 'Tahoma'
                    Font.Style = []
                    AutoSelect = True
                    ParentFont = False
                    CustomButtons = <>
                    CustomButtonParentCtlXP = False
                    Step = 100
                    Suffix = ' msec'
                    LineSize = 100
                    PageSize = 100
                    MinValue = 100
                    MaxValue = 10000
                    Value = 100
                    Value = 100
                  end
                  object BuzzChkBox: TCheckBox
                    Left = 16
                    Top = 232
                    Width = 85
                    Height = 17
                    Caption = 'Use Buzzer'
                    TabOrder = 6
                    OnClick = DataChange
                  end
                  object UseBuzzValidTimeChkBox: TCheckBox
                    Left = 16
                    Top = 260
                    Width = 133
                    Height = 17
                    Caption = 'Use Buzzer Invalid Time'
                    TabOrder = 8
                    OnClick = DataChange
                  end
                  object BuzzValidTimeSpinEdit: TLMDSpinEdit
                    Left = 164
                    Top = 252
                    Width = 100
                    Height = 25
                    Bevel.Mode = bmWindows
                    Caret.BlinkRate = 530
                    ImeName = '???(??) (MS-IME98)'
                    TabOrder = 7
                    OnChange = DataChange
                    Font.Charset = ANSI_CHARSET
                    Font.Color = clWindowText
                    Font.Height = -13
                    Font.Name = 'Tahoma'
                    Font.Style = []
                    AutoSelect = True
                    ParentFont = False
                    CustomButtons = <>
                    CustomButtonParentCtlXP = False
                    Suffix = ' sec'
                    MinValue = 1
                    Value = 1
                    Value = 1
                  end
                end
              end
              object GroupBox90: TGroupBox
                Left = 16
                Top = 84
                Width = 349
                Height = 73
                Caption = 'Engineer: '
                Color = 16119543
                ParentColor = False
                TabOrder = 2
                object StaticText7: TStaticText
                  Left = 16
                  Top = 20
                  Width = 50
                  Height = 17
                  Caption = 'Password'
                  Color = 16119543
                  ParentColor = False
                  TabOrder = 2
                end
                object StaticText8: TStaticText
                  Left = 16
                  Top = 44
                  Width = 41
                  Height = 17
                  Caption = 'Confirm'
                  Color = 16119543
                  ParentColor = False
                  TabOrder = 4
                end
                object EngPswdChangeEdit: TEdit
                  Left = 84
                  Top = 16
                  Width = 170
                  Height = 21
                  ImeName = '???(??) (MS-IME98)'
                  MaxLength = 16
                  PasswordChar = '*'
                  TabOrder = 0
                  Text = '1111'
                  OnChange = DataChange
                end
                object EngPswdConfirmEdit: TEdit
                  Left = 84
                  Top = 40
                  Width = 170
                  Height = 21
                  ImeName = '??'#0'(??) (MS-IME98)'
                  MaxLength = 16
                  PasswordChar = '*'
                  TabOrder = 3
                  OnChange = DataChange
                end
                object EngPswdSetBtn: TBitBtn
                  Left = 256
                  Top = 17
                  Width = 81
                  Height = 41
                  Caption = 'Set'
                  TabOrder = 1
                  OnClick = BitBtnClick
                  Glyph.Data = {
                    36080000424D3608000000000000360400002800000020000000200000000100
                    0800000000000004000000000000000000000001000000000000000000000000
                    80000080000000808000800000008000800080800000C0C0C000C0DCC000F0CA
                    A600CCFFFF0099FFFF0066FFFF0033FFFF00FFCCFF00CCCCFF0099CCFF0066CC
                    FF0033CCFF0000CCFF00FF99FF00CC99FF009999FF006699FF003399FF000099
                    FF00FF66FF00CC66FF009966FF006666FF003366FF000066FF00FF33FF00CC33
                    FF009933FF006633FF003333FF000033FF00CC00FF009900FF006600FF003300
                    FF00FFFFCC00CCFFCC0099FFCC0066FFCC0066FFCC0033FFCC0000FFCC00FFCC
                    CC00CCCCCC0099CCCC0066CCCC0033CCCC0000CCCC00FF99CC00CC99CC009999
                    CC006699CC003399CC000099CC00FF66CC00CC66CC009966CC006666CC003366
                    CC000066CC00FF33CC00CC33CC009933CC006633CC003333CC000033CC00FF00
                    CC00CC00CC009900CC006600CC003300CC000000CC00FFFF9900CCFF990099FF
                    990066FF990033FF990000FF9900FFCC9900CCCC990099CC990066CC990033CC
                    990000CC9900FF999900CC99990099999900669999003399990000999900FF66
                    9900CC66990099669900666699003366990000669900FF339900CC3399009933
                    9900663399003333990000339900FF009900CC00990099009900660099003300
                    990000009900FFFF6600CCFF660099FF660066FF660033FF660000FF6600FFCC
                    6600CCCC660099CC660066CC660033CC660000CC6600FF996600CC9966009999
                    6600669966003399660000996600FF666600CC66660099666600666666003366
                    660000666600FF336600CC33660099336600663366003333660000336600FF00
                    6600CC00660099006600660066003300660000006600FFFF3300CCFF330099FF
                    330066FF330033FF330000FF3300FFCC3300CCCC330099CC330066CC330033CC
                    330000CC3300FF993300CC99330099993300669933003399330000993300FF66
                    3300CC66330099663300666633003366330000663300FF333300CC3333009933
                    3300663333003333330000333300FF003300CC00330099003300660033003300
                    330000003300CCFF000099FF000066FF000033FF0000FFCC0000CCCC000099CC
                    000066CC000033CC000000CC0000FF990000CC99000099990000669900003399
                    000000990000FF660000CC66000099660000666600000066000033660000FF33
                    0000CC33000099330000663300003333000000330000CC000000990000006600
                    0000330000000000DD000000BB000000AA000000880000007700000055000000
                    44000000220000DD000000BB000000AA00000088000000770000005500000044
                    000000220000DDDDDD0055555500777777007777770044444400222222001111
                    110077000000550000004400000022000000F0FBFF00A4A0A000808080000000
                    FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00FDFDFDFDFDFD
                    FDFDFDFDFDFD89FDFDFDFDFDFDFDFDFDFDFDFDFDFDFDFDFDFDFDFDFDFDFDFDFD
                    FDFDFDFDFD89008989EBEBEB89FDFDFDFDFDFDFDFDFDFDFDFDFDFDFDFDFDFDFD
                    FDFDFDFD89000C00008989898989FDFDFDFDFDFDFDFDFDFDFDFDFDFDFDFDFDFD
                    FDFDFD89000C0C0C0C000089008989FDFDFDFDFDFDFDFDFDFDFDFDFDFDFDFDFD
                    FDFD89000C0C33335E5E0000FB008989FDFDFDFDFDFDFDFDFDFDFDFDFDFDFDFD
                    FD89000C33335E5E0000FBFBFBFB008989FDFDFDFDFDFDFDFDFDFDFDFDFDFDFD
                    890033335E5E0000FBFBFBFBFBFBFB00008989FDFDFDFDFDFDFDFDFDFDFDFD89
                    00335E5E00000D0D0D0D0D0D0D0D0D0D0000008989FDFDFDFDFDFDFDFDFD8900
                    5E5E00000C0C0C0C0C0C0C0C0C0C0C0C0C003300008989FDFDFDFDFDFD89005E
                    00000B0B0B0B0B0B0B0B0B890B0B0B0B0B0B003333F5008989FDFDFD89000000
                    0B0B0B0B0B0B0000890089890089898989898900898989000089FD8900000A0A
                    0A0A0A0A0A0AEC0000890089890089898989898900898900898900000A0A0A0A
                    0A0A0A0A0A890AECEF0000893333895E5E5E5E5E5E0000898989FD00FF0A0A0A
                    0A0A0A890AFF89ECEF171700000A0A890A0A0A0A0A0A008989FDFDFD00FFFF0A
                    FF0AFF0A890AFFECFF1617171700FF0A330AFF0AFF0A0A00FDFDFDFDFD00FFFF
                    0AFF0AFF0A5E0AFFECFFEC00000000FF0AFF0AFF0AFF0A0A00FDFDFDFDFD00FF
                    FF0AFF0AFF0A890AECFFECFBEF181800FF0AFF0AFF0A0000FDFDFDFDFDFDFD00
                    FFFF0AFF0AFF0A89ECECECFFFBEF181800FF0AFF0000FDFDFDFDFDFDFDFDFDFD
                    00FFFFFFFFFFFFFF33EC0B5DFFFBEF1818000000FDFDFDFDFDFDFDFDFDFDFDFD
                    FD00FFFF0AFF0AFF0AEC180B5DFFFBEF181800FDFDFDFDFDFDFDFDFDFDFDFDFD
                    FDFD00FFFFFFFFFFFFFFEC180B5DFFFBEF181800FDFDFDFDFDFDFDFDFDFDFDFD
                    FDFDFD00FFFF0AFF0AFF0AEC180B5DFFFBEF181800FDFDFDFDFDFDFDFDFDFDFD
                    FDFDFDFD00FFFFFFFF0A0000EC180B5DFFFBEF181800FDFDFDFDFDFDFDFDFDFD
                    FDFDFDFDFD00FFFF0000FDFDFDEC180B5DFFFBEF181800FDFDFDFDFDFDFDFDFD
                    FDFDFDFDFDFD0000FDFDFDFDFDFDEC180B5DFFFBEFEFEF00FDFDFDFDFDFDFDFD
                    FDFDFDFDFDFDFDFDFDFDFDFDFDFDFDEC180B5DFFEF40406B00FDFDFDFDFDFDFD
                    FDFDFDFDFDFDFDFDFDFDFDFDFDFDFDFDEC180BECFF4040EFEF00FDFDFDFDFDFD
                    FDFDFDFDFDFDFDFDFDFDFDFDFDFDFDFDFDEC18EC16FFEF161600FDFDFDFDFDFD
                    FDFDFDFDFDFDFDFDFDFDFDFDFDFDFDFDFDFDECEC16ECFF161600FDFDFDFDFDFD
                    FDFDFDFDFDFDFDFDFDFDFDFDFDFDFDFDFDFDFDEC16ECFF161600FDFDFDFDFDFD
                    FDFDFDFDFDFDFDFDFDFDFDFDFDFDFDFDFDFDFDFDECECFF16ECFDFDFDFDFDFDFD
                    FDFDFDFDFDFDFDFDFDFDFDFDFDFDFDFDFDFDFDFDFDECECECFDFD}
                end
              end
              object GroupBox20: TGroupBox
                Left = 16
                Top = 372
                Width = 350
                Height = 77
                Caption = 'Production Log: '
                Color = 16119543
                ParentColor = False
                TabOrder = 5
                object Label71: TLabel
                  Left = 20
                  Top = 20
                  Width = 96
                  Height = 13
                  Caption = 'File Expiration Date '
                end
                object FileValidDaySpinEdit: TLMDSpinEdit
                  Left = 20
                  Top = 41
                  Width = 85
                  Height = 25
                  Bevel.Mode = bmWindows
                  Caret.BlinkRate = 530
                  ImeName = '???(??) (MS-IME98)'
                  TabOrder = 0
                  OnChange = DataChange
                  Font.Charset = ANSI_CHARSET
                  Font.Color = clWindowText
                  Font.Height = -13
                  Font.Name = 'Tahoma'
                  Font.Style = []
                  AutoSelect = True
                  ParentFont = False
                  CustomButtons = <>
                  CustomButtonParentCtlXP = False
                  Suffix = ' Day'
                  MinValue = 1
                  MaxValue = 365
                  Value = 10
                  Value = 10
                end
              end
              object GroupBox41: TGroupBox
                Left = 16
                Top = 160
                Width = 349
                Height = 73
                Caption = 'Work Button Password: '
                Color = 16119543
                ParentColor = False
                TabOrder = 3
                object StaticText3: TStaticText
                  Left = 16
                  Top = 20
                  Width = 50
                  Height = 17
                  Caption = 'Password'
                  Color = 16119543
                  ParentColor = False
                  TabOrder = 2
                end
                object StaticText4: TStaticText
                  Left = 16
                  Top = 44
                  Width = 41
                  Height = 17
                  Caption = 'Confirm'
                  Color = 16119543
                  ParentColor = False
                  TabOrder = 4
                end
                object WorkPswdChangeEdit: TEdit
                  Left = 84
                  Top = 16
                  Width = 170
                  Height = 21
                  ImeName = '???(??) (MS-IME98)'
                  MaxLength = 16
                  PasswordChar = '*'
                  TabOrder = 0
                  Text = '1111'
                  OnChange = DataChange
                end
                object WorkPswdConfirmEdit: TEdit
                  Left = 84
                  Top = 40
                  Width = 170
                  Height = 21
                  ImeName = '??'#0'(??) (MS-IME98)'
                  MaxLength = 16
                  PasswordChar = '*'
                  TabOrder = 3
                  OnChange = DataChange
                end
                object WorkPswdSetBtn: TBitBtn
                  Left = 256
                  Top = 17
                  Width = 81
                  Height = 41
                  Caption = 'Set'
                  TabOrder = 1
                  OnClick = BitBtnClick
                  Glyph.Data = {
                    36080000424D3608000000000000360400002800000020000000200000000100
                    0800000000000004000000000000000000000001000000000000000000000000
                    80000080000000808000800000008000800080800000C0C0C000C0DCC000F0CA
                    A600CCFFFF0099FFFF0066FFFF0033FFFF00FFCCFF00CCCCFF0099CCFF0066CC
                    FF0033CCFF0000CCFF00FF99FF00CC99FF009999FF006699FF003399FF000099
                    FF00FF66FF00CC66FF009966FF006666FF003366FF000066FF00FF33FF00CC33
                    FF009933FF006633FF003333FF000033FF00CC00FF009900FF006600FF003300
                    FF00FFFFCC00CCFFCC0099FFCC0066FFCC0066FFCC0033FFCC0000FFCC00FFCC
                    CC00CCCCCC0099CCCC0066CCCC0033CCCC0000CCCC00FF99CC00CC99CC009999
                    CC006699CC003399CC000099CC00FF66CC00CC66CC009966CC006666CC003366
                    CC000066CC00FF33CC00CC33CC009933CC006633CC003333CC000033CC00FF00
                    CC00CC00CC009900CC006600CC003300CC000000CC00FFFF9900CCFF990099FF
                    990066FF990033FF990000FF9900FFCC9900CCCC990099CC990066CC990033CC
                    990000CC9900FF999900CC99990099999900669999003399990000999900FF66
                    9900CC66990099669900666699003366990000669900FF339900CC3399009933
                    9900663399003333990000339900FF009900CC00990099009900660099003300
                    990000009900FFFF6600CCFF660099FF660066FF660033FF660000FF6600FFCC
                    6600CCCC660099CC660066CC660033CC660000CC6600FF996600CC9966009999
                    6600669966003399660000996600FF666600CC66660099666600666666003366
                    660000666600FF336600CC33660099336600663366003333660000336600FF00
                    6600CC00660099006600660066003300660000006600FFFF3300CCFF330099FF
                    330066FF330033FF330000FF3300FFCC3300CCCC330099CC330066CC330033CC
                    330000CC3300FF993300CC99330099993300669933003399330000993300FF66
                    3300CC66330099663300666633003366330000663300FF333300CC3333009933
                    3300663333003333330000333300FF003300CC00330099003300660033003300
                    330000003300CCFF000099FF000066FF000033FF0000FFCC0000CCCC000099CC
                    000066CC000033CC000000CC0000FF990000CC99000099990000669900003399
                    000000990000FF660000CC66000099660000666600000066000033660000FF33
                    0000CC33000099330000663300003333000000330000CC000000990000006600
                    0000330000000000DD000000BB000000AA000000880000007700000055000000
                    44000000220000DD000000BB000000AA00000088000000770000005500000044
                    000000220000DDDDDD0055555500777777007777770044444400222222001111
                    110077000000550000004400000022000000F0FBFF00A4A0A000808080000000
                    FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00FDFDFDFDFDFD
                    FDFDFDFDFDFD89FDFDFDFDFDFDFDFDFDFDFDFDFDFDFDFDFDFDFDFDFDFDFDFDFD
                    FDFDFDFDFD89008989EBEBEB89FDFDFDFDFDFDFDFDFDFDFDFDFDFDFDFDFDFDFD
                    FDFDFDFD89000C00008989898989FDFDFDFDFDFDFDFDFDFDFDFDFDFDFDFDFDFD
                    FDFDFD89000C0C0C0C000089008989FDFDFDFDFDFDFDFDFDFDFDFDFDFDFDFDFD
                    FDFD89000C0C33335E5E0000FB008989FDFDFDFDFDFDFDFDFDFDFDFDFDFDFDFD
                    FD89000C33335E5E0000FBFBFBFB008989FDFDFDFDFDFDFDFDFDFDFDFDFDFDFD
                    890033335E5E0000FBFBFBFBFBFBFB00008989FDFDFDFDFDFDFDFDFDFDFDFD89
                    00335E5E00000D0D0D0D0D0D0D0D0D0D0000008989FDFDFDFDFDFDFDFDFD8900
                    5E5E00000C0C0C0C0C0C0C0C0C0C0C0C0C003300008989FDFDFDFDFDFD89005E
                    00000B0B0B0B0B0B0B0B0B890B0B0B0B0B0B003333F5008989FDFDFD89000000
                    0B0B0B0B0B0B0000890089890089898989898900898989000089FD8900000A0A
                    0A0A0A0A0A0AEC0000890089890089898989898900898900898900000A0A0A0A
                    0A0A0A0A0A890AECEF0000893333895E5E5E5E5E5E0000898989FD00FF0A0A0A
                    0A0A0A890AFF89ECEF171700000A0A890A0A0A0A0A0A008989FDFDFD00FFFF0A
                    FF0AFF0A890AFFECFF1617171700FF0A330AFF0AFF0A0A00FDFDFDFDFD00FFFF
                    0AFF0AFF0A5E0AFFECFFEC00000000FF0AFF0AFF0AFF0A0A00FDFDFDFDFD00FF
                    FF0AFF0AFF0A890AECFFECFBEF181800FF0AFF0AFF0A0000FDFDFDFDFDFDFD00
                    FFFF0AFF0AFF0A89ECECECFFFBEF181800FF0AFF0000FDFDFDFDFDFDFDFDFDFD
                    00FFFFFFFFFFFFFF33EC0B5DFFFBEF1818000000FDFDFDFDFDFDFDFDFDFDFDFD
                    FD00FFFF0AFF0AFF0AEC180B5DFFFBEF181800FDFDFDFDFDFDFDFDFDFDFDFDFD
                    FDFD00FFFFFFFFFFFFFFEC180B5DFFFBEF181800FDFDFDFDFDFDFDFDFDFDFDFD
                    FDFDFD00FFFF0AFF0AFF0AEC180B5DFFFBEF181800FDFDFDFDFDFDFDFDFDFDFD
                    FDFDFDFD00FFFFFFFF0A0000EC180B5DFFFBEF181800FDFDFDFDFDFDFDFDFDFD
                    FDFDFDFDFD00FFFF0000FDFDFDEC180B5DFFFBEF181800FDFDFDFDFDFDFDFDFD
                    FDFDFDFDFDFD0000FDFDFDFDFDFDEC180B5DFFFBEFEFEF00FDFDFDFDFDFDFDFD
                    FDFDFDFDFDFDFDFDFDFDFDFDFDFDFDEC180B5DFFEF40406B00FDFDFDFDFDFDFD
                    FDFDFDFDFDFDFDFDFDFDFDFDFDFDFDFDEC180BECFF4040EFEF00FDFDFDFDFDFD
                    FDFDFDFDFDFDFDFDFDFDFDFDFDFDFDFDFDEC18EC16FFEF161600FDFDFDFDFDFD
                    FDFDFDFDFDFDFDFDFDFDFDFDFDFDFDFDFDFDECEC16ECFF161600FDFDFDFDFDFD
                    FDFDFDFDFDFDFDFDFDFDFDFDFDFDFDFDFDFDFDEC16ECFF161600FDFDFDFDFDFD
                    FDFDFDFDFDFDFDFDFDFDFDFDFDFDFDFDFDFDFDFDECECFF16ECFDFDFDFDFDFDFD
                    FDFDFDFDFDFDFDFDFDFDFDFDFDFDFDFDFDFDFDFDFDECECECFDFD}
                end
              end
            end
          end
          object TabSheet1: TTabSheet
            Caption = 'TabSheet1'
            ImageIndex = 4
            object Panel10: TPanel
              Left = 0
              Top = 0
              Width = 737
              Height = 594
              Align = alClient
              BevelOuter = bvNone
              Color = 16119543
              Font.Charset = ANSI_CHARSET
              Font.Color = clBlack
              Font.Height = -11
              Font.Name = 'Tahoma'
              Font.Style = []
              ParentFont = False
              TabOrder = 0
              object GroupBox122: TGroupBox
                Left = 376
                Top = 8
                Width = 350
                Height = 153
                Caption = 'Time Out Error: '
                TabOrder = 1
                object Label173: TLabel
                  Left = 16
                  Top = 28
                  Width = 90
                  Height = 13
                  Caption = 'Cylinder Operation'
                end
                object Label185: TLabel
                  Left = 16
                  Top = 120
                  Width = 72
                  Height = 13
                  Caption = 'Communication'
                end
                object Label30: TLabel
                  Left = 16
                  Top = 88
                  Width = 91
                  Height = 13
                  Caption = 'Conveyor Transfer'
                end
                object Label14: TLabel
                  Left = 16
                  Top = 56
                  Width = 64
                  Height = 13
                  Caption = 'Block Vacuum'
                end
                object CylTimeErrSpinEdit: TLMDSpinEdit
                  Left = 216
                  Top = 20
                  Width = 105
                  Height = 25
                  Bevel.Mode = bmWindows
                  Caret.BlinkRate = 530
                  ImeName = '???(??) (MS-IME98)'
                  TabOrder = 0
                  OnChange = DataChange
                  Font.Charset = ANSI_CHARSET
                  Font.Color = clWindowText
                  Font.Height = -13
                  Font.Name = 'Tahoma'
                  Font.Style = []
                  AutoSelect = True
                  ParentFont = False
                  CustomButtons = <>
                  CustomButtonParentCtlXP = False
                  Step = 100
                  Suffix = ' msec'
                  LineSize = 100
                  PageSize = 100
                  MaxValue = 10000
                  Value = 1000
                  Value = 1000
                end
                object ComTimeErrSpinEdit: TLMDSpinEdit
                  Left = 216
                  Top = 116
                  Width = 105
                  Height = 25
                  Bevel.Mode = bmWindows
                  Caret.BlinkRate = 530
                  ImeName = '???(??) (MS-IME98)'
                  TabOrder = 3
                  OnChange = DataChange
                  Font.Charset = ANSI_CHARSET
                  Font.Color = clWindowText
                  Font.Height = -13
                  Font.Name = 'Tahoma'
                  Font.Style = []
                  AutoSelect = True
                  ParentFont = False
                  CustomButtons = <>
                  CustomButtonParentCtlXP = False
                  Step = 100
                  Suffix = ' msec'
                  LineSize = 100
                  PageSize = 100
                  MaxValue = 10000
                  Value = 1000
                  Value = 1000
                end
                object CvyTimeErrSpinEdit: TLMDSpinEdit
                  Left = 216
                  Top = 84
                  Width = 105
                  Height = 25
                  Bevel.Mode = bmWindows
                  Caret.BlinkRate = 530
                  ImeName = '???(??) (MS-IME98)'
                  TabOrder = 2
                  OnChange = DataChange
                  Font.Charset = ANSI_CHARSET
                  Font.Color = clWindowText
                  Font.Height = -13
                  Font.Name = 'Tahoma'
                  Font.Style = []
                  AutoSelect = True
                  ParentFont = False
                  CustomButtons = <>
                  CustomButtonParentCtlXP = False
                  Suffix = ' sec'
                  MinValue = 1
                  MaxValue = 30
                  Value = 10
                  Value = 10
                end
                object BlkVacTimeErrSpinEdit: TLMDSpinEdit
                  Left = 216
                  Top = 52
                  Width = 105
                  Height = 25
                  Bevel.Mode = bmWindows
                  Caret.BlinkRate = 530
                  ImeName = '???(??) (MS-IME98)'
                  TabOrder = 1
                  OnChange = DataChange
                  Font.Charset = ANSI_CHARSET
                  Font.Color = clWindowText
                  Font.Height = -13
                  Font.Name = 'Tahoma'
                  Font.Style = []
                  AutoSelect = True
                  ParentFont = False
                  CustomButtons = <>
                  CustomButtonParentCtlXP = False
                  Step = 100
                  Suffix = ' msec'
                  LineSize = 100
                  PageSize = 100
                  MaxValue = 10000
                  Value = 1000
                  Value = 1000
                end
              end
              object GroupBox1: TGroupBox
                Left = 12
                Top = 8
                Width = 350
                Height = 153
                Caption = 'Inter Lock: '
                TabOrder = 0
                object SafetySrvOffChkBox: TCheckBox
                  Left = 16
                  Top = 16
                  Width = 317
                  Height = 17
                  Caption = 'Servo Power Off When Safety Sensor Detect '
                  Checked = True
                  Color = clRed
                  Font.Charset = ANSI_CHARSET
                  Font.Color = clBlue
                  Font.Height = -11
                  Font.Name = 'Tahoma'
                  Font.Style = []
                  ParentColor = False
                  ParentFont = False
                  State = cbChecked
                  TabOrder = 0
                  OnClick = DataChange
                end
                object SafetySensGrpBox: TGroupBox
                  Left = 8
                  Top = 36
                  Width = 333
                  Height = 105
                  Caption = 'Safety Sensor: '
                  TabOrder = 1
                  object UlBarSafetyChkBox: TCheckBox
                    Left = 16
                    Top = 63
                    Width = 133
                    Height = 13
                    Caption = 'Unloader Bar Safety'
                    Checked = True
                    State = cbChecked
                    TabOrder = 1
                    OnClick = DataChange
                  end
                  object FrntDoorSafetyChkBox: TCheckBox
                    Left = 16
                    Top = 20
                    Width = 111
                    Height = 17
                    Caption = 'Front Door Safety'
                    Checked = True
                    State = cbChecked
                    TabOrder = 0
                    OnClick = DataChange
                  end
                  object UvDoorSafetyChkBox: TCheckBox
                    Left = 16
                    Top = 42
                    Width = 133
                    Height = 13
                    Caption = 'UV Door Safety'
                    Checked = True
                    State = cbChecked
                    TabOrder = 2
                    OnClick = DataChange
                  end
                end
              end
              object GroupBox23: TGroupBox
                Left = 12
                Top = 170
                Width = 350
                Height = 183
                Caption = 'Inspection Block: '
                TabOrder = 2
                object Label37: TLabel
                  Left = 16
                  Top = 87
                  Width = 179
                  Height = 13
                  Caption = 'Inspection Block Vacuum Retry Count'
                end
                object NoUseInspBlkVacErrChkBox: TCheckBox
                  Left = 16
                  Top = 42
                  Width = 213
                  Height = 17
                  Caption = 'Disable Inspection Block Vacuum Error'
                  TabOrder = 2
                  OnClick = DataChange
                end
                object NoUseInspBlkVacOnChkBox: TCheckBox
                  Left = 16
                  Top = 62
                  Width = 197
                  Height = 17
                  Caption = 'No Use Inspection Block Vacuum On'
                  TabOrder = 3
                  OnClick = DataChange
                end
                object NoUseInspBlkChkBox: TCheckBox
                  Left = 16
                  Top = 20
                  Width = 157
                  Height = 17
                  Caption = 'No Use Inspection Block'
                  TabOrder = 0
                  OnClick = DataChange
                end
                object InspBlkVacRtyNumSpinEdit: TLMDSpinEdit
                  Left = 228
                  Top = 81
                  Width = 105
                  Height = 25
                  Bevel.Mode = bmWindows
                  Caret.BlinkRate = 530
                  ImeName = '???(??) (MS-IME98)'
                  TabOrder = 4
                  OnChange = DataChange
                  OnClick = DataChange
                  Font.Charset = ANSI_CHARSET
                  Font.Color = clWindowText
                  Font.Height = -13
                  Font.Name = 'Tahoma'
                  Font.Style = []
                  AutoSelect = True
                  ParentFont = False
                  CustomButtons = <>
                  CustomButtonParentCtlXP = False
                  Suffix = ' cnt'
                  MaxValue = 10
                  Value = 0
                end
                object UseClampChkBox: TCheckBox
                  Left = 184
                  Top = 20
                  Width = 157
                  Height = 17
                  Caption = 'Use Clamp'
                  TabOrder = 1
                  OnClick = DataChange
                end
                object ChkHeaterAlarm: TCheckBox
                  Left = 16
                  Top = 113
                  Width = 157
                  Height = 17
                  Caption = 'Use Heater S/W alarm'
                  TabOrder = 5
                  OnClick = DataChange
                end
              end
            end
          end
          object EngPage4: TTabSheet
            Caption = 'EngPage4'
            ImageIndex = 17
            object LdUlSetupPageCtrl: TRzPageControl
              Left = 0
              Top = 0
              Width = 737
              Height = 594
              ActivePage = RzTabSheet1
              BackgroundColor = 16119543
              Color = 16119543
              Font.Charset = ANSI_CHARSET
              Font.Color = clWindowText
              Font.Height = -11
              Font.Name = 'Tahoma'
              Font.Style = [fsBold]
              FlatColor = 10263441
              ParentBackgroundColor = False
              ParentColor = False
              ParentFont = False
              TabColors.HighlightBar = 1350640
              TabIndex = 0
              TabOrder = 0
              FixedDimension = 19
              object RzTabSheet1: TRzTabSheet
                Color = 16119543
                Caption = '  Magazine  '
                object PkgMgzUlSetGrpBox: TGroupBox
                  Left = 6
                  Top = 90
                  Width = 361
                  Height = 385
                  Caption = 'Unloader: '
                  Font.Charset = ANSI_CHARSET
                  Font.Color = clWindowText
                  Font.Height = -11
                  Font.Name = 'Tahoma'
                  Font.Style = []
                  ParentFont = False
                  TabOrder = 2
                  object PkgUlAlarmChkBox: TCheckBox
                    Left = 12
                    Top = 556
                    Width = 169
                    Height = 17
                    Caption = '?? ??? ?? ??'
                    Checked = True
                    State = cbChecked
                    TabOrder = 5
                    Visible = False
                  end
                  object PkgUM1SetGrpBox: TGroupBox
                    Left = 7
                    Top = 68
                    Width = 330
                    Height = 81
                    Caption = 'Magazine #1       : '
                    TabOrder = 1
                    object Label216: TLabel
                      Left = 12
                      Top = 24
                      Width = 85
                      Height = 13
                      AutoSize = False
                      Caption = '1'#39'st Slot Pos'
                    end
                    object Label217: TLabel
                      Left = 12
                      Top = 54
                      Width = 85
                      Height = 13
                      AutoSize = False
                      Caption = 'End Slot Pos'
                    end
                    object UlMgz1StartPosEdit: TEdit
                      Left = 112
                      Top = 18
                      Width = 64
                      Height = 24
                      Color = 16777088
                      Font.Charset = ANSI_CHARSET
                      Font.Color = clWindowText
                      Font.Height = -13
                      Font.Name = 'Tahoma'
                      Font.Style = []
                      ImeName = '???(??)'
                      MaxLength = 7
                      ParentFont = False
                      TabOrder = 1
                      Text = '0.000'
                    end
                    object UlMgz1EndPosEdit: TEdit
                      Left = 112
                      Top = 48
                      Width = 64
                      Height = 24
                      Color = 16777088
                      Font.Charset = ANSI_CHARSET
                      Font.Color = clWindowText
                      Font.Height = -13
                      Font.Name = 'Tahoma'
                      Font.Style = []
                      ImeName = '???(??)'
                      MaxLength = 7
                      ParentFont = False
                      TabOrder = 4
                      Text = '0.000'
                    end
                    object UlMgz1UseChkBox: TCheckBox
                      Left = 75
                      Top = -1
                      Width = 17
                      Height = 17
                      TabOrder = 0
                    end
                    object UlMgz1StartPosGetBtn: TRzBitBtn
                      Left = 188
                      Top = 18
                      Width = 61
                      Height = 24
                      FrameColor = 7617536
                      Caption = 'GET'
                      Color = 15791348
                      HotTrack = True
                      TabOrder = 2
                      OnClick = GetPosBtnClick
                      Glyph.Data = {
                        36030000424D3603000000000000360000002800000010000000100000000100
                        18000000000000030000C30E0000C30E00000000000000000000FFFFFFFFFFFF
                        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFBFB
                        FBE3E3E3DCDCDCDDDDDDD1D1DBE5E5E6FFFFFFE4DBDBD2CFCFDAD1D1D2CFCFE3
                        D9D9FFFFFFFFFFFFFFFFFFFFFFFFDDDDDD3434341919191A1A1A25251F424040
                        BCBABA3C4E4E2A29291D2F2F2C34343B5151CACDCDFDFAFAFFFFFFFFFFFFDDDD
                        DD353535242424282828B7B5001B15000E393F3CC1C195D2D24BD0D092C1C117
                        9595293535E6DDDDFFFFFFFFFFFFFAFAFAE3E3E3D4D4D4D1D1D1E4DB00242C1C
                        36B4C0A7FFFF6CFFFFADF0F05A64640A3939363B3BCBC8C8FFFFFFFFFFFFFFFF
                        FFE5E5E5404041252525D3D000332E259BD9E56CFFFF96FFFF6AF5F590C0C033
                        BDBD92A2A2433333B2AFAFE6DCDCFFFFFFDFE0DF3D3D33252518D9D100232D22
                        50D0DCA1FFFF68FFFFADF0F05861611144443240400828282731313B5050C3C5
                        C4FAF8F6DBDBE3CFCFDCDCD9003531259ADAE66EFCFC92D5D553D0D093C8C82D
                        B9B981BABA2DC4C48ABFBF109A9B435348D8CDDB4849FF2525FFB5AC00161F15
                        36B9C4B2EFEF5B5959033030192626203535333B3B253A3A2F3737394E4FC8CA
                        C3E1DFF93F40FF2525FF2A2922211E1F1441413BBEBE9BC5C5189797263030C4
                        B1B1D7D3D3DAD0D0D2CECEE3D9D9FFFFFFFBFBFCD9D9E3CFCFDCD3D3DDDFDCDD
                        C4C1C03346462932323B5151CCCFCFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                        FFDEDEDD3E3E33252518FFFFFFFFFFFFFFFFFFE3D9D9D0CDCDE3D9D9FFFFFFFF
                        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFE5E5E5404041252525FFFFFFFFFFFF
                        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFAFA
                        FAE3E3E3D4D4D4D1D1D1FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                        FFFFFFFFFFFFFFFFFFFFFFFFFFFFDDDDDD353535242424282828FFFFFFFFFFFF
                        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFDDDD
                        DD3434341919191A1A1AFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFBFBFBE3E3E3DCDCDCDDDDDD}
                    end
                    object UlMgz1StartPosGoBtn: TRzBitBtn
                      Left = 252
                      Top = 18
                      Width = 61
                      Height = 24
                      FrameColor = 7617536
                      Caption = 'GO'
                      Color = 15791348
                      HotTrack = True
                      TabOrder = 3
                      OnClick = GoBtnClick
                      Glyph.Data = {
                        36030000424D3603000000000000360000002800000010000000100000000100
                        18000000000000030000C30E0000C30E00000000000000000000FFFFFFFFFFFF
                        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFE3E3E3E3E3E3FFFFFFFFFFFFFFFFFFFF
                        FFFFFFFFFFFFFFFFFFFFFFFFFFFFE3E3E3E3E3E3FFFFFFFFFFFFFFFFFFCDCDCD
                        333333333333CDCDCDFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFCDCDCD3333
                        33333333CDCDCDFFFFFFC5C5C52B2B2B00000000000029292ABBBBBBD3D3D3D1
                        D1D1D4D4D4D4D4D4BBBBBB2A2A2A0000000000002A2A2AC5C5C51B1B1B171717
                        1717171717152323192A2A282E2E2F2C2C2C2828282D2D2D2929291919191414
                        141717171B1B1B1D1D1D1A1A1AC4C4C5C0C0BFBBBBB5D2D2D8DADAD4D1D1D1C9
                        C9C9ADADADD1D1D1DBDBDBDFDFDFC1C1C1CACACAC6C6C6101010252525E7E7E6
                        FFFFFFC0C0FF4848FFC2C2FFFFFFFFFFFFFFDCDCDCDBDBDBDBDBDBDBDBDBE0E0
                        E0DFDFDF818181242424222222E2E2DCEDEDFF3E3EFF0000FF3B3BFFE7E7FFFC
                        FCFAA9A9A93333332323232929292F2F2F181818323232C7C7C7212121E6E6E5
                        FFFFFFC2C2FF4B4BFFC2C2FFFFFFFFE2E2E1363636929293B7B7B8AEAEAF7272
                        732A2A2AC2C2C2FFFFFF242424B9B9B9D3D3D3D7D7D1CDCDD1D6D6D1D6D6D3B7
                        B7AD1616129A9A8FCDCDC0A5A59A4C4C49CFCFC8FFFFFFFFFFFF747474373737
                        2B2B2C2F2F2D37372D30302D28282E15152915152011112419192329293DBEBE
                        C5E3E3FFF7F7FFFFFFFFF1F1F1D6D6D6D0D0D0D1D1D1D0D0D1D4D4D1AFAFD144
                        44D3BDBDDC3737D60000D23C3CDCDFDFFF6161FFD8D8FFFFFFFFFFFFFFFFFFFF
                        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFE5E5FFE4E4FFC3C3FF4A4AFFC2C2FFDCDC
                        FFD7D7FFF6F6FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFE0
                        E0FF5858FFD6D6FFDDDDFFD6D6FF5858FFE1E1FFFFFFFFFFFFFFFFFFFFFFFFFF
                        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF6F6FFDBDBFFD2D2FF5F5FFFD2D2FFDBDB
                        FFF6F6FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                        FFFFFFFFFFF8F8FFD8D8FFF8F8FFFFFFFFFFFFFFFFFFFFFFFFFF}
                    end
                    object UlMgz1EndPosGetBtn: TRzBitBtn
                      Left = 188
                      Top = 48
                      Width = 61
                      Height = 24
                      FrameColor = 7617536
                      Caption = 'GET'
                      Color = 15791348
                      HotTrack = True
                      TabOrder = 5
                      OnClick = GetPosBtnClick
                      Glyph.Data = {
                        36030000424D3603000000000000360000002800000010000000100000000100
                        18000000000000030000C30E0000C30E00000000000000000000FFFFFFFFFFFF
                        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFBFB
                        FBE3E3E3DCDCDCDDDDDDD1D1DBE5E5E6FFFFFFE4DBDBD2CFCFDAD1D1D2CFCFE3
                        D9D9FFFFFFFFFFFFFFFFFFFFFFFFDDDDDD3434341919191A1A1A25251F424040
                        BCBABA3C4E4E2A29291D2F2F2C34343B5151CACDCDFDFAFAFFFFFFFFFFFFDDDD
                        DD353535242424282828B7B5001B15000E393F3CC1C195D2D24BD0D092C1C117
                        9595293535E6DDDDFFFFFFFFFFFFFAFAFAE3E3E3D4D4D4D1D1D1E4DB00242C1C
                        36B4C0A7FFFF6CFFFFADF0F05A64640A3939363B3BCBC8C8FFFFFFFFFFFFFFFF
                        FFE5E5E5404041252525D3D000332E259BD9E56CFFFF96FFFF6AF5F590C0C033
                        BDBD92A2A2433333B2AFAFE6DCDCFFFFFFDFE0DF3D3D33252518D9D100232D22
                        50D0DCA1FFFF68FFFFADF0F05861611144443240400828282731313B5050C3C5
                        C4FAF8F6DBDBE3CFCFDCDCD9003531259ADAE66EFCFC92D5D553D0D093C8C82D
                        B9B981BABA2DC4C48ABFBF109A9B435348D8CDDB4849FF2525FFB5AC00161F15
                        36B9C4B2EFEF5B5959033030192626203535333B3B253A3A2F3737394E4FC8CA
                        C3E1DFF93F40FF2525FF2A2922211E1F1441413BBEBE9BC5C5189797263030C4
                        B1B1D7D3D3DAD0D0D2CECEE3D9D9FFFFFFFBFBFCD9D9E3CFCFDCD3D3DDDFDCDD
                        C4C1C03346462932323B5151CCCFCFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                        FFDEDEDD3E3E33252518FFFFFFFFFFFFFFFFFFE3D9D9D0CDCDE3D9D9FFFFFFFF
                        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFE5E5E5404041252525FFFFFFFFFFFF
                        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFAFA
                        FAE3E3E3D4D4D4D1D1D1FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                        FFFFFFFFFFFFFFFFFFFFFFFFFFFFDDDDDD353535242424282828FFFFFFFFFFFF
                        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFDDDD
                        DD3434341919191A1A1AFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFBFBFBE3E3E3DCDCDCDDDDDD}
                    end
                    object UlMgz1EndPosGoBtn: TRzBitBtn
                      Left = 252
                      Top = 48
                      Width = 61
                      Height = 24
                      FrameColor = 7617536
                      Caption = 'GO'
                      Color = 15791348
                      HotTrack = True
                      TabOrder = 6
                      OnClick = GoBtnClick
                      Glyph.Data = {
                        36030000424D3603000000000000360000002800000010000000100000000100
                        18000000000000030000C30E0000C30E00000000000000000000FFFFFFFFFFFF
                        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFE3E3E3E3E3E3FFFFFFFFFFFFFFFFFFFF
                        FFFFFFFFFFFFFFFFFFFFFFFFFFFFE3E3E3E3E3E3FFFFFFFFFFFFFFFFFFCDCDCD
                        333333333333CDCDCDFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFCDCDCD3333
                        33333333CDCDCDFFFFFFC5C5C52B2B2B00000000000029292ABBBBBBD3D3D3D1
                        D1D1D4D4D4D4D4D4BBBBBB2A2A2A0000000000002A2A2AC5C5C51B1B1B171717
                        1717171717152323192A2A282E2E2F2C2C2C2828282D2D2D2929291919191414
                        141717171B1B1B1D1D1D1A1A1AC4C4C5C0C0BFBBBBB5D2D2D8DADAD4D1D1D1C9
                        C9C9ADADADD1D1D1DBDBDBDFDFDFC1C1C1CACACAC6C6C6101010252525E7E7E6
                        FFFFFFC0C0FF4848FFC2C2FFFFFFFFFFFFFFDCDCDCDBDBDBDBDBDBDBDBDBE0E0
                        E0DFDFDF818181242424222222E2E2DCEDEDFF3E3EFF0000FF3B3BFFE7E7FFFC
                        FCFAA9A9A93333332323232929292F2F2F181818323232C7C7C7212121E6E6E5
                        FFFFFFC2C2FF4B4BFFC2C2FFFFFFFFE2E2E1363636929293B7B7B8AEAEAF7272
                        732A2A2AC2C2C2FFFFFF242424B9B9B9D3D3D3D7D7D1CDCDD1D6D6D1D6D6D3B7
                        B7AD1616129A9A8FCDCDC0A5A59A4C4C49CFCFC8FFFFFFFFFFFF747474373737
                        2B2B2C2F2F2D37372D30302D28282E15152915152011112419192329293DBEBE
                        C5E3E3FFF7F7FFFFFFFFF1F1F1D6D6D6D0D0D0D1D1D1D0D0D1D4D4D1AFAFD144
                        44D3BDBDDC3737D60000D23C3CDCDFDFFF6161FFD8D8FFFFFFFFFFFFFFFFFFFF
                        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFE5E5FFE4E4FFC3C3FF4A4AFFC2C2FFDCDC
                        FFD7D7FFF6F6FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFE0
                        E0FF5858FFD6D6FFDDDDFFD6D6FF5858FFE1E1FFFFFFFFFFFFFFFFFFFFFFFFFF
                        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF6F6FFDBDBFFD2D2FF5F5FFFD2D2FFDBDB
                        FFF6F6FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                        FFFFFFFFFFF8F8FFD8D8FFF8F8FFFFFFFFFFFFFFFFFFFFFFFFFF}
                    end
                  end
                  object PkgUM2SetGrpBox: TGroupBox
                    Left = 7
                    Top = 152
                    Width = 330
                    Height = 81
                    Caption = 'Magazine #2       : '
                    TabOrder = 2
                    object Label214: TLabel
                      Left = 12
                      Top = 24
                      Width = 85
                      Height = 13
                      AutoSize = False
                      Caption = '1'#39'st Slot Pos'
                    end
                    object Label215: TLabel
                      Left = 12
                      Top = 54
                      Width = 85
                      Height = 13
                      AutoSize = False
                      Caption = 'End Slot Pos'
                    end
                    object UlMgz2StartPosEdit: TEdit
                      Left = 112
                      Top = 18
                      Width = 64
                      Height = 24
                      Color = 16777088
                      Font.Charset = ANSI_CHARSET
                      Font.Color = clWindowText
                      Font.Height = -13
                      Font.Name = 'Tahoma'
                      Font.Style = []
                      ImeName = '???(??)'
                      MaxLength = 7
                      ParentFont = False
                      TabOrder = 1
                      Text = '0.000'
                    end
                    object UlMgz2EndPosEdit: TEdit
                      Left = 112
                      Top = 48
                      Width = 64
                      Height = 24
                      Color = 16777088
                      Font.Charset = ANSI_CHARSET
                      Font.Color = clWindowText
                      Font.Height = -13
                      Font.Name = 'Tahoma'
                      Font.Style = []
                      ImeName = '???(??)'
                      MaxLength = 7
                      ParentFont = False
                      TabOrder = 4
                      Text = '0.000'
                    end
                    object UlMgz2UseChkBox: TCheckBox
                      Left = 75
                      Top = -1
                      Width = 17
                      Height = 17
                      TabOrder = 0
                    end
                    object UlMgz2StartPosGetBtn: TRzBitBtn
                      Left = 188
                      Top = 18
                      Width = 61
                      Height = 24
                      FrameColor = 7617536
                      Caption = 'GET'
                      Color = 15791348
                      HotTrack = True
                      TabOrder = 2
                      OnClick = GetPosBtnClick
                      Glyph.Data = {
                        36030000424D3603000000000000360000002800000010000000100000000100
                        18000000000000030000C30E0000C30E00000000000000000000FFFFFFFFFFFF
                        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFBFB
                        FBE3E3E3DCDCDCDDDDDDD1D1DBE5E5E6FFFFFFE4DBDBD2CFCFDAD1D1D2CFCFE3
                        D9D9FFFFFFFFFFFFFFFFFFFFFFFFDDDDDD3434341919191A1A1A25251F424040
                        BCBABA3C4E4E2A29291D2F2F2C34343B5151CACDCDFDFAFAFFFFFFFFFFFFDDDD
                        DD353535242424282828B7B5001B15000E393F3CC1C195D2D24BD0D092C1C117
                        9595293535E6DDDDFFFFFFFFFFFFFAFAFAE3E3E3D4D4D4D1D1D1E4DB00242C1C
                        36B4C0A7FFFF6CFFFFADF0F05A64640A3939363B3BCBC8C8FFFFFFFFFFFFFFFF
                        FFE5E5E5404041252525D3D000332E259BD9E56CFFFF96FFFF6AF5F590C0C033
                        BDBD92A2A2433333B2AFAFE6DCDCFFFFFFDFE0DF3D3D33252518D9D100232D22
                        50D0DCA1FFFF68FFFFADF0F05861611144443240400828282731313B5050C3C5
                        C4FAF8F6DBDBE3CFCFDCDCD9003531259ADAE66EFCFC92D5D553D0D093C8C82D
                        B9B981BABA2DC4C48ABFBF109A9B435348D8CDDB4849FF2525FFB5AC00161F15
                        36B9C4B2EFEF5B5959033030192626203535333B3B253A3A2F3737394E4FC8CA
                        C3E1DFF93F40FF2525FF2A2922211E1F1441413BBEBE9BC5C5189797263030C4
                        B1B1D7D3D3DAD0D0D2CECEE3D9D9FFFFFFFBFBFCD9D9E3CFCFDCD3D3DDDFDCDD
                        C4C1C03346462932323B5151CCCFCFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                        FFDEDEDD3E3E33252518FFFFFFFFFFFFFFFFFFE3D9D9D0CDCDE3D9D9FFFFFFFF
                        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFE5E5E5404041252525FFFFFFFFFFFF
                        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFAFA
                        FAE3E3E3D4D4D4D1D1D1FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                        FFFFFFFFFFFFFFFFFFFFFFFFFFFFDDDDDD353535242424282828FFFFFFFFFFFF
                        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFDDDD
                        DD3434341919191A1A1AFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFBFBFBE3E3E3DCDCDCDDDDDD}
                    end
                    object UlMgz2StartPosGoBtn: TRzBitBtn
                      Left = 252
                      Top = 18
                      Width = 61
                      Height = 24
                      FrameColor = 7617536
                      Caption = 'GO'
                      Color = 15791348
                      HotTrack = True
                      TabOrder = 3
                      OnClick = GoBtnClick
                      Glyph.Data = {
                        36030000424D3603000000000000360000002800000010000000100000000100
                        18000000000000030000C30E0000C30E00000000000000000000FFFFFFFFFFFF
                        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFE3E3E3E3E3E3FFFFFFFFFFFFFFFFFFFF
                        FFFFFFFFFFFFFFFFFFFFFFFFFFFFE3E3E3E3E3E3FFFFFFFFFFFFFFFFFFCDCDCD
                        333333333333CDCDCDFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFCDCDCD3333
                        33333333CDCDCDFFFFFFC5C5C52B2B2B00000000000029292ABBBBBBD3D3D3D1
                        D1D1D4D4D4D4D4D4BBBBBB2A2A2A0000000000002A2A2AC5C5C51B1B1B171717
                        1717171717152323192A2A282E2E2F2C2C2C2828282D2D2D2929291919191414
                        141717171B1B1B1D1D1D1A1A1AC4C4C5C0C0BFBBBBB5D2D2D8DADAD4D1D1D1C9
                        C9C9ADADADD1D1D1DBDBDBDFDFDFC1C1C1CACACAC6C6C6101010252525E7E7E6
                        FFFFFFC0C0FF4848FFC2C2FFFFFFFFFFFFFFDCDCDCDBDBDBDBDBDBDBDBDBE0E0
                        E0DFDFDF818181242424222222E2E2DCEDEDFF3E3EFF0000FF3B3BFFE7E7FFFC
                        FCFAA9A9A93333332323232929292F2F2F181818323232C7C7C7212121E6E6E5
                        FFFFFFC2C2FF4B4BFFC2C2FFFFFFFFE2E2E1363636929293B7B7B8AEAEAF7272
                        732A2A2AC2C2C2FFFFFF242424B9B9B9D3D3D3D7D7D1CDCDD1D6D6D1D6D6D3B7
                        B7AD1616129A9A8FCDCDC0A5A59A4C4C49CFCFC8FFFFFFFFFFFF747474373737
                        2B2B2C2F2F2D37372D30302D28282E15152915152011112419192329293DBEBE
                        C5E3E3FFF7F7FFFFFFFFF1F1F1D6D6D6D0D0D0D1D1D1D0D0D1D4D4D1AFAFD144
                        44D3BDBDDC3737D60000D23C3CDCDFDFFF6161FFD8D8FFFFFFFFFFFFFFFFFFFF
                        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFE5E5FFE4E4FFC3C3FF4A4AFFC2C2FFDCDC
                        FFD7D7FFF6F6FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFE0
                        E0FF5858FFD6D6FFDDDDFFD6D6FF5858FFE1E1FFFFFFFFFFFFFFFFFFFFFFFFFF
                        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF6F6FFDBDBFFD2D2FF5F5FFFD2D2FFDBDB
                        FFF6F6FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                        FFFFFFFFFFF8F8FFD8D8FFF8F8FFFFFFFFFFFFFFFFFFFFFFFFFF}
                    end
                    object UlMgz2EndPosGetBtn: TRzBitBtn
                      Left = 188
                      Top = 48
                      Width = 61
                      Height = 24
                      FrameColor = 7617536
                      Caption = 'GET'
                      Color = 15791348
                      HotTrack = True
                      TabOrder = 5
                      OnClick = GetPosBtnClick
                      Glyph.Data = {
                        36030000424D3603000000000000360000002800000010000000100000000100
                        18000000000000030000C30E0000C30E00000000000000000000FFFFFFFFFFFF
                        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFBFB
                        FBE3E3E3DCDCDCDDDDDDD1D1DBE5E5E6FFFFFFE4DBDBD2CFCFDAD1D1D2CFCFE3
                        D9D9FFFFFFFFFFFFFFFFFFFFFFFFDDDDDD3434341919191A1A1A25251F424040
                        BCBABA3C4E4E2A29291D2F2F2C34343B5151CACDCDFDFAFAFFFFFFFFFFFFDDDD
                        DD353535242424282828B7B5001B15000E393F3CC1C195D2D24BD0D092C1C117
                        9595293535E6DDDDFFFFFFFFFFFFFAFAFAE3E3E3D4D4D4D1D1D1E4DB00242C1C
                        36B4C0A7FFFF6CFFFFADF0F05A64640A3939363B3BCBC8C8FFFFFFFFFFFFFFFF
                        FFE5E5E5404041252525D3D000332E259BD9E56CFFFF96FFFF6AF5F590C0C033
                        BDBD92A2A2433333B2AFAFE6DCDCFFFFFFDFE0DF3D3D33252518D9D100232D22
                        50D0DCA1FFFF68FFFFADF0F05861611144443240400828282731313B5050C3C5
                        C4FAF8F6DBDBE3CFCFDCDCD9003531259ADAE66EFCFC92D5D553D0D093C8C82D
                        B9B981BABA2DC4C48ABFBF109A9B435348D8CDDB4849FF2525FFB5AC00161F15
                        36B9C4B2EFEF5B5959033030192626203535333B3B253A3A2F3737394E4FC8CA
                        C3E1DFF93F40FF2525FF2A2922211E1F1441413BBEBE9BC5C5189797263030C4
                        B1B1D7D3D3DAD0D0D2CECEE3D9D9FFFFFFFBFBFCD9D9E3CFCFDCD3D3DDDFDCDD
                        C4C1C03346462932323B5151CCCFCFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                        FFDEDEDD3E3E33252518FFFFFFFFFFFFFFFFFFE3D9D9D0CDCDE3D9D9FFFFFFFF
                        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFE5E5E5404041252525FFFFFFFFFFFF
                        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFAFA
                        FAE3E3E3D4D4D4D1D1D1FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                        FFFFFFFFFFFFFFFFFFFFFFFFFFFFDDDDDD353535242424282828FFFFFFFFFFFF
                        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFDDDD
                        DD3434341919191A1A1AFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFBFBFBE3E3E3DCDCDCDDDDDD}
                    end
                    object UlMgz2EndPosGoBtn: TRzBitBtn
                      Left = 252
                      Top = 48
                      Width = 61
                      Height = 24
                      FrameColor = 7617536
                      Caption = 'GO'
                      Color = 15791348
                      HotTrack = True
                      TabOrder = 6
                      OnClick = GoBtnClick
                      Glyph.Data = {
                        36030000424D3603000000000000360000002800000010000000100000000100
                        18000000000000030000C30E0000C30E00000000000000000000FFFFFFFFFFFF
                        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFE3E3E3E3E3E3FFFFFFFFFFFFFFFFFFFF
                        FFFFFFFFFFFFFFFFFFFFFFFFFFFFE3E3E3E3E3E3FFFFFFFFFFFFFFFFFFCDCDCD
                        333333333333CDCDCDFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFCDCDCD3333
                        33333333CDCDCDFFFFFFC5C5C52B2B2B00000000000029292ABBBBBBD3D3D3D1
                        D1D1D4D4D4D4D4D4BBBBBB2A2A2A0000000000002A2A2AC5C5C51B1B1B171717
                        1717171717152323192A2A282E2E2F2C2C2C2828282D2D2D2929291919191414
                        141717171B1B1B1D1D1D1A1A1AC4C4C5C0C0BFBBBBB5D2D2D8DADAD4D1D1D1C9
                        C9C9ADADADD1D1D1DBDBDBDFDFDFC1C1C1CACACAC6C6C6101010252525E7E7E6
                        FFFFFFC0C0FF4848FFC2C2FFFFFFFFFFFFFFDCDCDCDBDBDBDBDBDBDBDBDBE0E0
                        E0DFDFDF818181242424222222E2E2DCEDEDFF3E3EFF0000FF3B3BFFE7E7FFFC
                        FCFAA9A9A93333332323232929292F2F2F181818323232C7C7C7212121E6E6E5
                        FFFFFFC2C2FF4B4BFFC2C2FFFFFFFFE2E2E1363636929293B7B7B8AEAEAF7272
                        732A2A2AC2C2C2FFFFFF242424B9B9B9D3D3D3D7D7D1CDCDD1D6D6D1D6D6D3B7
                        B7AD1616129A9A8FCDCDC0A5A59A4C4C49CFCFC8FFFFFFFFFFFF747474373737
                        2B2B2C2F2F2D37372D30302D28282E15152915152011112419192329293DBEBE
                        C5E3E3FFF7F7FFFFFFFFF1F1F1D6D6D6D0D0D0D1D1D1D0D0D1D4D4D1AFAFD144
                        44D3BDBDDC3737D60000D23C3CDCDFDFFF6161FFD8D8FFFFFFFFFFFFFFFFFFFF
                        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFE5E5FFE4E4FFC3C3FF4A4AFFC2C2FFDCDC
                        FFD7D7FFF6F6FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFE0
                        E0FF5858FFD6D6FFDDDDFFD6D6FF5858FFE1E1FFFFFFFFFFFFFFFFFFFFFFFFFF
                        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF6F6FFDBDBFFD2D2FF5F5FFFD2D2FFDBDB
                        FFF6F6FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                        FFFFFFFFFFF8F8FFD8D8FFF8F8FFFFFFFFFFFFFFFFFFFFFFFFFF}
                    end
                  end
                  object PkgUM3SetGrpBox: TGroupBox
                    Left = 7
                    Top = 236
                    Width = 330
                    Height = 81
                    Caption = 'Magazine #3       : '
                    TabOrder = 3
                    object Label218: TLabel
                      Left = 12
                      Top = 24
                      Width = 85
                      Height = 13
                      AutoSize = False
                      Caption = '1'#39'st Slot Pos'
                    end
                    object Label219: TLabel
                      Left = 12
                      Top = 54
                      Width = 85
                      Height = 13
                      AutoSize = False
                      Caption = 'End Slot Pos'
                    end
                    object UlMgz3StartPosEdit: TEdit
                      Left = 112
                      Top = 18
                      Width = 64
                      Height = 24
                      Color = 16777088
                      Font.Charset = ANSI_CHARSET
                      Font.Color = clWindowText
                      Font.Height = -13
                      Font.Name = 'Tahoma'
                      Font.Style = []
                      ImeName = '???(??)'
                      MaxLength = 7
                      ParentFont = False
                      TabOrder = 1
                      Text = '0.000'
                    end
                    object UlMgz3EndPosEdit: TEdit
                      Left = 112
                      Top = 48
                      Width = 64
                      Height = 24
                      Color = 16777088
                      Font.Charset = ANSI_CHARSET
                      Font.Color = clWindowText
                      Font.Height = -13
                      Font.Name = 'Tahoma'
                      Font.Style = []
                      ImeName = '???(??)'
                      MaxLength = 7
                      ParentFont = False
                      TabOrder = 4
                      Text = '0.000'
                    end
                    object UlMgz3UseChkBox: TCheckBox
                      Left = 75
                      Top = -1
                      Width = 17
                      Height = 17
                      TabOrder = 0
                    end
                    object UlMgz3StartPosGetBtn: TRzBitBtn
                      Left = 188
                      Top = 18
                      Width = 61
                      Height = 24
                      FrameColor = 7617536
                      Caption = 'GET'
                      Color = 15791348
                      HotTrack = True
                      TabOrder = 2
                      OnClick = GetPosBtnClick
                      Glyph.Data = {
                        36030000424D3603000000000000360000002800000010000000100000000100
                        18000000000000030000C30E0000C30E00000000000000000000FFFFFFFFFFFF
                        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFBFB
                        FBE3E3E3DCDCDCDDDDDDD1D1DBE5E5E6FFFFFFE4DBDBD2CFCFDAD1D1D2CFCFE3
                        D9D9FFFFFFFFFFFFFFFFFFFFFFFFDDDDDD3434341919191A1A1A25251F424040
                        BCBABA3C4E4E2A29291D2F2F2C34343B5151CACDCDFDFAFAFFFFFFFFFFFFDDDD
                        DD353535242424282828B7B5001B15000E393F3CC1C195D2D24BD0D092C1C117
                        9595293535E6DDDDFFFFFFFFFFFFFAFAFAE3E3E3D4D4D4D1D1D1E4DB00242C1C
                        36B4C0A7FFFF6CFFFFADF0F05A64640A3939363B3BCBC8C8FFFFFFFFFFFFFFFF
                        FFE5E5E5404041252525D3D000332E259BD9E56CFFFF96FFFF6AF5F590C0C033
                        BDBD92A2A2433333B2AFAFE6DCDCFFFFFFDFE0DF3D3D33252518D9D100232D22
                        50D0DCA1FFFF68FFFFADF0F05861611144443240400828282731313B5050C3C5
                        C4FAF8F6DBDBE3CFCFDCDCD9003531259ADAE66EFCFC92D5D553D0D093C8C82D
                        B9B981BABA2DC4C48ABFBF109A9B435348D8CDDB4849FF2525FFB5AC00161F15
                        36B9C4B2EFEF5B5959033030192626203535333B3B253A3A2F3737394E4FC8CA
                        C3E1DFF93F40FF2525FF2A2922211E1F1441413BBEBE9BC5C5189797263030C4
                        B1B1D7D3D3DAD0D0D2CECEE3D9D9FFFFFFFBFBFCD9D9E3CFCFDCD3D3DDDFDCDD
                        C4C1C03346462932323B5151CCCFCFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                        FFDEDEDD3E3E33252518FFFFFFFFFFFFFFFFFFE3D9D9D0CDCDE3D9D9FFFFFFFF
                        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFE5E5E5404041252525FFFFFFFFFFFF
                        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFAFA
                        FAE3E3E3D4D4D4D1D1D1FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                        FFFFFFFFFFFFFFFFFFFFFFFFFFFFDDDDDD353535242424282828FFFFFFFFFFFF
                        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFDDDD
                        DD3434341919191A1A1AFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFBFBFBE3E3E3DCDCDCDDDDDD}
                    end
                    object UlMgz3StartPosGoBtn: TRzBitBtn
                      Left = 252
                      Top = 18
                      Width = 61
                      Height = 24
                      FrameColor = 7617536
                      Caption = 'GO'
                      Color = 15791348
                      HotTrack = True
                      TabOrder = 3
                      OnClick = GoBtnClick
                      Glyph.Data = {
                        36030000424D3603000000000000360000002800000010000000100000000100
                        18000000000000030000C30E0000C30E00000000000000000000FFFFFFFFFFFF
                        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFE3E3E3E3E3E3FFFFFFFFFFFFFFFFFFFF
                        FFFFFFFFFFFFFFFFFFFFFFFFFFFFE3E3E3E3E3E3FFFFFFFFFFFFFFFFFFCDCDCD
                        333333333333CDCDCDFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFCDCDCD3333
                        33333333CDCDCDFFFFFFC5C5C52B2B2B00000000000029292ABBBBBBD3D3D3D1
                        D1D1D4D4D4D4D4D4BBBBBB2A2A2A0000000000002A2A2AC5C5C51B1B1B171717
                        1717171717152323192A2A282E2E2F2C2C2C2828282D2D2D2929291919191414
                        141717171B1B1B1D1D1D1A1A1AC4C4C5C0C0BFBBBBB5D2D2D8DADAD4D1D1D1C9
                        C9C9ADADADD1D1D1DBDBDBDFDFDFC1C1C1CACACAC6C6C6101010252525E7E7E6
                        FFFFFFC0C0FF4848FFC2C2FFFFFFFFFFFFFFDCDCDCDBDBDBDBDBDBDBDBDBE0E0
                        E0DFDFDF818181242424222222E2E2DCEDEDFF3E3EFF0000FF3B3BFFE7E7FFFC
                        FCFAA9A9A93333332323232929292F2F2F181818323232C7C7C7212121E6E6E5
                        FFFFFFC2C2FF4B4BFFC2C2FFFFFFFFE2E2E1363636929293B7B7B8AEAEAF7272
                        732A2A2AC2C2C2FFFFFF242424B9B9B9D3D3D3D7D7D1CDCDD1D6D6D1D6D6D3B7
                        B7AD1616129A9A8FCDCDC0A5A59A4C4C49CFCFC8FFFFFFFFFFFF747474373737
                        2B2B2C2F2F2D37372D30302D28282E15152915152011112419192329293DBEBE
                        C5E3E3FFF7F7FFFFFFFFF1F1F1D6D6D6D0D0D0D1D1D1D0D0D1D4D4D1AFAFD144
                        44D3BDBDDC3737D60000D23C3CDCDFDFFF6161FFD8D8FFFFFFFFFFFFFFFFFFFF
                        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFE5E5FFE4E4FFC3C3FF4A4AFFC2C2FFDCDC
                        FFD7D7FFF6F6FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFE0
                        E0FF5858FFD6D6FFDDDDFFD6D6FF5858FFE1E1FFFFFFFFFFFFFFFFFFFFFFFFFF
                        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF6F6FFDBDBFFD2D2FF5F5FFFD2D2FFDBDB
                        FFF6F6FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                        FFFFFFFFFFF8F8FFD8D8FFF8F8FFFFFFFFFFFFFFFFFFFFFFFFFF}
                    end
                    object UlMgz3EndPosGetBtn: TRzBitBtn
                      Left = 188
                      Top = 48
                      Width = 61
                      Height = 24
                      FrameColor = 7617536
                      Caption = 'GET'
                      Color = 15791348
                      HotTrack = True
                      TabOrder = 5
                      OnClick = GetPosBtnClick
                      Glyph.Data = {
                        36030000424D3603000000000000360000002800000010000000100000000100
                        18000000000000030000C30E0000C30E00000000000000000000FFFFFFFFFFFF
                        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFBFB
                        FBE3E3E3DCDCDCDDDDDDD1D1DBE5E5E6FFFFFFE4DBDBD2CFCFDAD1D1D2CFCFE3
                        D9D9FFFFFFFFFFFFFFFFFFFFFFFFDDDDDD3434341919191A1A1A25251F424040
                        BCBABA3C4E4E2A29291D2F2F2C34343B5151CACDCDFDFAFAFFFFFFFFFFFFDDDD
                        DD353535242424282828B7B5001B15000E393F3CC1C195D2D24BD0D092C1C117
                        9595293535E6DDDDFFFFFFFFFFFFFAFAFAE3E3E3D4D4D4D1D1D1E4DB00242C1C
                        36B4C0A7FFFF6CFFFFADF0F05A64640A3939363B3BCBC8C8FFFFFFFFFFFFFFFF
                        FFE5E5E5404041252525D3D000332E259BD9E56CFFFF96FFFF6AF5F590C0C033
                        BDBD92A2A2433333B2AFAFE6DCDCFFFFFFDFE0DF3D3D33252518D9D100232D22
                        50D0DCA1FFFF68FFFFADF0F05861611144443240400828282731313B5050C3C5
                        C4FAF8F6DBDBE3CFCFDCDCD9003531259ADAE66EFCFC92D5D553D0D093C8C82D
                        B9B981BABA2DC4C48ABFBF109A9B435348D8CDDB4849FF2525FFB5AC00161F15
                        36B9C4B2EFEF5B5959033030192626203535333B3B253A3A2F3737394E4FC8CA
                        C3E1DFF93F40FF2525FF2A2922211E1F1441413BBEBE9BC5C5189797263030C4
                        B1B1D7D3D3DAD0D0D2CECEE3D9D9FFFFFFFBFBFCD9D9E3CFCFDCD3D3DDDFDCDD
                        C4C1C03346462932323B5151CCCFCFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                        FFDEDEDD3E3E33252518FFFFFFFFFFFFFFFFFFE3D9D9D0CDCDE3D9D9FFFFFFFF
                        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFE5E5E5404041252525FFFFFFFFFFFF
                        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFAFA
                        FAE3E3E3D4D4D4D1D1D1FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                        FFFFFFFFFFFFFFFFFFFFFFFFFFFFDDDDDD353535242424282828FFFFFFFFFFFF
                        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFDDDD
                        DD3434341919191A1A1AFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFBFBFBE3E3E3DCDCDCDDDDDD}
                    end
                    object UlMgz3EndPosGoBtn: TRzBitBtn
                      Left = 252
                      Top = 48
                      Width = 61
                      Height = 24
                      FrameColor = 7617536
                      Caption = 'GO'
                      Color = 15791348
                      HotTrack = True
                      TabOrder = 6
                      OnClick = GoBtnClick
                      Glyph.Data = {
                        36030000424D3603000000000000360000002800000010000000100000000100
                        18000000000000030000C30E0000C30E00000000000000000000FFFFFFFFFFFF
                        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFE3E3E3E3E3E3FFFFFFFFFFFFFFFFFFFF
                        FFFFFFFFFFFFFFFFFFFFFFFFFFFFE3E3E3E3E3E3FFFFFFFFFFFFFFFFFFCDCDCD
                        333333333333CDCDCDFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFCDCDCD3333
                        33333333CDCDCDFFFFFFC5C5C52B2B2B00000000000029292ABBBBBBD3D3D3D1
                        D1D1D4D4D4D4D4D4BBBBBB2A2A2A0000000000002A2A2AC5C5C51B1B1B171717
                        1717171717152323192A2A282E2E2F2C2C2C2828282D2D2D2929291919191414
                        141717171B1B1B1D1D1D1A1A1AC4C4C5C0C0BFBBBBB5D2D2D8DADAD4D1D1D1C9
                        C9C9ADADADD1D1D1DBDBDBDFDFDFC1C1C1CACACAC6C6C6101010252525E7E7E6
                        FFFFFFC0C0FF4848FFC2C2FFFFFFFFFFFFFFDCDCDCDBDBDBDBDBDBDBDBDBE0E0
                        E0DFDFDF818181242424222222E2E2DCEDEDFF3E3EFF0000FF3B3BFFE7E7FFFC
                        FCFAA9A9A93333332323232929292F2F2F181818323232C7C7C7212121E6E6E5
                        FFFFFFC2C2FF4B4BFFC2C2FFFFFFFFE2E2E1363636929293B7B7B8AEAEAF7272
                        732A2A2AC2C2C2FFFFFF242424B9B9B9D3D3D3D7D7D1CDCDD1D6D6D1D6D6D3B7
                        B7AD1616129A9A8FCDCDC0A5A59A4C4C49CFCFC8FFFFFFFFFFFF747474373737
                        2B2B2C2F2F2D37372D30302D28282E15152915152011112419192329293DBEBE
                        C5E3E3FFF7F7FFFFFFFFF1F1F1D6D6D6D0D0D0D1D1D1D0D0D1D4D4D1AFAFD144
                        44D3BDBDDC3737D60000D23C3CDCDFDFFF6161FFD8D8FFFFFFFFFFFFFFFFFFFF
                        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFE5E5FFE4E4FFC3C3FF4A4AFFC2C2FFDCDC
                        FFD7D7FFF6F6FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFE0
                        E0FF5858FFD6D6FFDDDDFFD6D6FF5858FFE1E1FFFFFFFFFFFFFFFFFFFFFFFFFF
                        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF6F6FFDBDBFFD2D2FF5F5FFFD2D2FFDBDB
                        FFF6F6FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                        FFFFFFFFFFF8F8FFD8D8FFF8F8FFFFFFFFFFFFFFFFFFFFFFFFFF}
                    end
                  end
                  object GroupBox2: TGroupBox
                    Left = 8
                    Top = 324
                    Width = 327
                    Height = 49
                    Caption = 'Use Reject Magazine: '
                    Font.Charset = ANSI_CHARSET
                    Font.Color = clWindowText
                    Font.Height = -11
                    Font.Name = 'Tahoma'
                    Font.Style = []
                    ParentFont = False
                    TabOrder = 4
                    object Label4: TLabel
                      Left = 168
                      Top = 22
                      Width = 51
                      Height = 13
                      Caption = ' Magazine '
                    end
                    object CheckBox1: TCheckBox
                      Left = 12
                      Top = 460
                      Width = 169
                      Height = 17
                      Caption = '?? ??? ?? ??'
                      Checked = True
                      State = cbChecked
                      TabOrder = 2
                      Visible = False
                    end
                    object UseRejMgzChkBox: TCheckBox
                      Left = 16
                      Top = 20
                      Width = 69
                      Height = 17
                      Caption = 'Enable'
                      Color = 16119543
                      ParentColor = False
                      TabOrder = 1
                    end
                    object RejMgzSelSpinEdit: TLMDSpinEdit
                      Left = 242
                      Top = 14
                      Width = 65
                      Height = 25
                      Bevel.Mode = bmWindows
                      Caret.BlinkRate = 530
                      ImeName = '???(??) (MS-IME98)'
                      TabOrder = 0
                      OnChange = UnitDataChange
                      Font.Charset = ANSI_CHARSET
                      Font.Color = clWindowText
                      Font.Height = -13
                      Font.Name = 'Tahoma'
                      Font.Style = []
                      AutoSelect = True
                      ParentFont = False
                      CustomButtons = <>
                      CustomButtonParentCtlXP = False
                      MinValue = 1
                      MaxValue = 3
                      Value = 1
                      Value = 1
                    end
                  end
                  object HTypeUlMgzPosPanel: TPanel
                    Left = -6
                    Top = 23
                    Width = 357
                    Height = 368
                    BevelOuter = bvNone
                    TabOrder = 0
                    object HTypeUlSetPanel: TPanel
                      Left = 0
                      Top = 32
                      Width = 357
                      Height = 314
                      BevelOuter = bvNone
                      Color = 16119543
                      TabOrder = 0
                      object GroupBox30: TGroupBox
                        Left = 10
                        Top = 18
                        Width = 325
                        Height = 85
                        Caption = '1'#39'st Slot Position: '
                        TabOrder = 0
                        object Label128: TLabel
                          Left = 14
                          Top = 28
                          Width = 29
                          Height = 13
                          Caption = 'Y Axis'
                        end
                        object Label153: TLabel
                          Left = 14
                          Top = 56
                          Width = 29
                          Height = 13
                          Caption = 'Z Axis'
                        end
                        object UlMgzStartYPosEdit: TEdit
                          Left = 76
                          Top = 22
                          Width = 64
                          Height = 24
                          Color = 16777088
                          Font.Charset = ANSI_CHARSET
                          Font.Color = clBlack
                          Font.Height = -13
                          Font.Name = 'Tahoma'
                          Font.Style = []
                          ImeName = '???(??)'
                          MaxLength = 7
                          ParentFont = False
                          TabOrder = 0
                          Text = '0.000'
                          OnChange = DataChange
                        end
                        object UlMgzStartZPosEdit: TEdit
                          Left = 76
                          Top = 52
                          Width = 64
                          Height = 24
                          Color = 16777088
                          Font.Charset = ANSI_CHARSET
                          Font.Color = clBlack
                          Font.Height = -13
                          Font.Name = 'Tahoma'
                          Font.Style = []
                          ImeName = '???(??)'
                          MaxLength = 7
                          ParentFont = False
                          TabOrder = 3
                          Text = '0.000'
                          OnChange = DataChange
                        end
                        object UlMgzStartPosGetBtn: TRzBitBtn
                          Left = 180
                          Top = 28
                          Width = 61
                          Height = 44
                          FrameColor = 7617536
                          Caption = 'GET'
                          Color = 15791348
                          HotTrack = True
                          TabOrder = 1
                          OnClick = GetPosBtnClick
                          Glyph.Data = {
                            36030000424D3603000000000000360000002800000010000000100000000100
                            18000000000000030000C30E0000C30E00000000000000000000FFFFFFFFFFFF
                            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFBFB
                            FBE3E3E3DCDCDCDDDDDDD1D1DBE5E5E6FFFFFFE4DBDBD2CFCFDAD1D1D2CFCFE3
                            D9D9FFFFFFFFFFFFFFFFFFFFFFFFDDDDDD3434341919191A1A1A25251F424040
                            BCBABA3C4E4E2A29291D2F2F2C34343B5151CACDCDFDFAFAFFFFFFFFFFFFDDDD
                            DD353535242424282828B7B5001B15000E393F3CC1C195D2D24BD0D092C1C117
                            9595293535E6DDDDFFFFFFFFFFFFFAFAFAE3E3E3D4D4D4D1D1D1E4DB00242C1C
                            36B4C0A7FFFF6CFFFFADF0F05A64640A3939363B3BCBC8C8FFFFFFFFFFFFFFFF
                            FFE5E5E5404041252525D3D000332E259BD9E56CFFFF96FFFF6AF5F590C0C033
                            BDBD92A2A2433333B2AFAFE6DCDCFFFFFFDFE0DF3D3D33252518D9D100232D22
                            50D0DCA1FFFF68FFFFADF0F05861611144443240400828282731313B5050C3C5
                            C4FAF8F6DBDBE3CFCFDCDCD9003531259ADAE66EFCFC92D5D553D0D093C8C82D
                            B9B981BABA2DC4C48ABFBF109A9B435348D8CDDB4849FF2525FFB5AC00161F15
                            36B9C4B2EFEF5B5959033030192626203535333B3B253A3A2F3737394E4FC8CA
                            C3E1DFF93F40FF2525FF2A2922211E1F1441413BBEBE9BC5C5189797263030C4
                            B1B1D7D3D3DAD0D0D2CECEE3D9D9FFFFFFFBFBFCD9D9E3CFCFDCD3D3DDDFDCDD
                            C4C1C03346462932323B5151CCCFCFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                            FFDEDEDD3E3E33252518FFFFFFFFFFFFFFFFFFE3D9D9D0CDCDE3D9D9FFFFFFFF
                            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFE5E5E5404041252525FFFFFFFFFFFF
                            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFAFA
                            FAE3E3E3D4D4D4D1D1D1FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                            FFFFFFFFFFFFFFFFFFFFFFFFFFFFDDDDDD353535242424282828FFFFFFFFFFFF
                            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFDDDD
                            DD3434341919191A1A1AFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFBFBFBE3E3E3DCDCDCDDDDDD}
                        end
                        object UlMgzStartPosGoBtn: TRzBitBtn
                          Left = 248
                          Top = 28
                          Width = 61
                          Height = 44
                          FrameColor = 7617536
                          Caption = 'GO'
                          Color = 15791348
                          HotTrack = True
                          TabOrder = 2
                          OnClick = GoBtnClick
                          Glyph.Data = {
                            36030000424D3603000000000000360000002800000010000000100000000100
                            18000000000000030000C30E0000C30E00000000000000000000FFFFFFFFFFFF
                            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFE3E3E3E3E3E3FFFFFFFFFFFFFFFFFFFF
                            FFFFFFFFFFFFFFFFFFFFFFFFFFFFE3E3E3E3E3E3FFFFFFFFFFFFFFFFFFCDCDCD
                            333333333333CDCDCDFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFCDCDCD3333
                            33333333CDCDCDFFFFFFC5C5C52B2B2B00000000000029292ABBBBBBD3D3D3D1
                            D1D1D4D4D4D4D4D4BBBBBB2A2A2A0000000000002A2A2AC5C5C51B1B1B171717
                            1717171717152323192A2A282E2E2F2C2C2C2828282D2D2D2929291919191414
                            141717171B1B1B1D1D1D1A1A1AC4C4C5C0C0BFBBBBB5D2D2D8DADAD4D1D1D1C9
                            C9C9ADADADD1D1D1DBDBDBDFDFDFC1C1C1CACACAC6C6C6101010252525E7E7E6
                            FFFFFFC0C0FF4848FFC2C2FFFFFFFFFFFFFFDCDCDCDBDBDBDBDBDBDBDBDBE0E0
                            E0DFDFDF818181242424222222E2E2DCEDEDFF3E3EFF0000FF3B3BFFE7E7FFFC
                            FCFAA9A9A93333332323232929292F2F2F181818323232C7C7C7212121E6E6E5
                            FFFFFFC2C2FF4B4BFFC2C2FFFFFFFFE2E2E1363636929293B7B7B8AEAEAF7272
                            732A2A2AC2C2C2FFFFFF242424B9B9B9D3D3D3D7D7D1CDCDD1D6D6D1D6D6D3B7
                            B7AD1616129A9A8FCDCDC0A5A59A4C4C49CFCFC8FFFFFFFFFFFF747474373737
                            2B2B2C2F2F2D37372D30302D28282E15152915152011112419192329293DBEBE
                            C5E3E3FFF7F7FFFFFFFFF1F1F1D6D6D6D0D0D0D1D1D1D0D0D1D4D4D1AFAFD144
                            44D3BDBDDC3737D60000D23C3CDCDFDFFF6161FFD8D8FFFFFFFFFFFFFFFFFFFF
                            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFE5E5FFE4E4FFC3C3FF4A4AFFC2C2FFDCDC
                            FFD7D7FFF6F6FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFE0
                            E0FF5858FFD6D6FFDDDDFFD6D6FF5858FFE1E1FFFFFFFFFFFFFFFFFFFFFFFFFF
                            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF6F6FFDBDBFFD2D2FF5F5FFFD2D2FFDBDB
                            FFF6F6FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                            FFFFFFFFFFF8F8FFD8D8FFF8F8FFFFFFFFFFFFFFFFFFFFFFFFFF}
                        end
                      end
                      object GroupBox36: TGroupBox
                        Left = 8
                        Top = 188
                        Width = 325
                        Height = 57
                        Caption = 'Last Slot Position: '
                        TabOrder = 1
                        object Label160: TLabel
                          Left = 14
                          Top = 28
                          Width = 29
                          Height = 13
                          Caption = 'Z Axis'
                        end
                        object CheckBox2: TCheckBox
                          Left = 16
                          Top = 196
                          Width = 169
                          Height = 17
                          Caption = '?? ??? ?? ??'
                          Checked = True
                          State = cbChecked
                          TabOrder = 3
                          Visible = False
                        end
                        object UlMgzEndZPosEdit: TEdit
                          Left = 76
                          Top = 21
                          Width = 64
                          Height = 24
                          Color = 16777088
                          Font.Charset = ANSI_CHARSET
                          Font.Color = clBlack
                          Font.Height = -13
                          Font.Name = 'Tahoma'
                          Font.Style = []
                          ImeName = '???(??)'
                          MaxLength = 7
                          ParentFont = False
                          TabOrder = 2
                          Text = '0.000'
                          OnChange = DataChange
                        end
                        object UlMgzEndZPosGetBtn: TRzBitBtn
                          Left = 188
                          Top = 17
                          Width = 61
                          Height = 24
                          FrameColor = 7617536
                          Caption = 'GET'
                          Color = 15791348
                          HotTrack = True
                          TabOrder = 0
                          OnClick = GetPosBtnClick
                          Glyph.Data = {
                            36030000424D3603000000000000360000002800000010000000100000000100
                            18000000000000030000C30E0000C30E00000000000000000000FFFFFFFFFFFF
                            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFBFB
                            FBE3E3E3DCDCDCDDDDDDD1D1DBE5E5E6FFFFFFE4DBDBD2CFCFDAD1D1D2CFCFE3
                            D9D9FFFFFFFFFFFFFFFFFFFFFFFFDDDDDD3434341919191A1A1A25251F424040
                            BCBABA3C4E4E2A29291D2F2F2C34343B5151CACDCDFDFAFAFFFFFFFFFFFFDDDD
                            DD353535242424282828B7B5001B15000E393F3CC1C195D2D24BD0D092C1C117
                            9595293535E6DDDDFFFFFFFFFFFFFAFAFAE3E3E3D4D4D4D1D1D1E4DB00242C1C
                            36B4C0A7FFFF6CFFFFADF0F05A64640A3939363B3BCBC8C8FFFFFFFFFFFFFFFF
                            FFE5E5E5404041252525D3D000332E259BD9E56CFFFF96FFFF6AF5F590C0C033
                            BDBD92A2A2433333B2AFAFE6DCDCFFFFFFDFE0DF3D3D33252518D9D100232D22
                            50D0DCA1FFFF68FFFFADF0F05861611144443240400828282731313B5050C3C5
                            C4FAF8F6DBDBE3CFCFDCDCD9003531259ADAE66EFCFC92D5D553D0D093C8C82D
                            B9B981BABA2DC4C48ABFBF109A9B435348D8CDDB4849FF2525FFB5AC00161F15
                            36B9C4B2EFEF5B5959033030192626203535333B3B253A3A2F3737394E4FC8CA
                            C3E1DFF93F40FF2525FF2A2922211E1F1441413BBEBE9BC5C5189797263030C4
                            B1B1D7D3D3DAD0D0D2CECEE3D9D9FFFFFFFBFBFCD9D9E3CFCFDCD3D3DDDFDCDD
                            C4C1C03346462932323B5151CCCFCFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                            FFDEDEDD3E3E33252518FFFFFFFFFFFFFFFFFFE3D9D9D0CDCDE3D9D9FFFFFFFF
                            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFE5E5E5404041252525FFFFFFFFFFFF
                            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFAFA
                            FAE3E3E3D4D4D4D1D1D1FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                            FFFFFFFFFFFFFFFFFFFFFFFFFFFFDDDDDD353535242424282828FFFFFFFFFFFF
                            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFDDDD
                            DD3434341919191A1A1AFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFBFBFBE3E3E3DCDCDCDDDDDD}
                        end
                        object UlMgzEndZPosGoBtn: TRzBitBtn
                          Left = 252
                          Top = 17
                          Width = 61
                          Height = 24
                          FrameColor = 7617536
                          Caption = 'GO'
                          Color = 15791348
                          HotTrack = True
                          TabOrder = 1
                          OnClick = GoBtnClick
                          Glyph.Data = {
                            36030000424D3603000000000000360000002800000010000000100000000100
                            18000000000000030000C30E0000C30E00000000000000000000FFFFFFFFFFFF
                            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFE3E3E3E3E3E3FFFFFFFFFFFFFFFFFFFF
                            FFFFFFFFFFFFFFFFFFFFFFFFFFFFE3E3E3E3E3E3FFFFFFFFFFFFFFFFFFCDCDCD
                            333333333333CDCDCDFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFCDCDCD3333
                            33333333CDCDCDFFFFFFC5C5C52B2B2B00000000000029292ABBBBBBD3D3D3D1
                            D1D1D4D4D4D4D4D4BBBBBB2A2A2A0000000000002A2A2AC5C5C51B1B1B171717
                            1717171717152323192A2A282E2E2F2C2C2C2828282D2D2D2929291919191414
                            141717171B1B1B1D1D1D1A1A1AC4C4C5C0C0BFBBBBB5D2D2D8DADAD4D1D1D1C9
                            C9C9ADADADD1D1D1DBDBDBDFDFDFC1C1C1CACACAC6C6C6101010252525E7E7E6
                            FFFFFFC0C0FF4848FFC2C2FFFFFFFFFFFFFFDCDCDCDBDBDBDBDBDBDBDBDBE0E0
                            E0DFDFDF818181242424222222E2E2DCEDEDFF3E3EFF0000FF3B3BFFE7E7FFFC
                            FCFAA9A9A93333332323232929292F2F2F181818323232C7C7C7212121E6E6E5
                            FFFFFFC2C2FF4B4BFFC2C2FFFFFFFFE2E2E1363636929293B7B7B8AEAEAF7272
                            732A2A2AC2C2C2FFFFFF242424B9B9B9D3D3D3D7D7D1CDCDD1D6D6D1D6D6D3B7
                            B7AD1616129A9A8FCDCDC0A5A59A4C4C49CFCFC8FFFFFFFFFFFF747474373737
                            2B2B2C2F2F2D37372D30302D28282E15152915152011112419192329293DBEBE
                            C5E3E3FFF7F7FFFFFFFFF1F1F1D6D6D6D0D0D0D1D1D1D0D0D1D4D4D1AFAFD144
                            44D3BDBDDC3737D60000D23C3CDCDFDFFF6161FFD8D8FFFFFFFFFFFFFFFFFFFF
                            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFE5E5FFE4E4FFC3C3FF4A4AFFC2C2FFDCDC
                            FFD7D7FFF6F6FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFE0
                            E0FF5858FFD6D6FFDDDDFFD6D6FF5858FFE1E1FFFFFFFFFFFFFFFFFFFFFFFFFF
                            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF6F6FFDBDBFFD2D2FF5F5FFFD2D2FFDBDB
                            FFF6F6FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                            FFFFFFFFFFF8F8FFD8D8FFF8F8FFFFFFFFFFFFFFFFFFFFFFFFFF}
                        end
                      end
                    end
                  end
                end
                object GroupBox48: TGroupBox
                  Left = 376
                  Top = 6
                  Width = 350
                  Height = 67
                  Caption = 'Option: '
                  Font.Charset = ANSI_CHARSET
                  Font.Color = clWindowText
                  Font.Height = -11
                  Font.Name = 'Tahoma'
                  Font.Style = []
                  ParentFont = False
                  TabOrder = 1
                  object CheckBox4: TCheckBox
                    Left = 12
                    Top = 460
                    Width = 169
                    Height = 17
                    Caption = '?? ??? ?? ??'
                    Checked = True
                    State = cbChecked
                    TabOrder = 2
                    Visible = False
                  end
                  object UseUlPushJamChkBox: TCheckBox
                    Left = 16
                    Top = 20
                    Width = 159
                    Height = 17
                    Caption = 'Unloader Pusher Jam Check'
                    Checked = True
                    State = cbChecked
                    TabOrder = 0
                    OnClick = DataClick
                  end
                  object UlErrMcStopChkBox: TCheckBox
                    Left = 16
                    Top = 42
                    Width = 169
                    Height = 17
                    Caption = 'When Unloader Error M/C Stop'
                    Checked = True
                    State = cbChecked
                    TabOrder = 1
                    Visible = False
                  end
                end
                object GroupBox33: TGroupBox
                  Left = 6
                  Top = 6
                  Width = 355
                  Height = 81
                  Caption = 'Unloader Setup File: '
                  Font.Charset = ANSI_CHARSET
                  Font.Color = clWindowText
                  Font.Height = -11
                  Font.Name = 'Tahoma'
                  Font.Style = []
                  ParentFont = False
                  TabOrder = 0
                  object m_SaveSettings: TBitBtn
                    Left = 24
                    Top = 47
                    Width = 129
                    Height = 25
                    Caption = 'Save As...'
                    TabOrder = 1
                    OnClick = m_SaveSettingsClick
                    Glyph.Data = {
                      76010000424D7601000000000000760000002800000020000000100000000100
                      04000000000000010000120B0000120B00001000000000000000000000000000
                      800000800000008080008000000080008000808000007F7F7F00BFBFBF000000
                      FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00333333333333
                      333333FFFFFFFFFFFFF33000077777770033377777777777773F000007888888
                      00037F3337F3FF37F37F00000780088800037F3337F77F37F37F000007800888
                      00037F3337F77FF7F37F00000788888800037F3337777777337F000000000000
                      00037F3FFFFFFFFFFF7F00000000000000037F77777777777F7F000FFFFFFFFF
                      00037F7F333333337F7F000FFFFFFFFF00037F7F333333337F7F000FFFFFFFFF
                      00037F7F333333337F7F000FFFFFFFFF00037F7F333333337F7F000FFFFFFFFF
                      00037F7F333333337F7F000FFFFFFFFF07037F7F33333333777F000FFFFFFFFF
                      0003737FFFFFFFFF7F7330099999999900333777777777777733}
                    NumGlyphs = 2
                  end
                  object m_LoadSettings: TBitBtn
                    Left = 208
                    Top = 47
                    Width = 129
                    Height = 25
                    Caption = 'Load Settings'
                    TabOrder = 2
                    OnClick = m_LoadSettingsClick
                    Glyph.Data = {
                      76010000424D7601000000000000760000002800000020000000100000000100
                      04000000000000010000120B0000120B00001000000000000000000000000000
                      800000800000008080008000000080008000808000007F7F7F00BFBFBF000000
                      FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00555555555555
                      5555555555555555555555555555555555555555555555555555555555555555
                      555555555555555555555555555555555555555FFFFFFFFFF555550000000000
                      55555577777777775F55500B8B8B8B8B05555775F555555575F550F0B8B8B8B8
                      B05557F75F555555575F50BF0B8B8B8B8B0557F575FFFFFFFF7F50FBF0000000
                      000557F557777777777550BFBFBFBFB0555557F555555557F55550FBFBFBFBF0
                      555557F555555FF7555550BFBFBF00055555575F555577755555550BFBF05555
                      55555575FFF75555555555700007555555555557777555555555555555555555
                      5555555555555555555555555555555555555555555555555555}
                    NumGlyphs = 2
                  end
                  object LdFileNamePnl: TPanel
                    Left = 2
                    Top = 15
                    Width = 351
                    Height = 26
                    Align = alTop
                    BevelOuter = bvNone
                    BorderStyle = bsSingle
                    Color = clWhite
                    Font.Charset = ANSI_CHARSET
                    Font.Color = clWindowText
                    Font.Height = -13
                    Font.Name = 'Tahoma'
                    Font.Style = []
                    ParentFont = False
                    TabOrder = 0
                  end
                end
                object Panel6: TPanel
                  Left = 8
                  Top = 482
                  Width = 345
                  Height = 45
                  BevelInner = bvRaised
                  BevelOuter = bvLowered
                  Color = 16119543
                  TabOrder = 3
                  object Label21: TLabel
                    Left = 10
                    Top = 16
                    Width = 135
                    Height = 13
                    AutoSize = False
                    Caption = ' Magazine Slot Number'
                  end
                  object UlMgzSlotNumSpinEdit: TLMDSpinEdit
                    Left = 143
                    Top = 10
                    Width = 65
                    Height = 25
                    Bevel.Mode = bmWindows
                    Caret.BlinkRate = 530
                    ImeName = '???(??) (MS-IME98)'
                    TabOrder = 0
                    OnChange = UnitDataChange
                    Font.Charset = ANSI_CHARSET
                    Font.Color = clWindowText
                    Font.Height = -13
                    Font.Name = 'Tahoma'
                    Font.Style = []
                    AutoSelect = True
                    ParentFont = False
                    CustomButtons = <>
                    CustomButtonParentCtlXP = False
                    MinValue = 1
                    MaxValue = 20
                    Value = 1
                    Value = 1
                  end
                end
              end
              object RzTabSheet2: TRzTabSheet
                Color = 16119543
                Caption = ' Gripper Position '
                object Label24: TLabel
                  Left = 157
                  Top = 4
                  Width = 56
                  Height = 16
                  Caption = 'LOADING'
                  Font.Charset = ANSI_CHARSET
                  Font.Color = clWindowText
                  Font.Height = -13
                  Font.Name = 'Tahoma'
                  Font.Style = [fsBold]
                  ParentFont = False
                end
                object Label25: TLabel
                  Left = 508
                  Top = 4
                  Width = 72
                  Height = 16
                  Caption = 'UNLOADING'
                  Font.Charset = ANSI_CHARSET
                  Font.Color = clWindowText
                  Font.Height = -13
                  Font.Name = 'Tahoma'
                  Font.Style = [fsBold]
                  ParentFont = False
                end
                object RzLine1: TRzLine
                  Left = 176
                  Top = 16
                  Width = 14
                  Height = 33
                  ArrowLength = 15
                  LineWidth = 5
                  ShowArrows = saEnd
                end
                object RzLine2: TRzLine
                  Left = 536
                  Top = 16
                  Width = 14
                  Height = 33
                  ArrowLength = 15
                  LineWidth = 5
                  ShowArrows = saEnd
                end
                object GroupBox26: TGroupBox
                  Left = 14
                  Top = 42
                  Width = 350
                  Height = 80
                  Caption = 'Grip On Ready Position: posGripOnPre'
                  Color = 16119543
                  Font.Charset = ANSI_CHARSET
                  Font.Color = clWindowText
                  Font.Height = -11
                  Font.Name = 'Tahoma'
                  Font.Style = []
                  ParentColor = False
                  ParentFont = False
                  TabOrder = 0
                  object Label111: TLabel
                    Left = 26
                    Top = 25
                    Width = 29
                    Height = 13
                    Caption = 'Y Axis'
                  end
                  object Label112: TLabel
                    Left = 26
                    Top = 53
                    Width = 29
                    Height = 13
                    Caption = 'Z Axis'
                  end
                  object UlMgzGripOnPreYPosEdit: TEdit
                    Left = 88
                    Top = 19
                    Width = 64
                    Height = 24
                    Color = 16777088
                    Font.Charset = ANSI_CHARSET
                    Font.Color = clBlack
                    Font.Height = -13
                    Font.Name = 'Tahoma'
                    Font.Style = []
                    ImeName = '???(??)'
                    MaxLength = 7
                    ParentFont = False
                    TabOrder = 0
                    Text = '0.000'
                    OnChange = DataChange
                  end
                  object UlMgzGripOnPreZPosEdit: TEdit
                    Left = 88
                    Top = 47
                    Width = 64
                    Height = 24
                    Color = 16777088
                    Font.Charset = ANSI_CHARSET
                    Font.Color = clBlack
                    Font.Height = -13
                    Font.Name = 'Tahoma'
                    Font.Style = []
                    ImeName = '???(??)'
                    MaxLength = 7
                    ParentFont = False
                    TabOrder = 3
                    Text = '0.000'
                    OnChange = DataChange
                  end
                  object UlMgzGripOnPrePosGetBtn: TRzBitBtn
                    Left = 196
                    Top = 22
                    Width = 61
                    Height = 44
                    FrameColor = 7617536
                    Caption = 'GET'
                    Color = 15791348
                    HotTrack = True
                    TabOrder = 1
                    OnClick = GetPosBtnClick
                    Glyph.Data = {
                      36030000424D3603000000000000360000002800000010000000100000000100
                      18000000000000030000C30E0000C30E00000000000000000000FFFFFFFFFFFF
                      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFBFB
                      FBE3E3E3DCDCDCDDDDDDD1D1DBE5E5E6FFFFFFE4DBDBD2CFCFDAD1D1D2CFCFE3
                      D9D9FFFFFFFFFFFFFFFFFFFFFFFFDDDDDD3434341919191A1A1A25251F424040
                      BCBABA3C4E4E2A29291D2F2F2C34343B5151CACDCDFDFAFAFFFFFFFFFFFFDDDD
                      DD353535242424282828B7B5001B15000E393F3CC1C195D2D24BD0D092C1C117
                      9595293535E6DDDDFFFFFFFFFFFFFAFAFAE3E3E3D4D4D4D1D1D1E4DB00242C1C
                      36B4C0A7FFFF6CFFFFADF0F05A64640A3939363B3BCBC8C8FFFFFFFFFFFFFFFF
                      FFE5E5E5404041252525D3D000332E259BD9E56CFFFF96FFFF6AF5F590C0C033
                      BDBD92A2A2433333B2AFAFE6DCDCFFFFFFDFE0DF3D3D33252518D9D100232D22
                      50D0DCA1FFFF68FFFFADF0F05861611144443240400828282731313B5050C3C5
                      C4FAF8F6DBDBE3CFCFDCDCD9003531259ADAE66EFCFC92D5D553D0D093C8C82D
                      B9B981BABA2DC4C48ABFBF109A9B435348D8CDDB4849FF2525FFB5AC00161F15
                      36B9C4B2EFEF5B5959033030192626203535333B3B253A3A2F3737394E4FC8CA
                      C3E1DFF93F40FF2525FF2A2922211E1F1441413BBEBE9BC5C5189797263030C4
                      B1B1D7D3D3DAD0D0D2CECEE3D9D9FFFFFFFBFBFCD9D9E3CFCFDCD3D3DDDFDCDD
                      C4C1C03346462932323B5151CCCFCFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                      FFDEDEDD3E3E33252518FFFFFFFFFFFFFFFFFFE3D9D9D0CDCDE3D9D9FFFFFFFF
                      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFE5E5E5404041252525FFFFFFFFFFFF
                      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFAFA
                      FAE3E3E3D4D4D4D1D1D1FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                      FFFFFFFFFFFFFFFFFFFFFFFFFFFFDDDDDD353535242424282828FFFFFFFFFFFF
                      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFDDDD
                      DD3434341919191A1A1AFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFBFBFBE3E3E3DCDCDCDDDDDD}
                  end
                  object UlMgzGripOnPrePosGoBtn: TRzBitBtn
                    Left = 264
                    Top = 22
                    Width = 61
                    Height = 44
                    FrameColor = 7617536
                    Caption = 'GO'
                    Color = 15791348
                    HotTrack = True
                    TabOrder = 2
                    OnClick = GoBtnClick
                    Glyph.Data = {
                      36030000424D3603000000000000360000002800000010000000100000000100
                      18000000000000030000C30E0000C30E00000000000000000000FFFFFFFFFFFF
                      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFE3E3E3E3E3E3FFFFFFFFFFFFFFFFFFFF
                      FFFFFFFFFFFFFFFFFFFFFFFFFFFFE3E3E3E3E3E3FFFFFFFFFFFFFFFFFFCDCDCD
                      333333333333CDCDCDFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFCDCDCD3333
                      33333333CDCDCDFFFFFFC5C5C52B2B2B00000000000029292ABBBBBBD3D3D3D1
                      D1D1D4D4D4D4D4D4BBBBBB2A2A2A0000000000002A2A2AC5C5C51B1B1B171717
                      1717171717152323192A2A282E2E2F2C2C2C2828282D2D2D2929291919191414
                      141717171B1B1B1D1D1D1A1A1AC4C4C5C0C0BFBBBBB5D2D2D8DADAD4D1D1D1C9
                      C9C9ADADADD1D1D1DBDBDBDFDFDFC1C1C1CACACAC6C6C6101010252525E7E7E6
                      FFFFFFC0C0FF4848FFC2C2FFFFFFFFFFFFFFDCDCDCDBDBDBDBDBDBDBDBDBE0E0
                      E0DFDFDF818181242424222222E2E2DCEDEDFF3E3EFF0000FF3B3BFFE7E7FFFC
                      FCFAA9A9A93333332323232929292F2F2F181818323232C7C7C7212121E6E6E5
                      FFFFFFC2C2FF4B4BFFC2C2FFFFFFFFE2E2E1363636929293B7B7B8AEAEAF7272
                      732A2A2AC2C2C2FFFFFF242424B9B9B9D3D3D3D7D7D1CDCDD1D6D6D1D6D6D3B7
                      B7AD1616129A9A8FCDCDC0A5A59A4C4C49CFCFC8FFFFFFFFFFFF747474373737
                      2B2B2C2F2F2D37372D30302D28282E15152915152011112419192329293DBEBE
                      C5E3E3FFF7F7FFFFFFFFF1F1F1D6D6D6D0D0D0D1D1D1D0D0D1D4D4D1AFAFD144
                      44D3BDBDDC3737D60000D23C3CDCDFDFFF6161FFD8D8FFFFFFFFFFFFFFFFFFFF
                      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFE5E5FFE4E4FFC3C3FF4A4AFFC2C2FFDCDC
                      FFD7D7FFF6F6FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFE0
                      E0FF5858FFD6D6FFDDDDFFD6D6FF5858FFE1E1FFFFFFFFFFFFFFFFFFFFFFFFFF
                      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF6F6FFDBDBFFD2D2FF5F5FFFD2D2FFDBDB
                      FFF6F6FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                      FFFFFFFFFFF8F8FFD8D8FFF8F8FFFFFFFFFFFFFFFFFFFFFFFFFF}
                  end
                end
                object GroupBox57: TGroupBox
                  Left = 14
                  Top = 295
                  Width = 350
                  Height = 80
                  Caption = 'Fully Lift Position(More Then Stopper Height): posGripOnOut'
                  Color = 16119543
                  Font.Charset = ANSI_CHARSET
                  Font.Color = clWindowText
                  Font.Height = -11
                  Font.Name = 'Tahoma'
                  Font.Style = []
                  ParentColor = False
                  ParentFont = False
                  TabOrder = 6
                  object Label113: TLabel
                    Left = 26
                    Top = 49
                    Width = 29
                    Height = 13
                    Caption = 'Z Axis'
                  end
                  object Label134: TLabel
                    Left = 26
                    Top = 21
                    Width = 29
                    Height = 13
                    Caption = 'Y Axis'
                  end
                  object UlMgzGripOnOutZPosEdit: TEdit
                    Left = 88
                    Top = 47
                    Width = 64
                    Height = 24
                    Color = 16777088
                    Font.Charset = ANSI_CHARSET
                    Font.Color = clBlack
                    Font.Height = -13
                    Font.Name = 'Tahoma'
                    Font.Style = []
                    ImeName = '???(??)'
                    MaxLength = 7
                    ParentFont = False
                    TabOrder = 3
                    Text = '0.000'
                    OnChange = DataChange
                  end
                  object UlMgzGripOnOutYPosEdit: TEdit
                    Left = 88
                    Top = 19
                    Width = 64
                    Height = 24
                    Color = 16777088
                    Font.Charset = ANSI_CHARSET
                    Font.Color = clBlack
                    Font.Height = -13
                    Font.Name = 'Tahoma'
                    Font.Style = []
                    ImeName = '???(??)'
                    MaxLength = 7
                    ParentFont = False
                    TabOrder = 0
                    Text = '0.000'
                    OnChange = DataChange
                  end
                  object UlMgzGripOnOutPosGetBtn: TRzBitBtn
                    Left = 196
                    Top = 22
                    Width = 61
                    Height = 44
                    FrameColor = 7617536
                    Caption = 'GET'
                    Color = 15791348
                    HotTrack = True
                    TabOrder = 1
                    OnClick = GetPosBtnClick
                    Glyph.Data = {
                      36030000424D3603000000000000360000002800000010000000100000000100
                      18000000000000030000C30E0000C30E00000000000000000000FFFFFFFFFFFF
                      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFBFB
                      FBE3E3E3DCDCDCDDDDDDD1D1DBE5E5E6FFFFFFE4DBDBD2CFCFDAD1D1D2CFCFE3
                      D9D9FFFFFFFFFFFFFFFFFFFFFFFFDDDDDD3434341919191A1A1A25251F424040
                      BCBABA3C4E4E2A29291D2F2F2C34343B5151CACDCDFDFAFAFFFFFFFFFFFFDDDD
                      DD353535242424282828B7B5001B15000E393F3CC1C195D2D24BD0D092C1C117
                      9595293535E6DDDDFFFFFFFFFFFFFAFAFAE3E3E3D4D4D4D1D1D1E4DB00242C1C
                      36B4C0A7FFFF6CFFFFADF0F05A64640A3939363B3BCBC8C8FFFFFFFFFFFFFFFF
                      FFE5E5E5404041252525D3D000332E259BD9E56CFFFF96FFFF6AF5F590C0C033
                      BDBD92A2A2433333B2AFAFE6DCDCFFFFFFDFE0DF3D3D33252518D9D100232D22
                      50D0DCA1FFFF68FFFFADF0F05861611144443240400828282731313B5050C3C5
                      C4FAF8F6DBDBE3CFCFDCDCD9003531259ADAE66EFCFC92D5D553D0D093C8C82D
                      B9B981BABA2DC4C48ABFBF109A9B435348D8CDDB4849FF2525FFB5AC00161F15
                      36B9C4B2EFEF5B5959033030192626203535333B3B253A3A2F3737394E4FC8CA
                      C3E1DFF93F40FF2525FF2A2922211E1F1441413BBEBE9BC5C5189797263030C4
                      B1B1D7D3D3DAD0D0D2CECEE3D9D9FFFFFFFBFBFCD9D9E3CFCFDCD3D3DDDFDCDD
                      C4C1C03346462932323B5151CCCFCFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                      FFDEDEDD3E3E33252518FFFFFFFFFFFFFFFFFFE3D9D9D0CDCDE3D9D9FFFFFFFF
                      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFE5E5E5404041252525FFFFFFFFFFFF
                      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFAFA
                      FAE3E3E3D4D4D4D1D1D1FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                      FFFFFFFFFFFFFFFFFFFFFFFFFFFFDDDDDD353535242424282828FFFFFFFFFFFF
                      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFDDDD
                      DD3434341919191A1A1AFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFBFBFBE3E3E3DCDCDCDDDDDD}
                  end
                  object UlMgzGripOnOutPosGoBtn: TRzBitBtn
                    Left = 264
                    Top = 22
                    Width = 61
                    Height = 44
                    FrameColor = 7617536
                    Caption = 'GO'
                    Color = 15791348
                    HotTrack = True
                    TabOrder = 2
                    OnClick = GoBtnClick
                    Glyph.Data = {
                      36030000424D3603000000000000360000002800000010000000100000000100
                      18000000000000030000C30E0000C30E00000000000000000000FFFFFFFFFFFF
                      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFE3E3E3E3E3E3FFFFFFFFFFFFFFFFFFFF
                      FFFFFFFFFFFFFFFFFFFFFFFFFFFFE3E3E3E3E3E3FFFFFFFFFFFFFFFFFFCDCDCD
                      333333333333CDCDCDFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFCDCDCD3333
                      33333333CDCDCDFFFFFFC5C5C52B2B2B00000000000029292ABBBBBBD3D3D3D1
                      D1D1D4D4D4D4D4D4BBBBBB2A2A2A0000000000002A2A2AC5C5C51B1B1B171717
                      1717171717152323192A2A282E2E2F2C2C2C2828282D2D2D2929291919191414
                      141717171B1B1B1D1D1D1A1A1AC4C4C5C0C0BFBBBBB5D2D2D8DADAD4D1D1D1C9
                      C9C9ADADADD1D1D1DBDBDBDFDFDFC1C1C1CACACAC6C6C6101010252525E7E7E6
                      FFFFFFC0C0FF4848FFC2C2FFFFFFFFFFFFFFDCDCDCDBDBDBDBDBDBDBDBDBE0E0
                      E0DFDFDF818181242424222222E2E2DCEDEDFF3E3EFF0000FF3B3BFFE7E7FFFC
                      FCFAA9A9A93333332323232929292F2F2F181818323232C7C7C7212121E6E6E5
                      FFFFFFC2C2FF4B4BFFC2C2FFFFFFFFE2E2E1363636929293B7B7B8AEAEAF7272
                      732A2A2AC2C2C2FFFFFF242424B9B9B9D3D3D3D7D7D1CDCDD1D6D6D1D6D6D3B7
                      B7AD1616129A9A8FCDCDC0A5A59A4C4C49CFCFC8FFFFFFFFFFFF747474373737
                      2B2B2C2F2F2D37372D30302D28282E15152915152011112419192329293DBEBE
                      C5E3E3FFF7F7FFFFFFFFF1F1F1D6D6D6D0D0D0D1D1D1D0D0D1D4D4D1AFAFD144
                      44D3BDBDDC3737D60000D23C3CDCDFDFFF6161FFD8D8FFFFFFFFFFFFFFFFFFFF
                      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFE5E5FFE4E4FFC3C3FF4A4AFFC2C2FFDCDC
                      FFD7D7FFF6F6FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFE0
                      E0FF5858FFD6D6FFDDDDFFD6D6FF5858FFE1E1FFFFFFFFFFFFFFFFFFFFFFFFFF
                      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF6F6FFDBDBFFD2D2FF5F5FFFD2D2FFDBDB
                      FFF6F6FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                      FFFFFFFFFFF8F8FFD8D8FFF8F8FFFFFFFFFFFFFFFFFFFFFFFFFF}
                  end
                end
                object GroupBox58: TGroupBox
                  Left = 372
                  Top = 42
                  Width = 350
                  Height = 80
                  Caption = 'Unloading Ready Position(Conveyor Height+10mm): posGripOffPre'
                  Color = 16119543
                  Font.Charset = ANSI_CHARSET
                  Font.Color = clWindowText
                  Font.Height = -11
                  Font.Name = 'Tahoma'
                  Font.Style = []
                  ParentColor = False
                  ParentFont = False
                  TabOrder = 1
                  object Label116: TLabel
                    Left = 26
                    Top = 53
                    Width = 29
                    Height = 13
                    Caption = 'Z Axis'
                  end
                  object Label139: TLabel
                    Left = 26
                    Top = 25
                    Width = 29
                    Height = 13
                    Caption = 'Y Axis'
                  end
                  object UlMgzGripOffPreZPosEdit: TEdit
                    Left = 88
                    Top = 47
                    Width = 64
                    Height = 24
                    Color = 16777088
                    Font.Charset = ANSI_CHARSET
                    Font.Color = clBlack
                    Font.Height = -13
                    Font.Name = 'Tahoma'
                    Font.Style = []
                    ImeName = '???(??)'
                    MaxLength = 7
                    ParentFont = False
                    TabOrder = 3
                    Text = '0.000'
                    OnChange = DataChange
                  end
                  object UlMgzGripOffPreYPosEdit: TEdit
                    Left = 88
                    Top = 19
                    Width = 64
                    Height = 24
                    Color = 16777088
                    Font.Charset = ANSI_CHARSET
                    Font.Color = clBlack
                    Font.Height = -13
                    Font.Name = 'Tahoma'
                    Font.Style = []
                    ImeName = '???(??)'
                    MaxLength = 7
                    ParentFont = False
                    TabOrder = 0
                    Text = '0.000'
                    OnChange = DataChange
                  end
                  object UlMgzGripOffPrePosGetBtn: TRzBitBtn
                    Left = 196
                    Top = 22
                    Width = 61
                    Height = 44
                    FrameColor = 7617536
                    Caption = 'GET'
                    Color = 15791348
                    HotTrack = True
                    TabOrder = 1
                    OnClick = GetPosBtnClick
                    Glyph.Data = {
                      36030000424D3603000000000000360000002800000010000000100000000100
                      18000000000000030000C30E0000C30E00000000000000000000FFFFFFFFFFFF
                      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFBFB
                      FBE3E3E3DCDCDCDDDDDDD1D1DBE5E5E6FFFFFFE4DBDBD2CFCFDAD1D1D2CFCFE3
                      D9D9FFFFFFFFFFFFFFFFFFFFFFFFDDDDDD3434341919191A1A1A25251F424040
                      BCBABA3C4E4E2A29291D2F2F2C34343B5151CACDCDFDFAFAFFFFFFFFFFFFDDDD
                      DD353535242424282828B7B5001B15000E393F3CC1C195D2D24BD0D092C1C117
                      9595293535E6DDDDFFFFFFFFFFFFFAFAFAE3E3E3D4D4D4D1D1D1E4DB00242C1C
                      36B4C0A7FFFF6CFFFFADF0F05A64640A3939363B3BCBC8C8FFFFFFFFFFFFFFFF
                      FFE5E5E5404041252525D3D000332E259BD9E56CFFFF96FFFF6AF5F590C0C033
                      BDBD92A2A2433333B2AFAFE6DCDCFFFFFFDFE0DF3D3D33252518D9D100232D22
                      50D0DCA1FFFF68FFFFADF0F05861611144443240400828282731313B5050C3C5
                      C4FAF8F6DBDBE3CFCFDCDCD9003531259ADAE66EFCFC92D5D553D0D093C8C82D
                      B9B981BABA2DC4C48ABFBF109A9B435348D8CDDB4849FF2525FFB5AC00161F15
                      36B9C4B2EFEF5B5959033030192626203535333B3B253A3A2F3737394E4FC8CA
                      C3E1DFF93F40FF2525FF2A2922211E1F1441413BBEBE9BC5C5189797263030C4
                      B1B1D7D3D3DAD0D0D2CECEE3D9D9FFFFFFFBFBFCD9D9E3CFCFDCD3D3DDDFDCDD
                      C4C1C03346462932323B5151CCCFCFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                      FFDEDEDD3E3E33252518FFFFFFFFFFFFFFFFFFE3D9D9D0CDCDE3D9D9FFFFFFFF
                      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFE5E5E5404041252525FFFFFFFFFFFF
                      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFAFA
                      FAE3E3E3D4D4D4D1D1D1FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                      FFFFFFFFFFFFFFFFFFFFFFFFFFFFDDDDDD353535242424282828FFFFFFFFFFFF
                      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFDDDD
                      DD3434341919191A1A1AFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFBFBFBE3E3E3DCDCDCDDDDDD}
                  end
                  object UlMgzGripOffPrePosGoBtn: TRzBitBtn
                    Left = 264
                    Top = 22
                    Width = 61
                    Height = 44
                    FrameColor = 7617536
                    Caption = 'GO'
                    Color = 15791348
                    HotTrack = True
                    TabOrder = 2
                    OnClick = GoBtnClick
                    Glyph.Data = {
                      36030000424D3603000000000000360000002800000010000000100000000100
                      18000000000000030000C30E0000C30E00000000000000000000FFFFFFFFFFFF
                      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFE3E3E3E3E3E3FFFFFFFFFFFFFFFFFFFF
                      FFFFFFFFFFFFFFFFFFFFFFFFFFFFE3E3E3E3E3E3FFFFFFFFFFFFFFFFFFCDCDCD
                      333333333333CDCDCDFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFCDCDCD3333
                      33333333CDCDCDFFFFFFC5C5C52B2B2B00000000000029292ABBBBBBD3D3D3D1
                      D1D1D4D4D4D4D4D4BBBBBB2A2A2A0000000000002A2A2AC5C5C51B1B1B171717
                      1717171717152323192A2A282E2E2F2C2C2C2828282D2D2D2929291919191414
                      141717171B1B1B1D1D1D1A1A1AC4C4C5C0C0BFBBBBB5D2D2D8DADAD4D1D1D1C9
                      C9C9ADADADD1D1D1DBDBDBDFDFDFC1C1C1CACACAC6C6C6101010252525E7E7E6
                      FFFFFFC0C0FF4848FFC2C2FFFFFFFFFFFFFFDCDCDCDBDBDBDBDBDBDBDBDBE0E0
                      E0DFDFDF818181242424222222E2E2DCEDEDFF3E3EFF0000FF3B3BFFE7E7FFFC
                      FCFAA9A9A93333332323232929292F2F2F181818323232C7C7C7212121E6E6E5
                      FFFFFFC2C2FF4B4BFFC2C2FFFFFFFFE2E2E1363636929293B7B7B8AEAEAF7272
                      732A2A2AC2C2C2FFFFFF242424B9B9B9D3D3D3D7D7D1CDCDD1D6D6D1D6D6D3B7
                      B7AD1616129A9A8FCDCDC0A5A59A4C4C49CFCFC8FFFFFFFFFFFF747474373737
                      2B2B2C2F2F2D37372D30302D28282E15152915152011112419192329293DBEBE
                      C5E3E3FFF7F7FFFFFFFFF1F1F1D6D6D6D0D0D0D1D1D1D0D0D1D4D4D1AFAFD144
                      44D3BDBDDC3737D60000D23C3CDCDFDFFF6161FFD8D8FFFFFFFFFFFFFFFFFFFF
                      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFE5E5FFE4E4FFC3C3FF4A4AFFC2C2FFDCDC
                      FFD7D7FFF6F6FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFE0
                      E0FF5858FFD6D6FFDDDDFFD6D6FF5858FFE1E1FFFFFFFFFFFFFFFFFFFFFFFFFF
                      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF6F6FFDBDBFFD2D2FF5F5FFFD2D2FFDBDB
                      FFF6F6FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                      FFFFFFFFFFF8F8FFD8D8FFF8F8FFFFFFFFFFFFFFFFFFFFFFFFFF}
                  end
                end
                object GroupBox61: TGroupBox
                  Left = 372
                  Top = 126
                  Width = 350
                  Height = 80
                  Caption = 'Unloading Conveyor Input Pos'#39'(Conveyor In Sensor): posGripOffCvy'
                  Color = 16119543
                  Font.Charset = ANSI_CHARSET
                  Font.Color = clWindowText
                  Font.Height = -11
                  Font.Name = 'Tahoma'
                  Font.Style = []
                  ParentColor = False
                  ParentFont = False
                  TabOrder = 3
                  object Label117: TLabel
                    Left = 26
                    Top = 25
                    Width = 29
                    Height = 13
                    Caption = 'Y Axis'
                  end
                  object Label140: TLabel
                    Left = 26
                    Top = 53
                    Width = 29
                    Height = 13
                    Caption = 'Z Axis'
                  end
                  object UlMgzGripOffCvyYPosEdit: TEdit
                    Left = 88
                    Top = 19
                    Width = 64
                    Height = 24
                    Color = 16777088
                    Font.Charset = ANSI_CHARSET
                    Font.Color = clBlack
                    Font.Height = -13
                    Font.Name = 'Tahoma'
                    Font.Style = []
                    ImeName = '???(??)'
                    MaxLength = 7
                    ParentFont = False
                    TabOrder = 0
                    Text = '0.000'
                    OnChange = DataChange
                  end
                  object UlMgzGripOffCvyZPosEdit: TEdit
                    Left = 88
                    Top = 47
                    Width = 64
                    Height = 24
                    Color = 16777088
                    Font.Charset = ANSI_CHARSET
                    Font.Color = clBlack
                    Font.Height = -13
                    Font.Name = 'Tahoma'
                    Font.Style = []
                    ImeName = '???(??)'
                    MaxLength = 7
                    ParentFont = False
                    TabOrder = 3
                    Text = '0.000'
                    OnChange = DataChange
                  end
                  object UlMgzGripOffCvyPosGetBtn: TRzBitBtn
                    Left = 196
                    Top = 22
                    Width = 61
                    Height = 44
                    FrameColor = 7617536
                    Caption = 'GET'
                    Color = 15791348
                    HotTrack = True
                    TabOrder = 1
                    OnClick = GetPosBtnClick
                    Glyph.Data = {
                      36030000424D3603000000000000360000002800000010000000100000000100
                      18000000000000030000C30E0000C30E00000000000000000000FFFFFFFFFFFF
                      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFBFB
                      FBE3E3E3DCDCDCDDDDDDD1D1DBE5E5E6FFFFFFE4DBDBD2CFCFDAD1D1D2CFCFE3
                      D9D9FFFFFFFFFFFFFFFFFFFFFFFFDDDDDD3434341919191A1A1A25251F424040
                      BCBABA3C4E4E2A29291D2F2F2C34343B5151CACDCDFDFAFAFFFFFFFFFFFFDDDD
                      DD353535242424282828B7B5001B15000E393F3CC1C195D2D24BD0D092C1C117
                      9595293535E6DDDDFFFFFFFFFFFFFAFAFAE3E3E3D4D4D4D1D1D1E4DB00242C1C
                      36B4C0A7FFFF6CFFFFADF0F05A64640A3939363B3BCBC8C8FFFFFFFFFFFFFFFF
                      FFE5E5E5404041252525D3D000332E259BD9E56CFFFF96FFFF6AF5F590C0C033
                      BDBD92A2A2433333B2AFAFE6DCDCFFFFFFDFE0DF3D3D33252518D9D100232D22
                      50D0DCA1FFFF68FFFFADF0F05861611144443240400828282731313B5050C3C5
                      C4FAF8F6DBDBE3CFCFDCDCD9003531259ADAE66EFCFC92D5D553D0D093C8C82D
                      B9B981BABA2DC4C48ABFBF109A9B435348D8CDDB4849FF2525FFB5AC00161F15
                      36B9C4B2EFEF5B5959033030192626203535333B3B253A3A2F3737394E4FC8CA
                      C3E1DFF93F40FF2525FF2A2922211E1F1441413BBEBE9BC5C5189797263030C4
                      B1B1D7D3D3DAD0D0D2CECEE3D9D9FFFFFFFBFBFCD9D9E3CFCFDCD3D3DDDFDCDD
                      C4C1C03346462932323B5151CCCFCFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                      FFDEDEDD3E3E33252518FFFFFFFFFFFFFFFFFFE3D9D9D0CDCDE3D9D9FFFFFFFF
                      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFE5E5E5404041252525FFFFFFFFFFFF
                      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFAFA
                      FAE3E3E3D4D4D4D1D1D1FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                      FFFFFFFFFFFFFFFFFFFFFFFFFFFFDDDDDD353535242424282828FFFFFFFFFFFF
                      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFDDDD
                      DD3434341919191A1A1AFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFBFBFBE3E3E3DCDCDCDDDDDD}
                  end
                  object UlMgzGripOffCvyPosGoBtn: TRzBitBtn
                    Left = 264
                    Top = 22
                    Width = 61
                    Height = 44
                    FrameColor = 7617536
                    Caption = 'GO'
                    Color = 15791348
                    HotTrack = True
                    TabOrder = 2
                    OnClick = GoBtnClick
                    Glyph.Data = {
                      36030000424D3603000000000000360000002800000010000000100000000100
                      18000000000000030000C30E0000C30E00000000000000000000FFFFFFFFFFFF
                      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFE3E3E3E3E3E3FFFFFFFFFFFFFFFFFFFF
                      FFFFFFFFFFFFFFFFFFFFFFFFFFFFE3E3E3E3E3E3FFFFFFFFFFFFFFFFFFCDCDCD
                      333333333333CDCDCDFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFCDCDCD3333
                      33333333CDCDCDFFFFFFC5C5C52B2B2B00000000000029292ABBBBBBD3D3D3D1
                      D1D1D4D4D4D4D4D4BBBBBB2A2A2A0000000000002A2A2AC5C5C51B1B1B171717
                      1717171717152323192A2A282E2E2F2C2C2C2828282D2D2D2929291919191414
                      141717171B1B1B1D1D1D1A1A1AC4C4C5C0C0BFBBBBB5D2D2D8DADAD4D1D1D1C9
                      C9C9ADADADD1D1D1DBDBDBDFDFDFC1C1C1CACACAC6C6C6101010252525E7E7E6
                      FFFFFFC0C0FF4848FFC2C2FFFFFFFFFFFFFFDCDCDCDBDBDBDBDBDBDBDBDBE0E0
                      E0DFDFDF818181242424222222E2E2DCEDEDFF3E3EFF0000FF3B3BFFE7E7FFFC
                      FCFAA9A9A93333332323232929292F2F2F181818323232C7C7C7212121E6E6E5
                      FFFFFFC2C2FF4B4BFFC2C2FFFFFFFFE2E2E1363636929293B7B7B8AEAEAF7272
                      732A2A2AC2C2C2FFFFFF242424B9B9B9D3D3D3D7D7D1CDCDD1D6D6D1D6D6D3B7
                      B7AD1616129A9A8FCDCDC0A5A59A4C4C49CFCFC8FFFFFFFFFFFF747474373737
                      2B2B2C2F2F2D37372D30302D28282E15152915152011112419192329293DBEBE
                      C5E3E3FFF7F7FFFFFFFFF1F1F1D6D6D6D0D0D0D1D1D1D0D0D1D4D4D1AFAFD144
                      44D3BDBDDC3737D60000D23C3CDCDFDFFF6161FFD8D8FFFFFFFFFFFFFFFFFFFF
                      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFE5E5FFE4E4FFC3C3FF4A4AFFC2C2FFDCDC
                      FFD7D7FFF6F6FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFE0
                      E0FF5858FFD6D6FFDDDDFFD6D6FF5858FFE1E1FFFFFFFFFFFFFFFFFFFFFFFFFF
                      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF6F6FFDBDBFFD2D2FF5F5FFFD2D2FFDBDB
                      FFF6F6FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                      FFFFFFFFFFF8F8FFD8D8FFF8F8FFFFFFFFFFFFFFFFFFFFFFFFFF}
                  end
                end
                object GroupBox63: TGroupBox
                  Left = 372
                  Top = 210
                  Width = 350
                  Height = 80
                  Caption = 'Unloading Conveyor Grip Off Position: posGripOff'
                  Color = 16119543
                  Font.Charset = ANSI_CHARSET
                  Font.Color = clWindowText
                  Font.Height = -11
                  Font.Name = 'Tahoma'
                  Font.Style = []
                  ParentColor = False
                  ParentFont = False
                  TabOrder = 5
                  object Label119: TLabel
                    Left = 26
                    Top = 53
                    Width = 29
                    Height = 13
                    Caption = 'Z Axis'
                  end
                  object Label146: TLabel
                    Left = 26
                    Top = 25
                    Width = 29
                    Height = 13
                    Caption = 'Y Axis'
                  end
                  object UlMgzGripOffZPosEdit: TEdit
                    Left = 88
                    Top = 47
                    Width = 64
                    Height = 24
                    Color = 16777088
                    Font.Charset = ANSI_CHARSET
                    Font.Color = clBlack
                    Font.Height = -13
                    Font.Name = 'Tahoma'
                    Font.Style = []
                    ImeName = '???(??)'
                    MaxLength = 7
                    ParentFont = False
                    TabOrder = 3
                    Text = '0.000'
                    OnChange = DataChange
                  end
                  object UlMgzGripOffYPosEdit: TEdit
                    Left = 88
                    Top = 19
                    Width = 64
                    Height = 24
                    Color = 16777088
                    Font.Charset = ANSI_CHARSET
                    Font.Color = clBlack
                    Font.Height = -13
                    Font.Name = 'Tahoma'
                    Font.Style = []
                    ImeName = '???(??)'
                    MaxLength = 7
                    ParentFont = False
                    TabOrder = 0
                    Text = '0.000'
                    OnChange = DataChange
                  end
                  object UlMgzGripOffPosGetBtn: TRzBitBtn
                    Left = 196
                    Top = 22
                    Width = 61
                    Height = 44
                    FrameColor = 7617536
                    Caption = 'GET'
                    Color = 15791348
                    HotTrack = True
                    TabOrder = 1
                    OnClick = GetPosBtnClick
                    Glyph.Data = {
                      36030000424D3603000000000000360000002800000010000000100000000100
                      18000000000000030000C30E0000C30E00000000000000000000FFFFFFFFFFFF
                      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFBFB
                      FBE3E3E3DCDCDCDDDDDDD1D1DBE5E5E6FFFFFFE4DBDBD2CFCFDAD1D1D2CFCFE3
                      D9D9FFFFFFFFFFFFFFFFFFFFFFFFDDDDDD3434341919191A1A1A25251F424040
                      BCBABA3C4E4E2A29291D2F2F2C34343B5151CACDCDFDFAFAFFFFFFFFFFFFDDDD
                      DD353535242424282828B7B5001B15000E393F3CC1C195D2D24BD0D092C1C117
                      9595293535E6DDDDFFFFFFFFFFFFFAFAFAE3E3E3D4D4D4D1D1D1E4DB00242C1C
                      36B4C0A7FFFF6CFFFFADF0F05A64640A3939363B3BCBC8C8FFFFFFFFFFFFFFFF
                      FFE5E5E5404041252525D3D000332E259BD9E56CFFFF96FFFF6AF5F590C0C033
                      BDBD92A2A2433333B2AFAFE6DCDCFFFFFFDFE0DF3D3D33252518D9D100232D22
                      50D0DCA1FFFF68FFFFADF0F05861611144443240400828282731313B5050C3C5
                      C4FAF8F6DBDBE3CFCFDCDCD9003531259ADAE66EFCFC92D5D553D0D093C8C82D
                      B9B981BABA2DC4C48ABFBF109A9B435348D8CDDB4849FF2525FFB5AC00161F15
                      36B9C4B2EFEF5B5959033030192626203535333B3B253A3A2F3737394E4FC8CA
                      C3E1DFF93F40FF2525FF2A2922211E1F1441413BBEBE9BC5C5189797263030C4
                      B1B1D7D3D3DAD0D0D2CECEE3D9D9FFFFFFFBFBFCD9D9E3CFCFDCD3D3DDDFDCDD
                      C4C1C03346462932323B5151CCCFCFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                      FFDEDEDD3E3E33252518FFFFFFFFFFFFFFFFFFE3D9D9D0CDCDE3D9D9FFFFFFFF
                      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFE5E5E5404041252525FFFFFFFFFFFF
                      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFAFA
                      FAE3E3E3D4D4D4D1D1D1FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                      FFFFFFFFFFFFFFFFFFFFFFFFFFFFDDDDDD353535242424282828FFFFFFFFFFFF
                      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFDDDD
                      DD3434341919191A1A1AFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFBFBFBE3E3E3DCDCDCDDDDDD}
                  end
                  object UlMgzGripOffPosGoBtn: TRzBitBtn
                    Left = 264
                    Top = 22
                    Width = 61
                    Height = 44
                    FrameColor = 7617536
                    Caption = 'GO'
                    Color = 15791348
                    HotTrack = True
                    TabOrder = 2
                    OnClick = GoBtnClick
                    Glyph.Data = {
                      36030000424D3603000000000000360000002800000010000000100000000100
                      18000000000000030000C30E0000C30E00000000000000000000FFFFFFFFFFFF
                      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFE3E3E3E3E3E3FFFFFFFFFFFFFFFFFFFF
                      FFFFFFFFFFFFFFFFFFFFFFFFFFFFE3E3E3E3E3E3FFFFFFFFFFFFFFFFFFCDCDCD
                      333333333333CDCDCDFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFCDCDCD3333
                      33333333CDCDCDFFFFFFC5C5C52B2B2B00000000000029292ABBBBBBD3D3D3D1
                      D1D1D4D4D4D4D4D4BBBBBB2A2A2A0000000000002A2A2AC5C5C51B1B1B171717
                      1717171717152323192A2A282E2E2F2C2C2C2828282D2D2D2929291919191414
                      141717171B1B1B1D1D1D1A1A1AC4C4C5C0C0BFBBBBB5D2D2D8DADAD4D1D1D1C9
                      C9C9ADADADD1D1D1DBDBDBDFDFDFC1C1C1CACACAC6C6C6101010252525E7E7E6
                      FFFFFFC0C0FF4848FFC2C2FFFFFFFFFFFFFFDCDCDCDBDBDBDBDBDBDBDBDBE0E0
                      E0DFDFDF818181242424222222E2E2DCEDEDFF3E3EFF0000FF3B3BFFE7E7FFFC
                      FCFAA9A9A93333332323232929292F2F2F181818323232C7C7C7212121E6E6E5
                      FFFFFFC2C2FF4B4BFFC2C2FFFFFFFFE2E2E1363636929293B7B7B8AEAEAF7272
                      732A2A2AC2C2C2FFFFFF242424B9B9B9D3D3D3D7D7D1CDCDD1D6D6D1D6D6D3B7
                      B7AD1616129A9A8FCDCDC0A5A59A4C4C49CFCFC8FFFFFFFFFFFF747474373737
                      2B2B2C2F2F2D37372D30302D28282E15152915152011112419192329293DBEBE
                      C5E3E3FFF7F7FFFFFFFFF1F1F1D6D6D6D0D0D0D1D1D1D0D0D1D4D4D1AFAFD144
                      44D3BDBDDC3737D60000D23C3CDCDFDFFF6161FFD8D8FFFFFFFFFFFFFFFFFFFF
                      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFE5E5FFE4E4FFC3C3FF4A4AFFC2C2FFDCDC
                      FFD7D7FFF6F6FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFE0
                      E0FF5858FFD6D6FFDDDDFFD6D6FF5858FFE1E1FFFFFFFFFFFFFFFFFFFFFFFFFF
                      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF6F6FFDBDBFFD2D2FF5F5FFFD2D2FFDBDB
                      FFF6F6FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                      FFFFFFFFFFF8F8FFD8D8FFF8F8FFFFFFFFFFFFFFFFFFFFFFFFFF}
                  end
                end
                object GroupBox72: TGroupBox
                  Left = 14
                  Top = 379
                  Width = 350
                  Height = 80
                  Caption = 'Conveyor On Going Delay: '
                  Font.Charset = ANSI_CHARSET
                  Font.Color = clWindowText
                  Font.Height = -11
                  Font.Name = 'Tahoma'
                  Font.Style = []
                  ParentFont = False
                  TabOrder = 9
                  object Label126: TLabel
                    Left = 17
                    Top = 24
                    Width = 153
                    Height = 13
                    Caption = 'After Detect Loader Out Sensor'
                  end
                  object Label129: TLabel
                    Left = 17
                    Top = 52
                    Width = 132
                    Height = 13
                    Caption = 'Check For Magazine Empty '
                    WordWrap = True
                  end
                  object UlMgzLdOutDlySpinEdit: TLMDSpinEdit
                    Left = 232
                    Top = 18
                    Width = 101
                    Height = 25
                    Bevel.Mode = bmWindows
                    Caret.BlinkRate = 530
                    ImeName = '???(??) (MS-IME98)'
                    TabOrder = 0
                    OnChange = DataChange
                    Font.Charset = ANSI_CHARSET
                    Font.Color = clWindowText
                    Font.Height = -13
                    Font.Name = 'Tahoma'
                    Font.Style = []
                    AutoSelect = True
                    ParentFont = False
                    CustomButtons = <>
                    CustomButtonParentCtlXP = False
                    Suffix = ' ms'
                    MaxValue = 10000
                    Value = 700
                    Value = 700
                  end
                  object UlMgzEmptyChkTimeSpinEdit: TLMDSpinEdit
                    Left = 232
                    Top = 46
                    Width = 101
                    Height = 25
                    Bevel.Mode = bmWindows
                    Caret.BlinkRate = 530
                    ImeName = '???(??) (MS-IME98)'
                    TabOrder = 1
                    OnChange = DataChange
                    Font.Charset = ANSI_CHARSET
                    Font.Color = clWindowText
                    Font.Height = -13
                    Font.Name = 'Tahoma'
                    Font.Style = []
                    AutoSelect = True
                    ParentFont = False
                    CustomButtons = <>
                    CustomButtonParentCtlXP = False
                    Suffix = ' sec'
                    MinValue = 1
                    MaxValue = 30
                    Value = 3
                    Value = 3
                  end
                end
                object GroupBox73: TGroupBox
                  Left = 14
                  Top = 126
                  Width = 350
                  Height = 80
                  Caption = 'Grip On Position: posGripOnCvy'
                  Color = 16119543
                  Font.Charset = ANSI_CHARSET
                  Font.Color = clWindowText
                  Font.Height = -11
                  Font.Name = 'Tahoma'
                  Font.Style = []
                  ParentColor = False
                  ParentFont = False
                  TabOrder = 2
                  object Label130: TLabel
                    Left = 26
                    Top = 25
                    Width = 29
                    Height = 13
                    Caption = 'Y Axis'
                  end
                  object Label131: TLabel
                    Left = 26
                    Top = 53
                    Width = 29
                    Height = 13
                    Caption = 'Z Axis'
                  end
                  object UlMgzGripOnCvyYPosEdit: TEdit
                    Left = 88
                    Top = 19
                    Width = 64
                    Height = 24
                    Color = 16777088
                    Font.Charset = ANSI_CHARSET
                    Font.Color = clBlack
                    Font.Height = -13
                    Font.Name = 'Tahoma'
                    Font.Style = []
                    ImeName = '???(??)'
                    MaxLength = 7
                    ParentFont = False
                    TabOrder = 0
                    Text = '0.000'
                    OnChange = DataChange
                  end
                  object UlMgzGripOnCvyZPosEdit: TEdit
                    Left = 88
                    Top = 47
                    Width = 64
                    Height = 24
                    Color = 16777088
                    Font.Charset = ANSI_CHARSET
                    Font.Color = clBlack
                    Font.Height = -13
                    Font.Name = 'Tahoma'
                    Font.Style = []
                    ImeName = '???(??)'
                    MaxLength = 7
                    ParentFont = False
                    TabOrder = 3
                    Text = '0.000'
                    OnChange = DataChange
                  end
                  object UlMgzGripOnCvyPosGetBtn: TRzBitBtn
                    Left = 196
                    Top = 22
                    Width = 61
                    Height = 44
                    FrameColor = 7617536
                    Caption = 'GET'
                    Color = 15791348
                    HotTrack = True
                    TabOrder = 1
                    OnClick = GetPosBtnClick
                    Glyph.Data = {
                      36030000424D3603000000000000360000002800000010000000100000000100
                      18000000000000030000C30E0000C30E00000000000000000000FFFFFFFFFFFF
                      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFBFB
                      FBE3E3E3DCDCDCDDDDDDD1D1DBE5E5E6FFFFFFE4DBDBD2CFCFDAD1D1D2CFCFE3
                      D9D9FFFFFFFFFFFFFFFFFFFFFFFFDDDDDD3434341919191A1A1A25251F424040
                      BCBABA3C4E4E2A29291D2F2F2C34343B5151CACDCDFDFAFAFFFFFFFFFFFFDDDD
                      DD353535242424282828B7B5001B15000E393F3CC1C195D2D24BD0D092C1C117
                      9595293535E6DDDDFFFFFFFFFFFFFAFAFAE3E3E3D4D4D4D1D1D1E4DB00242C1C
                      36B4C0A7FFFF6CFFFFADF0F05A64640A3939363B3BCBC8C8FFFFFFFFFFFFFFFF
                      FFE5E5E5404041252525D3D000332E259BD9E56CFFFF96FFFF6AF5F590C0C033
                      BDBD92A2A2433333B2AFAFE6DCDCFFFFFFDFE0DF3D3D33252518D9D100232D22
                      50D0DCA1FFFF68FFFFADF0F05861611144443240400828282731313B5050C3C5
                      C4FAF8F6DBDBE3CFCFDCDCD9003531259ADAE66EFCFC92D5D553D0D093C8C82D
                      B9B981BABA2DC4C48ABFBF109A9B435348D8CDDB4849FF2525FFB5AC00161F15
                      36B9C4B2EFEF5B5959033030192626203535333B3B253A3A2F3737394E4FC8CA
                      C3E1DFF93F40FF2525FF2A2922211E1F1441413BBEBE9BC5C5189797263030C4
                      B1B1D7D3D3DAD0D0D2CECEE3D9D9FFFFFFFBFBFCD9D9E3CFCFDCD3D3DDDFDCDD
                      C4C1C03346462932323B5151CCCFCFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                      FFDEDEDD3E3E33252518FFFFFFFFFFFFFFFFFFE3D9D9D0CDCDE3D9D9FFFFFFFF
                      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFE5E5E5404041252525FFFFFFFFFFFF
                      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFAFA
                      FAE3E3E3D4D4D4D1D1D1FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                      FFFFFFFFFFFFFFFFFFFFFFFFFFFFDDDDDD353535242424282828FFFFFFFFFFFF
                      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFDDDD
                      DD3434341919191A1A1AFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFBFBFBE3E3E3DCDCDCDDDDDD}
                  end
                  object UlMgzGripOnCvyPosGoBtn: TRzBitBtn
                    Left = 264
                    Top = 22
                    Width = 61
                    Height = 44
                    FrameColor = 7617536
                    Caption = 'GO'
                    Color = 15791348
                    HotTrack = True
                    TabOrder = 2
                    OnClick = GoBtnClick
                    Glyph.Data = {
                      36030000424D3603000000000000360000002800000010000000100000000100
                      18000000000000030000C30E0000C30E00000000000000000000FFFFFFFFFFFF
                      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFE3E3E3E3E3E3FFFFFFFFFFFFFFFFFFFF
                      FFFFFFFFFFFFFFFFFFFFFFFFFFFFE3E3E3E3E3E3FFFFFFFFFFFFFFFFFFCDCDCD
                      333333333333CDCDCDFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFCDCDCD3333
                      33333333CDCDCDFFFFFFC5C5C52B2B2B00000000000029292ABBBBBBD3D3D3D1
                      D1D1D4D4D4D4D4D4BBBBBB2A2A2A0000000000002A2A2AC5C5C51B1B1B171717
                      1717171717152323192A2A282E2E2F2C2C2C2828282D2D2D2929291919191414
                      141717171B1B1B1D1D1D1A1A1AC4C4C5C0C0BFBBBBB5D2D2D8DADAD4D1D1D1C9
                      C9C9ADADADD1D1D1DBDBDBDFDFDFC1C1C1CACACAC6C6C6101010252525E7E7E6
                      FFFFFFC0C0FF4848FFC2C2FFFFFFFFFFFFFFDCDCDCDBDBDBDBDBDBDBDBDBE0E0
                      E0DFDFDF818181242424222222E2E2DCEDEDFF3E3EFF0000FF3B3BFFE7E7FFFC
                      FCFAA9A9A93333332323232929292F2F2F181818323232C7C7C7212121E6E6E5
                      FFFFFFC2C2FF4B4BFFC2C2FFFFFFFFE2E2E1363636929293B7B7B8AEAEAF7272
                      732A2A2AC2C2C2FFFFFF242424B9B9B9D3D3D3D7D7D1CDCDD1D6D6D1D6D6D3B7
                      B7AD1616129A9A8FCDCDC0A5A59A4C4C49CFCFC8FFFFFFFFFFFF747474373737
                      2B2B2C2F2F2D37372D30302D28282E15152915152011112419192329293DBEBE
                      C5E3E3FFF7F7FFFFFFFFF1F1F1D6D6D6D0D0D0D1D1D1D0D0D1D4D4D1AFAFD144
                      44D3BDBDDC3737D60000D23C3CDCDFDFFF6161FFD8D8FFFFFFFFFFFFFFFFFFFF
                      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFE5E5FFE4E4FFC3C3FF4A4AFFC2C2FFDCDC
                      FFD7D7FFF6F6FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFE0
                      E0FF5858FFD6D6FFDDDDFFD6D6FF5858FFE1E1FFFFFFFFFFFFFFFFFFFFFFFFFF
                      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF6F6FFDBDBFFD2D2FF5F5FFFD2D2FFDBDB
                      FFF6F6FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                      FFFFFFFFFFF8F8FFD8D8FFF8F8FFFFFFFFFFFFFFFFFFFFFFFFFF}
                  end
                end
                object GroupBox109: TGroupBox
                  Left = 14
                  Top = 210
                  Width = 350
                  Height = 80
                  Caption = 'Slightly Lift Position(After Grip On): posGripOnUp'
                  Color = 16119543
                  Font.Charset = ANSI_CHARSET
                  Font.Color = clWindowText
                  Font.Height = -11
                  Font.Name = 'Tahoma'
                  Font.Style = []
                  ParentColor = False
                  ParentFont = False
                  TabOrder = 4
                  object Label148: TLabel
                    Left = 26
                    Top = 25
                    Width = 29
                    Height = 13
                    Caption = 'Y Axis'
                  end
                  object Label149: TLabel
                    Left = 26
                    Top = 53
                    Width = 29
                    Height = 13
                    Caption = 'Z Axis'
                  end
                  object UlMgzGripOnUpYPosEdit: TEdit
                    Left = 88
                    Top = 19
                    Width = 64
                    Height = 24
                    Color = 16777088
                    Font.Charset = ANSI_CHARSET
                    Font.Color = clBlack
                    Font.Height = -13
                    Font.Name = 'Tahoma'
                    Font.Style = []
                    ImeName = '???(??)'
                    MaxLength = 7
                    ParentFont = False
                    TabOrder = 0
                    Text = '0.000'
                    OnChange = DataChange
                  end
                  object UlMgzGripOnUpZPosEdit: TEdit
                    Left = 88
                    Top = 47
                    Width = 64
                    Height = 24
                    Color = 16777088
                    Font.Charset = ANSI_CHARSET
                    Font.Color = clBlack
                    Font.Height = -13
                    Font.Name = 'Tahoma'
                    Font.Style = []
                    ImeName = '???(??)'
                    MaxLength = 7
                    ParentFont = False
                    TabOrder = 3
                    Text = '0.000'
                    OnChange = DataChange
                  end
                  object UlMgzGripOnUpPosGetBtn: TRzBitBtn
                    Left = 196
                    Top = 22
                    Width = 61
                    Height = 44
                    FrameColor = 7617536
                    Caption = 'GET'
                    Color = 15791348
                    HotTrack = True
                    TabOrder = 1
                    OnClick = GetPosBtnClick
                    Glyph.Data = {
                      36030000424D3603000000000000360000002800000010000000100000000100
                      18000000000000030000C30E0000C30E00000000000000000000FFFFFFFFFFFF
                      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFBFB
                      FBE3E3E3DCDCDCDDDDDDD1D1DBE5E5E6FFFFFFE4DBDBD2CFCFDAD1D1D2CFCFE3
                      D9D9FFFFFFFFFFFFFFFFFFFFFFFFDDDDDD3434341919191A1A1A25251F424040
                      BCBABA3C4E4E2A29291D2F2F2C34343B5151CACDCDFDFAFAFFFFFFFFFFFFDDDD
                      DD353535242424282828B7B5001B15000E393F3CC1C195D2D24BD0D092C1C117
                      9595293535E6DDDDFFFFFFFFFFFFFAFAFAE3E3E3D4D4D4D1D1D1E4DB00242C1C
                      36B4C0A7FFFF6CFFFFADF0F05A64640A3939363B3BCBC8C8FFFFFFFFFFFFFFFF
                      FFE5E5E5404041252525D3D000332E259BD9E56CFFFF96FFFF6AF5F590C0C033
                      BDBD92A2A2433333B2AFAFE6DCDCFFFFFFDFE0DF3D3D33252518D9D100232D22
                      50D0DCA1FFFF68FFFFADF0F05861611144443240400828282731313B5050C3C5
                      C4FAF8F6DBDBE3CFCFDCDCD9003531259ADAE66EFCFC92D5D553D0D093C8C82D
                      B9B981BABA2DC4C48ABFBF109A9B435348D8CDDB4849FF2525FFB5AC00161F15
                      36B9C4B2EFEF5B5959033030192626203535333B3B253A3A2F3737394E4FC8CA
                      C3E1DFF93F40FF2525FF2A2922211E1F1441413BBEBE9BC5C5189797263030C4
                      B1B1D7D3D3DAD0D0D2CECEE3D9D9FFFFFFFBFBFCD9D9E3CFCFDCD3D3DDDFDCDD
                      C4C1C03346462932323B5151CCCFCFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                      FFDEDEDD3E3E33252518FFFFFFFFFFFFFFFFFFE3D9D9D0CDCDE3D9D9FFFFFFFF
                      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFE5E5E5404041252525FFFFFFFFFFFF
                      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFAFA
                      FAE3E3E3D4D4D4D1D1D1FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                      FFFFFFFFFFFFFFFFFFFFFFFFFFFFDDDDDD353535242424282828FFFFFFFFFFFF
                      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFDDDD
                      DD3434341919191A1A1AFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFBFBFBE3E3E3DCDCDCDDDDDD}
                  end
                  object UlMgzGripOnUpPosGoBtn: TRzBitBtn
                    Left = 264
                    Top = 22
                    Width = 61
                    Height = 44
                    FrameColor = 7617536
                    Caption = 'GO'
                    Color = 15791348
                    HotTrack = True
                    TabOrder = 2
                    OnClick = GoBtnClick
                    Glyph.Data = {
                      36030000424D3603000000000000360000002800000010000000100000000100
                      18000000000000030000C30E0000C30E00000000000000000000FFFFFFFFFFFF
                      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFE3E3E3E3E3E3FFFFFFFFFFFFFFFFFFFF
                      FFFFFFFFFFFFFFFFFFFFFFFFFFFFE3E3E3E3E3E3FFFFFFFFFFFFFFFFFFCDCDCD
                      333333333333CDCDCDFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFCDCDCD3333
                      33333333CDCDCDFFFFFFC5C5C52B2B2B00000000000029292ABBBBBBD3D3D3D1
                      D1D1D4D4D4D4D4D4BBBBBB2A2A2A0000000000002A2A2AC5C5C51B1B1B171717
                      1717171717152323192A2A282E2E2F2C2C2C2828282D2D2D2929291919191414
                      141717171B1B1B1D1D1D1A1A1AC4C4C5C0C0BFBBBBB5D2D2D8DADAD4D1D1D1C9
                      C9C9ADADADD1D1D1DBDBDBDFDFDFC1C1C1CACACAC6C6C6101010252525E7E7E6
                      FFFFFFC0C0FF4848FFC2C2FFFFFFFFFFFFFFDCDCDCDBDBDBDBDBDBDBDBDBE0E0
                      E0DFDFDF818181242424222222E2E2DCEDEDFF3E3EFF0000FF3B3BFFE7E7FFFC
                      FCFAA9A9A93333332323232929292F2F2F181818323232C7C7C7212121E6E6E5
                      FFFFFFC2C2FF4B4BFFC2C2FFFFFFFFE2E2E1363636929293B7B7B8AEAEAF7272
                      732A2A2AC2C2C2FFFFFF242424B9B9B9D3D3D3D7D7D1CDCDD1D6D6D1D6D6D3B7
                      B7AD1616129A9A8FCDCDC0A5A59A4C4C49CFCFC8FFFFFFFFFFFF747474373737
                      2B2B2C2F2F2D37372D30302D28282E15152915152011112419192329293DBEBE
                      C5E3E3FFF7F7FFFFFFFFF1F1F1D6D6D6D0D0D0D1D1D1D0D0D1D4D4D1AFAFD144
                      44D3BDBDDC3737D60000D23C3CDCDFDFFF6161FFD8D8FFFFFFFFFFFFFFFFFFFF
                      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFE5E5FFE4E4FFC3C3FF4A4AFFC2C2FFDCDC
                      FFD7D7FFF6F6FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFE0
                      E0FF5858FFD6D6FFDDDDFFD6D6FF5858FFE1E1FFFFFFFFFFFFFFFFFFFFFFFFFF
                      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF6F6FFDBDBFFD2D2FF5F5FFFD2D2FFDBDB
                      FFF6F6FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                      FFFFFFFFFFF8F8FFD8D8FFF8F8FFFFFFFFFFFFFFFFFFFFFFFFFF}
                  end
                end
                object GroupBox110: TGroupBox
                  Left = 372
                  Top = 295
                  Width = 350
                  Height = 80
                  Caption = 'Gripper Slightly Down Position After Grip Off: posGripOffDn'
                  Color = 16119543
                  Font.Charset = ANSI_CHARSET
                  Font.Color = clWindowText
                  Font.Height = -11
                  Font.Name = 'Tahoma'
                  Font.Style = []
                  ParentColor = False
                  ParentFont = False
                  TabOrder = 7
                  object Label154: TLabel
                    Left = 26
                    Top = 53
                    Width = 29
                    Height = 13
                    Caption = 'Z Axis'
                  end
                  object Label157: TLabel
                    Left = 26
                    Top = 25
                    Width = 29
                    Height = 13
                    Caption = 'Y Axis'
                  end
                  object UlMgzGripOffDnZPosEdit: TEdit
                    Left = 88
                    Top = 47
                    Width = 64
                    Height = 24
                    Color = 16777088
                    Font.Charset = ANSI_CHARSET
                    Font.Color = clBlack
                    Font.Height = -13
                    Font.Name = 'Tahoma'
                    Font.Style = []
                    ImeName = '???(??)'
                    MaxLength = 7
                    ParentFont = False
                    TabOrder = 3
                    Text = '0.000'
                    OnChange = DataChange
                  end
                  object UlMgzGripOffDnYPosEdit: TEdit
                    Left = 88
                    Top = 19
                    Width = 64
                    Height = 24
                    Color = 16777088
                    Font.Charset = ANSI_CHARSET
                    Font.Color = clBlack
                    Font.Height = -13
                    Font.Name = 'Tahoma'
                    Font.Style = []
                    ImeName = '???(??)'
                    MaxLength = 7
                    ParentFont = False
                    TabOrder = 0
                    Text = '0.000'
                    OnChange = DataChange
                  end
                  object UlMgzGripOffDnPosGetBtn: TRzBitBtn
                    Left = 196
                    Top = 22
                    Width = 61
                    Height = 44
                    FrameColor = 7617536
                    Caption = 'GET'
                    Color = 15791348
                    HotTrack = True
                    TabOrder = 1
                    OnClick = GetPosBtnClick
                    Glyph.Data = {
                      36030000424D3603000000000000360000002800000010000000100000000100
                      18000000000000030000C30E0000C30E00000000000000000000FFFFFFFFFFFF
                      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFBFB
                      FBE3E3E3DCDCDCDDDDDDD1D1DBE5E5E6FFFFFFE4DBDBD2CFCFDAD1D1D2CFCFE3
                      D9D9FFFFFFFFFFFFFFFFFFFFFFFFDDDDDD3434341919191A1A1A25251F424040
                      BCBABA3C4E4E2A29291D2F2F2C34343B5151CACDCDFDFAFAFFFFFFFFFFFFDDDD
                      DD353535242424282828B7B5001B15000E393F3CC1C195D2D24BD0D092C1C117
                      9595293535E6DDDDFFFFFFFFFFFFFAFAFAE3E3E3D4D4D4D1D1D1E4DB00242C1C
                      36B4C0A7FFFF6CFFFFADF0F05A64640A3939363B3BCBC8C8FFFFFFFFFFFFFFFF
                      FFE5E5E5404041252525D3D000332E259BD9E56CFFFF96FFFF6AF5F590C0C033
                      BDBD92A2A2433333B2AFAFE6DCDCFFFFFFDFE0DF3D3D33252518D9D100232D22
                      50D0DCA1FFFF68FFFFADF0F05861611144443240400828282731313B5050C3C5
                      C4FAF8F6DBDBE3CFCFDCDCD9003531259ADAE66EFCFC92D5D553D0D093C8C82D
                      B9B981BABA2DC4C48ABFBF109A9B435348D8CDDB4849FF2525FFB5AC00161F15
                      36B9C4B2EFEF5B5959033030192626203535333B3B253A3A2F3737394E4FC8CA
                      C3E1DFF93F40FF2525FF2A2922211E1F1441413BBEBE9BC5C5189797263030C4
                      B1B1D7D3D3DAD0D0D2CECEE3D9D9FFFFFFFBFBFCD9D9E3CFCFDCD3D3DDDFDCDD
                      C4C1C03346462932323B5151CCCFCFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                      FFDEDEDD3E3E33252518FFFFFFFFFFFFFFFFFFE3D9D9D0CDCDE3D9D9FFFFFFFF
                      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFE5E5E5404041252525FFFFFFFFFFFF
                      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFAFA
                      FAE3E3E3D4D4D4D1D1D1FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                      FFFFFFFFFFFFFFFFFFFFFFFFFFFFDDDDDD353535242424282828FFFFFFFFFFFF
                      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFDDDD
                      DD3434341919191A1A1AFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFBFBFBE3E3E3DCDCDCDDDDDD}
                  end
                  object UlMgzGripOffDnPosGoBtn: TRzBitBtn
                    Left = 264
                    Top = 22
                    Width = 61
                    Height = 44
                    FrameColor = 7617536
                    Caption = 'GO'
                    Color = 15791348
                    HotTrack = True
                    TabOrder = 2
                    OnClick = GoBtnClick
                    Glyph.Data = {
                      36030000424D3603000000000000360000002800000010000000100000000100
                      18000000000000030000C30E0000C30E00000000000000000000FFFFFFFFFFFF
                      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFE3E3E3E3E3E3FFFFFFFFFFFFFFFFFFFF
                      FFFFFFFFFFFFFFFFFFFFFFFFFFFFE3E3E3E3E3E3FFFFFFFFFFFFFFFFFFCDCDCD
                      333333333333CDCDCDFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFCDCDCD3333
                      33333333CDCDCDFFFFFFC5C5C52B2B2B00000000000029292ABBBBBBD3D3D3D1
                      D1D1D4D4D4D4D4D4BBBBBB2A2A2A0000000000002A2A2AC5C5C51B1B1B171717
                      1717171717152323192A2A282E2E2F2C2C2C2828282D2D2D2929291919191414
                      141717171B1B1B1D1D1D1A1A1AC4C4C5C0C0BFBBBBB5D2D2D8DADAD4D1D1D1C9
                      C9C9ADADADD1D1D1DBDBDBDFDFDFC1C1C1CACACAC6C6C6101010252525E7E7E6
                      FFFFFFC0C0FF4848FFC2C2FFFFFFFFFFFFFFDCDCDCDBDBDBDBDBDBDBDBDBE0E0
                      E0DFDFDF818181242424222222E2E2DCEDEDFF3E3EFF0000FF3B3BFFE7E7FFFC
                      FCFAA9A9A93333332323232929292F2F2F181818323232C7C7C7212121E6E6E5
                      FFFFFFC2C2FF4B4BFFC2C2FFFFFFFFE2E2E1363636929293B7B7B8AEAEAF7272
                      732A2A2AC2C2C2FFFFFF242424B9B9B9D3D3D3D7D7D1CDCDD1D6D6D1D6D6D3B7
                      B7AD1616129A9A8FCDCDC0A5A59A4C4C49CFCFC8FFFFFFFFFFFF747474373737
                      2B2B2C2F2F2D37372D30302D28282E15152915152011112419192329293DBEBE
                      C5E3E3FFF7F7FFFFFFFFF1F1F1D6D6D6D0D0D0D1D1D1D0D0D1D4D4D1AFAFD144
                      44D3BDBDDC3737D60000D23C3CDCDFDFFF6161FFD8D8FFFFFFFFFFFFFFFFFFFF
                      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFE5E5FFE4E4FFC3C3FF4A4AFFC2C2FFDCDC
                      FFD7D7FFF6F6FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFE0
                      E0FF5858FFD6D6FFDDDDFFD6D6FF5858FFE1E1FFFFFFFFFFFFFFFFFFFFFFFFFF
                      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF6F6FFDBDBFFD2D2FF5F5FFFD2D2FFDBDB
                      FFF6F6FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                      FFFFFFFFFFF8F8FFD8D8FFF8F8FFFFFFFFFFFFFFFFFFFFFFFFFF}
                  end
                end
                object GroupBox111: TGroupBox
                  Left = 372
                  Top = 379
                  Width = 350
                  Height = 80
                  Caption = 'Gripper Fully Out Position: posGripOffOut'
                  Color = 16119543
                  Font.Charset = ANSI_CHARSET
                  Font.Color = clWindowText
                  Font.Height = -11
                  Font.Name = 'Tahoma'
                  Font.Style = []
                  ParentColor = False
                  ParentFont = False
                  TabOrder = 8
                  object Label158: TLabel
                    Left = 26
                    Top = 53
                    Width = 29
                    Height = 13
                    Caption = 'Z Axis'
                  end
                  object Label159: TLabel
                    Left = 26
                    Top = 25
                    Width = 29
                    Height = 13
                    Caption = 'Y Axis'
                  end
                  object UlMgzGripOffOutZPosEdit: TEdit
                    Left = 88
                    Top = 47
                    Width = 64
                    Height = 24
                    Color = 16777088
                    Font.Charset = ANSI_CHARSET
                    Font.Color = clBlack
                    Font.Height = -13
                    Font.Name = 'Tahoma'
                    Font.Style = []
                    ImeName = '???(??)'
                    MaxLength = 7
                    ParentFont = False
                    TabOrder = 3
                    Text = '0.000'
                    OnChange = DataChange
                  end
                  object UlMgzGripOffOutYPosEdit: TEdit
                    Left = 88
                    Top = 19
                    Width = 64
                    Height = 24
                    Color = 16777088
                    Font.Charset = ANSI_CHARSET
                    Font.Color = clBlack
                    Font.Height = -13
                    Font.Name = 'Tahoma'
                    Font.Style = []
                    ImeName = '???(??)'
                    MaxLength = 7
                    ParentFont = False
                    TabOrder = 0
                    Text = '0.000'
                    OnChange = DataChange
                  end
                  object UlMgzGripOffOutPosGetBtn: TRzBitBtn
                    Left = 196
                    Top = 22
                    Width = 61
                    Height = 44
                    FrameColor = 7617536
                    Caption = 'GET'
                    Color = 15791348
                    HotTrack = True
                    TabOrder = 1
                    OnClick = GetPosBtnClick
                    Glyph.Data = {
                      36030000424D3603000000000000360000002800000010000000100000000100
                      18000000000000030000C30E0000C30E00000000000000000000FFFFFFFFFFFF
                      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFBFB
                      FBE3E3E3DCDCDCDDDDDDD1D1DBE5E5E6FFFFFFE4DBDBD2CFCFDAD1D1D2CFCFE3
                      D9D9FFFFFFFFFFFFFFFFFFFFFFFFDDDDDD3434341919191A1A1A25251F424040
                      BCBABA3C4E4E2A29291D2F2F2C34343B5151CACDCDFDFAFAFFFFFFFFFFFFDDDD
                      DD353535242424282828B7B5001B15000E393F3CC1C195D2D24BD0D092C1C117
                      9595293535E6DDDDFFFFFFFFFFFFFAFAFAE3E3E3D4D4D4D1D1D1E4DB00242C1C
                      36B4C0A7FFFF6CFFFFADF0F05A64640A3939363B3BCBC8C8FFFFFFFFFFFFFFFF
                      FFE5E5E5404041252525D3D000332E259BD9E56CFFFF96FFFF6AF5F590C0C033
                      BDBD92A2A2433333B2AFAFE6DCDCFFFFFFDFE0DF3D3D33252518D9D100232D22
                      50D0DCA1FFFF68FFFFADF0F05861611144443240400828282731313B5050C3C5
                      C4FAF8F6DBDBE3CFCFDCDCD9003531259ADAE66EFCFC92D5D553D0D093C8C82D
                      B9B981BABA2DC4C48ABFBF109A9B435348D8CDDB4849FF2525FFB5AC00161F15
                      36B9C4B2EFEF5B5959033030192626203535333B3B253A3A2F3737394E4FC8CA
                      C3E1DFF93F40FF2525FF2A2922211E1F1441413BBEBE9BC5C5189797263030C4
                      B1B1D7D3D3DAD0D0D2CECEE3D9D9FFFFFFFBFBFCD9D9E3CFCFDCD3D3DDDFDCDD
                      C4C1C03346462932323B5151CCCFCFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                      FFDEDEDD3E3E33252518FFFFFFFFFFFFFFFFFFE3D9D9D0CDCDE3D9D9FFFFFFFF
                      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFE5E5E5404041252525FFFFFFFFFFFF
                      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFAFA
                      FAE3E3E3D4D4D4D1D1D1FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                      FFFFFFFFFFFFFFFFFFFFFFFFFFFFDDDDDD353535242424282828FFFFFFFFFFFF
                      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFDDDD
                      DD3434341919191A1A1AFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFBFBFBE3E3E3DCDCDCDDDDDD}
                  end
                  object UlMgzGripOffOutPosGoBtn: TRzBitBtn
                    Left = 264
                    Top = 22
                    Width = 61
                    Height = 44
                    FrameColor = 7617536
                    Caption = 'GO'
                    Color = 15791348
                    HotTrack = True
                    TabOrder = 2
                    OnClick = GoBtnClick
                    Glyph.Data = {
                      36030000424D3603000000000000360000002800000010000000100000000100
                      18000000000000030000C30E0000C30E00000000000000000000FFFFFFFFFFFF
                      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFE3E3E3E3E3E3FFFFFFFFFFFFFFFFFFFF
                      FFFFFFFFFFFFFFFFFFFFFFFFFFFFE3E3E3E3E3E3FFFFFFFFFFFFFFFFFFCDCDCD
                      333333333333CDCDCDFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFCDCDCD3333
                      33333333CDCDCDFFFFFFC5C5C52B2B2B00000000000029292ABBBBBBD3D3D3D1
                      D1D1D4D4D4D4D4D4BBBBBB2A2A2A0000000000002A2A2AC5C5C51B1B1B171717
                      1717171717152323192A2A282E2E2F2C2C2C2828282D2D2D2929291919191414
                      141717171B1B1B1D1D1D1A1A1AC4C4C5C0C0BFBBBBB5D2D2D8DADAD4D1D1D1C9
                      C9C9ADADADD1D1D1DBDBDBDFDFDFC1C1C1CACACAC6C6C6101010252525E7E7E6
                      FFFFFFC0C0FF4848FFC2C2FFFFFFFFFFFFFFDCDCDCDBDBDBDBDBDBDBDBDBE0E0
                      E0DFDFDF818181242424222222E2E2DCEDEDFF3E3EFF0000FF3B3BFFE7E7FFFC
                      FCFAA9A9A93333332323232929292F2F2F181818323232C7C7C7212121E6E6E5
                      FFFFFFC2C2FF4B4BFFC2C2FFFFFFFFE2E2E1363636929293B7B7B8AEAEAF7272
                      732A2A2AC2C2C2FFFFFF242424B9B9B9D3D3D3D7D7D1CDCDD1D6D6D1D6D6D3B7
                      B7AD1616129A9A8FCDCDC0A5A59A4C4C49CFCFC8FFFFFFFFFFFF747474373737
                      2B2B2C2F2F2D37372D30302D28282E15152915152011112419192329293DBEBE
                      C5E3E3FFF7F7FFFFFFFFF1F1F1D6D6D6D0D0D0D1D1D1D0D0D1D4D4D1AFAFD144
                      44D3BDBDDC3737D60000D23C3CDCDFDFFF6161FFD8D8FFFFFFFFFFFFFFFFFFFF
                      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFE5E5FFE4E4FFC3C3FF4A4AFFC2C2FFDCDC
                      FFD7D7FFF6F6FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFE0
                      E0FF5858FFD6D6FFDDDDFFD6D6FF5858FFE1E1FFFFFFFFFFFFFFFFFFFFFFFFFF
                      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF6F6FFDBDBFFD2D2FF5F5FFFD2D2FFDBDB
                      FFF6F6FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                      FFFFFFFFFFF8F8FFD8D8FFF8F8FFFFFFFFFFFFFFFFFFFFFFFFFF}
                  end
                end
                object GroupBox55: TGroupBox
                  Left = 192
                  Top = 465
                  Width = 350
                  Height = 54
                  Caption = 'For Unloader Motion Test: '
                  Font.Charset = ANSI_CHARSET
                  Font.Color = clBlack
                  Font.Height = -11
                  Font.Name = 'Tahoma'
                  Font.Style = []
                  ParentFont = False
                  TabOrder = 10
                  object UlMgzLdBtn: TSpeedButton
                    Left = 21
                    Top = 19
                    Width = 120
                    Height = 25
                    Caption = 'LOAD'
                    Font.Charset = ANSI_CHARSET
                    Font.Color = clBlack
                    Font.Height = -11
                    Font.Name = 'Tahoma'
                    Font.Style = [fsBold]
                    Glyph.Data = {
                      C6050000424DC605000000000000360400002800000014000000140000000100
                      0800000000009001000000000000000000000001000000000000000000000000
                      80000080000000808000800000008000800080800000C0C0C000C0DCC000F0CA
                      A6000020400000206000002080000020A0000020C0000020E000004000000040
                      20000040400000406000004080000040A0000040C0000040E000006000000060
                      20000060400000606000006080000060A0000060C0000060E000008000000080
                      20000080400000806000008080000080A0000080C0000080E00000A0000000A0
                      200000A0400000A0600000A0800000A0A00000A0C00000A0E00000C0000000C0
                      200000C0400000C0600000C0800000C0A00000C0C00000C0E00000E0000000E0
                      200000E0400000E0600000E0800000E0A00000E0C00000E0E000400000004000
                      20004000400040006000400080004000A0004000C0004000E000402000004020
                      20004020400040206000402080004020A0004020C0004020E000404000004040
                      20004040400040406000404080004040A0004040C0004040E000406000004060
                      20004060400040606000406080004060A0004060C0004060E000408000004080
                      20004080400040806000408080004080A0004080C0004080E00040A0000040A0
                      200040A0400040A0600040A0800040A0A00040A0C00040A0E00040C0000040C0
                      200040C0400040C0600040C0800040C0A00040C0C00040C0E00040E0000040E0
                      200040E0400040E0600040E0800040E0A00040E0C00040E0E000800000008000
                      20008000400080006000800080008000A0008000C0008000E000802000008020
                      20008020400080206000802080008020A0008020C0008020E000804000008040
                      20008040400080406000804080008040A0008040C0008040E000806000008060
                      20008060400080606000806080008060A0008060C0008060E000808000008080
                      20008080400080806000808080008080A0008080C0008080E00080A0000080A0
                      200080A0400080A0600080A0800080A0A00080A0C00080A0E00080C0000080C0
                      200080C0400080C0600080C0800080C0A00080C0C00080C0E00080E0000080E0
                      200080E0400080E0600080E0800080E0A00080E0C00080E0E000C0000000C000
                      2000C0004000C0006000C0008000C000A000C000C000C000E000C0200000C020
                      2000C0204000C0206000C0208000C020A000C020C000C020E000C0400000C040
                      2000C0404000C0406000C0408000C040A000C040C000C040E000C0600000C060
                      2000C0604000C0606000C0608000C060A000C060C000C060E000C0800000C080
                      2000C0804000C0806000C0808000C080A000C080C000C080E000C0A00000C0A0
                      2000C0A04000C0A06000C0A08000C0A0A000C0A0C000C0A0E000C0C00000C0C0
                      2000C0C04000C0C06000C0C08000C0C0A000F0FBFF00A4A0A000808080000000
                      FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00F7F7F7F7F7F7
                      F7F7F7F7F7F7F7F7F7F7F7F7F7F7F7F7F7F7F7F7F7F7F7F7F7F7F7F7F7F7F7F7
                      F7F7F70404040404040404040404040404F7F7F7F7F7F7040404040404040404
                      0404040404F7F7F7F7F7F7F7F7F7F7F7F7F7F7F7F7F7F70404F7F7F7F7F7F7F7
                      F7F7F7F7F7F7F7F7F704F70404F704F7F7F7F7F7F7F7F7F7F7F7F7F7F7F70404
                      0404F7F7F7F7F7F7F7F7F7F7F7F7F7F7F7F704040404F7F7F7F7F7F7F7F7F7F7
                      F7F7F7F7F7F7F70404F7F7F7F7F7F7F7F7F7F7F7F7F7F7F7F7F7F7F7F7F7F7F7
                      F7F7F7F7F7F7F7101010101010101010101010101010F7F7F7F7101802020202
                      02020202020202021002F7F7F718100202020202020202020202021002F7F7F7
                      18180202020202020202020202021002F7F7F718180202020202020202020202
                      020210F7F7F718180202020202020202020202020210F7F7F7F7101010101010
                      101010101010101010F7F7F7F7F7F7F7F7F7F7F7F7F7F7F7F7F7F7F7F7F7F7F7
                      F7F7F7F7F7F7F7F7F7F7F7F7F7F7F7F7F7F7F7F7F7F7F7F7F7F7F7F7F7F7F7F7
                      F7F7F7F7F7F7F7F7F7F7}
                    ParentFont = False
                    OnClick = MotionBtnClick
                  end
                  object UlMgzUlBtn: TSpeedButton
                    Left = 205
                    Top = 19
                    Width = 120
                    Height = 25
                    Caption = 'UNLOAD'
                    Font.Charset = ANSI_CHARSET
                    Font.Color = clBlack
                    Font.Height = -11
                    Font.Name = 'Tahoma'
                    Font.Style = [fsBold]
                    Glyph.Data = {
                      C6050000424DC605000000000000360400002800000014000000140000000100
                      0800000000009001000000000000000000000001000000000000000000000000
                      80000080000000808000800000008000800080800000C0C0C000C0DCC000F0CA
                      A6000020400000206000002080000020A0000020C0000020E000004000000040
                      20000040400000406000004080000040A0000040C0000040E000006000000060
                      20000060400000606000006080000060A0000060C0000060E000008000000080
                      20000080400000806000008080000080A0000080C0000080E00000A0000000A0
                      200000A0400000A0600000A0800000A0A00000A0C00000A0E00000C0000000C0
                      200000C0400000C0600000C0800000C0A00000C0C00000C0E00000E0000000E0
                      200000E0400000E0600000E0800000E0A00000E0C00000E0E000400000004000
                      20004000400040006000400080004000A0004000C0004000E000402000004020
                      20004020400040206000402080004020A0004020C0004020E000404000004040
                      20004040400040406000404080004040A0004040C0004040E000406000004060
                      20004060400040606000406080004060A0004060C0004060E000408000004080
                      20004080400040806000408080004080A0004080C0004080E00040A0000040A0
                      200040A0400040A0600040A0800040A0A00040A0C00040A0E00040C0000040C0
                      200040C0400040C0600040C0800040C0A00040C0C00040C0E00040E0000040E0
                      200040E0400040E0600040E0800040E0A00040E0C00040E0E000800000008000
                      20008000400080006000800080008000A0008000C0008000E000802000008020
                      20008020400080206000802080008020A0008020C0008020E000804000008040
                      20008040400080406000804080008040A0008040C0008040E000806000008060
                      20008060400080606000806080008060A0008060C0008060E000808000008080
                      20008080400080806000808080008080A0008080C0008080E00080A0000080A0
                      200080A0400080A0600080A0800080A0A00080A0C00080A0E00080C0000080C0
                      200080C0400080C0600080C0800080C0A00080C0C00080C0E00080E0000080E0
                      200080E0400080E0600080E0800080E0A00080E0C00080E0E000C0000000C000
                      2000C0004000C0006000C0008000C000A000C000C000C000E000C0200000C020
                      2000C0204000C0206000C0208000C020A000C020C000C020E000C0400000C040
                      2000C0404000C0406000C0408000C040A000C040C000C040E000C0600000C060
                      2000C0604000C0606000C0608000C060A000C060C000C060E000C0800000C080
                      2000C0804000C0806000C0808000C080A000C080C000C080E000C0A00000C0A0
                      2000C0A04000C0A06000C0A08000C0A0A000C0A0C000C0A0E000C0C00000C0C0
                      2000C0C04000C0C06000C0C08000C0C0A000F0FBFF00A4A0A000808080000000
                      FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00F7F7F7F7F7F7
                      F7F7F7F7F7F7F7F7F7F7F7F7F7F7F7F7F7F7F7F7F7F7F7F7F7F7F7F7F7F7F7F7
                      F7F7F7F7F7F7F7F7F7F7F7F7F7F7F7F7F7F704F7F7F7F7F7F7F7F7F7F7F7F7F7
                      F7F7F7F7F7F7F70404F7F7F7F7F7F7F7F7F7040404040404040404040404F7F7
                      F7F7F7F7F7F7040404040404040404040404F7F7F7F7F7F7F7F70404F7F7F7F7
                      F7F7F70404F7F7F7F7F7F7F7F7F70404F7F7F7F7F7F704F7F7F7F7F7F7F7F7F7
                      F7F70404F7F7F7F7F7F7F7F7F7F7F7F7F7F7F7F7F7F70404F7F7F7F7F7F7F7F7
                      F7F7F7F7F7F7F7F7F7F7F7F7F7F7F7F7F7F7F7F7F7F7F7F7F7F7F71010101010
                      10101010101010101010F7F7F7F710180202020202020202020202021002F7F7
                      F718100202020202020202020202021002F7F7F7181802020202020202020202
                      02021002F7F7F718180202020202020202020202020210F7F7F7181802020202
                      02020202020202020210F7F7F7F7101010101010101010101010101010F7F7F7
                      F7F7F7F7F7F7F7F7F7F7F7F7F7F7F7F7F7F7F7F7F7F7F7F7F7F7F7F7F7F7F7F7
                      F7F7F7F7F7F7F7F7F7F7}
                    ParentFont = False
                    OnClick = MotionBtnClick
                  end
                end
              end
            end
          end
          object EngPage5: TTabSheet
            Caption = 'EngPage5'
            ImageIndex = 9
            object Panel12: TPanel
              Left = 0
              Top = 0
              Width = 737
              Height = 594
              Align = alClient
              BevelOuter = bvNone
              Color = 16119543
              Font.Charset = ANSI_CHARSET
              Font.Color = clRed
              Font.Height = -11
              Font.Name = 'Tahoma'
              Font.Style = []
              ParentFont = False
              TabOrder = 0
              object GroupBox65: TGroupBox
                Left = 372
                Top = 268
                Width = 350
                Height = 117
                Caption = 'Origin Search Speed: '
                Font.Charset = ANSI_CHARSET
                Font.Color = clBlack
                Font.Height = -11
                Font.Name = 'Tahoma'
                Font.Style = []
                ParentFont = False
                TabOrder = 6
                object Label197: TLabel
                  Left = 18
                  Top = 53
                  Width = 100
                  Height = 13
                  Caption = 'Distributer Conveyor'
                end
                object Label198: TLabel
                  Left = 18
                  Top = 25
                  Width = 72
                  Height = 13
                  Caption = 'Inspection X, Y'
                end
                object Label20: TLabel
                  Left = 18
                  Top = 85
                  Width = 66
                  Height = 13
                  Caption = 'Unloader Part'
                end
                object Ax0HSpdSpinEdit: TLMDSpinEdit
                  Left = 152
                  Top = 18
                  Width = 177
                  Height = 25
                  Bevel.Mode = bmWindows
                  Caret.BlinkRate = 530
                  ImeName = '???(??) (MS-IME98)'
                  TabOrder = 0
                  OnChange = DataChange
                  Font.Charset = ANSI_CHARSET
                  Font.Color = clWindowText
                  Font.Height = -13
                  Font.Name = 'Tahoma'
                  Font.Style = []
                  AutoSelect = True
                  ParentFont = False
                  CustomButtons = <>
                  CustomButtonParentCtlXP = False
                  Step = 5
                  Suffix = ' mm/sec'
                  LineSize = 5
                  PageSize = 5
                  MinValue = 1
                  Value = 50
                  Value = 50
                end
                object Ax2HSpdSpinEdit: TLMDSpinEdit
                  Left = 152
                  Top = 46
                  Width = 177
                  Height = 25
                  Bevel.Mode = bmWindows
                  Caret.BlinkRate = 530
                  ImeName = '???(??) (MS-IME98)'
                  TabOrder = 1
                  OnChange = DataChange
                  Font.Charset = ANSI_CHARSET
                  Font.Color = clWindowText
                  Font.Height = -13
                  Font.Name = 'Tahoma'
                  Font.Style = []
                  AutoSelect = True
                  ParentFont = False
                  CustomButtons = <>
                  CustomButtonParentCtlXP = False
                  Step = 10
                  Suffix = ' mm/sec'
                  LineSize = 10
                  MinValue = 1
                  Value = 50
                  Value = 50
                end
                object Ax3HSpdSpinEdit: TLMDSpinEdit
                  Left = 152
                  Top = 78
                  Width = 177
                  Height = 25
                  Bevel.Mode = bmWindows
                  Caret.BlinkRate = 530
                  ImeName = '???(??) (MS-IME98)'
                  TabOrder = 2
                  OnChange = DataChange
                  Font.Charset = ANSI_CHARSET
                  Font.Color = clWindowText
                  Font.Height = -13
                  Font.Name = 'Tahoma'
                  Font.Style = []
                  AutoSelect = True
                  ParentFont = False
                  CustomButtons = <>
                  CustomButtonParentCtlXP = False
                  Step = 10
                  Suffix = ' mm/sec'
                  LineSize = 10
                  MinValue = 1
                  Value = 50
                  Value = 50
                end
              end
              object GroupBox42: TGroupBox
                Left = 8
                Top = 8
                Width = 350
                Height = 81
                Caption = 'Inspection X, Y Motion Speed: '
                Font.Charset = ANSI_CHARSET
                Font.Color = clBlack
                Font.Height = -11
                Font.Name = 'Tahoma'
                Font.Style = []
                ParentFont = False
                TabOrder = 0
                object Label187: TLabel
                  Left = 18
                  Top = 24
                  Width = 53
                  Height = 13
                  Caption = 'Max Speed'
                end
                object Label188: TLabel
                  Left = 18
                  Top = 52
                  Width = 59
                  Height = 13
                  Caption = 'Acceleration'
                end
                object Ax0SpdSpinEdit: TLMDSpinEdit
                  Left = 152
                  Top = 18
                  Width = 177
                  Height = 25
                  Bevel.Mode = bmWindows
                  Caret.BlinkRate = 530
                  ImeName = '???(??) (MS-IME98)'
                  TabOrder = 0
                  OnChange = DataChange
                  Font.Charset = ANSI_CHARSET
                  Font.Color = clWindowText
                  Font.Height = -13
                  Font.Name = 'Tahoma'
                  Font.Style = []
                  AutoSelect = True
                  ParentFont = False
                  CustomButtons = <>
                  CustomButtonParentCtlXP = False
                  Step = 5
                  Suffix = ' mm/sec'
                  LineSize = 5
                  PageSize = 5
                  MinValue = 10
                  MaxValue = 1000
                  Value = 100
                  Value = 100
                end
                object Ax0AccSpinEdit: TLMDSpinEdit
                  Left = 152
                  Top = 46
                  Width = 177
                  Height = 25
                  Bevel.Mode = bmWindows
                  Caret.BlinkRate = 530
                  ImeName = '???(??) (MS-IME98)'
                  TabOrder = 1
                  OnChange = DataChange
                  Font.Charset = ANSI_CHARSET
                  Font.Color = clWindowText
                  Font.Height = -13
                  Font.Name = 'Tahoma'
                  Font.Style = []
                  AutoSelect = True
                  ParentFont = False
                  CustomButtons = <>
                  CustomButtonParentCtlXP = False
                  Step = 10
                  Suffix = ' msec'
                  LineSize = 10
                  MinValue = 10
                  MaxValue = 2000
                  Value = 100
                  Value = 100
                end
              end
              object GroupBox50: TGroupBox
                Left = 8
                Top = 182
                Width = 350
                Height = 81
                Caption = 'Unloader Part Motion Speed: '
                Font.Charset = ANSI_CHARSET
                Font.Color = clBlack
                Font.Height = -11
                Font.Name = 'Tahoma'
                Font.Style = []
                ParentFont = False
                TabOrder = 4
                object Label191: TLabel
                  Left = 18
                  Top = 24
                  Width = 53
                  Height = 13
                  Caption = 'Max Speed'
                end
                object Label192: TLabel
                  Left = 18
                  Top = 52
                  Width = 59
                  Height = 13
                  Caption = 'Acceleration'
                end
                object Ax3SpdSpinEdit: TLMDSpinEdit
                  Left = 152
                  Top = 18
                  Width = 177
                  Height = 25
                  Bevel.Mode = bmWindows
                  Caret.BlinkRate = 530
                  ImeName = '???(??) (MS-IME98)'
                  TabOrder = 0
                  OnChange = DataChange
                  Font.Charset = ANSI_CHARSET
                  Font.Color = clWindowText
                  Font.Height = -13
                  Font.Name = 'Tahoma'
                  Font.Style = []
                  AutoSelect = True
                  ParentFont = False
                  CustomButtons = <>
                  CustomButtonParentCtlXP = False
                  Step = 5
                  Suffix = ' mm/sec'
                  LineSize = 5
                  PageSize = 5
                  MinValue = 1
                  Value = 100
                  Value = 100
                end
                object Ax3AccSpinEdit: TLMDSpinEdit
                  Left = 152
                  Top = 46
                  Width = 177
                  Height = 25
                  Bevel.Mode = bmWindows
                  Caret.BlinkRate = 530
                  ImeName = '???(??) (MS-IME98)'
                  TabOrder = 1
                  OnChange = DataChange
                  Font.Charset = ANSI_CHARSET
                  Font.Color = clWindowText
                  Font.Height = -13
                  Font.Name = 'Tahoma'
                  Font.Style = []
                  AutoSelect = True
                  ParentFont = False
                  CustomButtons = <>
                  CustomButtonParentCtlXP = False
                  Step = 10
                  Suffix = ' msec'
                  LineSize = 10
                  MinValue = 10
                  MaxValue = 2000
                  Value = 100
                  Value = 100
                end
              end
              object GroupBox51: TGroupBox
                Left = 372
                Top = 8
                Width = 350
                Height = 81
                Caption = 'Inspection X, Y Jog Speed: '
                Font.Charset = ANSI_CHARSET
                Font.Color = clBlack
                Font.Height = -11
                Font.Name = 'Tahoma'
                Font.Style = []
                ParentFont = False
                TabOrder = 1
                object Label193: TLabel
                  Left = 18
                  Top = 24
                  Width = 53
                  Height = 13
                  Caption = 'Max Speed'
                end
                object Label194: TLabel
                  Left = 18
                  Top = 52
                  Width = 59
                  Height = 13
                  Caption = 'Acceleration'
                end
                object Ax0JSpdSpinEdit: TLMDSpinEdit
                  Left = 152
                  Top = 18
                  Width = 177
                  Height = 25
                  Bevel.Mode = bmWindows
                  Caret.BlinkRate = 530
                  ImeName = '???(??) (MS-IME98)'
                  TabOrder = 0
                  OnChange = DataChange
                  Font.Charset = ANSI_CHARSET
                  Font.Color = clWindowText
                  Font.Height = -13
                  Font.Name = 'Tahoma'
                  Font.Style = []
                  AutoSelect = True
                  ParentFont = False
                  CustomButtons = <>
                  CustomButtonParentCtlXP = False
                  Step = 5
                  Suffix = ' mm/sec'
                  LineSize = 5
                  PageSize = 5
                  MinValue = 1
                  MaxValue = 50
                  Value = 50
                  Value = 50
                end
                object Ax0JAccSpinEdit: TLMDSpinEdit
                  Left = 152
                  Top = 46
                  Width = 177
                  Height = 25
                  Bevel.Mode = bmWindows
                  Caret.BlinkRate = 530
                  ImeName = '???(??) (MS-IME98)'
                  TabOrder = 1
                  OnChange = DataChange
                  Font.Charset = ANSI_CHARSET
                  Font.Color = clWindowText
                  Font.Height = -13
                  Font.Name = 'Tahoma'
                  Font.Style = []
                  AutoSelect = True
                  ParentFont = False
                  CustomButtons = <>
                  CustomButtonParentCtlXP = False
                  Step = 10
                  Suffix = ' msec'
                  LineSize = 10
                  MinValue = 10
                  MaxValue = 2000
                  Value = 100
                  Value = 100
                end
              end
              object GroupBox52: TGroupBox
                Left = 372
                Top = 182
                Width = 350
                Height = 81
                Caption = 'Unloader Part Jog Speed: '
                Font.Charset = ANSI_CHARSET
                Font.Color = clBlack
                Font.Height = -11
                Font.Name = 'Tahoma'
                Font.Style = []
                ParentFont = False
                TabOrder = 5
                object Label195: TLabel
                  Left = 18
                  Top = 24
                  Width = 53
                  Height = 13
                  Caption = 'Max Speed'
                end
                object Label196: TLabel
                  Left = 18
                  Top = 52
                  Width = 59
                  Height = 13
                  Caption = 'Acceleration'
                end
                object Ax3JSpdSpinEdit: TLMDSpinEdit
                  Left = 152
                  Top = 18
                  Width = 177
                  Height = 25
                  Bevel.Mode = bmWindows
                  Caret.BlinkRate = 530
                  ImeName = '???(??) (MS-IME98)'
                  TabOrder = 0
                  OnChange = DataChange
                  Font.Charset = ANSI_CHARSET
                  Font.Color = clWindowText
                  Font.Height = -13
                  Font.Name = 'Tahoma'
                  Font.Style = []
                  AutoSelect = True
                  ParentFont = False
                  CustomButtons = <>
                  CustomButtonParentCtlXP = False
                  Step = 5
                  Suffix = ' mm/sec'
                  LineSize = 5
                  PageSize = 5
                  MinValue = 1
                  MaxValue = 50
                  Value = 50
                  Value = 50
                end
                object Ax3JAccSpinEdit: TLMDSpinEdit
                  Left = 152
                  Top = 46
                  Width = 177
                  Height = 25
                  Bevel.Mode = bmWindows
                  Caret.BlinkRate = 530
                  ImeName = '???(??) (MS-IME98)'
                  TabOrder = 1
                  OnChange = DataChange
                  Font.Charset = ANSI_CHARSET
                  Font.Color = clWindowText
                  Font.Height = -13
                  Font.Name = 'Tahoma'
                  Font.Style = []
                  AutoSelect = True
                  ParentFont = False
                  CustomButtons = <>
                  CustomButtonParentCtlXP = False
                  Step = 10
                  Suffix = ' msec'
                  LineSize = 10
                  MinValue = 10
                  MaxValue = 2000
                  Value = 100
                  Value = 100
                end
              end
              object GroupBox4: TGroupBox
                Left = 8
                Top = 94
                Width = 350
                Height = 81
                Caption = 'Conveyor Distributer Motion Speed: '
                Font.Charset = ANSI_CHARSET
                Font.Color = clBlack
                Font.Height = -11
                Font.Name = 'Tahoma'
                Font.Style = []
                ParentFont = False
                TabOrder = 2
                object Label6: TLabel
                  Left = 18
                  Top = 24
                  Width = 53
                  Height = 13
                  Caption = 'Max Speed'
                end
                object Label15: TLabel
                  Left = 18
                  Top = 52
                  Width = 59
                  Height = 13
                  Caption = 'Acceleration'
                end
                object Ax2SpdSpinEdit: TLMDSpinEdit
                  Left = 152
                  Top = 18
                  Width = 177
                  Height = 25
                  Bevel.Mode = bmWindows
                  Caret.BlinkRate = 530
                  ImeName = '???(??) (MS-IME98)'
                  TabOrder = 0
                  OnChange = DataChange
                  Font.Charset = ANSI_CHARSET
                  Font.Color = clWindowText
                  Font.Height = -13
                  Font.Name = 'Tahoma'
                  Font.Style = []
                  AutoSelect = True
                  ParentFont = False
                  CustomButtons = <>
                  CustomButtonParentCtlXP = False
                  Step = 5
                  Suffix = ' mm/sec'
                  LineSize = 5
                  PageSize = 5
                  MinValue = 1
                  Value = 100
                  Value = 100
                end
                object Ax2AccSpinEdit: TLMDSpinEdit
                  Left = 152
                  Top = 46
                  Width = 177
                  Height = 25
                  Bevel.Mode = bmWindows
                  Caret.BlinkRate = 530
                  ImeName = '???(??) (MS-IME98)'
                  TabOrder = 1
                  OnChange = DataChange
                  Font.Charset = ANSI_CHARSET
                  Font.Color = clWindowText
                  Font.Height = -13
                  Font.Name = 'Tahoma'
                  Font.Style = []
                  AutoSelect = True
                  ParentFont = False
                  CustomButtons = <>
                  CustomButtonParentCtlXP = False
                  Step = 10
                  Suffix = ' msec'
                  LineSize = 10
                  MinValue = 10
                  MaxValue = 2000
                  Value = 100
                  Value = 100
                end
              end
              object GroupBox6: TGroupBox
                Left = 372
                Top = 94
                Width = 350
                Height = 81
                Caption = 'Conveyor Distributer Jog Speed: '
                Font.Charset = ANSI_CHARSET
                Font.Color = clBlack
                Font.Height = -11
                Font.Name = 'Tahoma'
                Font.Style = []
                ParentFont = False
                TabOrder = 3
                object Label16: TLabel
                  Left = 18
                  Top = 24
                  Width = 53
                  Height = 13
                  Caption = 'Max Speed'
                end
                object Label17: TLabel
                  Left = 18
                  Top = 52
                  Width = 59
                  Height = 13
                  Caption = 'Acceleration'
                end
                object Ax2JSpdSpinEdit: TLMDSpinEdit
                  Left = 152
                  Top = 18
                  Width = 177
                  Height = 25
                  Bevel.Mode = bmWindows
                  Caret.BlinkRate = 530
                  ImeName = '???(??) (MS-IME98)'
                  TabOrder = 0
                  OnChange = DataChange
                  Font.Charset = ANSI_CHARSET
                  Font.Color = clWindowText
                  Font.Height = -13
                  Font.Name = 'Tahoma'
                  Font.Style = []
                  AutoSelect = True
                  ParentFont = False
                  CustomButtons = <>
                  CustomButtonParentCtlXP = False
                  Step = 5
                  Suffix = ' mm/sec'
                  LineSize = 5
                  PageSize = 5
                  MinValue = 1
                  MaxValue = 50
                  Value = 50
                  Value = 50
                end
                object Ax2JAccSpinEdit: TLMDSpinEdit
                  Left = 152
                  Top = 46
                  Width = 177
                  Height = 25
                  Bevel.Mode = bmWindows
                  Caret.BlinkRate = 530
                  ImeName = '???(??) (MS-IME98)'
                  TabOrder = 1
                  OnChange = DataChange
                  Font.Charset = ANSI_CHARSET
                  Font.Color = clWindowText
                  Font.Height = -13
                  Font.Name = 'Tahoma'
                  Font.Style = []
                  AutoSelect = True
                  ParentFont = False
                  CustomButtons = <>
                  CustomButtonParentCtlXP = False
                  Step = 10
                  Suffix = ' msec'
                  LineSize = 10
                  MinValue = 10
                  MaxValue = 2000
                  Value = 100
                  Value = 100
                end
              end
            end
          end
        end
      end
      object TabSheet4: TTabSheet
        Caption = 'TabSheet4'
        ImageIndex = 2
        object FacPageCtrl: TPageControl
          Left = 7
          Top = 4
          Width = 746
          Height = 609
          ActivePage = FacPage1
          TabIndex = 1
          TabOrder = 0
          TabPosition = tpBottom
          Visible = False
          object FacPage0: TTabSheet
            Caption = 'FacPage0'
            ImageIndex = 7
            object Panel3: TPanel
              Left = 0
              Top = 0
              Width = 738
              Height = 583
              Align = alClient
              BevelOuter = bvNone
              Caption = 'Factory Setup'
              Color = 16119543
              Font.Charset = ANSI_CHARSET
              Font.Color = clRed
              Font.Height = -64
              Font.Name = 'Tahoma'
              Font.Style = [fsBold]
              ParentFont = False
              TabOrder = 0
            end
          end
          object FacPage1: TTabSheet
            Caption = 'FacPage1'
            object Panel13: TPanel
              Left = 0
              Top = 0
              Width = 738
              Height = 583
              Align = alClient
              BevelOuter = bvNone
              Color = 16119543
              Font.Charset = ANSI_CHARSET
              Font.Color = clBlack
              Font.Height = -11
              Font.Name = 'Tahoma'
              Font.Style = []
              ParentFont = False
              TabOrder = 0
              object SysFacOptionGrpBox: TGroupBox
                Left = 12
                Top = 8
                Width = 233
                Height = 297
                Caption = 'Option: '
                TabOrder = 0
                object NoHWChkBox: TCheckBox
                  Left = 10
                  Top = 16
                  Width = 210
                  Height = 17
                  Caption = 'No Machine'
                  TabOrder = 0
                  OnClick = DataChange
                end
                object EnglishVersionChkBox: TCheckBox
                  Left = 10
                  Top = 35
                  Width = 210
                  Height = 17
                  Caption = 'English Version'
                  TabOrder = 1
                  OnClick = DataChange
                end
                object SetupBtnPswdChkBox: TCheckBox
                  Left = 10
                  Top = 132
                  Width = 210
                  Height = 17
                  Caption = 'Setup Button Engineer Password'
                  TabOrder = 6
                  OnClick = DataChange
                end
                object DisableSpdAdjustChkBox: TCheckBox
                  Left = 10
                  Top = 151
                  Width = 210
                  Height = 17
                  Caption = 'Disable Speed Adjust'
                  TabOrder = 7
                  OnClick = DataChange
                end
                object UseSecsGemChkBox: TCheckBox
                  Left = 10
                  Top = 74
                  Width = 210
                  Height = 17
                  Caption = 'Use SECS_GEM'
                  TabOrder = 3
                  OnClick = DataChange
                end
                object DebugModeChkBox: TCheckBox
                  Left = 10
                  Top = 54
                  Width = 210
                  Height = 17
                  Caption = 'Debug Mode'
                  TabOrder = 2
                  OnClick = DataChange
                end
                object NoUseUnloaderChkBox: TCheckBox
                  Left = 10
                  Top = 190
                  Width = 210
                  Height = 17
                  Caption = 'No Use Unloader'
                  TabOrder = 9
                  OnClick = DataChange
                end
                object EnaSmemaChkBox: TCheckBox
                  Left = 10
                  Top = 93
                  Width = 210
                  Height = 17
                  Caption = 'Enable Smema'
                  TabOrder = 4
                  OnClick = DataChange
                end
                object NoUseXYCoordMoveChkBox: TCheckBox
                  Left = 10
                  Top = 112
                  Width = 210
                  Height = 17
                  Caption = 'Disable Inspection XY Interpolation'
                  TabOrder = 5
                  OnClick = DataChange
                end
                object UseLineScanChkBox: TCheckBox
                  Left = 10
                  Top = 171
                  Width = 210
                  Height = 17
                  Caption = 'Use Line Scan Camera'
                  TabOrder = 8
                  OnClick = DataChange
                end
                object UsePreBufCvyChkBox: TCheckBox
                  Left = 10
                  Top = 209
                  Width = 210
                  Height = 17
                  Caption = 'Use Pre Buffer Conveyor(Single Lane)'
                  TabOrder = 10
                  OnClick = DataChange
                end
                object NoUseRearRailChkBox: TCheckBox
                  Left = 10
                  Top = 229
                  Width = 210
                  Height = 17
                  Caption = 'No Use Rear Rail(Dual Lane)'
                  TabOrder = 11
                  OnClick = DataChange
                end
                object NoUseFnIoChkBox: TCheckBox
                  Left = 10
                  Top = 248
                  Width = 210
                  Height = 17
                  Caption = 'No Use Network I/O(For Single Lane)'
                  TabOrder = 12
                  OnClick = DataChange
                end
                object ChkFrontDispComm: TCheckBox
                  Left = 10
                  Top = 269
                  Width = 210
                  Height = 17
                  Caption = 'Use Network with Front UnderFill Dispenser'
                  TabOrder = 13
                  OnClick = DataChange
                end
              end
              object GroupBox62: TGroupBox
                Left = 264
                Top = 100
                Width = 281
                Height = 81
                Caption = 'Vision Module UDP: '
                TabOrder = 2
                object Label3: TLabel
                  Left = 18
                  Top = 24
                  Width = 10
                  Height = 13
                  Caption = 'IP'
                end
                object Label2: TLabel
                  Left = 18
                  Top = 54
                  Width = 20
                  Height = 13
                  Caption = 'Port'
                end
                object UdpIpEdit: TEdit
                  Left = 156
                  Top = 18
                  Width = 101
                  Height = 24
                  Font.Charset = ANSI_CHARSET
                  Font.Color = clWindowText
                  Font.Height = -13
                  Font.Name = 'Tahoma'
                  Font.Style = []
                  ImeName = '???(??)'
                  ParentFont = False
                  TabOrder = 0
                  Text = '10.0.0.151'
                  OnChange = DataChange
                end
                object UdpPortEdit: TEdit
                  Left = 156
                  Top = 48
                  Width = 101
                  Height = 24
                  Font.Charset = ANSI_CHARSET
                  Font.Color = clWindowText
                  Font.Height = -13
                  Font.Name = 'Tahoma'
                  Font.Style = []
                  ImeName = '???(??)'
                  ParentFont = False
                  TabOrder = 1
                  Text = '7000'
                  OnChange = DataChange
                end
              end
              object GroupBox8: TGroupBox
                Left = 264
                Top = 12
                Width = 281
                Height = 83
                Caption = 'Safety: '
                TabOrder = 1
                object AlwaysSafetyOnChkBox: TCheckBox
                  Left = 10
                  Top = 38
                  Width = 170
                  Height = 17
                  Caption = 'Always Safety Check'
                  TabOrder = 1
                  OnClick = DataChange
                end
                object AutoDoorLockChkBox: TCheckBox
                  Left = 10
                  Top = 58
                  Width = 159
                  Height = 17
                  Caption = 'Auto Safety Locking'
                  TabOrder = 2
                  OnClick = DataChange
                end
                object EngSaftySetEnaChkBox: TCheckBox
                  Left = 10
                  Top = 18
                  Width = 220
                  Height = 17
                  Caption = 'Safety Setup Permission For Engineer'
                  TabOrder = 0
                  OnClick = DataChange
                end
              end
              object EquipTypeSelRdoGrp: TRadioGroup
                Left = 12
                Top = 318
                Width = 233
                Height = 61
                Caption = 'Lane Type: '
                ItemIndex = 0
                Items.Strings = (
                  'Single Lane(Horizontal Type Unloader)'
                  'Dual Lane(Vertical Type Unloader)')
                TabOrder = 3
                OnClick = DataChange
              end
              object GroupBox9: TGroupBox
                Left = 264
                Top = 188
                Width = 281
                Height = 53
                Caption = 'Dispenser Module TCP/IP: '
                TabOrder = 4
                Visible = False
                object Label28: TLabel
                  Left = 18
                  Top = 24
                  Width = 20
                  Height = 13
                  Caption = 'Port'
                end
                object Edit2: TEdit
                  Left = 156
                  Top = 18
                  Width = 101
                  Height = 24
                  Font.Charset = ANSI_CHARSET
                  Font.Color = clWindowText
                  Font.Height = -13
                  Font.Name = 'Tahoma'
                  Font.Style = []
                  ImeName = '???(??)'
                  ParentFont = False
                  TabOrder = 0
                  Text = '6000'
                  OnChange = DataChange
                end
              end
            end
          end
          object FacPage2: TTabSheet
            Caption = 'FacPage2'
            ImageIndex = 1
            object Panel14: TPanel
              Left = 0
              Top = 0
              Width = 738
              Height = 583
              Align = alClient
              BevelOuter = bvNone
              Color = 16119543
              Font.Charset = ANSI_CHARSET
              Font.Color = clBlack
              Font.Height = -11
              Font.Name = 'Tahoma'
              Font.Style = []
              ParentFont = False
              TabOrder = 0
              object GroupBox45: TGroupBox
                Left = 12
                Top = 8
                Width = 350
                Height = 275
                Caption = 'Unit(pulse/mm): '
                TabOrder = 0
                object Label27: TLabel
                  Left = 16
                  Top = 119
                  Width = 52
                  Height = 13
                  Caption = 'Unloader Y'
                end
                object Label184: TLabel
                  Left = 16
                  Top = 25
                  Width = 59
                  Height = 13
                  Caption = 'Inspection X'
                end
                object Label186: TLabel
                  Left = 16
                  Top = 88
                  Width = 50
                  Height = 13
                  Caption = 'Distributer'
                end
                object Label220: TLabel
                  Left = 16
                  Top = 57
                  Width = 59
                  Height = 13
                  Caption = 'Inspection Y'
                end
                object Label10: TLabel
                  Left = 16
                  Top = 151
                  Width = 52
                  Height = 13
                  Caption = 'Unloader Z'
                end
                object Ax3PulsePermmEdit: TEdit
                  Left = 204
                  Top = 113
                  Width = 121
                  Height = 24
                  Font.Charset = ANSI_CHARSET
                  Font.Color = clWindowText
                  Font.Height = -13
                  Font.Name = 'Tahoma'
                  Font.Style = []
                  ImeName = '???(??) (MS-IME98)'
                  ParentFont = False
                  TabOrder = 3
                  Text = '0'
                  OnChange = DataChange
                end
                object Ax0PulsePermmEdit: TEdit
                  Left = 204
                  Top = 19
                  Width = 121
                  Height = 24
                  Font.Charset = ANSI_CHARSET
                  Font.Color = clWindowText
                  Font.Height = -13
                  Font.Name = 'Tahoma'
                  Font.Style = []
                  ImeName = '???(??) (MS-IME98)'
                  ParentFont = False
                  TabOrder = 0
                  Text = '0'
                  OnChange = DataChange
                end
                object Ax2PulsePermmEdit: TEdit
                  Left = 204
                  Top = 82
                  Width = 121
                  Height = 24
                  Font.Charset = ANSI_CHARSET
                  Font.Color = clWindowText
                  Font.Height = -13
                  Font.Name = 'Tahoma'
                  Font.Style = []
                  ImeName = '???(??) (MS-IME98)'
                  ParentFont = False
                  TabOrder = 2
                  Text = '0'
                  OnChange = DataChange
                end
                object Ax1PulsePermmEdit: TEdit
                  Left = 204
                  Top = 51
                  Width = 121
                  Height = 24
                  Font.Charset = ANSI_CHARSET
                  Font.Color = clWindowText
                  Font.Height = -13
                  Font.Name = 'Tahoma'
                  Font.Style = []
                  ImeName = '???(??) (MS-IME98)'
                  ParentFont = False
                  TabOrder = 1
                  Text = '0'
                  OnChange = DataChange
                end
                object Ax4PulsePermmEdit: TEdit
                  Left = 204
                  Top = 145
                  Width = 121
                  Height = 24
                  Font.Charset = ANSI_CHARSET
                  Font.Color = clWindowText
                  Font.Height = -13
                  Font.Name = 'Tahoma'
                  Font.Style = []
                  ImeName = '???(??) (MS-IME98)'
                  ParentFont = False
                  TabOrder = 4
                  Text = '0'
                  OnChange = DataChange
                end
              end
            end
          end
          object FacPage3: TTabSheet
            Caption = 'FacPage3'
            ImageIndex = 2
            object Panel15: TPanel
              Left = 0
              Top = 0
              Width = 738
              Height = 583
              Align = alClient
              BevelOuter = bvNone
              Color = 16119543
              Font.Charset = ANSI_CHARSET
              Font.Color = clBlack
              Font.Height = -11
              Font.Name = 'Tahoma'
              Font.Style = []
              ParentFont = False
              TabOrder = 0
              object GroupBox44: TGroupBox
                Left = 10
                Top = 8
                Width = 350
                Height = 169
                Caption = '(-)  Software Limit: '
                TabOrder = 0
                object Label145: TLabel
                  Left = 16
                  Top = 52
                  Width = 59
                  Height = 13
                  Caption = 'Inspection Y'
                end
                object Label89: TLabel
                  Left = 16
                  Top = 23
                  Width = 59
                  Height = 13
                  Caption = 'Inspection X'
                end
                object Label189: TLabel
                  Left = 16
                  Top = 112
                  Width = 46
                  Height = 13
                  Caption = 'Unloader '
                end
                object Label1: TLabel
                  Left = 16
                  Top = 82
                  Width = 50
                  Height = 13
                  Caption = 'Distributer'
                end
                object Label18: TLabel
                  Left = 16
                  Top = 142
                  Width = 52
                  Height = 13
                  Caption = 'Unloader Z'
                end
                object Ax0MSftLmtPosEdit: TEdit
                  Left = 126
                  Top = 17
                  Width = 64
                  Height = 24
                  Color = 16777088
                  Font.Charset = ANSI_CHARSET
                  Font.Color = clBlack
                  Font.Height = -13
                  Font.Name = 'Tahoma'
                  Font.Style = []
                  ImeName = '???(??)'
                  MaxLength = 7
                  ParentFont = False
                  TabOrder = 0
                  Text = '0.000'
                  OnChange = DataChange
                end
                object Ax1MSftLmtPosEdit: TEdit
                  Left = 126
                  Top = 46
                  Width = 64
                  Height = 24
                  Color = 16777088
                  Font.Charset = ANSI_CHARSET
                  Font.Color = clBlack
                  Font.Height = -13
                  Font.Name = 'Tahoma'
                  Font.Style = []
                  ImeName = '???(??)'
                  MaxLength = 7
                  ParentFont = False
                  TabOrder = 3
                  Text = '0.000'
                  OnChange = DataChange
                end
                object Ax3MSftLmtPosEdit: TEdit
                  Left = 126
                  Top = 106
                  Width = 64
                  Height = 24
                  Color = 16777088
                  Font.Charset = ANSI_CHARSET
                  Font.Color = clBlack
                  Font.Height = -13
                  Font.Name = 'Tahoma'
                  Font.Style = []
                  ImeName = '???(??)'
                  MaxLength = 7
                  ParentFont = False
                  TabOrder = 9
                  Text = '0.000'
                  OnChange = DataChange
                end
                object Ax2MSftLmtPosEdit: TEdit
                  Left = 126
                  Top = 76
                  Width = 64
                  Height = 24
                  Color = 16777088
                  Font.Charset = ANSI_CHARSET
                  Font.Color = clBlack
                  Font.Height = -13
                  Font.Name = 'Tahoma'
                  Font.Style = []
                  ImeName = '???(??)'
                  MaxLength = 7
                  ParentFont = False
                  TabOrder = 6
                  Text = '0.000'
                  OnChange = DataChange
                end
                object Ax0MSftLmtPosGetBtn: TRzBitBtn
                  Left = 204
                  Top = 17
                  Width = 61
                  Height = 24
                  FrameColor = 7617536
                  Caption = 'GET'
                  Color = 15791348
                  HotTrack = True
                  TabOrder = 1
                  OnClick = GetPosBtnClick
                  Glyph.Data = {
                    36030000424D3603000000000000360000002800000010000000100000000100
                    18000000000000030000C30E0000C30E00000000000000000000FFFFFFFFFFFF
                    FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFBFB
                    FBE3E3E3DCDCDCDDDDDDD1D1DBE5E5E6FFFFFFE4DBDBD2CFCFDAD1D1D2CFCFE3
                    D9D9FFFFFFFFFFFFFFFFFFFFFFFFDDDDDD3434341919191A1A1A25251F424040
                    BCBABA3C4E4E2A29291D2F2F2C34343B5151CACDCDFDFAFAFFFFFFFFFFFFDDDD
                    DD353535242424282828B7B5001B15000E393F3CC1C195D2D24BD0D092C1C117
                    9595293535E6DDDDFFFFFFFFFFFFFAFAFAE3E3E3D4D4D4D1D1D1E4DB00242C1C
                    36B4C0A7FFFF6CFFFFADF0F05A64640A3939363B3BCBC8C8FFFFFFFFFFFFFFFF
                    FFE5E5E5404041252525D3D000332E259BD9E56CFFFF96FFFF6AF5F590C0C033
                    BDBD92A2A2433333B2AFAFE6DCDCFFFFFFDFE0DF3D3D33252518D9D100232D22
                    50D0DCA1FFFF68FFFFADF0F05861611144443240400828282731313B5050C3C5
                    C4FAF8F6DBDBE3CFCFDCDCD9003531259ADAE66EFCFC92D5D553D0D093C8C82D
                    B9B981BABA2DC4C48ABFBF109A9B435348D8CDDB4849FF2525FFB5AC00161F15
                    36B9C4B2EFEF5B5959033030192626203535333B3B253A3A2F3737394E4FC8CA
                    C3E1DFF93F40FF2525FF2A2922211E1F1441413BBEBE9BC5C5189797263030C4
                    B1B1D7D3D3DAD0D0D2CECEE3D9D9FFFFFFFBFBFCD9D9E3CFCFDCD3D3DDDFDCDD
                    C4C1C03346462932323B5151CCCFCFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                    FFDEDEDD3E3E33252518FFFFFFFFFFFFFFFFFFE3D9D9D0CDCDE3D9D9FFFFFFFF
                    FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFE5E5E5404041252525FFFFFFFFFFFF
                    FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFAFA
                    FAE3E3E3D4D4D4D1D1D1FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                    FFFFFFFFFFFFFFFFFFFFFFFFFFFFDDDDDD353535242424282828FFFFFFFFFFFF
                    FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFDDDD
                    DD3434341919191A1A1AFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                    FFFFFFFFFFFFFFFFFFFFFFFFFFFFFBFBFBE3E3E3DCDCDCDDDDDD}
                end
                object Ax0MSftLmtPosGoBtn: TRzBitBtn
                  Left = 274
                  Top = 17
                  Width = 61
                  Height = 24
                  FrameColor = 7617536
                  Caption = 'GO'
                  Color = 15791348
                  HotTrack = True
                  TabOrder = 2
                  OnClick = GoBtnClick
                  Glyph.Data = {
                    36030000424D3603000000000000360000002800000010000000100000000100
                    18000000000000030000C30E0000C30E00000000000000000000FFFFFFFFFFFF
                    FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                    FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFE3E3E3E3E3E3FFFFFFFFFFFFFFFFFFFF
                    FFFFFFFFFFFFFFFFFFFFFFFFFFFFE3E3E3E3E3E3FFFFFFFFFFFFFFFFFFCDCDCD
                    333333333333CDCDCDFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFCDCDCD3333
                    33333333CDCDCDFFFFFFC5C5C52B2B2B00000000000029292ABBBBBBD3D3D3D1
                    D1D1D4D4D4D4D4D4BBBBBB2A2A2A0000000000002A2A2AC5C5C51B1B1B171717
                    1717171717152323192A2A282E2E2F2C2C2C2828282D2D2D2929291919191414
                    141717171B1B1B1D1D1D1A1A1AC4C4C5C0C0BFBBBBB5D2D2D8DADAD4D1D1D1C9
                    C9C9ADADADD1D1D1DBDBDBDFDFDFC1C1C1CACACAC6C6C6101010252525E7E7E6
                    FFFFFFC0C0FF4848FFC2C2FFFFFFFFFFFFFFDCDCDCDBDBDBDBDBDBDBDBDBE0E0
                    E0DFDFDF818181242424222222E2E2DCEDEDFF3E3EFF0000FF3B3BFFE7E7FFFC
                    FCFAA9A9A93333332323232929292F2F2F181818323232C7C7C7212121E6E6E5
                    FFFFFFC2C2FF4B4BFFC2C2FFFFFFFFE2E2E1363636929293B7B7B8AEAEAF7272
                    732A2A2AC2C2C2FFFFFF242424B9B9B9D3D3D3D7D7D1CDCDD1D6D6D1D6D6D3B7
                    B7AD1616129A9A8FCDCDC0A5A59A4C4C49CFCFC8FFFFFFFFFFFF747474373737
                    2B2B2C2F2F2D37372D30302D28282E15152915152011112419192329293DBEBE
                    C5E3E3FFF7F7FFFFFFFFF1F1F1D6D6D6D0D0D0D1D1D1D0D0D1D4D4D1AFAFD144
                    44D3BDBDDC3737D60000D23C3CDCDFDFFF6161FFD8D8FFFFFFFFFFFFFFFFFFFF
                    FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFE5E5FFE4E4FFC3C3FF4A4AFFC2C2FFDCDC
                    FFD7D7FFF6F6FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFE0
                    E0FF5858FFD6D6FFDDDDFFD6D6FF5858FFE1E1FFFFFFFFFFFFFFFFFFFFFFFFFF
                    FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF6F6FFDBDBFFD2D2FF5F5FFFD2D2FFDBDB
                    FFF6F6FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                    FFFFFFFFFFF8F8FFD8D8FFF8F8FFFFFFFFFFFFFFFFFFFFFFFFFF}
                end
                object Ax1MSftLmtPosGetBtn: TRzBitBtn
                  Left = 204
                  Top = 46
                  Width = 61
                  Height = 24
                  FrameColor = 7617536
                  Caption = 'GET'
                  Color = 15791348
                  HotTrack = True
                  TabOrder = 4
                  OnClick = GetPosBtnClick
                  Glyph.Data = {
                    36030000424D3603000000000000360000002800000010000000100000000100
                    18000000000000030000C30E0000C30E00000000000000000000FFFFFFFFFFFF
                    FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFBFB
                    FBE3E3E3DCDCDCDDDDDDD1D1DBE5E5E6FFFFFFE4DBDBD2CFCFDAD1D1D2CFCFE3
                    D9D9FFFFFFFFFFFFFFFFFFFFFFFFDDDDDD3434341919191A1A1A25251F424040
                    BCBABA3C4E4E2A29291D2F2F2C34343B5151CACDCDFDFAFAFFFFFFFFFFFFDDDD
                    DD353535242424282828B7B5001B15000E393F3CC1C195D2D24BD0D092C1C117
                    9595293535E6DDDDFFFFFFFFFFFFFAFAFAE3E3E3D4D4D4D1D1D1E4DB00242C1C
                    36B4C0A7FFFF6CFFFFADF0F05A64640A3939363B3BCBC8C8FFFFFFFFFFFFFFFF
                    FFE5E5E5404041252525D3D000332E259BD9E56CFFFF96FFFF6AF5F590C0C033
                    BDBD92A2A2433333B2AFAFE6DCDCFFFFFFDFE0DF3D3D33252518D9D100232D22
                    50D0DCA1FFFF68FFFFADF0F05861611144443240400828282731313B5050C3C5
                    C4FAF8F6DBDBE3CFCFDCDCD9003531259ADAE66EFCFC92D5D553D0D093C8C82D
                    B9B981BABA2DC4C48ABFBF109A9B435348D8CDDB4849FF2525FFB5AC00161F15
                    36B9C4B2EFEF5B5959033030192626203535333B3B253A3A2F3737394E4FC8CA
                    C3E1DFF93F40FF2525FF2A2922211E1F1441413BBEBE9BC5C5189797263030C4
                    B1B1D7D3D3DAD0D0D2CECEE3D9D9FFFFFFFBFBFCD9D9E3CFCFDCD3D3DDDFDCDD
                    C4C1C03346462932323B5151CCCFCFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                    FFDEDEDD3E3E33252518FFFFFFFFFFFFFFFFFFE3D9D9D0CDCDE3D9D9FFFFFFFF
                    FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFE5E5E5404041252525FFFFFFFFFFFF
                    FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFAFA
                    FAE3E3E3D4D4D4D1D1D1FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                    FFFFFFFFFFFFFFFFFFFFFFFFFFFFDDDDDD353535242424282828FFFFFFFFFFFF
                    FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFDDDD
                    DD3434341919191A1A1AFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                    FFFFFFFFFFFFFFFFFFFFFFFFFFFFFBFBFBE3E3E3DCDCDCDDDDDD}
                end
                object Ax1MSftLmtPosGoBtn: TRzBitBtn
                  Left = 274
                  Top = 46
                  Width = 61
                  Height = 24
                  FrameColor = 7617536
                  Caption = 'GO'
                  Color = 15791348
                  HotTrack = True
                  TabOrder = 5
                  OnClick = GoBtnClick
                  Glyph.Data = {
                    36030000424D3603000000000000360000002800000010000000100000000100
                    18000000000000030000C30E0000C30E00000000000000000000FFFFFFFFFFFF
                    FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                    FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFE3E3E3E3E3E3FFFFFFFFFFFFFFFFFFFF
                    FFFFFFFFFFFFFFFFFFFFFFFFFFFFE3E3E3E3E3E3FFFFFFFFFFFFFFFFFFCDCDCD
                    333333333333CDCDCDFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFCDCDCD3333
                    33333333CDCDCDFFFFFFC5C5C52B2B2B00000000000029292ABBBBBBD3D3D3D1
                    D1D1D4D4D4D4D4D4BBBBBB2A2A2A0000000000002A2A2AC5C5C51B1B1B171717
                    1717171717152323192A2A282E2E2F2C2C2C2828282D2D2D2929291919191414
                    141717171B1B1B1D1D1D1A1A1AC4C4C5C0C0BFBBBBB5D2D2D8DADAD4D1D1D1C9
                    C9C9ADADADD1D1D1DBDBDBDFDFDFC1C1C1CACACAC6C6C6101010252525E7E7E6
                    FFFFFFC0C0FF4848FFC2C2FFFFFFFFFFFFFFDCDCDCDBDBDBDBDBDBDBDBDBE0E0
                    E0DFDFDF818181242424222222E2E2DCEDEDFF3E3EFF0000FF3B3BFFE7E7FFFC
                    FCFAA9A9A93333332323232929292F2F2F181818323232C7C7C7212121E6E6E5
                    FFFFFFC2C2FF4B4BFFC2C2FFFFFFFFE2E2E1363636929293B7B7B8AEAEAF7272
                    732A2A2AC2C2C2FFFFFF242424B9B9B9D3D3D3D7D7D1CDCDD1D6D6D1D6D6D3B7
                    B7AD1616129A9A8FCDCDC0A5A59A4C4C49CFCFC8FFFFFFFFFFFF747474373737
                    2B2B2C2F2F2D37372D30302D28282E15152915152011112419192329293DBEBE
                    C5E3E3FFF7F7FFFFFFFFF1F1F1D6D6D6D0D0D0D1D1D1D0D0D1D4D4D1AFAFD144
                    44D3BDBDDC3737D60000D23C3CDCDFDFFF6161FFD8D8FFFFFFFFFFFFFFFFFFFF
                    FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFE5E5FFE4E4FFC3C3FF4A4AFFC2C2FFDCDC
                    FFD7D7FFF6F6FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFE0
                    E0FF5858FFD6D6FFDDDDFFD6D6FF5858FFE1E1FFFFFFFFFFFFFFFFFFFFFFFFFF
                    FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF6F6FFDBDBFFD2D2FF5F5FFFD2D2FFDBDB
                    FFF6F6FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                    FFFFFFFFFFF8F8FFD8D8FFF8F8FFFFFFFFFFFFFFFFFFFFFFFFFF}
                end
                object Ax2MSftLmtPosGetBtn: TRzBitBtn
                  Left = 204
                  Top = 76
                  Width = 61
                  Height = 24
                  FrameColor = 7617536
                  Caption = 'GET'
                  Color = 15791348
                  HotTrack = True
                  TabOrder = 7
                  OnClick = GetPosBtnClick
                  Glyph.Data = {
                    36030000424D3603000000000000360000002800000010000000100000000100
                    18000000000000030000C30E0000C30E00000000000000000000FFFFFFFFFFFF
                    FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFBFB
                    FBE3E3E3DCDCDCDDDDDDD1D1DBE5E5E6FFFFFFE4DBDBD2CFCFDAD1D1D2CFCFE3
                    D9D9FFFFFFFFFFFFFFFFFFFFFFFFDDDDDD3434341919191A1A1A25251F424040
                    BCBABA3C4E4E2A29291D2F2F2C34343B5151CACDCDFDFAFAFFFFFFFFFFFFDDDD
                    DD353535242424282828B7B5001B15000E393F3CC1C195D2D24BD0D092C1C117
                    9595293535E6DDDDFFFFFFFFFFFFFAFAFAE3E3E3D4D4D4D1D1D1E4DB00242C1C
                    36B4C0A7FFFF6CFFFFADF0F05A64640A3939363B3BCBC8C8FFFFFFFFFFFFFFFF
                    FFE5E5E5404041252525D3D000332E259BD9E56CFFFF96FFFF6AF5F590C0C033
                    BDBD92A2A2433333B2AFAFE6DCDCFFFFFFDFE0DF3D3D33252518D9D100232D22
                    50D0DCA1FFFF68FFFFADF0F05861611144443240400828282731313B5050C3C5
                    C4FAF8F6DBDBE3CFCFDCDCD9003531259ADAE66EFCFC92D5D553D0D093C8C82D
                    B9B981BABA2DC4C48ABFBF109A9B435348D8CDDB4849FF2525FFB5AC00161F15
                    36B9C4B2EFEF5B5959033030192626203535333B3B253A3A2F3737394E4FC8CA
                    C3E1DFF93F40FF2525FF2A2922211E1F1441413BBEBE9BC5C5189797263030C4
                    B1B1D7D3D3DAD0D0D2CECEE3D9D9FFFFFFFBFBFCD9D9E3CFCFDCD3D3DDDFDCDD
                    C4C1C03346462932323B5151CCCFCFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                    FFDEDEDD3E3E33252518FFFFFFFFFFFFFFFFFFE3D9D9D0CDCDE3D9D9FFFFFFFF
                    FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFE5E5E5404041252525FFFFFFFFFFFF
                    FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFAFA
                    FAE3E3E3D4D4D4D1D1D1FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                    FFFFFFFFFFFFFFFFFFFFFFFFFFFFDDDDDD353535242424282828FFFFFFFFFFFF
                    FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFDDDD
                    DD3434341919191A1A1AFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                    FFFFFFFFFFFFFFFFFFFFFFFFFFFFFBFBFBE3E3E3DCDCDCDDDDDD}
                end
                object Ax2MSftLmtPosGoBtn: TRzBitBtn
                  Left = 274
                  Top = 76
                  Width = 61
                  Height = 24
                  FrameColor = 7617536
                  Caption = 'GO'
                  Color = 15791348
                  HotTrack = True
                  TabOrder = 8
                  OnClick = GoBtnClick
                  Glyph.Data = {
                    36030000424D3603000000000000360000002800000010000000100000000100
                    18000000000000030000C30E0000C30E00000000000000000000FFFFFFFFFFFF
                    FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                    FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFE3E3E3E3E3E3FFFFFFFFFFFFFFFFFFFF
                    FFFFFFFFFFFFFFFFFFFFFFFFFFFFE3E3E3E3E3E3FFFFFFFFFFFFFFFFFFCDCDCD
                    333333333333CDCDCDFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFCDCDCD3333
                    33333333CDCDCDFFFFFFC5C5C52B2B2B00000000000029292ABBBBBBD3D3D3D1
                    D1D1D4D4D4D4D4D4BBBBBB2A2A2A0000000000002A2A2AC5C5C51B1B1B171717
                    1717171717152323192A2A282E2E2F2C2C2C2828282D2D2D2929291919191414
                    141717171B1B1B1D1D1D1A1A1AC4C4C5C0C0BFBBBBB5D2D2D8DADAD4D1D1D1C9
                    C9C9ADADADD1D1D1DBDBDBDFDFDFC1C1C1CACACAC6C6C6101010252525E7E7E6
                    FFFFFFC0C0FF4848FFC2C2FFFFFFFFFFFFFFDCDCDCDBDBDBDBDBDBDBDBDBE0E0
                    E0DFDFDF818181242424222222E2E2DCEDEDFF3E3EFF0000FF3B3BFFE7E7FFFC
                    FCFAA9A9A93333332323232929292F2F2F181818323232C7C7C7212121E6E6E5
                    FFFFFFC2C2FF4B4BFFC2C2FFFFFFFFE2E2E1363636929293B7B7B8AEAEAF7272
                    732A2A2AC2C2C2FFFFFF242424B9B9B9D3D3D3D7D7D1CDCDD1D6D6D1D6D6D3B7
                    B7AD1616129A9A8FCDCDC0A5A59A4C4C49CFCFC8FFFFFFFFFFFF747474373737
                    2B2B2C2F2F2D37372D30302D28282E15152915152011112419192329293DBEBE
                    C5E3E3FFF7F7FFFFFFFFF1F1F1D6D6D6D0D0D0D1D1D1D0D0D1D4D4D1AFAFD144
                    44D3BDBDDC3737D60000D23C3CDCDFDFFF6161FFD8D8FFFFFFFFFFFFFFFFFFFF
                    FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFE5E5FFE4E4FFC3C3FF4A4AFFC2C2FFDCDC
                    FFD7D7FFF6F6FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFE0
                    E0FF5858FFD6D6FFDDDDFFD6D6FF5858FFE1E1FFFFFFFFFFFFFFFFFFFFFFFFFF
                    FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF6F6FFDBDBFFD2D2FF5F5FFFD2D2FFDBDB
                    FFF6F6FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                    FFFFFFFFFFF8F8FFD8D8FFF8F8FFFFFFFFFFFFFFFFFFFFFFFFFF}
                end
                object Ax3MSftLmtPosGetBtn: TRzBitBtn
                  Left = 204
                  Top = 106
                  Width = 61
                  Height = 24
                  FrameColor = 7617536
                  Caption = 'GET'
                  Color = 15791348
                  HotTrack = True
                  TabOrder = 10
                  OnClick = GetPosBtnClick
                  Glyph.Data = {
                    36030000424D3603000000000000360000002800000010000000100000000100
                    18000000000000030000C30E0000C30E00000000000000000000FFFFFFFFFFFF
                    FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFBFB
                    FBE3E3E3DCDCDCDDDDDDD1D1DBE5E5E6FFFFFFE4DBDBD2CFCFDAD1D1D2CFCFE3
                    D9D9FFFFFFFFFFFFFFFFFFFFFFFFDDDDDD3434341919191A1A1A25251F424040
                    BCBABA3C4E4E2A29291D2F2F2C34343B5151CACDCDFDFAFAFFFFFFFFFFFFDDDD
                    DD353535242424282828B7B5001B15000E393F3CC1C195D2D24BD0D092C1C117
                    9595293535E6DDDDFFFFFFFFFFFFFAFAFAE3E3E3D4D4D4D1D1D1E4DB00242C1C
                    36B4C0A7FFFF6CFFFFADF0F05A64640A3939363B3BCBC8C8FFFFFFFFFFFFFFFF
                    FFE5E5E5404041252525D3D000332E259BD9E56CFFFF96FFFF6AF5F590C0C033
                    BDBD92A2A2433333B2AFAFE6DCDCFFFFFFDFE0DF3D3D33252518D9D100232D22
                    50D0DCA1FFFF68FFFFADF0F05861611144443240400828282731313B5050C3C5
                    C4FAF8F6DBDBE3CFCFDCDCD9003531259ADAE66EFCFC92D5D553D0D093C8C82D
                    B9B981BABA2DC4C48ABFBF109A9B435348D8CDDB4849FF2525FFB5AC00161F15
                    36B9C4B2EFEF5B5959033030192626203535333B3B253A3A2F3737394E4FC8CA
                    C3E1DFF93F40FF2525FF2A2922211E1F1441413BBEBE9BC5C5189797263030C4
                    B1B1D7D3D3DAD0D0D2CECEE3D9D9FFFFFFFBFBFCD9D9E3CFCFDCD3D3DDDFDCDD
                    C4C1C03346462932323B5151CCCFCFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                    FFDEDEDD3E3E33252518FFFFFFFFFFFFFFFFFFE3D9D9D0CDCDE3D9D9FFFFFFFF
                    FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFE5E5E5404041252525FFFFFFFFFFFF
                    FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFAFA
                    FAE3E3E3D4D4D4D1D1D1FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                    FFFFFFFFFFFFFFFFFFFFFFFFFFFFDDDDDD353535242424282828FFFFFFFFFFFF
                    FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFDDDD
                    DD3434341919191A1A1AFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                    FFFFFFFFFFFFFFFFFFFFFFFFFFFFFBFBFBE3E3E3DCDCDCDDDDDD}
                end
                object Ax3MSftLmtPosGoBtn: TRzBitBtn
                  Left = 274
                  Top = 106
                  Width = 61
                  Height = 24
                  FrameColor = 7617536
                  Caption = 'GO'
                  Color = 15791348
                  HotTrack = True
                  TabOrder = 11
                  OnClick = GoBtnClick
                  Glyph.Data = {
                    36030000424D3603000000000000360000002800000010000000100000000100
                    18000000000000030000C30E0000C30E00000000000000000000FFFFFFFFFFFF
                    FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                    FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFE3E3E3E3E3E3FFFFFFFFFFFFFFFFFFFF
                    FFFFFFFFFFFFFFFFFFFFFFFFFFFFE3E3E3E3E3E3FFFFFFFFFFFFFFFFFFCDCDCD
                    333333333333CDCDCDFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFCDCDCD3333
                    33333333CDCDCDFFFFFFC5C5C52B2B2B00000000000029292ABBBBBBD3D3D3D1
                    D1D1D4D4D4D4D4D4BBBBBB2A2A2A0000000000002A2A2AC5C5C51B1B1B171717
                    1717171717152323192A2A282E2E2F2C2C2C2828282D2D2D2929291919191414
                    141717171B1B1B1D1D1D1A1A1AC4C4C5C0C0BFBBBBB5D2D2D8DADAD4D1D1D1C9
                    C9C9ADADADD1D1D1DBDBDBDFDFDFC1C1C1CACACAC6C6C6101010252525E7E7E6
                    FFFFFFC0C0FF4848FFC2C2FFFFFFFFFFFFFFDCDCDCDBDBDBDBDBDBDBDBDBE0E0
                    E0DFDFDF818181242424222222E2E2DCEDEDFF3E3EFF0000FF3B3BFFE7E7FFFC
                    FCFAA9A9A93333332323232929292F2F2F181818323232C7C7C7212121E6E6E5
                    FFFFFFC2C2FF4B4BFFC2C2FFFFFFFFE2E2E1363636929293B7B7B8AEAEAF7272
                    732A2A2AC2C2C2FFFFFF242424B9B9B9D3D3D3D7D7D1CDCDD1D6D6D1D6D6D3B7
                    B7AD1616129A9A8FCDCDC0A5A59A4C4C49CFCFC8FFFFFFFFFFFF747474373737
                    2B2B2C2F2F2D37372D30302D28282E15152915152011112419192329293DBEBE
                    C5E3E3FFF7F7FFFFFFFFF1F1F1D6D6D6D0D0D0D1D1D1D0D0D1D4D4D1AFAFD144
                    44D3BDBDDC3737D60000D23C3CDCDFDFFF6161FFD8D8FFFFFFFFFFFFFFFFFFFF
                    FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFE5E5FFE4E4FFC3C3FF4A4AFFC2C2FFDCDC
                    FFD7D7FFF6F6FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFE0
                    E0FF5858FFD6D6FFDDDDFFD6D6FF5858FFE1E1FFFFFFFFFFFFFFFFFFFFFFFFFF
                    FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF6F6FFDBDBFFD2D2FF5F5FFFD2D2FFDBDB
                    FFF6F6FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                    FFFFFFFFFFF8F8FFD8D8FFF8F8FFFFFFFFFFFFFFFFFFFFFFFFFF}
                end
                object Ax4MSftLmtPosEdit: TEdit
                  Left = 126
                  Top = 136
                  Width = 64
                  Height = 24
                  Color = 16777088
                  Font.Charset = ANSI_CHARSET
                  Font.Color = clBlack
                  Font.Height = -13
                  Font.Name = 'Tahoma'
                  Font.Style = []
                  ImeName = '???(??)'
                  MaxLength = 7
                  ParentFont = False
                  TabOrder = 12
                  Text = '0.000'
                  OnChange = DataChange
                end
                object Ax4MSftLmtPosGetBtn: TRzBitBtn
                  Left = 204
                  Top = 136
                  Width = 61
                  Height = 24
                  FrameColor = 7617536
                  Caption = 'GET'
                  Color = 15791348
                  HotTrack = True
                  TabOrder = 13
                  OnClick = GetPosBtnClick
                  Glyph.Data = {
                    36030000424D3603000000000000360000002800000010000000100000000100
                    18000000000000030000C30E0000C30E00000000000000000000FFFFFFFFFFFF
                    FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFBFB
                    FBE3E3E3DCDCDCDDDDDDD1D1DBE5E5E6FFFFFFE4DBDBD2CFCFDAD1D1D2CFCFE3
                    D9D9FFFFFFFFFFFFFFFFFFFFFFFFDDDDDD3434341919191A1A1A25251F424040
                    BCBABA3C4E4E2A29291D2F2F2C34343B5151CACDCDFDFAFAFFFFFFFFFFFFDDDD
                    DD353535242424282828B7B5001B15000E393F3CC1C195D2D24BD0D092C1C117
                    9595293535E6DDDDFFFFFFFFFFFFFAFAFAE3E3E3D4D4D4D1D1D1E4DB00242C1C
                    36B4C0A7FFFF6CFFFFADF0F05A64640A3939363B3BCBC8C8FFFFFFFFFFFFFFFF
                    FFE5E5E5404041252525D3D000332E259BD9E56CFFFF96FFFF6AF5F590C0C033
                    BDBD92A2A2433333B2AFAFE6DCDCFFFFFFDFE0DF3D3D33252518D9D100232D22
                    50D0DCA1FFFF68FFFFADF0F05861611144443240400828282731313B5050C3C5
                    C4FAF8F6DBDBE3CFCFDCDCD9003531259ADAE66EFCFC92D5D553D0D093C8C82D
                    B9B981BABA2DC4C48ABFBF109A9B435348D8CDDB4849FF2525FFB5AC00161F15
                    36B9C4B2EFEF5B5959033030192626203535333B3B253A3A2F3737394E4FC8CA
                    C3E1DFF93F40FF2525FF2A2922211E1F1441413BBEBE9BC5C5189797263030C4
                    B1B1D7D3D3DAD0D0D2CECEE3D9D9FFFFFFFBFBFCD9D9E3CFCFDCD3D3DDDFDCDD
                    C4C1C03346462932323B5151CCCFCFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                    FFDEDEDD3E3E33252518FFFFFFFFFFFFFFFFFFE3D9D9D0CDCDE3D9D9FFFFFFFF
                    FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFE5E5E5404041252525FFFFFFFFFFFF
                    FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFAFA
                    FAE3E3E3D4D4D4D1D1D1FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                    FFFFFFFFFFFFFFFFFFFFFFFFFFFFDDDDDD353535242424282828FFFFFFFFFFFF
                    FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFDDDD
                    DD3434341919191A1A1AFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                    FFFFFFFFFFFFFFFFFFFFFFFFFFFFFBFBFBE3E3E3DCDCDCDDDDDD}
                end
                object Ax4MSftLmtPosGoBtn: TRzBitBtn
                  Left = 274
                  Top = 136
                  Width = 61
                  Height = 24
                  FrameColor = 7617536
                  Caption = 'GO'
                  Color = 15791348
                  HotTrack = True
                  TabOrder = 14
                  OnClick = GoBtnClick
                  Glyph.Data = {
                    36030000424D3603000000000000360000002800000010000000100000000100
                    18000000000000030000C30E0000C30E00000000000000000000FFFFFFFFFFFF
                    FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                    FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFE3E3E3E3E3E3FFFFFFFFFFFFFFFFFFFF
                    FFFFFFFFFFFFFFFFFFFFFFFFFFFFE3E3E3E3E3E3FFFFFFFFFFFFFFFFFFCDCDCD
                    333333333333CDCDCDFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFCDCDCD3333
                    33333333CDCDCDFFFFFFC5C5C52B2B2B00000000000029292ABBBBBBD3D3D3D1
                    D1D1D4D4D4D4D4D4BBBBBB2A2A2A0000000000002A2A2AC5C5C51B1B1B171717
                    1717171717152323192A2A282E2E2F2C2C2C2828282D2D2D2929291919191414
                    141717171B1B1B1D1D1D1A1A1AC4C4C5C0C0BFBBBBB5D2D2D8DADAD4D1D1D1C9
                    C9C9ADADADD1D1D1DBDBDBDFDFDFC1C1C1CACACAC6C6C6101010252525E7E7E6
                    FFFFFFC0C0FF4848FFC2C2FFFFFFFFFFFFFFDCDCDCDBDBDBDBDBDBDBDBDBE0E0
                    E0DFDFDF818181242424222222E2E2DCEDEDFF3E3EFF0000FF3B3BFFE7E7FFFC
                    FCFAA9A9A93333332323232929292F2F2F181818323232C7C7C7212121E6E6E5
                    FFFFFFC2C2FF4B4BFFC2C2FFFFFFFFE2E2E1363636929293B7B7B8AEAEAF7272
                    732A2A2AC2C2C2FFFFFF242424B9B9B9D3D3D3D7D7D1CDCDD1D6D6D1D6D6D3B7
                    B7AD1616129A9A8FCDCDC0A5A59A4C4C49CFCFC8FFFFFFFFFFFF747474373737
                    2B2B2C2F2F2D37372D30302D28282E15152915152011112419192329293DBEBE
                    C5E3E3FFF7F7FFFFFFFFF1F1F1D6D6D6D0D0D0D1D1D1D0D0D1D4D4D1AFAFD144
                    44D3BDBDDC3737D60000D23C3CDCDFDFFF6161FFD8D8FFFFFFFFFFFFFFFFFFFF
                    FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFE5E5FFE4E4FFC3C3FF4A4AFFC2C2FFDCDC
                    FFD7D7FFF6F6FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFE0
                    E0FF5858FFD6D6FFDDDDFFD6D6FF5858FFE1E1FFFFFFFFFFFFFFFFFFFFFFFFFF
                    FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF6F6FFDBDBFFD2D2FF5F5FFFD2D2FFDBDB
                    FFF6F6FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                    FFFFFFFFFFF8F8FFD8D8FFF8F8FFFFFFFFFFFFFFFFFFFFFFFFFF}
                end
              end
              object GroupBox46: TGroupBox
                Left = 376
                Top = 8
                Width = 350
                Height = 169
                Caption = '(+) Software Limit: '
                TabOrder = 1
                object Label5: TLabel
                  Left = 16
                  Top = 50
                  Width = 59
                  Height = 13
                  Caption = 'Inspection Y'
                end
                object Label9: TLabel
                  Left = 16
                  Top = 21
                  Width = 59
                  Height = 13
                  Caption = 'Inspection X'
                end
                object Label11: TLabel
                  Left = 16
                  Top = 110
                  Width = 43
                  Height = 13
                  Caption = 'Unloader'
                end
                object Label12: TLabel
                  Left = 16
                  Top = 80
                  Width = 50
                  Height = 13
                  Caption = 'Distributer'
                end
                object Label19: TLabel
                  Left = 16
                  Top = 140
                  Width = 52
                  Height = 13
                  Caption = 'Unloader Z'
                end
                object Ax0PSftLmtPosEdit: TEdit
                  Left = 126
                  Top = 15
                  Width = 64
                  Height = 24
                  Color = 16777088
                  Font.Charset = ANSI_CHARSET
                  Font.Color = clBlack
                  Font.Height = -13
                  Font.Name = 'Tahoma'
                  Font.Style = []
                  ImeName = '???(??)'
                  MaxLength = 7
                  ParentFont = False
                  TabOrder = 0
                  Text = '0.000'
                  OnChange = DataChange
                end
                object Ax1PSftLmtPosEdit: TEdit
                  Left = 126
                  Top = 44
                  Width = 64
                  Height = 24
                  Color = 16777088
                  Font.Charset = ANSI_CHARSET
                  Font.Color = clBlack
                  Font.Height = -13
                  Font.Name = 'Tahoma'
                  Font.Style = []
                  ImeName = '???(??)'
                  MaxLength = 7
                  ParentFont = False
                  TabOrder = 3
                  Text = '0.000'
                  OnChange = DataChange
                end
                object Ax3PSftLmtPosEdit: TEdit
                  Left = 126
                  Top = 104
                  Width = 64
                  Height = 24
                  Color = 16777088
                  Font.Charset = ANSI_CHARSET
                  Font.Color = clBlack
                  Font.Height = -13
                  Font.Name = 'Tahoma'
                  Font.Style = []
                  ImeName = '???(??)'
                  MaxLength = 7
                  ParentFont = False
                  TabOrder = 9
                  Text = '0.000'
                  OnChange = DataChange
                end
                object Ax2PSftLmtPosEdit: TEdit
                  Left = 126
                  Top = 74
                  Width = 64
                  Height = 24
                  Color = 16777088
                  Font.Charset = ANSI_CHARSET
                  Font.Color = clBlack
                  Font.Height = -13
                  Font.Name = 'Tahoma'
                  Font.Style = []
                  ImeName = '???(??)'
                  MaxLength = 7
                  ParentFont = False
                  TabOrder = 6
                  Text = '0.000'
                  OnChange = DataChange
                end
                object Ax0PSftLmtPosGetBtn: TRzBitBtn
                  Left = 204
                  Top = 15
                  Width = 61
                  Height = 24
                  FrameColor = 7617536
                  Caption = 'GET'
                  Color = 15791348
                  HotTrack = True
                  TabOrder = 1
                  OnClick = GetPosBtnClick
                  Glyph.Data = {
                    36030000424D3603000000000000360000002800000010000000100000000100
                    18000000000000030000C30E0000C30E00000000000000000000FFFFFFFFFFFF
                    FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFBFB
                    FBE3E3E3DCDCDCDDDDDDD1D1DBE5E5E6FFFFFFE4DBDBD2CFCFDAD1D1D2CFCFE3
                    D9D9FFFFFFFFFFFFFFFFFFFFFFFFDDDDDD3434341919191A1A1A25251F424040
                    BCBABA3C4E4E2A29291D2F2F2C34343B5151CACDCDFDFAFAFFFFFFFFFFFFDDDD
                    DD353535242424282828B7B5001B15000E393F3CC1C195D2D24BD0D092C1C117
                    9595293535E6DDDDFFFFFFFFFFFFFAFAFAE3E3E3D4D4D4D1D1D1E4DB00242C1C
                    36B4C0A7FFFF6CFFFFADF0F05A64640A3939363B3BCBC8C8FFFFFFFFFFFFFFFF
                    FFE5E5E5404041252525D3D000332E259BD9E56CFFFF96FFFF6AF5F590C0C033
                    BDBD92A2A2433333B2AFAFE6DCDCFFFFFFDFE0DF3D3D33252518D9D100232D22
                    50D0DCA1FFFF68FFFFADF0F05861611144443240400828282731313B5050C3C5
                    C4FAF8F6DBDBE3CFCFDCDCD9003531259ADAE66EFCFC92D5D553D0D093C8C82D
                    B9B981BABA2DC4C48ABFBF109A9B435348D8CDDB4849FF2525FFB5AC00161F15
                    36B9C4B2EFEF5B5959033030192626203535333B3B253A3A2F3737394E4FC8CA
                    C3E1DFF93F40FF2525FF2A2922211E1F1441413BBEBE9BC5C5189797263030C4
                    B1B1D7D3D3DAD0D0D2CECEE3D9D9FFFFFFFBFBFCD9D9E3CFCFDCD3D3DDDFDCDD
                    C4C1C03346462932323B5151CCCFCFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                    FFDEDEDD3E3E33252518FFFFFFFFFFFFFFFFFFE3D9D9D0CDCDE3D9D9FFFFFFFF
                    FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFE5E5E5404041252525FFFFFFFFFFFF
                    FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFAFA
                    FAE3E3E3D4D4D4D1D1D1FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                    FFFFFFFFFFFFFFFFFFFFFFFFFFFFDDDDDD353535242424282828FFFFFFFFFFFF
                    FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFDDDD
                    DD3434341919191A1A1AFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                    FFFFFFFFFFFFFFFFFFFFFFFFFFFFFBFBFBE3E3E3DCDCDCDDDDDD}
                end
                object Ax0PSftLmtPosGoBtn: TRzBitBtn
                  Left = 274
                  Top = 15
                  Width = 61
                  Height = 24
                  FrameColor = 7617536
                  Caption = 'GO'
                  Color = 15791348
                  HotTrack = True
                  TabOrder = 2
                  OnClick = GoBtnClick
                  Glyph.Data = {
                    36030000424D3603000000000000360000002800000010000000100000000100
                    18000000000000030000C30E0000C30E00000000000000000000FFFFFFFFFFFF
                    FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                    FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFE3E3E3E3E3E3FFFFFFFFFFFFFFFFFFFF
                    FFFFFFFFFFFFFFFFFFFFFFFFFFFFE3E3E3E3E3E3FFFFFFFFFFFFFFFFFFCDCDCD
                    333333333333CDCDCDFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFCDCDCD3333
                    33333333CDCDCDFFFFFFC5C5C52B2B2B00000000000029292ABBBBBBD3D3D3D1
                    D1D1D4D4D4D4D4D4BBBBBB2A2A2A0000000000002A2A2AC5C5C51B1B1B171717
                    1717171717152323192A2A282E2E2F2C2C2C2828282D2D2D2929291919191414
                    141717171B1B1B1D1D1D1A1A1AC4C4C5C0C0BFBBBBB5D2D2D8DADAD4D1D1D1C9
                    C9C9ADADADD1D1D1DBDBDBDFDFDFC1C1C1CACACAC6C6C6101010252525E7E7E6
                    FFFFFFC0C0FF4848FFC2C2FFFFFFFFFFFFFFDCDCDCDBDBDBDBDBDBDBDBDBE0E0
                    E0DFDFDF818181242424222222E2E2DCEDEDFF3E3EFF0000FF3B3BFFE7E7FFFC
                    FCFAA9A9A93333332323232929292F2F2F181818323232C7C7C7212121E6E6E5
                    FFFFFFC2C2FF4B4BFFC2C2FFFFFFFFE2E2E1363636929293B7B7B8AEAEAF7272
                    732A2A2AC2C2C2FFFFFF242424B9B9B9D3D3D3D7D7D1CDCDD1D6D6D1D6D6D3B7
                    B7AD1616129A9A8FCDCDC0A5A59A4C4C49CFCFC8FFFFFFFFFFFF747474373737
                    2B2B2C2F2F2D37372D30302D28282E15152915152011112419192329293DBEBE
                    C5E3E3FFF7F7FFFFFFFFF1F1F1D6D6D6D0D0D0D1D1D1D0D0D1D4D4D1AFAFD144
                    44D3BDBDDC3737D60000D23C3CDCDFDFFF6161FFD8D8FFFFFFFFFFFFFFFFFFFF
                    FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFE5E5FFE4E4FFC3C3FF4A4AFFC2C2FFDCDC
                    FFD7D7FFF6F6FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFE0
                    E0FF5858FFD6D6FFDDDDFFD6D6FF5858FFE1E1FFFFFFFFFFFFFFFFFFFFFFFFFF
                    FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF6F6FFDBDBFFD2D2FF5F5FFFD2D2FFDBDB
                    FFF6F6FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                    FFFFFFFFFFF8F8FFD8D8FFF8F8FFFFFFFFFFFFFFFFFFFFFFFFFF}
                end
                object Ax1PSftLmtPosGetBtn: TRzBitBtn
                  Left = 204
                  Top = 44
                  Width = 61
                  Height = 24
                  FrameColor = 7617536
                  Caption = 'GET'
                  Color = 15791348
                  HotTrack = True
                  TabOrder = 4
                  OnClick = GetPosBtnClick
                  Glyph.Data = {
                    36030000424D3603000000000000360000002800000010000000100000000100
                    18000000000000030000C30E0000C30E00000000000000000000FFFFFFFFFFFF
                    FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFBFB
                    FBE3E3E3DCDCDCDDDDDDD1D1DBE5E5E6FFFFFFE4DBDBD2CFCFDAD1D1D2CFCFE3
                    D9D9FFFFFFFFFFFFFFFFFFFFFFFFDDDDDD3434341919191A1A1A25251F424040
                    BCBABA3C4E4E2A29291D2F2F2C34343B5151CACDCDFDFAFAFFFFFFFFFFFFDDDD
                    DD353535242424282828B7B5001B15000E393F3CC1C195D2D24BD0D092C1C117
                    9595293535E6DDDDFFFFFFFFFFFFFAFAFAE3E3E3D4D4D4D1D1D1E4DB00242C1C
                    36B4C0A7FFFF6CFFFFADF0F05A64640A3939363B3BCBC8C8FFFFFFFFFFFFFFFF
                    FFE5E5E5404041252525D3D000332E259BD9E56CFFFF96FFFF6AF5F590C0C033
                    BDBD92A2A2433333B2AFAFE6DCDCFFFFFFDFE0DF3D3D33252518D9D100232D22
                    50D0DCA1FFFF68FFFFADF0F05861611144443240400828282731313B5050C3C5
                    C4FAF8F6DBDBE3CFCFDCDCD9003531259ADAE66EFCFC92D5D553D0D093C8C82D
                    B9B981BABA2DC4C48ABFBF109A9B435348D8CDDB4849FF2525FFB5AC00161F15
                    36B9C4B2EFEF5B5959033030192626203535333B3B253A3A2F3737394E4FC8CA
                    C3E1DFF93F40FF2525FF2A2922211E1F1441413BBEBE9BC5C5189797263030C4
                    B1B1D7D3D3DAD0D0D2CECEE3D9D9FFFFFFFBFBFCD9D9E3CFCFDCD3D3DDDFDCDD
                    C4C1C03346462932323B5151CCCFCFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                    FFDEDEDD3E3E33252518FFFFFFFFFFFFFFFFFFE3D9D9D0CDCDE3D9D9FFFFFFFF
                    FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFE5E5E5404041252525FFFFFFFFFFFF
                    FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFAFA
                    FAE3E3E3D4D4D4D1D1D1FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                    FFFFFFFFFFFFFFFFFFFFFFFFFFFFDDDDDD353535242424282828FFFFFFFFFFFF
                    FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFDDDD
                    DD3434341919191A1A1AFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                    FFFFFFFFFFFFFFFFFFFFFFFFFFFFFBFBFBE3E3E3DCDCDCDDDDDD}
                end
                object Ax1PSftLmtPosGoBtn: TRzBitBtn
                  Left = 274
                  Top = 44
                  Width = 61
                  Height = 24
                  FrameColor = 7617536
                  Caption = 'GO'
                  Color = 15791348
                  HotTrack = True
                  TabOrder = 5
                  OnClick = GoBtnClick
                  Glyph.Data = {
                    36030000424D3603000000000000360000002800000010000000100000000100
                    18000000000000030000C30E0000C30E00000000000000000000FFFFFFFFFFFF
                    FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                    FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFE3E3E3E3E3E3FFFFFFFFFFFFFFFFFFFF
                    FFFFFFFFFFFFFFFFFFFFFFFFFFFFE3E3E3E3E3E3FFFFFFFFFFFFFFFFFFCDCDCD
                    333333333333CDCDCDFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFCDCDCD3333
                    33333333CDCDCDFFFFFFC5C5C52B2B2B00000000000029292ABBBBBBD3D3D3D1
                    D1D1D4D4D4D4D4D4BBBBBB2A2A2A0000000000002A2A2AC5C5C51B1B1B171717
                    1717171717152323192A2A282E2E2F2C2C2C2828282D2D2D2929291919191414
                    141717171B1B1B1D1D1D1A1A1AC4C4C5C0C0BFBBBBB5D2D2D8DADAD4D1D1D1C9
                    C9C9ADADADD1D1D1DBDBDBDFDFDFC1C1C1CACACAC6C6C6101010252525E7E7E6
                    FFFFFFC0C0FF4848FFC2C2FFFFFFFFFFFFFFDCDCDCDBDBDBDBDBDBDBDBDBE0E0
                    E0DFDFDF818181242424222222E2E2DCEDEDFF3E3EFF0000FF3B3BFFE7E7FFFC
                    FCFAA9A9A93333332323232929292F2F2F181818323232C7C7C7212121E6E6E5
                    FFFFFFC2C2FF4B4BFFC2C2FFFFFFFFE2E2E1363636929293B7B7B8AEAEAF7272
                    732A2A2AC2C2C2FFFFFF242424B9B9B9D3D3D3D7D7D1CDCDD1D6D6D1D6D6D3B7
                    B7AD1616129A9A8FCDCDC0A5A59A4C4C49CFCFC8FFFFFFFFFFFF747474373737
                    2B2B2C2F2F2D37372D30302D28282E15152915152011112419192329293DBEBE
                    C5E3E3FFF7F7FFFFFFFFF1F1F1D6D6D6D0D0D0D1D1D1D0D0D1D4D4D1AFAFD144
                    44D3BDBDDC3737D60000D23C3CDCDFDFFF6161FFD8D8FFFFFFFFFFFFFFFFFFFF
                    FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFE5E5FFE4E4FFC3C3FF4A4AFFC2C2FFDCDC
                    FFD7D7FFF6F6FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFE0
                    E0FF5858FFD6D6FFDDDDFFD6D6FF5858FFE1E1FFFFFFFFFFFFFFFFFFFFFFFFFF
                    FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF6F6FFDBDBFFD2D2FF5F5FFFD2D2FFDBDB
                    FFF6F6FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                    FFFFFFFFFFF8F8FFD8D8FFF8F8FFFFFFFFFFFFFFFFFFFFFFFFFF}
                end
                object Ax2PSftLmtPosGetBtn: TRzBitBtn
                  Left = 204
                  Top = 74
                  Width = 61
                  Height = 24
                  FrameColor = 7617536
                  Caption = 'GET'
                  Color = 15791348
                  HotTrack = True
                  TabOrder = 7
                  OnClick = GetPosBtnClick
                  Glyph.Data = {
                    36030000424D3603000000000000360000002800000010000000100000000100
                    18000000000000030000C30E0000C30E00000000000000000000FFFFFFFFFFFF
                    FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFBFB
                    FBE3E3E3DCDCDCDDDDDDD1D1DBE5E5E6FFFFFFE4DBDBD2CFCFDAD1D1D2CFCFE3
                    D9D9FFFFFFFFFFFFFFFFFFFFFFFFDDDDDD3434341919191A1A1A25251F424040
                    BCBABA3C4E4E2A29291D2F2F2C34343B5151CACDCDFDFAFAFFFFFFFFFFFFDDDD
                    DD353535242424282828B7B5001B15000E393F3CC1C195D2D24BD0D092C1C117
                    9595293535E6DDDDFFFFFFFFFFFFFAFAFAE3E3E3D4D4D4D1D1D1E4DB00242C1C
                    36B4C0A7FFFF6CFFFFADF0F05A64640A3939363B3BCBC8C8FFFFFFFFFFFFFFFF
                    FFE5E5E5404041252525D3D000332E259BD9E56CFFFF96FFFF6AF5F590C0C033
                    BDBD92A2A2433333B2AFAFE6DCDCFFFFFFDFE0DF3D3D33252518D9D100232D22
                    50D0DCA1FFFF68FFFFADF0F05861611144443240400828282731313B5050C3C5
                    C4FAF8F6DBDBE3CFCFDCDCD9003531259ADAE66EFCFC92D5D553D0D093C8C82D
                    B9B981BABA2DC4C48ABFBF109A9B435348D8CDDB4849FF2525FFB5AC00161F15
                    36B9C4B2EFEF5B5959033030192626203535333B3B253A3A2F3737394E4FC8CA
                    C3E1DFF93F40FF2525FF2A2922211E1F1441413BBEBE9BC5C5189797263030C4
                    B1B1D7D3D3DAD0D0D2CECEE3D9D9FFFFFFFBFBFCD9D9E3CFCFDCD3D3DDDFDCDD
                    C4C1C03346462932323B5151CCCFCFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                    FFDEDEDD3E3E33252518FFFFFFFFFFFFFFFFFFE3D9D9D0CDCDE3D9D9FFFFFFFF
                    FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFE5E5E5404041252525FFFFFFFFFFFF
                    FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFAFA
                    FAE3E3E3D4D4D4D1D1D1FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                    FFFFFFFFFFFFFFFFFFFFFFFFFFFFDDDDDD353535242424282828FFFFFFFFFFFF
                    FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFDDDD
                    DD3434341919191A1A1AFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                    FFFFFFFFFFFFFFFFFFFFFFFFFFFFFBFBFBE3E3E3DCDCDCDDDDDD}
                end
                object Ax2PSftLmtPosGoBtn: TRzBitBtn
                  Left = 274
                  Top = 74
                  Width = 61
                  Height = 24
                  FrameColor = 7617536
                  Caption = 'GO'
                  Color = 15791348
                  HotTrack = True
                  TabOrder = 8
                  OnClick = GoBtnClick
                  Glyph.Data = {
                    36030000424D3603000000000000360000002800000010000000100000000100
                    18000000000000030000C30E0000C30E00000000000000000000FFFFFFFFFFFF
                    FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                    FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFE3E3E3E3E3E3FFFFFFFFFFFFFFFFFFFF
                    FFFFFFFFFFFFFFFFFFFFFFFFFFFFE3E3E3E3E3E3FFFFFFFFFFFFFFFFFFCDCDCD
                    333333333333CDCDCDFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFCDCDCD3333
                    33333333CDCDCDFFFFFFC5C5C52B2B2B00000000000029292ABBBBBBD3D3D3D1
                    D1D1D4D4D4D4D4D4BBBBBB2A2A2A0000000000002A2A2AC5C5C51B1B1B171717
                    1717171717152323192A2A282E2E2F2C2C2C2828282D2D2D2929291919191414
                    141717171B1B1B1D1D1D1A1A1AC4C4C5C0C0BFBBBBB5D2D2D8DADAD4D1D1D1C9
                    C9C9ADADADD1D1D1DBDBDBDFDFDFC1C1C1CACACAC6C6C6101010252525E7E7E6
                    FFFFFFC0C0FF4848FFC2C2FFFFFFFFFFFFFFDCDCDCDBDBDBDBDBDBDBDBDBE0E0
                    E0DFDFDF818181242424222222E2E2DCEDEDFF3E3EFF0000FF3B3BFFE7E7FFFC
                    FCFAA9A9A93333332323232929292F2F2F181818323232C7C7C7212121E6E6E5
                    FFFFFFC2C2FF4B4BFFC2C2FFFFFFFFE2E2E1363636929293B7B7B8AEAEAF7272
                    732A2A2AC2C2C2FFFFFF242424B9B9B9D3D3D3D7D7D1CDCDD1D6D6D1D6D6D3B7
                    B7AD1616129A9A8FCDCDC0A5A59A4C4C49CFCFC8FFFFFFFFFFFF747474373737
                    2B2B2C2F2F2D37372D30302D28282E15152915152011112419192329293DBEBE
                    C5E3E3FFF7F7FFFFFFFFF1F1F1D6D6D6D0D0D0D1D1D1D0D0D1D4D4D1AFAFD144
                    44D3BDBDDC3737D60000D23C3CDCDFDFFF6161FFD8D8FFFFFFFFFFFFFFFFFFFF
                    FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFE5E5FFE4E4FFC3C3FF4A4AFFC2C2FFDCDC
                    FFD7D7FFF6F6FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFE0
                    E0FF5858FFD6D6FFDDDDFFD6D6FF5858FFE1E1FFFFFFFFFFFFFFFFFFFFFFFFFF
                    FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF6F6FFDBDBFFD2D2FF5F5FFFD2D2FFDBDB
                    FFF6F6FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                    FFFFFFFFFFF8F8FFD8D8FFF8F8FFFFFFFFFFFFFFFFFFFFFFFFFF}
                end
                object Ax3PSftLmtPosGetBtn: TRzBitBtn
                  Left = 204
                  Top = 104
                  Width = 61
                  Height = 24
                  FrameColor = 7617536
                  Caption = 'GET'
                  Color = 15791348
                  HotTrack = True
                  TabOrder = 10
                  OnClick = GetPosBtnClick
                  Glyph.Data = {
                    36030000424D3603000000000000360000002800000010000000100000000100
                    18000000000000030000C30E0000C30E00000000000000000000FFFFFFFFFFFF
                    FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFBFB
                    FBE3E3E3DCDCDCDDDDDDD1D1DBE5E5E6FFFFFFE4DBDBD2CFCFDAD1D1D2CFCFE3
                    D9D9FFFFFFFFFFFFFFFFFFFFFFFFDDDDDD3434341919191A1A1A25251F424040
                    BCBABA3C4E4E2A29291D2F2F2C34343B5151CACDCDFDFAFAFFFFFFFFFFFFDDDD
                    DD353535242424282828B7B5001B15000E393F3CC1C195D2D24BD0D092C1C117
                    9595293535E6DDDDFFFFFFFFFFFFFAFAFAE3E3E3D4D4D4D1D1D1E4DB00242C1C
                    36B4C0A7FFFF6CFFFFADF0F05A64640A3939363B3BCBC8C8FFFFFFFFFFFFFFFF
                    FFE5E5E5404041252525D3D000332E259BD9E56CFFFF96FFFF6AF5F590C0C033
                    BDBD92A2A2433333B2AFAFE6DCDCFFFFFFDFE0DF3D3D33252518D9D100232D22
                    50D0DCA1FFFF68FFFFADF0F05861611144443240400828282731313B5050C3C5
                    C4FAF8F6DBDBE3CFCFDCDCD9003531259ADAE66EFCFC92D5D553D0D093C8C82D
                    B9B981BABA2DC4C48ABFBF109A9B435348D8CDDB4849FF2525FFB5AC00161F15
                    36B9C4B2EFEF5B5959033030192626203535333B3B253A3A2F3737394E4FC8CA
                    C3E1DFF93F40FF2525FF2A2922211E1F1441413BBEBE9BC5C5189797263030C4
                    B1B1D7D3D3DAD0D0D2CECEE3D9D9FFFFFFFBFBFCD9D9E3CFCFDCD3D3DDDFDCDD
                    C4C1C03346462932323B5151CCCFCFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                    FFDEDEDD3E3E33252518FFFFFFFFFFFFFFFFFFE3D9D9D0CDCDE3D9D9FFFFFFFF
                    FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFE5E5E5404041252525FFFFFFFFFFFF
                    FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFAFA
                    FAE3E3E3D4D4D4D1D1D1FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                    FFFFFFFFFFFFFFFFFFFFFFFFFFFFDDDDDD353535242424282828FFFFFFFFFFFF
                    FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFDDDD
                    DD3434341919191A1A1AFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                    FFFFFFFFFFFFFFFFFFFFFFFFFFFFFBFBFBE3E3E3DCDCDCDDDDDD}
                end
                object Ax3PSftLmtPosGoBtn: TRzBitBtn
                  Left = 274
                  Top = 104
                  Width = 61
                  Height = 24
                  FrameColor = 7617536
                  Caption = 'GO'
                  Color = 15791348
                  HotTrack = True
                  TabOrder = 11
                  OnClick = GoBtnClick
                  Glyph.Data = {
                    36030000424D3603000000000000360000002800000010000000100000000100
                    18000000000000030000C30E0000C30E00000000000000000000FFFFFFFFFFFF
                    FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                    FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFE3E3E3E3E3E3FFFFFFFFFFFFFFFFFFFF
                    FFFFFFFFFFFFFFFFFFFFFFFFFFFFE3E3E3E3E3E3FFFFFFFFFFFFFFFFFFCDCDCD
                    333333333333CDCDCDFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFCDCDCD3333
                    33333333CDCDCDFFFFFFC5C5C52B2B2B00000000000029292ABBBBBBD3D3D3D1
                    D1D1D4D4D4D4D4D4BBBBBB2A2A2A0000000000002A2A2AC5C5C51B1B1B171717
                    1717171717152323192A2A282E2E2F2C2C2C2828282D2D2D2929291919191414
                    141717171B1B1B1D1D1D1A1A1AC4C4C5C0C0BFBBBBB5D2D2D8DADAD4D1D1D1C9
                    C9C9ADADADD1D1D1DBDBDBDFDFDFC1C1C1CACACAC6C6C6101010252525E7E7E6
                    FFFFFFC0C0FF4848FFC2C2FFFFFFFFFFFFFFDCDCDCDBDBDBDBDBDBDBDBDBE0E0
                    E0DFDFDF818181242424222222E2E2DCEDEDFF3E3EFF0000FF3B3BFFE7E7FFFC
                    FCFAA9A9A93333332323232929292F2F2F181818323232C7C7C7212121E6E6E5
                    FFFFFFC2C2FF4B4BFFC2C2FFFFFFFFE2E2E1363636929293B7B7B8AEAEAF7272
                    732A2A2AC2C2C2FFFFFF242424B9B9B9D3D3D3D7D7D1CDCDD1D6D6D1D6D6D3B7
                    B7AD1616129A9A8FCDCDC0A5A59A4C4C49CFCFC8FFFFFFFFFFFF747474373737
                    2B2B2C2F2F2D37372D30302D28282E15152915152011112419192329293DBEBE
                    C5E3E3FFF7F7FFFFFFFFF1F1F1D6D6D6D0D0D0D1D1D1D0D0D1D4D4D1AFAFD144
                    44D3BDBDDC3737D60000D23C3CDCDFDFFF6161FFD8D8FFFFFFFFFFFFFFFFFFFF
                    FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFE5E5FFE4E4FFC3C3FF4A4AFFC2C2FFDCDC
                    FFD7D7FFF6F6FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFE0
                    E0FF5858FFD6D6FFDDDDFFD6D6FF5858FFE1E1FFFFFFFFFFFFFFFFFFFFFFFFFF
                    FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF6F6FFDBDBFFD2D2FF5F5FFFD2D2FFDBDB
                    FFF6F6FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                    FFFFFFFFFFF8F8FFD8D8FFF8F8FFFFFFFFFFFFFFFFFFFFFFFFFF}
                end
                object Ax4PSftLmtPosEdit: TEdit
                  Left = 126
                  Top = 134
                  Width = 64
                  Height = 24
                  Color = 16777088
                  Font.Charset = ANSI_CHARSET
                  Font.Color = clBlack
                  Font.Height = -13
                  Font.Name = 'Tahoma'
                  Font.Style = []
                  ImeName = '???(??)'
                  MaxLength = 7
                  ParentFont = False
                  TabOrder = 12
                  Text = '0.000'
                  OnChange = DataChange
                end
                object Ax4PSftLmtPosGetBtn: TRzBitBtn
                  Left = 204
                  Top = 134
                  Width = 61
                  Height = 24
                  FrameColor = 7617536
                  Caption = 'GET'
                  Color = 15791348
                  HotTrack = True
                  TabOrder = 13
                  OnClick = GetPosBtnClick
                  Glyph.Data = {
                    36030000424D3603000000000000360000002800000010000000100000000100
                    18000000000000030000C30E0000C30E00000000000000000000FFFFFFFFFFFF
                    FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFBFB
                    FBE3E3E3DCDCDCDDDDDDD1D1DBE5E5E6FFFFFFE4DBDBD2CFCFDAD1D1D2CFCFE3
                    D9D9FFFFFFFFFFFFFFFFFFFFFFFFDDDDDD3434341919191A1A1A25251F424040
                    BCBABA3C4E4E2A29291D2F2F2C34343B5151CACDCDFDFAFAFFFFFFFFFFFFDDDD
                    DD353535242424282828B7B5001B15000E393F3CC1C195D2D24BD0D092C1C117
                    9595293535E6DDDDFFFFFFFFFFFFFAFAFAE3E3E3D4D4D4D1D1D1E4DB00242C1C
                    36B4C0A7FFFF6CFFFFADF0F05A64640A3939363B3BCBC8C8FFFFFFFFFFFFFFFF
                    FFE5E5E5404041252525D3D000332E259BD9E56CFFFF96FFFF6AF5F590C0C033
                    BDBD92A2A2433333B2AFAFE6DCDCFFFFFFDFE0DF3D3D33252518D9D100232D22
                    50D0DCA1FFFF68FFFFADF0F05861611144443240400828282731313B5050C3C5
                    C4FAF8F6DBDBE3CFCFDCDCD9003531259ADAE66EFCFC92D5D553D0D093C8C82D
                    B9B981BABA2DC4C48ABFBF109A9B435348D8CDDB4849FF2525FFB5AC00161F15
                    36B9C4B2EFEF5B5959033030192626203535333B3B253A3A2F3737394E4FC8CA
                    C3E1DFF93F40FF2525FF2A2922211E1F1441413BBEBE9BC5C5189797263030C4
                    B1B1D7D3D3DAD0D0D2CECEE3D9D9FFFFFFFBFBFCD9D9E3CFCFDCD3D3DDDFDCDD
                    C4C1C03346462932323B5151CCCFCFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                    FFDEDEDD3E3E33252518FFFFFFFFFFFFFFFFFFE3D9D9D0CDCDE3D9D9FFFFFFFF
                    FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFE5E5E5404041252525FFFFFFFFFFFF
                    FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFAFA
                    FAE3E3E3D4D4D4D1D1D1FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                    FFFFFFFFFFFFFFFFFFFFFFFFFFFFDDDDDD353535242424282828FFFFFFFFFFFF
                    FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFDDDD
                    DD3434341919191A1A1AFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                    FFFFFFFFFFFFFFFFFFFFFFFFFFFFFBFBFBE3E3E3DCDCDCDDDDDD}
                end
                object Ax4PSftLmtPosGoBtn: TRzBitBtn
                  Left = 274
                  Top = 134
                  Width = 61
                  Height = 24
                  FrameColor = 7617536
                  Caption = 'GO'
                  Color = 15791348
                  HotTrack = True
                  TabOrder = 14
                  OnClick = GoBtnClick
                  Glyph.Data = {
                    36030000424D3603000000000000360000002800000010000000100000000100
                    18000000000000030000C30E0000C30E00000000000000000000FFFFFFFFFFFF
                    FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                    FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFE3E3E3E3E3E3FFFFFFFFFFFFFFFFFFFF
                    FFFFFFFFFFFFFFFFFFFFFFFFFFFFE3E3E3E3E3E3FFFFFFFFFFFFFFFFFFCDCDCD
                    333333333333CDCDCDFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFCDCDCD3333
                    33333333CDCDCDFFFFFFC5C5C52B2B2B00000000000029292ABBBBBBD3D3D3D1
                    D1D1D4D4D4D4D4D4BBBBBB2A2A2A0000000000002A2A2AC5C5C51B1B1B171717
                    1717171717152323192A2A282E2E2F2C2C2C2828282D2D2D2929291919191414
                    141717171B1B1B1D1D1D1A1A1AC4C4C5C0C0BFBBBBB5D2D2D8DADAD4D1D1D1C9
                    C9C9ADADADD1D1D1DBDBDBDFDFDFC1C1C1CACACAC6C6C6101010252525E7E7E6
                    FFFFFFC0C0FF4848FFC2C2FFFFFFFFFFFFFFDCDCDCDBDBDBDBDBDBDBDBDBE0E0
                    E0DFDFDF818181242424222222E2E2DCEDEDFF3E3EFF0000FF3B3BFFE7E7FFFC
                    FCFAA9A9A93333332323232929292F2F2F181818323232C7C7C7212121E6E6E5
                    FFFFFFC2C2FF4B4BFFC2C2FFFFFFFFE2E2E1363636929293B7B7B8AEAEAF7272
                    732A2A2AC2C2C2FFFFFF242424B9B9B9D3D3D3D7D7D1CDCDD1D6D6D1D6D6D3B7
                    B7AD1616129A9A8FCDCDC0A5A59A4C4C49CFCFC8FFFFFFFFFFFF747474373737
                    2B2B2C2F2F2D37372D30302D28282E15152915152011112419192329293DBEBE
                    C5E3E3FFF7F7FFFFFFFFF1F1F1D6D6D6D0D0D0D1D1D1D0D0D1D4D4D1AFAFD144
                    44D3BDBDDC3737D60000D23C3CDCDFDFFF6161FFD8D8FFFFFFFFFFFFFFFFFFFF
                    FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFE5E5FFE4E4FFC3C3FF4A4AFFC2C2FFDCDC
                    FFD7D7FFF6F6FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFE0
                    E0FF5858FFD6D6FFDDDDFFD6D6FF5858FFE1E1FFFFFFFFFFFFFFFFFFFFFFFFFF
                    FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF6F6FFDBDBFFD2D2FF5F5FFFD2D2FFDBDB
                    FFF6F6FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                    FFFFFFFFFFF8F8FFD8D8FFF8F8FFFFFFFFFFFFFFFFFFFFFFFFFF}
                end
              end
            end
          end
        end
      end
    end
  end
  object SetupTreeViewPanel: TPanel
    Left = 0
    Top = 0
    Width = 237
    Height = 714
    Align = alLeft
    TabOrder = 0
    object CoolBar1: TCoolBar
      Left = 1
      Top = 1
      Width = 235
      Height = 34
      AutoSize = True
      Bands = <
        item
          Control = ToolBar
          ImageIndex = -1
          MinHeight = 30
          Width = 231
        end>
      Color = clBtnFace
      FixedOrder = True
      ParentColor = False
      object ToolBar: TToolBar
        Left = 0
        Top = 0
        Width = 227
        Height = 30
        Align = alClient
        AutoSize = True
        ButtonHeight = 26
        ButtonWidth = 25
        Caption = 'ToolBar'
        Color = 16119543
        EdgeInner = esNone
        EdgeOuter = esNone
        ParentColor = False
        TabOrder = 0
        object FileSaveBtn: TSpeedButton
          Left = 0
          Top = 2
          Width = 26
          Height = 26
          Hint = 'Data Save'
          Flat = True
          Glyph.Data = {
            76010000424D7601000000000000760000002800000020000000100000000100
            04000000000000010000120B0000120B00001000000000000000000000000000
            800000800000008080008000000080008000808000007F7F7F00BFBFBF000000
            FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00333333333333
            333333FFFFFFFFFFFFF33000077777770033377777777777773F000007888888
            00037F3337F3FF37F37F00000780088800037F3337F77F37F37F000007800888
            00037F3337F77FF7F37F00000788888800037F3337777777337F000000000000
            00037F3FFFFFFFFFFF7F00000000000000037F77777777777F7F000FFFFFFFFF
            00037F7F333333337F7F000FFFFFFFFF00037F7F333333337F7F000FFFFFFFFF
            00037F7F333333337F7F000FFFFFFFFF00037F7F333333337F7F000FFFFFFFFF
            00037F7F333333337F7F000FFFFFFFFF07037F7F33333333777F000FFFFFFFFF
            0003737FFFFFFFFF7F7330099999999900333777777777777733}
          NumGlyphs = 2
          ParentShowHint = False
          ShowHint = True
          OnClick = ToolBarBtnClick
        end
        object CancelBtn: TSpeedButton
          Left = 26
          Top = 2
          Width = 26
          Height = 26
          Hint = 'Modify Cancel'
          Flat = True
          Glyph.Data = {
            76010000424D7601000000000000760000002800000020000000100000000100
            04000000000000010000130B0000130B00001000000000000000000000000000
            800000800000008080008000000080008000808000007F7F7F00BFBFBF000000
            FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00333333333333
            3333333333FFFFF3333333333999993333333333F77777FFF333333999999999
            3333333777333777FF3333993333339993333377FF3333377FF3399993333339
            993337777FF3333377F3393999333333993337F777FF333337FF993399933333
            399377F3777FF333377F993339993333399377F33777FF33377F993333999333
            399377F333777FF3377F993333399933399377F3333777FF377F993333339993
            399377FF3333777FF7733993333339993933373FF3333777F7F3399933333399
            99333773FF3333777733339993333339933333773FFFFFF77333333999999999
            3333333777333777333333333999993333333333377777333333}
          NumGlyphs = 2
          ParentShowHint = False
          ShowHint = True
          OnClick = ToolBarBtnClick
        end
        object ToolButton1: TToolButton
          Left = 52
          Top = 2
          Width = 8
          Caption = 'ToolButton1'
          Style = tbsDivider
        end
        object CloseBtn: TSpeedButton
          Left = 60
          Top = 2
          Width = 26
          Height = 26
          Hint = 'Close'
          Flat = True
          Glyph.Data = {
            76010000424D7601000000000000760000002800000020000000100000000100
            04000000000000010000120B0000120B00001000000000000000000000000000
            800000800000008080008000000080008000808000007F7F7F00BFBFBF000000
            FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00330000000000
            03333377777777777F333301BBBBBBBB033333773F3333337F3333011BBBBBBB
            0333337F73F333337F33330111BBBBBB0333337F373F33337F333301110BBBBB
            0333337F337F33337F333301110BBBBB0333337F337F33337F333301110BBBBB
            0333337F337F33337F333301110BBBBB0333337F337F33337F333301110BBBBB
            0333337F337F33337F333301110BBBBB0333337F337FF3337F33330111B0BBBB
            0333337F337733337F333301110BBBBB0333337F337F33337F333301110BBBBB
            0333337F3F7F33337F333301E10BBBBB0333337F7F7F33337F333301EE0BBBBB
            0333337F777FFFFF7F3333000000000003333377777777777333}
          NumGlyphs = 2
          ParentShowHint = False
          ShowHint = True
          OnClick = ToolBarBtnClick
        end
      end
    end
    object SetupTreeView: TTreeView
      Left = 1
      Top = 35
      Width = 235
      Height = 678
      Align = alClient
      BorderStyle = bsNone
      Color = 16119543
      Font.Charset = ANSI_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
      Images = TreeViewImageList
      Indent = 35
      ParentFont = False
      ReadOnly = True
      TabOrder = 1
      OnChange = SetupTreeViewChange
      OnChanging = SetupTreeViewChanging
      OnExpanding = SetupTreeViewExpanding
      Items.Data = {
        0300000021000000000000000000000000000000FFFFFFFF0000000001000000
        084F7065726174657220000000040000000500000001000000FFFFFFFF000000
        00000000000747656E6572616C2100000001000000010000000A000000FFFFFF
        FF000000000400000008456E67696E6565722000000004000000050000000B00
        0000FFFFFFFF00000000000000000747656E6572616C25000000040000000500
        00000C000000FFFFFFFF00000000000000000C436865636B2041742052756E2A
        00000004000000050000000D000000FFFFFFFF000000000000000011556E6C6F
        6164657220506F736974696F6E2400000004000000050000000E000000FFFFFF
        FF00000000000000000B4D6F746F722053706565642000000002000000020000
        0064000000FFFFFFFF000000000300000007466163746F727920000000040000
        000500000065000000FFFFFFFF00000000000000000747656E6572616C200000
        00040000000500000066000000FFFFFFFF000000000000000007456E636F6465
        7227000000040000000500000067000000FFFFFFFF00000000000000000E536F
        667477617265204C696D6974}
    end
  end
  object TreeViewImageList: TImageList
    Height = 32
    Width = 32
    Left = 140
    Top = 4
    Bitmap = {
      494C010106000900040020002000FFFFFFFFFF10FFFFFFFFFFFFFFFF424D3600
      00000000000036000000280000008000000060000000010020000000000000C0
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000003131000031310000313100003131000031310000313100003131000031
      3100003131000031310000313100003131000031310000313100003131000031
      3100003131000031310000313100003131000031310000313100003131000031
      3100003131000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000000000000000000000000000009C
      9C00009C9C00009C9C00009C9C00009C9C00009C9C00009C9C00009C9C00009C
      9C00009C9C00009C9C00009C9C00009C9C00009C9C00009C9C00009C9C00009C
      9C00009C9C00009C9C00009C9C00009C9C00009C9C00009C9C00009C9C00009C
      9C00009C9C000031310000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000000000000000000000000000009C
      9C009CCEFF009CCEFF009CCEFF009CCEFF009CCEFF009CCEFF009CCEFF009CCE
      FF009CCEFF009CCEFF009CCEFF009CCEFF009CCEFF009CCEFF009CCEFF009CCE
      FF009CCEFF009CCEFF009CCEFF009CCEFF009CCEFF009CCEFF009CCEFF009CCE
      FF00009C9C000031310000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000313100003131000031
      3100003131000031310000313100003131000031310000313100003131000031
      3100003131000031310000313100003131000031310000313100003131000031
      3100003131000031310000313100003131000031310000313100003131000031
      310000313100003131000031310000000000000000000000000000000000009C
      9C009CFFFF009CFFFF009CCEFF009CFFFF009CFFFF009CCEFF009CFFFF009CFF
      FF009CCEFF009CCEFF009CFFFF009CCEFF009CCEFF009CFFFF009CFFFF009CCE
      FF009CFFFF009CCEFF009CFFFF009CCEFF009CFFFF009CCEFF009CCEFF009CCE
      FF00009C9C000031310000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000009C9C0063CECE0063CECE0063CE
      CE0063CECE0063CECE0063CECE0063CECE0063CECE0063CECE0063CECE0063CE
      CE0063CECE0063CECE0063CECE0063CECE0063CECE0063CECE0063CECE0063CE
      CE0063CECE0063CECE0063CECE0063CECE0063CECE0063CECE0063CECE0063CE
      CE0063CECE0063CECE0063CECE00003131000000000000000000009C9C00F7FF
      FF009CFFFF009CCEFF009CFFFF009CCEFF009CFFFF009CFFFF009CCEFF009CCE
      FF009CFFFF009CFFFF009CCEFF009CFFFF009CFFFF009CCEFF009CCEFF009CFF
      FF009CCEFF009CFFFF009CCEFF009CCEFF009CCEFF009CFFFF009CCEFF009CCE
      FF00009C9C000031310000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000009C9C00FFFFFF009CCEFF009CFF
      FF009CCEFF009CFFFF009CCEFF009CFFFF009CFFFF009CCEFF009CFFFF009CCE
      FF009CFFFF009CFFFF009CFFFF009CCEFF009CFFFF009CCEFF009CFFFF009CFF
      FF009CCEFF009CCEFF009CFFFF009CCEFF009CFFFF009CCEFF009CCEFF009CCE
      FF009CFFFF009CCEFF0063CECE00003131000000000000000000009C9C00F7FF
      FF009CCEFF009CFFFF009CFFFF009CFFFF009CCEFF009CFFFF009CFFFF009CFF
      FF009CCEFF009CFFFF009CCEFF009CCEFF009CFFFF009CFFFF009CCEFF009CFF
      FF009CCEFF009CCEFF009CFFFF009CCEFF009CFFFF009CCEFF009CFFFF009CCE
      FF00009C9C000031310000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000009C9C00FFFFFF009CFFFF009CFF
      FF009CFFFF009CCEFF009CFFFF009CCEFF009CFFFF009CFFFF009CCEFF009CFF
      FF009CFFFF009CCEFF009CCEFF009CFFFF009CCEFF009CFFFF009CCEFF009CCE
      FF009CFFFF009CFFFF009CCEFF009CCEFF009CCEFF009CFFFF009CCEFF009CCE
      FF009CCEFF009CCEFF0063CECE00003131000000000000000000009C9C00F7FF
      FF009CFFFF009CFFFF009CFFFF009CFFFF009CFFFF009CFFFF009CCEFF009CFF
      FF009CFFFF009CCEFF009CFFFF009CFFFF009CCEFF009CCEFF009CFFFF009CCE
      FF009CFFFF009CFFFF009CCEFF009CFFFF009CCEFF009CCEFF009CCEFF009CCE
      FF00009C9C000031310000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000009C9C00FFFFFF009CCEFF009CFF
      FF009CFFFF009CFFFF009CFFFF009CFFFF009CCEFF009CFFFF009CFFFF009CCE
      FF009CCEFF009CFFFF009CFFFF009CCEFF009CFFFF009CCEFF009CFFFF009CFF
      FF009CCEFF009CCEFF009CCEFF009CFFFF009CCEFF009CCEFF009CCEFF009CCE
      FF009CCEFF009CCEFF0063CECE00003131000000000000000000009C9C00F7FF
      FF009CFFFF009CCEFF009CFFFF009CCEFF009CFFFF009CCEFF009CFFFF009CFF
      FF009CCEFF009CFFFF009CCEFF009CFFFF009CFFFF009CFFFF009CCEFF009CFF
      FF009CCEFF009CCEFF009CFFFF009CCEFF009CFFFF009CCEFF009CFFFF009CCE
      FF00003131000031310000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000009C9C00FFFFFF009CFFFF009CFF
      FF009CCEFF009CFFFF009CCEFF009CFFFF009CFFFF009CCEFF009CFFFF009CFF
      FF009CFFFF009CCEFF009CFFFF009CCEFF009CFFFF009CFFFF009CCEFF009CFF
      FF009CFFFF009CCEFF009CCEFF009CCEFF009CFFFF009CCEFF009CFFFF009CFF
      FF009CCEFF009CCEFF0063CECE000031310000000000009C9C00F7FFFF009CFF
      FF009CFFFF009CFFFF009CCEFF009CFFFF009CFFFF009CFFFF009CFFFF009CCE
      FF009CFFFF009CCEFF009CFFFF009CFFFF009CCEFF009CCEFF009CFFFF009CCE
      FF009CFFFF009CFFFF009CCEFF009CFFFF009CCEFF009CFFFF009CCEFF009CCE
      FF00003131000031310000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000009C9C00FFFFFF009CFFFF009CFF
      FF009CFFFF009CFFFF009CFFFF009CFFFF009CFFFF009CFFFF009CFFFF009CCE
      FF009CFFFF009CFFFF009CCEFF009CFFFF009CCEFF009CCEFF009CFFFF009CCE
      FF009CCEFF009CFFFF009CFFFF009CFFFF009CCEFF009CCEFF009CCEFF009CCE
      FF009CFFFF009CCEFF0063CECE000031310000000000009C9C00F7FFFF009CFF
      FF009CFFFF009CFFFF009CFFFF009CCEFF009CFFFF009CCEFF009CFFFF009CFF
      FF009CFFFF009CFFFF009CFFFF009CCEFF009CFFFF009CCEFF009CFFFF009CFF
      FF009CCEFF009CFFFF009CCEFF009CFFFF009CCEFF009CFFFF009CCEFF0063CE
      CE00003131000031310000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000009C9C00FFFFFF009CFFFF009CCE
      FF009CFFFF009CCEFF009CFFFF009CFFFF009CCEFF009CFFFF009CCEFF009CFF
      FF009CFFFF009CCEFF009CFFFF009CCEFF009CFFFF009CFFFF009CFFFF009CFF
      FF009CFFFF009CCEFF009CCEFF009CCEFF009CCEFF009CFFFF009CCEFF009CCE
      FF009CCEFF009CCEFF0063CECE000031310000000000009C9C00F7FFFF009CFF
      FF009CCEFF009CFFFF009CFFFF009CFFFF009CFFFF009CFFFF009CFFFF009CCE
      FF009CFFFF009CCEFF009CFFFF009CFFFF009CCEFF009CFFFF009CCEFF009CCE
      FF009CFFFF009CCEFF009CFFFF009CCEFF009CFFFF009CCEFF009CCEFF00009C
      9C00003131000031310000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000009C9C00FFFFFF009CFFFF009CFF
      FF009CFFFF009CFFFF009CFFFF009CFFFF009CFFFF009CFFFF009CFFFF009CCE
      FF009CFFFF009CFFFF009CFFFF009CFFFF009CFFFF009CCEFF009CFFFF009CCE
      FF009CCEFF009CFFFF009CCEFF009CCEFF009CFFFF009CCEFF009CCEFF009CFF
      FF009CCEFF009CFFFF0063CECE000031310000000000009C9C00F7FFFF009CFF
      FF009CFFFF009CFFFF009CFFFF009CCEFF009CFFFF009CCEFF009CFFFF009CFF
      FF009CFFFF009CFFFF009CFFFF009CFFFF009CFFFF009CFFFF009CFFFF009CCE
      FF009CFFFF009CCEFF009CFFFF009CFFFF009CFFFF009CFFFF009CCEFF00009C
      9C00000000000031310000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000009C9C00FFFFFF009CFFFF009CFF
      FF009CFFFF009CFFFF009CFFFF009CFFFF009CCEFF009CFFFF009CFFFF009CFF
      FF009CCEFF009CFFFF009CCEFF009CFFFF009CCEFF009CFFFF009CCEFF009CFF
      FF009CFFFF009CCEFF009CFFFF009CFFFF009CCEFF009CFFFF009CFFFF009CCE
      FF009CCEFF009CCEFF0063CECE0000313100009C9C00F7FFFF009CFFFF009CFF
      FF009CFFFF009CFFFF009CFFFF009CFFFF009CFFFF009CFFFF009CCEFF009CFF
      FF009CFFFF009CCEFF009CFFFF009CCEFF009CFFFF009CFFFF009CFFFF009CFF
      FF009CFFFF009CFFFF009CFFFF009CFFFF009CCEFF009CFFFF0063CECE00009C
      9C00C6C6C6000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000009C9C00FFFFFF009CFFFF009CFF
      FF009CFFFF009CFFFF009CCEFF009CFFFF009CFFFF009CFFFF009CFFFF009CFF
      FF009CFFFF009CFFFF009CFFFF009CFFFF009CFFFF009CFFFF009CFFFF009CFF
      FF009CCEFF009CFFFF009CCEFF009CCEFF009CFFFF009CCEFF009CCEFF009CCE
      FF009CFFFF009CCEFF0063CECE0000313100009C9C00F7FFFF009CFFFF009CFF
      FF009CFFFF009CCEFF009CFFFF009CFFFF009CFFFF009CCEFF009CFFFF009CFF
      FF009CCEFF009CFFFF009CFFFF009CFFFF009CFFFF009CCEFF009CFFFF009CCE
      FF009CFFFF009CFFFF009CFFFF009CCEFF009CFFFF009CFFFF00009C9C00C6C6
      C600D6E7E700C6C6C60000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000009C9C00FFFFFF009CFFFF009CFF
      FF009CFFFF009CFFFF009CFFFF009CFFFF009CFFFF009CFFFF009CCEFF009CFF
      FF009CCEFF009CFFFF009CCEFF009CFFFF009CCEFF009CCEFF009CFFFF009CCE
      FF009CFFFF009CFFFF009CFFFF009CFFFF009CCEFF009CFFFF009CFFFF009CCE
      FF009CCEFF009CFFFF0063CECE0000313100009C9C00F7FFFF009CFFFF009CFF
      FF009CFFFF009CFFFF009CFFFF009CFFFF009CFFFF009CFFFF009CFFFF009CFF
      FF009CFFFF009CFFFF009CFFFF009CFFFF009CFFFF009CFFFF009CFFFF009CFF
      FF009CFFFF009CCEFF009CFFFF009CFFFF009CCEFF009CFFFF00009C9C00C6C6
      C600D6E7E700D6E7E700C6C6C600080808000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000009C9C00FFFFFF009CFFFF009CFF
      FF009CFFFF009CFFFF009CFFFF009CFFFF009CCEFF009CFFFF009CFFFF009CFF
      FF009CFFFF009CFFFF009CFFFF009CFFFF009CFFFF009CFFFF009CFFFF009CFF
      FF009CCEFF009CFFFF009CCEFF009CFFFF009CFFFF009CCEFF009CCEFF009CFF
      FF009CFFFF009CCEFF0063CECE0000313100009C9C00F7FFFF009CFFFF009CFF
      FF009CFFFF009CFFFF009CFFFF009CFFFF009CFFFF009CFFFF009CFFFF009CCE
      FF009CFFFF009CFFFF009CCEFF009CFFFF009CCEFF009CFFFF009CCEFF009CFF
      FF009CFFFF009CFFFF009CCEFF009CFFFF009CFFFF0063CECE00009C9C00C6C6
      C600D6E7E700C6C6C60000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000009C9C00FFFFFF009CFFFF009CFF
      FF009CFFFF009CFFFF009CFFFF009CFFFF009CFFFF009CFFFF009CFFFF009CFF
      FF009CFFFF009CCEFF009CFFFF009CFFFF009CCEFF009CFFFF009CCEFF009CFF
      FF009CFFFF009CCEFF009CFFFF009CFFFF009CCEFF009CFFFF009CFFFF009CFF
      FF009CCEFF009CFFFF0063CECE0000313100009C9C00F7FFFF00F7FFFF00F7FF
      FF00F7FFFF00F7FFFF00F7FFFF00F7FFFF00F7FFFF00F7FFFF00F7FFFF00F7FF
      FF00F7FFFF00F7FFFF00F7FFFF00F7FFFF00F7FFFF00F7FFFF00F7FFFF00F7FF
      FF00F7FFFF00F7FFFF00F7FFFF00F7FFFF009CFFFF00009C9C00C6C6C600D6E7
      E700C6C6C6000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000009C9C00FFFFFF009CFFFF009CFF
      FF009CFFFF009CFFFF009CFFFF009CFFFF009CFFFF009CFFFF009CCEFF009CFF
      FF009CFFFF009CFFFF009CFFFF009CCEFF009CFFFF009CFFFF009CFFFF009CFF
      FF009CFFFF009CFFFF009CFFFF009CCEFF009CFFFF009CFFFF009CCEFF009CCE
      FF009CFFFF009CCEFF0063CECE000031310000000000009C9C00009C9C00009C
      9C00009C9C00009C9C00009C9C00009C9C00009C9C00009C9C00009C9C00009C
      9C00009C9C00009C9C00009C9C00009C9C00009C9C00009C9C00009C9C00009C
      9C00009C9C00009C9C00009C9C00009C9C00009C9C00C6C6C600D6E7E700C6C6
      C6004A4A4A003131000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000009C9C00FFFFFF009CFFFF009CFF
      FF009CFFFF009CFFFF009CFFFF009CFFFF009CFFFF009CFFFF009CFFFF009CFF
      FF009CFFFF009CFFFF009CFFFF009CFFFF009CFFFF009CFFFF009CCEFF009CFF
      FF009CCEFF009CFFFF009CCEFF009CFFFF009CCEFF009CFFFF009CFFFF009CFF
      FF009CCEFF009CFFFF0063CECE00003131000000000000000000000000000084
      84009CFFFF0084848400C6C6C600C6C6C600C6C6C600C6C6C6009C310000A5A5
      A500C6C6C6009C310000A5A5A500C6C6C6009C310000A5A5A500C6C6C6009C31
      0000A5A5A500C6C6C600C6C6C600C6C6C600C6C6C600D6E7E700C6C6C6004A4A
      4A00008484003131000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000009C9C00FFFFFF009CFFFF009CFF
      FF009CFFFF009CFFFF009CFFFF009CFFFF009CFFFF009CFFFF009CFFFF009CFF
      FF009CCEFF009CFFFF009CCEFF009CFFFF009CCEFF009CFFFF009CFFFF009CFF
      FF009CFFFF009CFFFF009CFFFF009CFFFF009CFFFF009CCEFF009CFFFF009CCE
      FF009CFFFF009CCEFF0063CECE00003131000000000000000000000000000084
      84009CFFFF00009C9C0084848400D6E7E700D6E7E700D6E7E700D6E7E7009C31
      0000A5A5A500D6E7E7009C310000A5A5A500D6E7E7009C310000A5A5A500D6E7
      E7009C310000D6E7E700D6E7E700D6E7E700D6E7E700C6C6C6004A4A4A0063CE
      CE00008484003131000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000009C9C00FFFFFF009CFFFF009CFF
      FF009CFFFF009CFFFF009CFFFF009CFFFF009CFFFF009CFFFF009CFFFF009CFF
      FF009CFFFF009CFFFF009CFFFF009CFFFF009CFFFF009CFFFF009CCEFF009CFF
      FF009CCEFF009CFFFF009CFFFF009CFFFF009CCEFF009CFFFF009CFFFF009CFF
      FF009CFFFF009CCEFF0063CECE00003131000000000000000000000000000084
      84009CFFFF0031CECE00009C9C0084848400F7FFFF00F7FFFF00F7FFFF00F7FF
      FF009C310000A5A5A500D6E7E7009C310000A5A5A500F7FFFF009C310000F7FF
      FF00F7FFFF00F7FFFF00F7FFFF00F7FFFF00C6C6C6002121210063CECE0063CE
      CE00008484003131000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000009C9C00FFFFFF009CFFFF009CFF
      FF009CFFFF009CFFFF009CFFFF009CFFFF009CFFFF009CFFFF009CFFFF009CFF
      FF009CFFFF009CFFFF009CFFFF009CFFFF009CFFFF009CFFFF009CFFFF009CFF
      FF009CFFFF009CFFFF009CCEFF009CFFFF009CFFFF009CCEFF009CCEFF009CFF
      FF009CFFFF009CFFFF0063CECE00003131000000000000000000000000000084
      84009CFFFF0063CECE0063CECE00009C9C0084848400F7FFFF00F7FFFF00F7FF
      FF00F7FFFF009C310000A5A5A500D6E7E7009C310000F7FFFF00F7FFFF00F7FF
      FF00F7FFFF00F7FFFF00F7FFFF0094ADAD004A4A4A0063CECE0063CECE000084
      8400313100000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000009C9C00FFFFFF009CFFFF009CFF
      FF009CFFFF009CFFFF009CFFFF009CFFFF009CFFFF009CFFFF009CFFFF009CFF
      FF009CFFFF009CFFFF009CFFFF009CCEFF009CFFFF009CCEFF009CFFFF009CCE
      FF009CFFFF009CFFFF009CFFFF009CCEFF009CFFFF009CFFFF009CFFFF009CCE
      FF009CFFFF009CCEFF0063CECE00003131000000000000000000000000000084
      84009CFFFF0063CECE0063CECE0063CECE00009C9C0084848400F7FFFF00F7FF
      FF00F7FFFF00F7FFFF009C310000A5A5A500F7FFFF00F7FFFF00F7FFFF00F7FF
      FF00F7FFFF00F7FFFF00C6C6C6004A4A4A000084840000848400008484000084
      8400000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000009C9C00FFFFFF009CFFFF009CFF
      FF009CFFFF009CFFFF009CFFFF009CFFFF009CFFFF009CFFFF009CFFFF009CFF
      FF009CFFFF009CFFFF009CFFFF009CFFFF009CFFFF009CFFFF009CFFFF009CFF
      FF009CFFFF009CCEFF009CFFFF009CFFFF009CCEFF009CFFFF009CFFFF009CFF
      FF009CCEFF009CFFFF0063CECE00080808000000000000000000000000000084
      84009CFFFF009CFFFF0063CECE0063CECE0063CECE00009C9C0084848400F7FF
      FF00F7FFFF00F7FFFF00F7FFFF009C310000F7FFFF00F7FFFF00F7FFFF00F7FF
      FF00F7FFFF00C6C6C60052525200000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000009C9C00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF0000000000000000000000000000000000000000000000
      0000008484009CFFFF009CFFFF009CFFFF009CFFFF009CFFFF0063CECE008484
      8400F7FFFF00F7FFFF00F7FFFF00F7FFFF00F7FFFF00F7FFFF00F7FFFF00F7FF
      FF00C6C6C6004A4A4A0000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000009C9C0063CECE0063CECE0063CE
      CE0063CECE0063CECE0063CECE0063CECE0063CECE0063CECE0063CECE0063CE
      CE0063CECE0063CECE0063CECE0063CECE00009C9C00009C9C00009C9C00009C
      9C00009C9C00009C9C00009C9C00009C9C00009C9C00009C9C00009C9C00009C
      9C00009C9C00009C9C0000000000000000000000000000000000000000000000
      0000000000000084840000848400008484000084840000848400008484000084
      840084848400F7FFFF00F7FFFF00F7FFFF00F7FFFF00F7FFFF00F7FFFF00C6C6
      C6004A4A4A000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000000000000000009C9C00F7FFFF009CFF
      FF009CFFFF009CFFFF009CFFFF009CFFFF009CFFFF009CFFFF009CFFFF009CFF
      FF009CFFFF009CFFFF009CFFFF00009C9C000808080000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000084848400F7FFFF00F7FFFF00F7FFFF00F7FFFF00C6C6C6004A4A
      4A00000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000009C9C00FFFF
      FF009CFFFF009CFFFF009CFFFF009CFFFF009CFFFF009CFFFF009CFFFF009CFF
      FF009CFFFF009CFFFF00009C9C00080808000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000084848400F7FFFF00F7FFFF00C6C6C600525252000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000000000000000000000000000009C
      9C00FFFFFF009CFFFF009CFFFF009CFFFF009CFFFF009CFFFF009CFFFF009CFF
      FF009CFFFF00009C9C0008080800000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000008484840094ADAD0052525200000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000009C9C00009C9C00009C9C00009C9C00009C9C00009C9C00009C9C00009C
      9C00009C9C000808080000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000008484840000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000000000000000FFFFFF00DEDEDE00E7E7
      E70000000000ADADAD0000000000CECECE00C6C6C60000000000000000000000
      000000000000FFFFFF0000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000006B6B
      6B000000000000000000ADADAD00000000000000000021B5AD000084AD0008A5
      AD0000527B000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000084848400C6C6C600C6C6C600C6C6C6000000
      0000C6C6C6000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000000000009C630000FF0000000000
      0000000000000000000000000000000000000000000000000000000000000031
      3100003131000031310000313100003131000000000000313100000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000D6D6D60000000000E7EFEF008C8C
      8C0000000000000000000000000018181800D6D6CE0084E7FF00EFFFFF00C6F7
      FF0073FFFF000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000084848400C6C6C600C6C6C600C6C6C60000000000C6C6
      C600C6C6C600C6C6C60000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000DEDEDE00E7E7E700E7E7E700F7F7
      F700F7F7F700F7F7F700FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00000000000000000000000000000000000000000000000000000000000000
      00000000000000000000FF000000000000000000000000000000000000000000
      000000000000FF0000009C6300009C6300009C630000FF000000000000000000
      00000031310000313100003131000031310000639C0000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000009C630000FF00000000000000000000000000
      0000000000000000000000000000000000007B7B7B00C6C6C600848484003131
      31008C8C8C00000000000000000039313100948C840000A5EF00E7FFFF007BBD
      D60052CEFF000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000084848400C6C6C600C6C6C600C6C6C60000000000C6C6C6000000
      0000000000000000000000000000000000000000000000315200003152000031
      5200003152000031520000315200003152000031520000315200003152000031
      520000315200003152000031520000315200DEDEDE00DEDEDE000000DE000000
      0000000000005252520000000000525252005252520000000000FFFFFF00FFFF
      FF00000000000031520000315200000000000000000000000000000000000000
      0000FF00000000000000000000000000000000000000FF0000009C630000FF00
      0000FF000000FF000000FF000000FF000000FF00000000000000000000000000
      0000003131000031310000313100003131000031310000639C00000000000031
      3100000000000000000000000000000000000000000000000000000000000000
      0000FF000000000000000000000000000000000000000000000000000000FF00
      00009C6300009C6300009C630000FF000000848484007B848400000000002121
      2100000000007B7B7B00FFFFFF00211818009C9C940021B5F700D6FFFF008CCE
      E70052D6FF000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000C6C6C600000000000000000000000000C6C6C600000000000000
      000000000000000000000000000000000000009494006BC6FF006BC6FF006BC6
      FF006BC6FF006BC6FF006BC6FF006BC6FF006BC6FF006BC6FF006BC6FF006BC6
      FF006BC6FF006BC6FF006BC6FF006BC6FF00CECECE00DEDEDE00DEDEDE00DEDE
      DE00E7E7E700F7F7F700F7F7F700F7F7F700FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00000000006BC6FF006BC6FF00003152000000000000000000000000000000
      0000000000000000000000000000FF0000009C630000FF000000FF000000FF00
      0000000000000000000000000000FF0000000000000000000000000000000000
      000000000000003131000031310000313100003131000031310000639C000000
      0000000000000000000000000000000000000000000000000000FF0000000000
      0000000000000000000000000000FF0000009C630000FF000000FF000000FF00
      0000FF000000FF000000FF00000000000000F7F7F70000000000000000000000
      0000E7E7E70000000000EFEFEF0000000000ADADA50021B5EF00D6FFFF008CCE
      E70052CEFF0000000000000000000000000000000000C6C6C600848484008484
      84008484840084848400C6C6C60084848400C6C6C60084848400C6C6C6000000
      0000C6C6C6000000000000000000C6C6C60000000000C6C6C600C6C6C6000000
      0000C6C6C600C6C6C60084848400000000000000000000000000C6C6C6000000
      00000000000000000000000000000000000000949400F7F7F7008CD6FF008CFF
      FF008CD6FF008CFFFF008CD6FF008CFFFF008CFFFF008CD6FF008CFFFF008CD6
      FF008CFFFF008CFFFF008CFFFF008CD6FF00CECECE00DEDEDE00DEDEDE00DEDE
      DE00DEDEDE00E7E7E700E7E7E700F7F7F700F7F7F700F7F7F700FFFFFF00FFFF
      FF00000000008CD6FF006BC6FF00003152000000000000000000000000000000
      000000000000FF0000009C630000FF000000FF000000FF000000000000000000
      000063CEFF008484840000000000000000000000000000000000000000000000
      0000000000000084840000639C00003131000031310000313100000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000FF0000009C630000FF000000FF000000FF000000000000000000
      000000000000FF00000000000000000000000000000042424200424A4A00CECE
      CE00EFEFEF008C8C8C000000000000000000F7EFE7000094FF000000000084B5
      D60073FFFF000000000000000000000000000000000000000000000000000000
      000084848400C6C6C600C6C6C600C6C6C600C6C6C600C6C6C60000000000C6C6
      C600000000000000000000000000C6C6C600C6C6C60000000000C6C6C600C6C6
      C60000000000C6C6C600000000008484840084848400C6C6C600C6C6C6000000
      00000000000000000000000000000000000000949400F7F7F7008CFFFF008CFF
      FF008CFFFF008CD6FF008CFFFF008CD6FF008CFFFF008CFFFF008CD6FF008CFF
      FF008CFFFF008CD6FF008CD6FF008CFFFF00C6C6C600CECECE00DEDEDE00DEDE
      DE00DEDEDE00DEDEDE00E7E7E700E7E7E700F7F7F700F7F7F700F7F7F700FFFF
      FF00000000008CD6FF006BC6FF00003152000000000000000000000000000000
      00000000000000000000FF000000FF0000000000000000000000C6C6C60063CE
      FF0094ADAD00319CCE0084848400000000000000840000008400000084000063
      FF00000084000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000000000000000000000000000FF00
      00009C630000FF000000FF000000FF000000000000000000000063CEFF008484
      8400000000000000000000000000000000000000000000000000000000008C94
      94000000000021212100080808000000000000000000FFF7E7005AC6FF00A5FF
      FF00000031002929290000000000000000000000000000000000000000000000
      00008484840084848400C6C6C60084848400C6C6C60000000000C6C6C6000000
      00000000000000000000C6C6C600C6C6C60000000000C6C6C600C6C6C6000000
      0000C6C6C600C6C6C600000000000000000000000000C6C6C600C6C6C6000000
      00000000000000000000000000000000000000949400F7F7F7008CD6FF008CFF
      FF008CFFFF008CFFFF008CFFFF008CFFFF008CD6FF008CFFFF008CFFFF008CD6
      FF008CD6FF008CFFFF008CFFFF008CD6FF00C6C6C600C6C6C600CECECE00C6DE
      C600DEDEDE00DEDEDE00E7E7E700E7E7E700F7F7F700F7F7F700F7F7F700F7F7
      F700000000008CD6FF006BC6FF00003152000000000000000000000000000000
      00000000000000000000000000000000000063CEFF00C6C6C60063CEFF0094AD
      AD00319CCE0084848400000000000000840000008400319CCE00848484000000
      84000063FF000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000FF000000FF0000000000000000000000C6C6C60063CEFF0094ADAD00319C
      CE00848484000000000000008400000084000000000000000000A5A5A5007B84
      8400FFFFFF0018181800ADADAD0000000000000000007B7B6B0073E7FF0000BD
      FF0000000000DEDEDE0000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000C6C6C600000000000000000000000000C6C6C600C6C6C6000000
      00000000000000000000000000000000000000949400F7F7F7008CFFFF008CFF
      FF008CD6FF008CFFFF008CD6FF008CFFFF008CFFFF008CD6FF008CFFFF008CFF
      FF008CFFFF008CD6FF008CFFFF008CD6FF00C6DEC600C6C6C6000000DE000000
      00000000000052525200000000005252520000000000B5B5B50052525200F7F7
      F700000000008CD6FF006BC6FF00003152000000000000000000000000000000
      000000000000000000000000000000000000C6C6C60063CEFF00C6C6C600319C
      CE0084848400319CCE000000000084848400319CCE0094ADAD00319CCE008484
      8400000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000063CEFF00C6C6C60063CEFF0094ADAD00319CCE008484
      8400000000000000840000008400319CCE0000000000000000007B7B7B00848C
      8C00FFFFFF0021212100B5B5B500737373006373730000000000F7FFFF000000
      000084FFFF00000000000000000000000000C6C6C60000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000C6C6C600C6C6C600C6C6C600C6C6C60084848400C6C6
      C60084848400C6C6C600000000000000000000949400F7F7F7008CFFFF008CFF
      FF008CFFFF008CFFFF008CFFFF008CFFFF008CFFFF008CFFFF008CFFFF008CD6
      FF008CFFFF008CFFFF008CD6FF008CFFFF00CECECE00C6DEC600C6C6C600CECE
      CE00CECECE00CECECE00DEDEDE00DEDEDE00DEDEDE00E7E7E700F7F7F700F7F7
      F700000000008CD6FF006BC6FF00003152000000000000000000000000000000
      00000000000000000000000000000000000000000000C6C6C60063CEFF0094AD
      AD000000000000000000000000000000000000000000319CCE00848484000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000C6C6C60063CEFF00C6C6C600319CCE0084848400319C
      CE000000000084848400319CCE0094ADAD000000000000000000A5A5A5007B84
      8400FFFFFF0010101000CECECE00BDBDBD000000000008080800000000001808
      0000001010001818180000000000000000000000000000000000000000000000
      000000000000C6C6C6000000000000FFFF0000FFFF0000FFFF0000FFFF0000FF
      FF0000FFFF0000FFFF0000FFFF0000FFFF000084840000000000000000000000
      0000000000000000000000000000C6C6C600C6C6C60084848400C6C6C6008484
      8400C6C6C60000000000000000000000000000949400F7F7F7008CFFFF008CD6
      FF008CFFFF008CD6FF008CFFFF008CFFFF008CD6FF008CFFFF008CD6FF008CFF
      FF008CFFFF008CD6FF008CFFFF008CD6FF00CECECE00CECECE000000DE000000
      0000000000005252520000000000525252005252520000000000B5B5B500E7E7
      E700000000008CD6FF006BC6FF00003152000000000000000000000000000000
      00000000000000000000000000000000000000000000319CCE00C6C6C600319C
      CE0084848400319CCE008484840063CEFF008484840000000000319CCE000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000C6C6C60063CEFF0094ADAD00000000000000
      0000000000000000000000000000319CCE00000000000000000008080800949C
      9C0000000000292929000808080000000000DED6D60000000000D6D6D6000808
      0800847B7B00FFFFFF000000000000000000000000000000000000000000C6C6
      C600000000000000000000FFFF0000FFFF0000FFFF0000FFFF0000FFFF0000FF
      FF0000FFFF0000FFFF0000FFFF000084840000FFFF0000848400000000000000
      000000000000C6C6C60000000000000000000000000000000000000000000000
      00000000000000000000000000000000000000949400F7F7F7008CFFFF008CFF
      FF008CFFFF008CFFFF008CFFFF008CFFFF008CFFFF008CFFFF008CFFFF008CD6
      FF008CFFFF008CFFFF008CFFFF008CFFFF00E7E7E700DEDEDE00DEDEDE00CECE
      CE00C6DEC600CECECE00CECECE00DEDEDE00DEDEDE00DEDEDE00DEDEDE00E7E7
      E700000000008CFFFF006BC6FF00003152000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000319CCE00C6C6
      C60063CEFF00C6C6C60063CEFF00C6C6C60063CEFF0000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000319CCE00C6C6C600319CCE0084848400319C
      CE008484840063CEFF008484840000000000000000004242420000000000B5B5
      B500EFEFEF008484840008080800424242000000000000000000000000001818
      18009C9C9C000000000000000000000000000000000000000000000000000000
      000000FFFF0000FFFF0000FFFF0000FFFF0000000000000000000000000000FF
      FF0000FFFF0000FFFF000084840000FFFF000084840000FFFF000084840000FF
      FF0000000000C6C6C600C6C6C600000000000000000000000000000000000000
      00000000000000000000000000000000000000949400F7F7F7008CFFFF008CFF
      FF008CFFFF008CFFFF008CFFFF008CFFFF008CD6FF008CFFFF008CFFFF008CFF
      FF008CD6FF008CFFFF008CD6FF008CFFFF00E7E7E700DEDEDE00DEDEDE00CECE
      CE00CECECE00C6DEC600C6C6C600CECECE00C6DEC600DEDEDE00DEDEDE00E7E7
      E700000000008CD6FF006BC6FF00003152000000000000000000000000000000
      00000000000000000000000000000000000000000000000000000000000063CE
      FF00C6C6C60063CEFF0094ADAD00319CCE0094ADAD0000000000319CCE0094AD
      AD00319CCE0094ADAD0000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000319CCE00C6C6C60063CEFF00C6C6
      C60063CEFF00C6C6C60063CEFF0000000000F7F7F70000000000F7F7F7000000
      0000FFFFFF0000000000EFEFEF0000000000FFFFFF0000000000000000001818
      18008C8C8C000000000000000000000000000000000000000000000000000000
      00000000000000FFFF0000FFFF00000000000000000000000000000000000000
      000000FFFF000084840000FFFF000084840000FFFF000084840000FFFF000000
      0000000000008484840000000000000000000000000000000000000000000000
      00000000000000000000000000000000000000949400F7F7F7008CFFFF008CFF
      FF008CFFFF008CFFFF008CD6FF008CFFFF008CFFFF008CFFFF008CFFFF008CFF
      FF008CFFFF008CFFFF008CFFFF008CFFFF00F7F7F700E7E7E7000000DE000000
      000052525200525252000000000052525200B5B5B500B5B5B500DEDEDE00DEDE
      DE00000000008CD6FF006BC6FF00003152000000000000000000000000000000
      000000000000000000000000000000000000000000000000000063CEFF0094AD
      AD0063CEFF0094ADAD0063CEFF00C6C6C60063CEFF000000000000000000319C
      CE0094ADAD0063CEFF0000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000063CEFF00C6C6C60063CE
      FF0094ADAD00319CCE0094ADAD000000000084848400737B7B00000000008484
      840018181800636363000000000018181800B5B5B50000000000000000001818
      18008C8C8C000000000000000000000000000000000000000000000000008484
      84000000000000FFFF0000FFFF00000000000000000000000000000000000000
      00000000000000FFFF000084840000FFFF000084840000FFFF0000FFFF000000
      0000848484008484840084848400000000000000000000000000000000000000
      00000000000000000000000000000000000000949400F7F7F7008CFFFF008CFF
      FF008CFFFF008CFFFF008CFFFF008CFFFF008CFFFF008CFFFF008CD6FF008CFF
      FF008CD6FF008CFFFF008CD6FF008CFFFF00F7F7F700F7F7F700DEDEDE00DEDE
      DE00DEDEDE00CECECE00C6DEC600C6C6C600CECECE00CECECE00CECECE00DEDE
      DE00000000008CFFFF006BC6FF00003152000000000000000000000000000000
      0000000000000000000000000000000000000000000063CEFF00C6C6C60063CE
      FF0094ADAD0063CEFF00EFEFEF0063CEFF00C6C6C60063CEFF00C6C6C6000000
      0000319CCE0094ADAD0000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000000063CEFF0094ADAD0063CEFF0094AD
      AD0063CEFF00C6C6C60063CEFF00000000009C9C9C00B5C6C600FFFFFF000000
      00007B7B7B0021212100ADADAD004A4A4A00B5B5B50000000000000000001818
      18008C8C8C000000000000000000000000000000000000000000000000000000
      000000FFFF0000FFFF0000FFFF00000000000000000084848400000000000000
      0000000000000000000000FFFF000084840000FFFF0000FFFF0000FFFF0000FF
      FF00000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000000000949400F7F7F7008CFFFF008CFF
      FF008CFFFF008CFFFF008CFFFF008CFFFF008CD6FF008CFFFF008CFFFF008CFF
      FF008CFFFF008CFFFF008CFFFF008CFFFF00F7F7F700F7F7F7000000DE000000
      000052525200B5B5B50000000000B5B5B500B5B5B50000000000CECECE00CECE
      CE00000000008CD6FF006BC6FF00003152000000000000000000000000000000
      00000000000000000000000000000000000000000000C6C6C60063CEFF00C6C6
      C60063CEFF00EFEFEF0063CEFF00EFEFEF0063CEFF00C6C6C60000000000319C
      CE0094ADAD00319CCE0000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000063CEFF00C6C6C60063CEFF0094ADAD0063CE
      FF00EFEFEF0063CEFF00C6C6C60063CEFF00848484005A5A5A00000000000000
      00000000000094949400ADADAD0000000000E7E7E70000000000000000002121
      210084848400000000000000000000000000000000000000000000FFFF0000FF
      FF0000FFFF0000FFFF0000FFFF0000FFFF000000000000000000C6C6C6000000
      000000000000000000000000000000FFFF0000FFFF0000FFFF0000FFFF0000FF
      FF0000FFFF0000FFFF0000FFFF00000000000000000000000000000000000000
      00000000000000000000000000000000000000949400F7F7F7008CFFFF008CFF
      FF008CFFFF008CFFFF008CFFFF008CFFFF008CFFFF008CFFFF008CFFFF008CFF
      FF008CFFFF008CD6FF008CFFFF008CFFFF00FFFFFF00FFFFFF00F7F7F700F7F7
      F700F7F7F700E7E7E700DEDEDE00CECECE00CECECE00C6C6C600C6C6C600CECE
      CE00000000008CFFFF006BC6FF00003152000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000C6C6C600319C
      CE0094ADAD0063CEFF00C6C6C6000000000094ADAD0063CEFF000000000094AD
      AD0063CEFF00C6C6C600319CCE0094ADAD000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000C6C6C60063CEFF00C6C6C60063CEFF00EFEF
      EF0063CEFF00EFEFEF0063CEFF00C6C6C6000000000000000000ADADAD000000
      0000000000006B6B6B0000000000000000000000000000000000ADADAD000000
      0000949494000000000000000000000000000000000000000000000000000000
      000000FFFF0000FFFF0000FFFF0000FFFF0000FFFF000000000000000000C6C6
      C60000000000000000000000000000FFFF0000FFFF0000FFFF0000FFFF0000FF
      FF00000000000000000000000000000000008484840000000000000000000000
      00000000000000000000000000000000000000949400F7F7F7008CFFFF008CFF
      FF008CFFFF008CFFFF008CFFFF008CFFFF008CFFFF008CFFFF008CD6FF008CFF
      FF008CFFFF008CFFFF008CFFFF008CD6FF008CFFFF008CFFFF008CFFFF008CFF
      FF008CFFFF008CFFFF008CFFFF008CD6FF008CFFFF008CFFFF008CD6FF008CD6
      FF008CFFFF008CD6FF006BC6FF00003152000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000319CCE0094ADAD0063CEFF000000000000000000000000000000000063CE
      FF00C6C6C600319CCE0094ADAD00000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000C6C6C600319CCE0094ADAD0063CE
      FF00C6C6C6000000000094ADAD0063CEFF0000000000ADADAD0000000000ADAD
      AD0000000000E7E7E700DEDEDE00FFFFFF0000000000FFFFFF0000000000ADAD
      AD00000000000000000000000000000000000000000000000000000000000000
      00000000000000FFFF0000FFFF0000FFFF0000FFFF0000FFFF00000000000000
      0000C6C6C600000000000000000000FFFF0000FFFF0000FFFF0000FFFF000000
      0000000000000000000000000000000000000000000084848400000000000000
      00000000000000000000000000000000000000949400F7F7F7008CFFFF008CFF
      FF008CFFFF008CFFFF008CFFFF008CFFFF008CFFFF008CFFFF008CFFFF008CFF
      FF008CFFFF008CFFFF008CFFFF008CFFFF008CFFFF008CFFFF008CD6FF008CFF
      FF008CD6FF008CFFFF008CD6FF008CFFFF008CD6FF008CFFFF008CFFFF008CFF
      FF008CD6FF008CFFFF006BC6FF00003152000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000319CCE00C6C6C60063CEFF00C6C6C600003131000000000094AD
      AD0000000000C6C6C600319CCE00000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000319CCE0094AD
      AD0063CEFF000000000000000000000000000000000063CEFF00C6C6C600319C
      CE0094ADAD000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000FFFF0000FFFF0000FFFF0000FFFF0000FFFF0000FFFF000000
      0000000000000000000000FFFF0000FFFF0000FFFF0000FFFF0000FFFF000000
      000084848400C6C6C600C6C6C600000000008484840000000000000000000000
      00000000000000000000000000000000000000949400F7F7F7008CFFFF008CFF
      FF008CFFFF008CFFFF008CFFFF008CFFFF008CFFFF008CFFFF008CFFFF008CFF
      FF008CD6FF008CFFFF008CD6FF008CFFFF008CD6FF008CFFFF008CFFFF008CFF
      FF008CFFFF008CFFFF008CFFFF008CFFFF008CFFFF008CD6FF008CFFFF008CD6
      FF008CFFFF008CD6FF006BC6FF00003152000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000319CCE00C6C6C60063CEFF00C6C6C60000000000319C
      CE00000000000000000000000000003163000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000000000000000000000000000319C
      CE00C6C6C60063CEFF00C6C6C600003131000000000094ADAD0000000000C6C6
      C600319CCE000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000FFFF0000FFFF0000FFFF0000FFFF0000FFFF0000FFFF0000FFFF0000FF
      FF0000FFFF0000FFFF0000FFFF0000FFFF0000FFFF0000FFFF0000FFFF0000FF
      FF000000000084848400C6C6C600C6C6C6000000000000000000000000000000
      00000000000000000000000000000000000000949400F7F7F7008CFFFF008CFF
      FF008CFFFF008CFFFF008CFFFF008CFFFF008CFFFF008CFFFF008CFFFF008CFF
      FF008CFFFF008CFFFF008CFFFF008CFFFF008CFFFF008CFFFF008CD6FF008CFF
      FF008CD6FF008CFFFF008CFFFF008CFFFF008CD6FF008CFFFF008CFFFF008CFF
      FF008CFFFF008CD6FF006BC6FF00003152000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000319CCE0094ADAD0063CEFF000000000094AD
      AD00319CCE0094ADAD0000313100003163000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000319CCE00C6C6C60063CEFF00C6C6C60000000000319CCE00000000000000
      0000000000000031630000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000FFFF0000FFFF0000FFFF0000FFFF0000FFFF0000FF
      FF0000FFFF0000FFFF0000FFFF0000FFFF0000FFFF0000FFFF0000FFFF000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000000000949400F7F7F7008CFFFF008CFF
      FF008CFFFF008CFFFF008CFFFF008CFFFF008CFFFF008CFFFF008CFFFF008CFF
      FF008CFFFF008CFFFF008CFFFF008CFFFF008CFFFF008CFFFF008CFFFF008CFF
      FF008CFFFF008CFFFF008CD6FF008CFFFF008CFFFF008CD6FF008CD6FF008CFF
      FF008CFFFF008CFFFF006BC6FF00003152000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000000000000000000000000000319C
      CE0094ADAD0063CEFF0094ADAD00000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000319CCE0094ADAD0063CEFF000000000094ADAD00319CCE0094AD
      AD00003131000031630000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000FFFF0000FFFF0000FFFF0000FFFF0000FF
      FF0000FFFF0000FFFF0000FFFF0000FFFF0000FFFF0000FFFF00000000000000
      0000000000000000000000000000848484000000000000000000000000000000
      00000000000000000000000000000000000000949400F7F7F7008CFFFF008CFF
      FF008CFFFF008CFFFF008CFFFF008CFFFF008CFFFF008CFFFF008CFFFF008CFF
      FF008CFFFF008CFFFF008CFFFF008CD6FF008CFFFF008CD6FF008CFFFF008CD6
      FF008CFFFF008CFFFF008CFFFF008CD6FF008CFFFF008CFFFF008CFFFF008CD6
      FF008CFFFF008CD6FF006BC6FF00003152000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000003131000000
      0000319CCE0094ADAD00319CCE00000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000000000000000319CCE0094ADAD0063CE
      FF0094ADAD000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00008484840084848400000000000000000000FFFF0000FFFF0000FFFF0000FF
      FF0000FFFF0000FFFF0000FFFF0000FFFF0000FFFF0000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000000000949400F7F7F7008CFFFF008CFF
      FF008CFFFF008CFFFF008CFFFF008CFFFF008CFFFF008CFFFF008CFFFF008CFF
      FF008CFFFF008CFFFF008CFFFF008CFFFF008CFFFF008CFFFF008CFFFF008CFF
      FF008CFFFF008CD6FF008CFFFF008CFFFF008CD6FF008CFFFF008CFFFF008CFF
      FF008CD6FF008CFFFF006BC6FF00080808000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000031310000313100000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000031310000000000319CCE0094AD
      AD00319CCE000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000084848400000000000000000000FFFF000000000000FFFF0000FF
      FF0000FFFF0000FFFF00000000000000000000FFFF0000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000000000949400F7F7F700F7F7F700F7F7
      F700F7F7F700F7F7F700F7F7F700F7F7F700F7F7F700F7F7F700F7F7F700F7F7
      F700F7F7F700F7F7F700F7F7F700F7F7F700F7F7F700F7F7F700F7F7F700F7F7
      F700F7F7F700F7F7F700F7F7F700F7F7F700F7F7F700F7F7F700F7F7F700F7F7
      F700F7F7F700F7F7F70000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000031310000313100003131000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000313100003131000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000000000000000848484000000000000FF
      FF0000FFFF000000000084848400000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000009494006BC6FF006BC6FF006BC6
      FF006BC6FF006BC6FF006BC6FF006BC6FF006BC6FF006BC6FF006BC6FF006BC6
      FF006BC6FF006BC6FF006BC6FF006BC6FF000094940000949400009494000094
      9400009494000094940000949400009494000094940000949400009494000094
      9400009494000094940000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000031
      3100003131000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000031
      3100003131000031310000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000084848400000000000000
      000000FFFF000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000949400F7FFFF008CFF
      FF008CFFFF008CFFFF008CFFFF008CFFFF008CFFFF008CFFFF008CFFFF008CFF
      FF008CFFFF008CFFFF008CFFFF00009494000808080000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000313100003131000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000000000000000000000949400F7F7
      F7008CFFFF008CFFFF008CFFFF008CFFFF008CFFFF008CFFFF008CFFFF008CFF
      FF008CFFFF008CFFFF0000949400080808000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000008484840084848400000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000094
      9400F7F7F7008CFFFF008CFFFF008CFFFF008CFFFF008CFFFF008CFFFF008CFF
      FF008CFFFF000094940008080800000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000009494000094940000949400009494000094940000949400009494000094
      9400009494000808080000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000424D3E000000000000003E000000
      2800000080000000600000000100010000000000000600000000000000000000
      000000000000000000000000FFFFFF0000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000FFFFFFFFFFFFFFFF0000000000000000
      FFFFFFFFF00000070000000000000000FFFFFFFFE00000030000000000000000
      FFFFFFFFE0000003000000000000000080000001E00000030000000000000000
      00000000C0000003000000000000000000000000C00000030000000000000000
      00000000C0000003000000000000000000000000C00000030000000000000000
      0000000080000003000000000000000000000000800000030000000000000000
      0000000080000003000000000000000000000000800000030000000000000000
      0000000000000003000000000000000000000000000000010000000000000000
      0000000000000000000000000000000000000000000000010000000000000000
      0000000000000003000000000000000000000000800000030000000000000000
      00000000E0000003000000000000000000000000E00000030000000000000000
      00000000E0000003000000000000000000000000E00000070000000000000000
      00000000E000000F000000000000000000000000E00001FF0000000000000000
      00000001F00003FF000000000000000000000003F80007FF0000000000000000
      80007FFFFFF80FFF0000000000000000C000FFFFFFFC1FFF0000000000000000
      E001FFFFFFFE3FFF0000000000000000F003FFFFFFFF7FFF0000000000000000
      FFFFFFFFFFFFFFFF0000000000000000FFFFFFFFFFFFFFFFFFFFFF07FFFFFFFF
      FFFFFFFFFFFF8803FFFFFE03FFFFFFFFFFFFFFFFFFFF8803FFFFFC11FFFF0007
      FF800007FFFF0A03FFFFF820FFFF0007FC00000FFE000203C000005E80000001
      F000000FF00020038000002000000000F000001FC00034030016914F00000000
      F000003FC0008023502E480F00000000F800007FC000C903405C910F00000000
      F80003FFE000C1037FFFF80000000000FC0007FFE000C0530000040200000000
      FE000FFFF000C003E000020500000000FE000FFFF800C903C00009FB00000000
      FC0003FFF80080A7D000080700000000F80001FFF0001427E8C011FF00000000
      F80001FFE0002227E0C000FF00000000F00001FFE0000027808001FF00000000
      F00000FFC0002827404000FF00000000F000007FC000888770200E7F00000000
      F00000FFC000888F8810103F00000000F00000FFC00003FFC000013F00000000
      F00000FFC00003FFE00000BF00000000F00000FFC00003FFDC00107F00000000
      F80000FFC00003FFD20008FF00000000F800007FE00003FFE10014FF00000000
      FC00007FE00001FFF1010AFF00000001FF00007FF00001FFFB00C1FF00000003
      FFE000FFFC0001FFFC9127FF80007FFFFFF803FFFF8003FFFE5817FFC000FFFF
      FFFFFFFFFFE00FFFFF040FFFE001FFFFFFFFFFFFFFFFFFFFFFF2FFFFF003FFFF
      FFFFFFFFFFFFFFFFFFF9FFFFFFFFFFFF00000000000000000000000000000000
      000000000000}
  end
  object TickTimer: TTimer
    Enabled = False
    Interval = 300
    OnTimer = TickTimerTimer
    Left = 176
    Top = 4
  end
  object OpenDialog1: TOpenDialog
    Filter = 'Loader File|*.LD'
    Left = 136
    Top = 39
  end
  object SaveDialog1: TSaveDialog
    Options = [ofOverwritePrompt, ofHideReadOnly, ofEnableSizing]
    Left = 172
    Top = 40
  end
end
