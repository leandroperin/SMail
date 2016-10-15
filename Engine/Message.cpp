//---------------------------------------------------------------------------


#pragma hdrstop

#include "Message.h"
#include <vcl.h>

//---------------------------------------------------------------------------

#pragma package(smart_init)

//---------------------------------------------------------------------------

Message::Message(Direction _direction, int _currentTime, int _messageID) {
	this->status = Arrived;

	this->direction = _direction;

	this->messageID = _messageID;

	this->calculateMessageTimes();

	this->arrivalTime = _currentTime + TEC;

	this->timeLimit = arrivalTime + frmSettings->edtMessageTimeLimit->Text.ToDouble()*100;

	this->nextStatusChange = this->arrivalTime;
}

Message::~Message() {}

Direction Message::getDirection() {
	return this->direction;
}

Destiny Message::getDestiny() {
	return this->destiny;
}

Status Message::getStatus() {
	return this->status;
}

int Message::getMessageID() {
    return this->messageID;
}

int Message::getArrivalTime() {
	return this->arrivalTime;
}

int Message::getTimeLimit() {
	return this->timeLimit;
}

int Message::getNextStatusChange() {
	return this->nextStatusChange;
}

void Message::moveOn() {
	if (this->status == Arrived) {
		this->status = Reception;
		this->nextStatusChange += this->TS_Reception;

	} else if (this->status == Reception) {
		this->status = Processing;
		this->nextStatusChange += this->TS_Processing;

	} else if (this->status == Processing) {
		if (this->destiny == Delayed) {
			this->calculateMessageTimes();

			this->nextStatusChange += this->TS_Processing;
		} else
			this->status = Finalized;
	}

	if (this->nextStatusChange > this->timeLimit) {
		this->status = Finalized;
		this->destiny = Fail;
	}
}

void Message::calculateMessageTimes() {
	this->calculateSFA();

	if (this->status == Arrived) {
    	this->calculateTEC();
	}

	this->calculateTS();
}

void Message::calculateSFA() {
	double SuccessRate, FailRate;

	if (this->direction == LL) {
		SuccessRate = frmSettings->edtLLS->Text.ToDouble();
		FailRate = frmSettings->edtLLF->Text.ToDouble();
	} else if (this->direction == LR) {
		SuccessRate = frmSettings->edtLRS->Text.ToDouble();
		FailRate = frmSettings->edtLRF->Text.ToDouble();
	} else if (this->direction == RL) {
		SuccessRate = frmSettings->edtRLS->Text.ToDouble();
		FailRate = frmSettings->edtRLF->Text.ToDouble();
	} else if (this->direction == RR) {
		SuccessRate = frmSettings->edtRRS->Text.ToDouble();
		FailRate = frmSettings->edtRRF->Text.ToDouble();
	}

	double destinyValue = 100 * Calculus::RNG();

	if (destinyValue <= SuccessRate) {
		this->destiny = Success;
	} else if (destinyValue <= SuccessRate + FailRate) {
		this->destiny = Fail;
	} else {
		this->destiny = Delayed;
	}
}

void Message::calculateTEC() {
	if (this->direction == LL || this->direction == LR) {
		this->TEC = Calculus::exponencialCalculation(
					frmSettings->edtTECLocal->Text.ToDouble())*100;
	} else {
		this->TEC = Calculus::exponencialCalculation(
					frmSettings->edtTECRemote->Text.ToDouble())*100;
	}
}

void Message::calculateTSTimes(double tRec, double tTS1, double tTS2,
							   double tTS3, int calcType) {

	this->TS_Reception = tRec;

	if (calcType == 0)
		this->TS_Processing = Calculus::normalCalculation(tTS1, tTS2);

	else if (calcType == 1)
		this->TS_Processing = Calculus::triangularCalculation(tTS1, tTS2, tTS3);

	else if (calcType == 2)
		this->TS_Processing = Calculus::uniformCalculation(tTS1, tTS2);

	else
		this->TS_Processing = tTS1;
}

