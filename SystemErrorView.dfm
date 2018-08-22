object SystemErrorViewForm: TSystemErrorViewForm
  Left = 903
  Top = 532
  AutoScroll = False
  BorderIcons = [biSystemMenu]
  Caption = '[System Error View]'
  ClientHeight = 246
  ClientWidth = 680
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  FormStyle = fsStayOnTop
  OldCreateOrder = False
  Position = poMainFormCenter
  Scaled = False
  OnCreate = FormCreate
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 7
    Top = 188
    Width = 660
    Height = 20
    Caption = 
      'The error message is automatically saved. (.exe file location\ER' +
      'ROR\DATE Folder)'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object memoSysError: TMemo
    Left = 8
    Top = 24
    Width = 665
    Height = 161
    BiDiMode = bdLeftToRight
    BorderStyle = bsNone
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    HideSelection = False
    ImeName = 'Microsoft IME 2010'
    Lines.Strings = (
      'memoSysError')
    ParentBiDiMode = False
    ParentFont = False
    ParentShowHint = False
    ReadOnly = True
    ShowHint = False
    TabOrder = 0
    WantReturns = False
  end
  object btnClose: TButton
    Left = 296
    Top = 213
    Width = 89
    Height = 25
    Caption = 'OK'
    TabOrder = 1
    OnClick = btnCloseClick
  end
end
