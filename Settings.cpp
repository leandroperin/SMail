//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Settings.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfrmSettings *frmSettings;
//---------------------------------------------------------------------------
__fastcall TfrmSettings::TfrmSettings(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TfrmSettings::btnResetClick(TObject *Sender)
{
	edtMessageTimeLimit->Text = "2";
	edtMaxSimTime->Text = "3600";

	edtLL->Text = "50";
	edtLR->Text = "25";
	edtRL->Text = "15";
	edtRR->Text = "10";

	edtLLS->Text = "87,00";
	edtLLF->Text = "0,50";
	edtLLA->Text = "12,50";
	edtLRS->Text = "96,00";
	edtLRF->Text = "1,50";
	edtLRA->Text = "2,50";
	edtRLS->Text = "96,00";
	edtRLF->Text = "3,00";
	edtRLA->Text = "1,00";
	edtRRS->Text = "90,00";
	edtRRF->Text = "1,00";
	edtRRA->Text = "9,00";

	edtCenter1Capacity->Text = "10";
	edtCenter2Capacity->Text = "20";

	edtTECLocal->Text = "0,5";
	edtTECRemote->Text = "0,6";

	edtLLSRec->Text = "0,12";
	edtLLFRec->Text = "0,14";
	edtLLARec->Text = "0,11";
	edtRLSRec->Text = "0,12";
	edtRLFRec->Text = "0,13";
	edtRLARec->Text = "0,15";
	edtLRSRec->Text = "0,12";
	edtLRFRec->Text = "0,14";
	edtLRARec->Text = "0,11";
	edtRRSRec->Text = "0,16";
	edtRRFRec->Text = "0,13";
	edtRRARec->Text = "0,16";

	comboLLS->ItemIndex = 0; comboLLS->OnSelect(comboLLS);
	comboLLF->ItemIndex = 1; comboLLF->OnSelect(comboLLF);
	comboLLA->ItemIndex = 2; comboLLA->OnSelect(comboLLA);
	comboLRS->ItemIndex = 0; comboLRS->OnSelect(comboLRS);
	comboLRF->ItemIndex = 2; comboLRF->OnSelect(comboLRF);
	comboLRA->ItemIndex = 1; comboLRA->OnSelect(comboLRA);
	comboRLS->ItemIndex = 2; comboRLS->OnSelect(comboRLS);
	comboRLF->ItemIndex = 0; comboRLF->OnSelect(comboRLF);
	comboRLA->ItemIndex = 0; comboRLA->OnSelect(comboRLA);
	comboRRS->ItemIndex = 2; comboRRS->OnSelect(comboRRS);
	comboRRF->ItemIndex = 1; comboRRF->OnSelect(comboRRF);
	comboRRA->ItemIndex = 0; comboRRA->OnSelect(comboRRA);

	edtLLSTS1->Text = "0,55"; edtLLSTS2->Text = "0,05"; edtLLSTS3->Text = "0,00";
	edtLLFTS1->Text = "0,02"; edtLLFTS2->Text = "0,05"; edtLLFTS3->Text = "0,12";
	edtLLATS1->Text = "0,06"; edtLLATS2->Text = "0,15"; edtLLATS3->Text = "0,00";
	edtLRSTS1->Text = "0,65"; edtLRSTS2->Text = "0,04"; edtLRSTS3->Text = "0,00";
	edtLRFTS1->Text = "0,16"; edtLRFTS2->Text = "0,25"; edtLRFTS3->Text = "0,00";
	edtLRATS1->Text = "0,05"; edtLRATS2->Text = "0,07"; edtLRATS3->Text = "0,10";
	edtRLSTS1->Text = "0,03"; edtRLSTS2->Text = "0,11"; edtRLSTS3->Text = "0,00";
	edtRLFTS1->Text = "0,46"; edtRLFTS2->Text = "0,05"; edtRLFTS3->Text = "0,00";
	edtRLATS1->Text = "0,72"; edtRLATS2->Text = "0,09"; edtRLATS3->Text = "0,00";
	edtRRSTS1->Text = "0,09"; edtRRSTS2->Text = "0,18"; edtRRSTS3->Text = "0,00";
	edtRRFTS1->Text = "0,08"; edtRRFTS2->Text = "0,15"; edtRRFTS3->Text = "0,22";
	edtRRATS1->Text = "0,63"; edtRRATS2->Text = "0,04"; edtRRATS3->Text = "0,00";
}
//---------------------------------------------------------------------------

void __fastcall TfrmSettings::verifyTSDistribution(TComboBox *cb, TEdit *e2, TEdit *e3) {
    switch (cb->ItemIndex) {
		case 1:	e2->Visible = true;
				e3->Visible = true;
				break;
		case 3: e2->Visible = false;
				e3->Visible = false;
				break;
		default: e2->Visible = true;
				 e3->Visible = false;
	}
}
//---------------------------------------------------------------------------
void __fastcall TfrmSettings::comboLLSSelect(TObject *Sender)
{
	this->verifyTSDistribution(comboLLS, edtLLSTS2, edtLLSTS3);
}
//---------------------------------------------------------------------------
void __fastcall TfrmSettings::comboLLFSelect(TObject *Sender)
{
	this->verifyTSDistribution(comboLLF, edtLLFTS2, edtLLFTS3);
}
//---------------------------------------------------------------------------

void __fastcall TfrmSettings::comboLLASelect(TObject *Sender)
{
	this->verifyTSDistribution(comboLLA, edtLLATS2, edtLLATS3);
}
//---------------------------------------------------------------------------

void __fastcall TfrmSettings::comboLRSSelect(TObject *Sender)
{
	this->verifyTSDistribution(comboLRS, edtLRSTS2, edtLRSTS3);
}
//---------------------------------------------------------------------------

void __fastcall TfrmSettings::comboLRFSelect(TObject *Sender)
{
	this->verifyTSDistribution(comboLRF, edtLRFTS2, edtLRFTS3);
}
//---------------------------------------------------------------------------

void __fastcall TfrmSettings::comboLRASelect(TObject *Sender)
{
	this->verifyTSDistribution(comboLRA, edtLRATS2, edtLRATS3);
}
//---------------------------------------------------------------------------

void __fastcall TfrmSettings::comboRLSSelect(TObject *Sender)
{
	this->verifyTSDistribution(comboRLS, edtRLSTS2, edtRLSTS3);
}
//---------------------------------------------------------------------------

void __fastcall TfrmSettings::comboRLFSelect(TObject *Sender)
{
	this->verifyTSDistribution(comboRLF, edtRLFTS2, edtRLFTS3);
}
//---------------------------------------------------------------------------

void __fastcall TfrmSettings::comboRLASelect(TObject *Sender)
{
	this->verifyTSDistribution(comboRLA, edtRLATS2, edtRLATS3);
}
//---------------------------------------------------------------------------

void __fastcall TfrmSettings::comboRRSSelect(TObject *Sender)
{
	this->verifyTSDistribution(comboRRS, edtRRSTS2, edtRRSTS3);
}
//---------------------------------------------------------------------------

void __fastcall TfrmSettings::comboRRFSelect(TObject *Sender)
{
	this->verifyTSDistribution(comboRRF, edtRRFTS2, edtRRFTS3);
}
//---------------------------------------------------------------------------

void __fastcall TfrmSettings::comboRRASelect(TObject *Sender)
{
	this->verifyTSDistribution(comboRRA, edtRRATS2, edtRRATS3);
}
//---------------------------------------------------------------------------


