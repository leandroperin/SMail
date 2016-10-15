//---------------------------------------------------------------------------

#ifndef SettingsH
#define SettingsH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Graphics.hpp>
//---------------------------------------------------------------------------
class TfrmSettings : public TForm
{
__published:	// IDE-managed Components
	TGroupBox *boxTrafVol;
	TLabel *lblLL;
	TLabel *lblLR;
	TLabel *lblRR;
	TLabel *lblRL;
	TEdit *edtLL;
	TEdit *edtLR;
	TEdit *edtRR;
	TEdit *edtRL;
	TButton *btnReset;
	TGroupBox *boxResProp;
	TLabel *lblSucess;
	TLabel *lblFail;
	TLabel *lblLater;
	TLabel *lblLL2;
	TLabel *lblLR2;
	TLabel *lblRL2;
	TLabel *lblRR2;
	TEdit *edtLLS;
	TEdit *edtLLF;
	TEdit *edtLLA;
	TEdit *edtLRS;
	TEdit *edtLRF;
	TEdit *edtLRA;
	TEdit *edtRRS;
	TEdit *edtRRF;
	TEdit *edtRRA;
	TEdit *edtRLS;
	TEdit *edtRLF;
	TEdit *edtRLA;
	TGroupBox *boxServiceCenter;
	TLabel *lblWorkersAmount;
	TLabel *lblCenter1;
	TLabel *lblCenter2;
	TEdit *edtCenter1Capacity;
	TEdit *edtCenter2Capacity;
	TGroupBox *boxTEC;
	TLabel *lblTECSource;
	TLabel *lblTECTime;
	TLabel *lblTECLocal;
	TLabel *lblTECRemote;
	TEdit *edtTECLocal;
	TEdit *edtTECRemote;
	TLabel *lblTECHelp;
	TGroupBox *boxWorkingTimes;
	TLabel *lblTSType;
	TLabel *lblTSRecCenter;
	TLabel *lblTSWorkingCenter;
	TLabel *lblLLS;
	TLabel *lblLLF;
	TLabel *lblLLA;
	TLabel *lblLRS;
	TLabel *lblLRF;
	TLabel *lblLRA;
	TLabel *lblRLS;
	TLabel *lblRLF;
	TLabel *lblRLA;
	TLabel *lblRRS;
	TLabel *lblRRF;
	TLabel *lblRRA;
	TEdit *edtLLSRec;
	TEdit *edtLLFRec;
	TEdit *edtLLARec;
	TEdit *edtLRSRec;
	TEdit *edtLRFRec;
	TEdit *edtLRARec;
	TEdit *edtRLSRec;
	TEdit *edtRLFRec;
	TEdit *edtRLARec;
	TEdit *edtRRSRec;
	TEdit *edtRRFRec;
	TEdit *edtRRARec;
	TLabel *lblTSTECHelp;
	TComboBox *comboLLS;
	TEdit *edtLLSTS1;
	TEdit *edtLLSTS2;
	TEdit *edtLLSTS3;
	TComboBox *comboLLF;
	TEdit *edtLLFTS1;
	TEdit *edtLLFTS2;
	TEdit *edtLLFTS3;
	TComboBox *comboLLA;
	TEdit *edtLLATS1;
	TEdit *edtLLATS2;
	TEdit *edtLLATS3;
	TComboBox *comboLRS;
	TEdit *edtLRSTS1;
	TEdit *edtLRSTS2;
	TEdit *edtLRSTS3;
	TComboBox *comboLRF;
	TEdit *edtLRFTS1;
	TEdit *edtLRFTS2;
	TEdit *edtLRFTS3;
	TComboBox *comboLRA;
	TEdit *edtLRATS1;
	TEdit *edtLRATS2;
	TEdit *edtLRATS3;
	TComboBox *comboRLS;
	TEdit *edtRLSTS1;
	TEdit *edtRLSTS2;
	TEdit *edtRLSTS3;
	TComboBox *comboRLF;
	TEdit *edtRLFTS1;
	TEdit *edtRLFTS2;
	TEdit *edtRLFTS3;
	TComboBox *comboRLA;
	TEdit *edtRLATS1;
	TEdit *edtRLATS2;
	TEdit *edtRLATS3;
	TComboBox *comboRRS;
	TEdit *edtRRSTS1;
	TEdit *edtRRSTS2;
	TEdit *edtRRSTS3;
	TComboBox *comboRRF;
	TEdit *edtRRFTS1;
	TEdit *edtRRFTS2;
	TEdit *edtRRFTS3;
	TComboBox *comboRRA;
	TEdit *edtRRATS1;
	TEdit *edtRRATS2;
	TEdit *edtRRATS3;
	TLabel *lvlMaxSimTime;
	TEdit *edtMaxSimTime;
	TLabel *lblMessageTimeLimit;
	TEdit *edtMessageTimeLimit;
	void __fastcall btnResetClick(TObject *Sender);
	void __fastcall verifyTSDistribution(TComboBox *cb, TEdit *e2, TEdit *e3);
	void __fastcall comboLLSSelect(TObject *Sender);
	void __fastcall comboLLFSelect(TObject *Sender);
	void __fastcall comboLLASelect(TObject *Sender);
	void __fastcall comboLRSSelect(TObject *Sender);
	void __fastcall comboLRFSelect(TObject *Sender);
	void __fastcall comboLRASelect(TObject *Sender);
	void __fastcall comboRLSSelect(TObject *Sender);
	void __fastcall comboRLFSelect(TObject *Sender);
	void __fastcall comboRLASelect(TObject *Sender);
	void __fastcall comboRRSSelect(TObject *Sender);
	void __fastcall comboRRFSelect(TObject *Sender);
	void __fastcall comboRRASelect(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TfrmSettings(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TfrmSettings *frmSettings;
//---------------------------------------------------------------------------
#endif
