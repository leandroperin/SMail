object frmSettings: TfrmSettings
  Left = 0
  Top = 0
  BorderIcons = [biSystemMenu, biMinimize]
  BorderStyle = bsDialog
  Caption = 'Configura'#231#245'es de Simula'#231#227'o'
  ClientHeight = 396
  ClientWidth = 892
  Color = clBtnFace
  TransparentColorValue = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  Position = poScreenCenter
  PixelsPerInch = 96
  TextHeight = 13
  object lblTSTECHelp: TLabel
    Left = 8
    Top = 351
    Width = 210
    Height = 13
    Caption = 'TEC e TS s'#227'o calculados em segundos'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
    Transparent = True
  end
  object lvlMaxSimTime: TLabel
    Left = 8
    Top = 320
    Width = 155
    Height = 13
    Caption = 'Tempo m'#225'ximo de simula'#231#227'o (s):'
  end
  object lblMessageTimeLimit: TLabel
    Left = 264
    Top = 320
    Width = 114
    Height = 13
    Caption = 'T. Limite Mensagem (s):'
  end
  object boxTrafVol: TGroupBox
    Left = 8
    Top = 8
    Width = 233
    Height = 89
    Caption = 'Volume de Tr'#225'fego (%)'
    DoubleBuffered = False
    ParentDoubleBuffered = False
    TabOrder = 0
    object lblLL: TLabel
      Left = 18
      Top = 24
      Width = 14
      Height = 13
      Caption = 'LL:'
    end
    object lblLR: TLabel
      Left = 16
      Top = 51
      Width = 16
      Height = 13
      Caption = 'LR:'
    end
    object lblRR: TLabel
      Left = 120
      Top = 24
      Width = 18
      Height = 13
      Caption = 'RR:'
    end
    object lblRL: TLabel
      Left = 122
      Top = 51
      Width = 16
      Height = 13
      Caption = 'RL:'
    end
    object edtLL: TEdit
      Left = 48
      Top = 21
      Width = 49
      Height = 21
      TabOrder = 0
      Text = '50'
    end
    object edtLR: TEdit
      Left = 48
      Top = 48
      Width = 49
      Height = 21
      TabOrder = 1
      Text = '25'
    end
    object edtRR: TEdit
      Left = 160
      Top = 21
      Width = 49
      Height = 21
      TabOrder = 2
      Text = '10'
    end
    object edtRL: TEdit
      Left = 160
      Top = 48
      Width = 49
      Height = 21
      TabOrder = 3
      Text = '15'
    end
  end
  object btnReset: TButton
    Left = 264
    Top = 352
    Width = 201
    Height = 25
    Caption = 'Resetar Valores'
    TabOrder = 2
    OnClick = btnResetClick
  end
  object boxResProp: TGroupBox
    Left = 8
    Top = 103
    Width = 233
    Height = 186
    Caption = 'Taxas de S / F / A'
    TabOrder = 1
    object lblSucess: TLabel
      Left = 48
      Top = 32
      Width = 39
      Height = 13
      Caption = 'Sucesso'
    end
    object lblFail: TLabel
      Left = 103
      Top = 32
      Width = 43
      Height = 13
      Caption = 'Fracasso'
    end
    object lblLater: TLabel
      Left = 160
      Top = 32
      Width = 51
      Height = 13
      Caption = 'Adiamento'
    end
    object lblLL2: TLabel
      Left = 18
      Top = 64
      Width = 10
      Height = 13
      Caption = 'LL'
    end
    object lblLR2: TLabel
      Left = 18
      Top = 91
      Width = 12
      Height = 13
      Caption = 'LR'
    end
    object lblRL2: TLabel
      Left = 18
      Top = 117
      Width = 12
      Height = 13
      Caption = 'RL'
    end
    object lblRR2: TLabel
      Left = 18
      Top = 144
      Width = 14
      Height = 13
      Caption = 'RR'
    end
    object edtLLS: TEdit
      Left = 48
      Top = 61
      Width = 49
      Height = 21
      TabOrder = 0
      Text = '87,00'
    end
    object edtLLF: TEdit
      Left = 103
      Top = 61
      Width = 49
      Height = 21
      TabOrder = 1
      Text = '0,50'
    end
    object edtLLA: TEdit
      Left = 158
      Top = 61
      Width = 49
      Height = 21
      TabOrder = 2
      Text = '12,50'
    end
    object edtLRS: TEdit
      Left = 48
      Top = 88
      Width = 49
      Height = 21
      TabOrder = 3
      Text = '96,00'
    end
    object edtLRF: TEdit
      Left = 103
      Top = 88
      Width = 49
      Height = 21
      TabOrder = 4
      Text = '1,50'
    end
    object edtLRA: TEdit
      Left = 158
      Top = 88
      Width = 49
      Height = 21
      TabOrder = 5
      Text = '2,50'
    end
    object edtRRS: TEdit
      Left = 48
      Top = 142
      Width = 49
      Height = 21
      TabOrder = 9
      Text = '90,00'
    end
    object edtRRF: TEdit
      Left = 103
      Top = 142
      Width = 49
      Height = 21
      TabOrder = 10
      Text = '1,00'
    end
    object edtRRA: TEdit
      Left = 158
      Top = 142
      Width = 49
      Height = 21
      TabOrder = 11
      Text = '9,00'
    end
    object edtRLS: TEdit
      Left = 48
      Top = 115
      Width = 49
      Height = 21
      TabOrder = 6
      Text = '96,00'
    end
    object edtRLF: TEdit
      Left = 103
      Top = 115
      Width = 49
      Height = 21
      TabOrder = 7
      Text = '3,00'
    end
    object edtRLA: TEdit
      Left = 158
      Top = 115
      Width = 49
      Height = 21
      TabOrder = 8
      Text = '1,00'
    end
  end
  object boxServiceCenter: TGroupBox
    Left = 264
    Top = 8
    Width = 201
    Height = 89
    Caption = 'Centro de Servi'#231'o'
    TabOrder = 3
    object lblWorkersAmount: TLabel
      Left = 65
      Top = 20
      Width = 125
      Height = 13
      Caption = 'Quantidade de Servidores'
    end
    object lblCenter1: TLabel
      Left = 11
      Top = 45
      Width = 42
      Height = 13
      Caption = 'Centro 1'
    end
    object lblCenter2: TLabel
      Left = 11
      Top = 67
      Width = 42
      Height = 13
      Caption = 'Centro 2'
    end
    object edtCenter1Capacity: TEdit
      Left = 72
      Top = 40
      Width = 121
      Height = 21
      TabOrder = 0
      Text = '10'
    end
    object edtCenter2Capacity: TEdit
      Left = 72
      Top = 63
      Width = 121
      Height = 21
      TabOrder = 1
      Text = '20'
    end
  end
  object boxTEC: TGroupBox
    Left = 264
    Top = 103
    Width = 201
    Height = 186
    Caption = 'Tempo entre Chegadas (TEC)'
    TabOrder = 4
    object lblTECSource: TLabel
      Left = 16
      Top = 64
      Width = 34
      Height = 13
      Caption = 'Origem'
    end
    object lblTECTime: TLabel
      Left = 112
      Top = 64
      Width = 51
      Height = 13
      Caption = 'TEC (seg.)'
    end
    object lblTECLocal: TLabel
      Left = 16
      Top = 93
      Width = 24
      Height = 13
      Caption = 'Local'
    end
    object lblTECRemote: TLabel
      Left = 16
      Top = 121
      Width = 37
      Height = 13
      Caption = 'Remota'
    end
    object lblTECHelp: TLabel
      Left = 16
      Top = 37
      Width = 167
      Height = 13
      Caption = 'Modelado atrav'#233's de uma EXPO(y)'
    end
    object edtTECLocal: TEdit
      Left = 72
      Top = 93
      Width = 121
      Height = 21
      TabOrder = 0
      Text = '0,5'
    end
    object edtTECRemote: TEdit
      Left = 72
      Top = 120
      Width = 121
      Height = 21
      TabOrder = 1
      Text = '0,6'
    end
  end
  object boxWorkingTimes: TGroupBox
    Left = 488
    Top = 8
    Width = 396
    Height = 369
    Caption = 'Tempos de Servi'#231'o (TS)'
    TabOrder = 5
    object lblTSType: TLabel
      Left = 16
      Top = 24
      Width = 20
      Height = 13
      Caption = 'Tipo'
    end
    object lblTSRecCenter: TLabel
      Left = 64
      Top = 24
      Width = 98
      Height = 13
      Caption = 'Centro de Recep'#231#227'o'
    end
    object lblTSWorkingCenter: TLabel
      Left = 240
      Top = 24
      Width = 86
      Height = 13
      Caption = 'Centro de Servi'#231'o'
    end
    object lblLLS: TLabel
      Left = 16
      Top = 46
      Width = 16
      Height = 13
      Caption = 'LLS'
    end
    object lblLLF: TLabel
      Left = 16
      Top = 73
      Width = 16
      Height = 13
      Caption = 'LLF'
    end
    object lblLLA: TLabel
      Left = 16
      Top = 100
      Width = 17
      Height = 13
      Caption = 'LLA'
    end
    object lblLRS: TLabel
      Left = 16
      Top = 127
      Width = 18
      Height = 13
      Caption = 'LRS'
    end
    object lblLRF: TLabel
      Left = 16
      Top = 154
      Width = 18
      Height = 13
      Caption = 'LRF'
    end
    object lblLRA: TLabel
      Left = 16
      Top = 181
      Width = 19
      Height = 13
      Caption = 'LRA'
    end
    object lblRLS: TLabel
      Left = 16
      Top = 208
      Width = 18
      Height = 13
      Caption = 'RLS'
    end
    object lblRLF: TLabel
      Left = 16
      Top = 235
      Width = 18
      Height = 13
      Caption = 'RLF'
    end
    object lblRLA: TLabel
      Left = 16
      Top = 262
      Width = 19
      Height = 13
      Caption = 'RLA'
    end
    object lblRRS: TLabel
      Left = 16
      Top = 289
      Width = 20
      Height = 13
      Caption = 'RRS'
    end
    object lblRRF: TLabel
      Left = 16
      Top = 316
      Width = 20
      Height = 13
      Caption = 'RRF'
    end
    object lblRRA: TLabel
      Left = 16
      Top = 343
      Width = 21
      Height = 13
      Caption = 'RRA'
    end
    object edtLLSRec: TEdit
      Left = 72
      Top = 43
      Width = 50
      Height = 21
      TabOrder = 0
      Text = '0,12'
    end
    object edtLLFRec: TEdit
      Left = 72
      Top = 70
      Width = 50
      Height = 21
      TabOrder = 1
      Text = '0,14'
    end
    object edtLLARec: TEdit
      Left = 72
      Top = 97
      Width = 50
      Height = 21
      TabOrder = 2
      Text = '0,11'
    end
    object edtLRSRec: TEdit
      Left = 72
      Top = 124
      Width = 50
      Height = 21
      TabOrder = 3
      Text = '0,12'
    end
    object edtLRFRec: TEdit
      Left = 72
      Top = 151
      Width = 50
      Height = 21
      TabOrder = 4
      Text = '0,13'
    end
    object edtLRARec: TEdit
      Left = 72
      Top = 178
      Width = 50
      Height = 21
      TabOrder = 5
      Text = '0,15'
    end
    object edtRLSRec: TEdit
      Left = 72
      Top = 205
      Width = 50
      Height = 21
      TabOrder = 6
      Text = '0,12'
    end
    object edtRLFRec: TEdit
      Left = 72
      Top = 232
      Width = 50
      Height = 21
      TabOrder = 7
      Text = '0,14'
    end
    object edtRLARec: TEdit
      Left = 72
      Top = 259
      Width = 50
      Height = 21
      TabOrder = 8
      Text = '0,11'
    end
    object edtRRSRec: TEdit
      Left = 72
      Top = 286
      Width = 50
      Height = 21
      TabOrder = 9
      Text = '0,16'
    end
    object edtRRFRec: TEdit
      Left = 72
      Top = 313
      Width = 50
      Height = 21
      TabOrder = 10
      Text = '0,13'
    end
    object edtRRARec: TEdit
      Left = 72
      Top = 340
      Width = 50
      Height = 21
      TabOrder = 11
      Text = '0,16'
    end
    object comboLLS: TComboBox
      Left = 176
      Top = 43
      Width = 73
      Height = 21
      ItemIndex = 0
      TabOrder = 12
      Text = 'Normal'
      OnSelect = comboLLSSelect
      Items.Strings = (
        'Normal'
        'Triangular'
        'Uniforme'
        'Constante')
    end
    object edtLLSTS1: TEdit
      Left = 255
      Top = 43
      Width = 41
      Height = 21
      TabOrder = 13
      Text = '0,55'
    end
    object edtLLSTS2: TEdit
      Left = 302
      Top = 43
      Width = 41
      Height = 21
      TabOrder = 14
      Text = '0,05'
    end
    object edtLLSTS3: TEdit
      Left = 347
      Top = 43
      Width = 41
      Height = 21
      TabOrder = 15
      Text = '0,00'
      Visible = False
    end
    object comboLLF: TComboBox
      Left = 176
      Top = 70
      Width = 73
      Height = 21
      ItemIndex = 1
      TabOrder = 16
      Text = 'Triangular'
      OnSelect = comboLLFSelect
      Items.Strings = (
        'Normal'
        'Triangular'
        'Uniforme'
        'Constante')
    end
    object edtLLFTS1: TEdit
      Left = 255
      Top = 70
      Width = 41
      Height = 21
      TabOrder = 17
      Text = '0,02'
    end
    object edtLLFTS2: TEdit
      Left = 302
      Top = 70
      Width = 41
      Height = 21
      TabOrder = 18
      Text = '0,05'
    end
    object edtLLFTS3: TEdit
      Left = 347
      Top = 70
      Width = 41
      Height = 21
      TabOrder = 19
      Text = '0,12'
    end
    object comboLLA: TComboBox
      Left = 176
      Top = 97
      Width = 73
      Height = 21
      ItemIndex = 2
      TabOrder = 20
      Text = 'Uniforme'
      OnSelect = comboLLASelect
      Items.Strings = (
        'Normal'
        'Triangular'
        'Uniforme'
        'Constante')
    end
    object edtLLATS1: TEdit
      Left = 255
      Top = 97
      Width = 41
      Height = 21
      TabOrder = 21
      Text = '0,06'
    end
    object edtLLATS2: TEdit
      Left = 302
      Top = 97
      Width = 41
      Height = 21
      TabOrder = 22
      Text = '0,15'
    end
    object edtLLATS3: TEdit
      Left = 347
      Top = 97
      Width = 41
      Height = 21
      TabOrder = 23
      Text = '0,00'
      Visible = False
    end
    object comboLRS: TComboBox
      Left = 176
      Top = 124
      Width = 73
      Height = 21
      ItemIndex = 0
      TabOrder = 24
      Text = 'Normal'
      OnSelect = comboLRSSelect
      Items.Strings = (
        'Normal'
        'Triangular'
        'Uniforme'
        'Constante')
    end
    object edtLRSTS1: TEdit
      Left = 255
      Top = 124
      Width = 41
      Height = 21
      TabOrder = 25
      Text = '0,65'
    end
    object edtLRSTS2: TEdit
      Left = 302
      Top = 124
      Width = 41
      Height = 21
      TabOrder = 26
      Text = '0,04'
    end
    object edtLRSTS3: TEdit
      Left = 347
      Top = 124
      Width = 41
      Height = 21
      TabOrder = 27
      Text = '0,00'
      Visible = False
    end
    object comboLRF: TComboBox
      Left = 176
      Top = 151
      Width = 73
      Height = 21
      ItemIndex = 2
      TabOrder = 28
      Text = 'Uniforme'
      OnSelect = comboLRFSelect
      Items.Strings = (
        'Normal'
        'Triangular'
        'Uniforme'
        'Constante')
    end
    object edtLRFTS1: TEdit
      Left = 255
      Top = 151
      Width = 41
      Height = 21
      TabOrder = 29
      Text = '0,16'
    end
    object edtLRFTS2: TEdit
      Left = 302
      Top = 151
      Width = 41
      Height = 21
      TabOrder = 30
      Text = '0,25'
    end
    object edtLRFTS3: TEdit
      Left = 347
      Top = 151
      Width = 41
      Height = 21
      TabOrder = 31
      Text = '0,00'
      Visible = False
    end
    object comboLRA: TComboBox
      Left = 176
      Top = 178
      Width = 73
      Height = 21
      ItemIndex = 1
      TabOrder = 32
      Text = 'Triangular'
      OnSelect = comboLRASelect
      Items.Strings = (
        'Normal'
        'Triangular'
        'Uniforme'
        'Constante')
    end
    object edtLRATS1: TEdit
      Left = 255
      Top = 178
      Width = 41
      Height = 21
      TabOrder = 33
      Text = '0,05'
    end
    object edtLRATS2: TEdit
      Left = 302
      Top = 178
      Width = 41
      Height = 21
      TabOrder = 34
      Text = '0,07'
    end
    object edtLRATS3: TEdit
      Left = 347
      Top = 178
      Width = 41
      Height = 21
      TabOrder = 35
      Text = '0,10'
    end
    object comboRLS: TComboBox
      Left = 176
      Top = 205
      Width = 73
      Height = 21
      ItemIndex = 2
      TabOrder = 36
      Text = 'Uniforme'
      OnSelect = comboRLSSelect
      Items.Strings = (
        'Normal'
        'Triangular'
        'Uniforme'
        'Constante')
    end
    object edtRLSTS1: TEdit
      Left = 255
      Top = 205
      Width = 41
      Height = 21
      TabOrder = 37
      Text = '0,03'
    end
    object edtRLSTS2: TEdit
      Left = 302
      Top = 205
      Width = 41
      Height = 21
      TabOrder = 38
      Text = '0,11'
    end
    object edtRLSTS3: TEdit
      Left = 347
      Top = 205
      Width = 41
      Height = 21
      TabOrder = 39
      Text = '0,00'
      Visible = False
    end
    object comboRLF: TComboBox
      Left = 176
      Top = 232
      Width = 73
      Height = 21
      ItemIndex = 0
      TabOrder = 40
      Text = 'Normal'
      OnSelect = comboRLFSelect
      Items.Strings = (
        'Normal'
        'Triangular'
        'Uniforme'
        'Constante')
    end
    object edtRLFTS1: TEdit
      Left = 255
      Top = 232
      Width = 41
      Height = 21
      TabOrder = 41
      Text = '0,46'
    end
    object edtRLFTS2: TEdit
      Left = 302
      Top = 232
      Width = 41
      Height = 21
      TabOrder = 42
      Text = '0,05'
    end
    object edtRLFTS3: TEdit
      Left = 347
      Top = 232
      Width = 41
      Height = 21
      TabOrder = 43
      Text = '0,00'
      Visible = False
    end
    object comboRLA: TComboBox
      Left = 176
      Top = 259
      Width = 73
      Height = 21
      ItemIndex = 0
      TabOrder = 44
      Text = 'Normal'
      OnSelect = comboRLASelect
      Items.Strings = (
        'Normal'
        'Triangular'
        'Uniforme'
        'Constante')
    end
    object edtRLATS1: TEdit
      Left = 255
      Top = 259
      Width = 41
      Height = 21
      TabOrder = 45
      Text = '0,72'
    end
    object edtRLATS2: TEdit
      Left = 302
      Top = 259
      Width = 41
      Height = 21
      TabOrder = 46
      Text = '0,09'
    end
    object edtRLATS3: TEdit
      Left = 347
      Top = 259
      Width = 41
      Height = 21
      TabOrder = 47
      Text = '0,00'
      Visible = False
    end
    object comboRRS: TComboBox
      Left = 176
      Top = 286
      Width = 73
      Height = 21
      ItemIndex = 2
      TabOrder = 48
      Text = 'Uniforme'
      OnSelect = comboRRSSelect
      Items.Strings = (
        'Normal'
        'Triangular'
        'Uniforme'
        'Constante')
    end
    object edtRRSTS1: TEdit
      Left = 255
      Top = 286
      Width = 41
      Height = 21
      TabOrder = 49
      Text = '0,09'
    end
    object edtRRSTS2: TEdit
      Left = 302
      Top = 286
      Width = 41
      Height = 21
      TabOrder = 50
      Text = '0,18'
    end
    object edtRRSTS3: TEdit
      Left = 347
      Top = 286
      Width = 41
      Height = 21
      TabOrder = 51
      Text = '0,00'
      Visible = False
    end
    object comboRRF: TComboBox
      Left = 176
      Top = 313
      Width = 73
      Height = 21
      ItemIndex = 1
      TabOrder = 52
      Text = 'Triangular'
      OnSelect = comboRRFSelect
      Items.Strings = (
        'Normal'
        'Triangular'
        'Uniforme'
        'Constante')
    end
    object edtRRFTS1: TEdit
      Left = 255
      Top = 313
      Width = 41
      Height = 21
      TabOrder = 53
      Text = '0,08'
    end
    object edtRRFTS2: TEdit
      Left = 302
      Top = 313
      Width = 41
      Height = 21
      TabOrder = 54
      Text = '0,15'
    end
    object edtRRFTS3: TEdit
      Left = 347
      Top = 313
      Width = 41
      Height = 21
      TabOrder = 55
      Text = '0,22'
    end
    object comboRRA: TComboBox
      Left = 176
      Top = 340
      Width = 73
      Height = 21
      ItemIndex = 0
      TabOrder = 56
      Text = 'Normal'
      OnSelect = comboRRASelect
      Items.Strings = (
        'Normal'
        'Triangular'
        'Uniforme'
        'Constante')
    end
    object edtRRATS1: TEdit
      Left = 255
      Top = 340
      Width = 41
      Height = 21
      TabOrder = 57
      Text = '0,63'
    end
    object edtRRATS2: TEdit
      Left = 302
      Top = 340
      Width = 41
      Height = 21
      TabOrder = 58
      Text = '0,04'
    end
    object edtRRATS3: TEdit
      Left = 347
      Top = 340
      Width = 41
      Height = 21
      TabOrder = 59
      Text = '0,00'
      Visible = False
    end
  end
  object edtMaxSimTime: TEdit
    Left = 169
    Top = 317
    Width = 72
    Height = 21
    TabOrder = 6
    Text = '3600'
  end
  object edtMessageTimeLimit: TEdit
    Left = 384
    Top = 317
    Width = 81
    Height = 21
    TabOrder = 7
    Text = '2'
  end
end
