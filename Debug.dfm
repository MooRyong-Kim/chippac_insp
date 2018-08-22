object DebugForm: TDebugForm
  Left = 373
  Top = 237
  BorderIcons = [biSystemMenu, biMinimize]
  BorderStyle = bsSingle
  Caption = 'Motion Simulation'
  ClientHeight = 384
  ClientWidth = 565
  Color = 16119543
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  FormStyle = fsStayOnTop
  OldCreateOrder = False
  PopupMenu = PopupMenu1
  Position = poMainFormCenter
  OnClose = FormClose
  OnCreate = FormCreate
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object Shape1: TShape
    Left = 380
    Top = 40
    Width = 120
    Height = 40
    Brush.Color = 16119543
    Pen.Width = 4
  end
  object Shape2: TShape
    Left = 380
    Top = 124
    Width = 120
    Height = 40
    Brush.Color = 16119543
    Pen.Width = 4
  end
  object Shape3: TShape
    Left = 12
    Top = 76
    Width = 120
    Height = 40
    Brush.Color = clBlack
    Brush.Style = bsHorizontal
    Pen.Width = 2
  end
  object Shape4: TShape
    Left = 12
    Top = 124
    Width = 120
    Height = 40
    Brush.Color = clBlack
    Brush.Style = bsHorizontal
    Pen.Width = 2
  end
  object Shape5: TShape
    Left = 12
    Top = 172
    Width = 120
    Height = 40
    Brush.Color = clBlack
    Brush.Style = bsHorizontal
    Pen.Width = 2
  end
  object InspPnl: TPanel
    Left = 140
    Top = 24
    Width = 100
    Height = 35
    BevelWidth = 2
    Color = clBlue
    TabOrder = 0
    object InspZoneDctChkBox: TCheckBox
      Left = 43
      Top = 9
      Width = 16
      Height = 17
      TabOrder = 0
    end
  end
  object UlPnl: TPanel
    Left = 414
    Top = 178
    Width = 77
    Height = 188
    BevelOuter = bvNone
    Color = clBlue
    TabOrder = 17
    object TPanel
      Left = 0
      Top = 0
      Width = 51
      Height = 188
      Align = alLeft
      BevelOuter = bvNone
      Color = 16119543
      TabOrder = 0
    end
    object Panel2: TPanel
      Left = 51
      Top = 0
      Width = 26
      Height = 188
      Align = alClient
      BevelWidth = 2
      Color = clGray
      TabOrder = 1
      object MgzGripGoodChkBox: TCheckBox
        Left = 5
        Top = 136
        Width = 16
        Height = 17
        TabOrder = 0
      end
    end
    object MgzPnl: TPanel
      Left = -2
      Top = 103
      Width = 53
      Height = 73
      BevelWidth = 2
      Color = clBlue
      TabOrder = 2
      object GoodMgzDrawBox: TPaintBox
        Left = 2
        Top = 6
        Width = 47
        Height = 61
      end
    end
  end
  object RejMgzPnl: TPanel
    Left = 505
    Top = 40
    Width = 51
    Height = 73
    BevelWidth = 2
    Color = clBlue
    TabOrder = 1
    object RejMgzDrawBox: TPaintBox
      Left = 1
      Top = 6
      Width = 47
      Height = 61
    end
  end
  object Panel4: TPanel
    Left = 200
    Top = 254
    Width = 200
    Height = 13
    TabOrder = 19
    object Shape7: TShape
      Left = 1
      Top = 1
      Width = 198
      Height = 11
      Align = alClient
      Pen.Width = 2
    end
  end
  object Panel3: TPanel
    Left = 200
    Top = 352
    Width = 200
    Height = 13
    TabOrder = 22
    object Shape6: TShape
      Left = 1
      Top = 1
      Width = 198
      Height = 11
      Align = alClient
      Pen.Width = 2
    end
  end
  object Roll3DctChkBox: TCheckBox
    Left = 60
    Top = 88
    Width = 16
    Height = 17
    TabOrder = 7
  end
  object Roll2DctChkBox: TCheckBox
    Left = 60
    Top = 136
    Width = 16
    Height = 17
    TabOrder = 13
  end
  object Roll1DctChkBox: TCheckBox
    Left = 60
    Top = 184
    Width = 16
    Height = 17
    TabOrder = 18
  end
  object RejCvyStprDctChkBox: TCheckBox
    Left = 437
    Top = 52
    Width = 16
    Height = 17
    TabOrder = 4
  end
  object UlCvyStprDctChkBox: TCheckBox
    Left = 437
    Top = 136
    Width = 16
    Height = 17
    TabOrder = 14
  end
  object TPanel
    Left = 386
    Top = 344
    Width = 13
    Height = 8
    Color = clBlack
    TabOrder = 21
  end
  object TPanel
    Left = 128
    Top = 78
    Width = 8
    Height = 36
    BevelOuter = bvNone
    Color = 16119543
    TabOrder = 6
  end
  object TPanel
    Left = 128
    Top = 126
    Width = 8
    Height = 36
    BevelOuter = bvNone
    Color = 16119543
    TabOrder = 10
  end
  object TPanel
    Left = 127
    Top = 174
    Width = 8
    Height = 36
    BevelOuter = bvNone
    Color = 16119543
    TabOrder = 16
  end
  object TPanel
    Left = 8
    Top = 78
    Width = 8
    Height = 36
    BevelOuter = bvNone
    Color = 16119543
    TabOrder = 5
  end
  object TPanel
    Left = 8
    Top = 126
    Width = 8
    Height = 36
    BevelOuter = bvNone
    Color = 16119543
    TabOrder = 9
  end
  object TPanel
    Left = 7
    Top = 174
    Width = 8
    Height = 36
    BevelOuter = bvNone
    Color = 16119543
    TabOrder = 15
  end
  object TPanel
    Left = 379
    Top = 44
    Width = 8
    Height = 32
    BevelOuter = bvNone
    Color = 16119543
    TabOrder = 2
  end
  object TPanel
    Left = 379
    Top = 128
    Width = 8
    Height = 32
    BevelOuter = bvNone
    Color = 16119543
    TabOrder = 11
  end
  object TPanel
    Left = 495
    Top = 44
    Width = 8
    Height = 32
    BevelOuter = bvNone
    Color = 16119543
    TabOrder = 3
  end
  object TPanel
    Left = 496
    Top = 128
    Width = 8
    Height = 32
    BevelOuter = bvNone
    Color = 16119543
    TabOrder = 12
  end
  object InspRdyOkChkBox: TCheckBox
    Left = 45
    Top = 328
    Width = 128
    Height = 17
    Caption = 'Inspection Ready Ok'
    Checked = True
    State = cbChecked
    TabOrder = 20
  end
  object Panel1: TPanel
    Left = 252
    Top = 99
    Width = 11
    Height = 11
    Color = clRed
    TabOrder = 8
  end
  object DrawTimer: TTimer
    Enabled = False
    Interval = 1
    OnTimer = DrawTimerTimer
    Left = 16
    Top = 244
  end
  object PopupMenu1: TPopupMenu
    Left = 24
    Top = 288
    object PositionReset1: TMenuItem
      Caption = 'Position Reset'
      OnClick = MenuItemClick
    end
    object Home1: TMenuItem
      Caption = 'Home'
      OnClick = MenuItemClick
    end
  end
end
