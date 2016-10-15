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

		this->updateGUI();

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

void TfrmMain::updateGUI() {
	this->lblSimulatedValue->Caption = (double) this->wheel->getCurrentTime() / 100;

	int inSystemMessages = this->wheel->getInSystemMessagesCounter();
	if (this->lblMinMessagesValue->Caption == "0")
		this->lblMinMessagesValue->Caption = inSystemMessages;
	if (inSystemMessages < this->lblMinMessagesValue->Caption)
		this->lblMinMessagesValue->Caption = inSystemMessages;
	if (inSystemMessages > this->lblMaxMessagesValue->Caption)
		this->lblMaxMessagesValue->Caption = inSystemMessages;
	this->lblAverageMessagesValue->Caption = FormatFloat("#0.00",
	this->wheel->getInSystemMessagesAverage());

    this->lblCenter1Average->Caption = FormatFloat("#0.00",
	this->wheel->getCenter1Usage()*100);
	this->lblCenter2Average->Caption = FormatFloat("#0.00",
	this->wheel->getCenter2Usage()*100);

    this->lblMessageCounterValue->Caption = IntToStr(
		this->wheel->getDispatchedMessagesCounter()) + " / "
		+ this->wheel->getMessageCounter();

    this->lblLLCounterValue->Caption = IntToStr(this->wheel->getTypeAcum(LL))
		+ " / " + IntToStr(this->wheel->getTypeCounter(LL));
	this->lblLRCounterValue->Caption = IntToStr(this->wheel->getTypeAcum(LR))
		+ " / " + IntToStr(this->wheel->getTypeCounter(LR));
	this->lblRLCounterValue->Caption = IntToStr(this->wheel->getTypeAcum(RL))
		+ " / " + IntToStr(this->wheel->getTypeCounter(RL));
	this->lblRRCounterValue->Caption = IntToStr(this->wheel->getTypeAcum(RR))
		+ " / " + IntToStr(this->wheel->getTypeCounter(RR));

    this->lblAverageMessageValue->Caption =  FormatFloat("#0.00",
		this->wheel->getAverageTimeSpent());

	this->lblMaxMessageValue->Caption = FormatFloat("#0.00",
		this->wheel->getMaxTimeSpent());

	this->lblMinMessageValue->Caption = FormatFloat("#0.00",
		this->wheel->getMinTimeSpent());
}


void __fastcall TfrmMain::btnShowResultsClick(TObject *Sender)
{
	this->memoStatistics->Clear();

	this->memoStatistics->Lines->Add("UNIVERSIDADE FEDERAL DE SANTA CATARINA");
	this->memoStatistics->Lines->Add("INE5425 - Modelagem e Simulação");
	this->memoStatistics->Lines->Add("Leandro Perin de Oliveira - 14100846");
	this->memoStatistics->Lines->Add("Gustavo Garcia Gava - 14100832");

	this->memoStatistics->Lines->Add("");
	this->memoStatistics->Lines->Add("---------------------------------------");
	this->memoStatistics->Lines->Add("Sistema de Simulação SMail - Resultados");
	this->memoStatistics->Lines->Add("---------------------------------------");

	this->memoStatistics->Lines->Add("");
	this->memoStatistics->Lines->Add("Tempo Simulado (s): "
	+ this->lblSimulatedValue->Caption);

	this->memoStatistics->Lines->Add("");
	this->memoStatistics->Lines->Add("Número de Mensagens no Sistema");
	this->memoStatistics->Lines->Add("MIN: " + this->lblMinMessagesValue->Caption);
	this->memoStatistics->Lines->Add("MÉDIA: " + this->lblAverageMessagesValue->Caption);
	this->memoStatistics->Lines->Add("MAX: " + this->lblMaxMessagesValue->Caption);

	this->memoStatistics->Lines->Add("");
	this->memoStatistics->Lines->Add("Taxa Média de Ocupação dos Centros");
	this->memoStatistics->Lines->Add("Centro 1: " + this->lblCenter1Average->Caption);
	this->memoStatistics->Lines->Add("Centro 2: " + this->lblCenter2Average->Caption);

	this->memoStatistics->Lines->Add("");
	this->memoStatistics->Lines->Add("Quantidade de Mensagens");
	this->memoStatistics->Lines->Add("Despachadas :"
	+ IntToStr(this->wheel->getDispatchedMessagesCounter()));
	this->memoStatistics->Lines->Add("Total :"
	+ IntToStr(this->wheel->getMessageCounter()));

	this->memoStatistics->Lines->Add("");
	this->memoStatistics->Lines->Add("Quantidade de Mensagens por Tipo");
	this->memoStatistics->Lines->Add("LL: " + IntToStr(this->wheel->getTypeCounter(LL)));
	this->memoStatistics->Lines->Add("LR: " + IntToStr(this->wheel->getTypeCounter(LR)));
	this->memoStatistics->Lines->Add("RL: " + IntToStr(this->wheel->getTypeCounter(RL)));
	this->memoStatistics->Lines->Add("RR: " + IntToStr(this->wheel->getTypeCounter(RR)));

	this->memoStatistics->Lines->Add("");
	this->memoStatistics->Lines->Add("Tempo de Trânsito das Mensagens");
	this->memoStatistics->Lines->Add("MIN: " + this->lblMinMessageValue->Caption);
	this->memoStatistics->Lines->Add("MÉDIA: " + this->lblAverageMessageValue->Caption);
	this->memoStatistics->Lines->Add("MAX: " + this->lblMaxMessageValue->Caption);

	if (saveDlg->Execute()) {
        this->memoStatistics->Lines->SaveToFile(saveDlg->FileName);
	}
}
//---------------------------------------------------------------------------

