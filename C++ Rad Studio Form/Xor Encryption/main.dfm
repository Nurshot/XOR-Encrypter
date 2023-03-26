object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Form1'
  ClientHeight = 150
  ClientWidth = 249
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  TextHeight = 15
  object Label1: TLabel
    Left = 2
    Top = 80
    Width = 87
    Height = 15
    Caption = 'Encrypted Value:'
  end
  object Label2: TLabel
    Left = 2
    Top = 115
    Width = 88
    Height = 15
    Caption = 'Decrypted Value:'
  end
  object Edit1: TEdit
    Left = 16
    Top = 8
    Width = 185
    Height = 23
    TabOrder = 0
  end
  object Button1: TButton
    Left = 16
    Top = 37
    Width = 89
    Height = 25
    Caption = 'Encrypt'
    TabOrder = 1
    OnClick = Button1Click
  end
  object Edit2: TEdit
    Left = 92
    Top = 77
    Width = 141
    Height = 23
    TabOrder = 2
  end
  object Edit3: TEdit
    Left = 92
    Top = 112
    Width = 141
    Height = 23
    TabOrder = 3
  end
  object Button2: TButton
    Left = 120
    Top = 37
    Width = 81
    Height = 25
    Caption = 'Decrypt'
    TabOrder = 4
    OnClick = Button2Click
  end
  object CheckBox1: TCheckBox
    Left = 207
    Top = 8
    Width = 49
    Height = 17
    Caption = 'Top'
    TabOrder = 5
    OnClick = CheckBox1Click
  end
end
