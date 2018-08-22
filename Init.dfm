object InitForm: TInitForm
  Left = 494
  Top = 209
  BorderStyle = bsDialog
  Caption = 'Machine Initialize...'
  ClientHeight = 373
  ClientWidth = 553
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  FormStyle = fsStayOnTop
  OldCreateOrder = False
  Position = poMainFormCenter
  OnClose = FormClose
  OnCloseQuery = FormCloseQuery
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object HomeSensGrpBox: TGroupBox
    Left = 8
    Top = 8
    Width = 181
    Height = 361
    Caption = 'Home Completed : '
    Color = clBtnFace
    Font.Charset = ANSI_CHARSET
    Font.Color = clBlack
    Font.Height = -11
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentColor = False
    ParentFont = False
    TabOrder = 0
  end
  object InitPgsViewGrpBox: TGroupBox
    Left = 200
    Top = 8
    Width = 345
    Height = 325
    Caption = 'Initialize Status: '
    Font.Charset = ANSI_CHARSET
    Font.Color = clBlack
    Font.Height = -11
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 1
    object InitMsgListBox: TListBox
      Left = 2
      Top = 85
      Width = 341
      Height = 238
      Style = lbOwnerDrawFixed
      Align = alClient
      BorderStyle = bsNone
      Color = clBlack
      Font.Charset = ANSI_CHARSET
      Font.Color = clLime
      Font.Height = -13
      Font.Name = 'Tahoma'
      Font.Style = []
      ImeName = #54620#44397#50612'('#54620#44544') (MS-IME98)'
      ItemHeight = 17
      ParentFont = False
      TabOrder = 1
    end
    object Panel3: TPanel
      Left = 2
      Top = 15
      Width = 341
      Height = 70
      Align = alTop
      BevelInner = bvRaised
      BevelOuter = bvLowered
      TabOrder = 0
      object StartBtn: TRzButton
        Left = 36
        Top = 12
        Width = 120
        Height = 45
        GroupIndex = 1
        ShowDownPattern = False
        ShowFocusRect = False
        Caption = 'START'
        Color = clGreen
        Font.Charset = ANSI_CHARSET
        Font.Color = clBlack
        Font.Height = -21
        Font.Name = 'Tahoma'
        Font.Style = [fsBold]
        ParentFont = False
        TabOrder = 0
        TextStyle = tsRecessed
        OnClick = InitBtnClick
      end
      object StopBtn: TRzButton
        Left = 188
        Top = 12
        Width = 120
        Height = 45
        GroupIndex = 1
        Down = True
        ShowDownPattern = False
        ShowFocusRect = False
        Caption = 'STOP'
        Color = clRed
        Font.Charset = ANSI_CHARSET
        Font.Color = clBlack
        Font.Height = -21
        Font.Name = 'Tahoma'
        Font.Style = [fsBold]
        ParentFont = False
        TabOrder = 1
        TextStyle = tsRecessed
        OnClick = InitBtnClick
      end
    end
  end
  object BitBtn1: TBitBtn
    Left = 335
    Top = 340
    Width = 75
    Height = 25
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    TabOrder = 2
    Kind = bkClose
  end
  object TickTimer: TTimer
    Enabled = False
    Interval = 1
    OnTimer = TickTimerTimer
    Left = 504
    Top = 4
  end
end