void Message::calculateTS() {
	switch (this->direction) {
		case LL:
			if (this->destiny == Success) {
				this->calculateTSTimes(
					frmSettings->edtLLSRec->Text.ToDouble()*100,
					frmSettings->edtLLSTS1->Text.ToDouble()*100,
					frmSettings->edtLLSTS2->Text.ToDouble()*100,
					frmSettings->edtLLSTS3->Text.ToDouble()*100,
					frmSettings->comboLLS->ItemIndex
				);
			} else if (this->destiny == Fail) {
				this->calculateTSTimes(
					frmSettings->edtLLFRec->Text.ToDouble()*100,
					frmSettings->edtLLFTS1->Text.ToDouble()*100,
					frmSettings->edtLLFTS2->Text.ToDouble()*100,
					frmSettings->edtLLFTS3->Text.ToDouble()*100,
					frmSettings->comboLLF->ItemIndex
				);
			} else {
				this->calculateTSTimes(
					frmSettings->edtLLARec->Text.ToDouble()*100,
					frmSettings->edtLLATS1->Text.ToDouble()*100,
					frmSettings->edtLLATS2->Text.ToDouble()*100,
					frmSettings->edtLLATS3->Text.ToDouble()*100,
					frmSettings->comboLLA->ItemIndex
				);
            }
			break;
		case LR:
			if (this->destiny == Success) {
				this->calculateTSTimes(
					frmSettings->edtLRSRec->Text.ToDouble()*100,
					frmSettings->edtLRSTS1->Text.ToDouble()*100,
					frmSettings->edtLRSTS2->Text.ToDouble()*100,
					frmSettings->edtLRSTS3->Text.ToDouble()*100,
					frmSettings->comboLRS->ItemIndex
				);
			} else if (this->destiny == Fail) {
				this->calculateTSTimes(
					frmSettings->edtLRFRec->Text.ToDouble()*100,
					frmSettings->edtLRFTS1->Text.ToDouble()*100,
					frmSettings->edtLRFTS2->Text.ToDouble()*100,
					frmSettings->edtLRFTS3->Text.ToDouble()*100,
					frmSettings->comboLRF->ItemIndex
				);
			} else {
				this->calculateTSTimes(
					frmSettings->edtLRARec->Text.ToDouble()*100,
					frmSettings->edtLRATS1->Text.ToDouble()*100,
					frmSettings->edtLRATS2->Text.ToDouble()*100,
					frmSettings->edtLRATS3->Text.ToDouble()*100,
					frmSettings->comboLRA->ItemIndex
				);
            }
			break;
		case RL:
			if (this->destiny == Success) {
				this->calculateTSTimes(
					frmSettings->edtRLSRec->Text.ToDouble()*100,
					frmSettings->edtRLSTS1->Text.ToDouble()*100,
					frmSettings->edtRLSTS2->Text.ToDouble()*100,
					frmSettings->edtRLSTS3->Text.ToDouble()*100,
					frmSettings->comboRLS->ItemIndex
				);
			} else if (this->destiny == Fail) {
				this->calculateTSTimes(
					frmSettings->edtRLFRec->Text.ToDouble()*100,
					frmSettings->edtRLFTS1->Text.ToDouble()*100,
					frmSettings->edtRLFTS2->Text.ToDouble()*100,
					frmSettings->edtRLFTS3->Text.ToDouble()*100,
					frmSettings->comboRLF->ItemIndex
				);
			} else {
				this->calculateTSTimes(
					frmSettings->edtRLARec->Text.ToDouble()*100,
					frmSettings->edtRLATS1->Text.ToDouble()*100,
					frmSettings->edtRLATS2->Text.ToDouble()*100,
					frmSettings->edtRLATS3->Text.ToDouble()*100,
					frmSettings->comboRLA->ItemIndex
				);
			}
			break;
		case RR:
			if (this->destiny == Success) {
				this->calculateTSTimes(
					frmSettings->edtRRSRec->Text.ToDouble()*100,
					frmSettings->edtRRSTS1->Text.ToDouble()*100,
					frmSettings->edtRRSTS2->Text.ToDouble()*100,
					frmSettings->edtRRSTS3->Text.ToDouble()*100,
					frmSettings->comboRRS->ItemIndex
				);
			} else if (this->destiny == Fail) {
				this->calculateTSTimes(
					frmSettings->edtRRFRec->Text.ToDouble()*100,
					frmSettings->edtRRFTS1->Text.ToDouble()*100,
					frmSettings->edtRRFTS2->Text.ToDouble()*100,
					frmSettings->edtRRFTS3->Text.ToDouble()*100,
					frmSettings->comboRRF->ItemIndex
				);
			} else {
				this->calculateTSTimes(
					frmSettings->edtRRARec->Text.ToDouble()*100,
					frmSettings->edtRRATS1->Text.ToDouble()*100,
					frmSettings->edtRRATS2->Text.ToDouble()*100,
					frmSettings->edtRRATS3->Text.ToDouble()*100,
					frmSettings->comboRRA->ItemIndex
				);
            }
			break;
	}
}
