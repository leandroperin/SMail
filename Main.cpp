//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Main.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfrmMain *frmMain;
//---------------------------------------------------------------------------
__fastcall TfrmMain::TfrmMain(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TfrmMain::btnExitClick(TObject *Sender)
{
	Application->Terminate();
}
//---------------------------------------------------------------------------
void __fastcall TfrmMain::btnAboutUsClick(TObject *Sender)
{
	Application->CreateForm(__classid(TfrmAboutUs), &frmAboutUs);
	frmAboutUs->ShowModal();
}
//---------------------------------------------------------------------------
void __fastcall TfrmMain::btnSimSettingsClick(TObject *Sender)
{
	frmSettings->ShowModal();
}
//---------------------------------------------------------------------------
void __fastcall TfrmMain::btnStartStopClick(TObject *Sender)
{
	if (!this->isRunning) {
    	this->imgRocketOn->Visible = true;

		wheel = new WheelOfTime();

		richEventList->Clear();
		this->richEventList->Lines->Add("-- INÍCIO DA SIMULAÇÃO --");

		this->btnShowResults->Enabled = false;
		this->btnPauseResume->Enabled = true;
		this->btnStartStop->Caption = "Interromper Simulação";

		this->lblMinMessagesValue->Caption = "0";
		this->lblAverageMessagesValue->Caption = "0";
		this->lblMaxMessagesValue->Caption = "0";

		this->isRunning = true;

		this->clock->Enabled = true;
	} else {
    	this->imgRocketOn->Visible = false;

		this->clock->Enabled = false;

		this->isRunning = false;

		this->btnShowResults->Enabled = true;
		this->btnPauseResume->Enabled = false;
		this->btnPauseResume->Caption = "Pausar Simulação";
		this->btnStartStop->Caption = "Iniciar Simulação";

		this->richEventList->Lines->Add("-- FIM DA SIMULAÇÃO --");

        delete wheel;
    }
}

void TfrmMain::addPastEvent(Event* event) {
	const char* desc = event->getDescription();
	double time = (double) event->getTime() / 100;

	std::stringstream ss;
	ss << time << "s: Mensagem " << event->getMessageID() << desc;
	richEventList->Lines->Add(ss.str().c_str());

	delete event;
}
//---------------------------------------------------------------------------

void __fastcall TfrmMain::FormActivate(TObject *Sender)
{
	this->isRunning = false;
}
//---------------------------------------------------------------------------

void __fastcall TfrmMain::btnPauseResumeClick(TObject *Sender)
{
	if (clock->Enabled) {
		this->clock->Enabled = false;
		this->btnPauseResume->Caption = "Continuar Simulação";
	} else {
		this->clock->Enabled = true;
		this->btnPauseResume->Caption = "Pausar Simulação";
    }
}
//---------------------------------------------------------------------------

void __fastcall TfrmMain::clockTimer(TObject *Sender)
{
	int i = 0;
	while (i < this->trackSimulationSpeed->Position * this->trackSimulationSpeed->Position) {
		this->pastEvents = this->wheel->getPastEvents();

		while (!this->pastEvents->empty()) {
			Event* e = this->pastEvents->front();

			this->addPastEvent(e);

			this->pastEvents->pop_front();
		}

		this->wheel->increaseTime();
		this->lblSimulatedValue->Caption = (double) this->wheel->getCurrentTime() / 100;

		this->lblMessageCounterValue->Caption = IntToStr(
		this->wheel->getDispatchedMessagesCounter()) + " / "
		+ this->wheel->getMessageCounter();

		int inSystemMessages = this->wheel->getInSystemMessagesCounter();
		if (this->lblMinMessagesValue->Caption == "0") {
			this->lblMinMessagesValue->Caption = inSystemMessages;
		}
		if (inSystemMessages < this->lblMinMessagesValue->Caption) {
			this->lblMinMessagesValue->Caption = inSystemMessages;
		}
		if (inSystemMessages > this->lblMaxMessagesValue->Caption) {
			this->lblMaxMessagesValue->Caption = inSystemMessages;
		}
		this->lblAverageMessagesValue->Caption = FormatFloat("#0.00",
		this->wheel->getInSystemMessagesAverage());

		this->lblAverageMessageValue->Caption =  FormatFloat("#0.00",
		this->wheel->getAverageTimeSpent());

		this->lblMaxMessageValue->Caption = FormatFloat("#0.00",
		this->wheel->getMaxTimeSpent());

		this->lblMinMessageValue->Caption = FormatFloat("#0.00",
		this->wheel->getMinTimeSpent());

		this->lblLLCounterValue->Caption = IntToStr(this->wheel->getTypeAcum(LL))
		+ " / " + IntToStr(this->wheel->getTypeCounter(LL));
		this->lblLRCounterValue->Caption = IntToStr(this->wheel->getTypeAcum(LR))
		+ " / " + IntToStr(this->wheel->getTypeCounter(LR));
		this->lblRLCounterValue->Caption = IntToStr(this->wheel->getTypeAcum(RL))
		+ " / " + IntToStr(this->wheel->getTypeCounter(RL));
		this->lblRRCounterValue->Caption = IntToStr(this->wheel->getTypeAcum(RR))
		+ " / " + IntToStr(this->wheel->getTypeCounter(RR));

		if (this->lblSimulatedValue->Caption.ToDouble() >=
			frmSettings->edtMaxSimTime->Text.ToDouble()) {
			this->btnStartStopClick(this->clock);
			this->lblSimulatedValue->Caption = frmSettings->edtMaxSimTime->Text;
			break;
		}

		i++;
	}
}
//---------------------------------------------------------------------------


