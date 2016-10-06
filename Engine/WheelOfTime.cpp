//---------------------------------------------------------------------------


#pragma hdrstop

#include "WheelOfTime.h"

//---------------------------------------------------------------------------

#pragma package(smart_init)
//---------------------------------------------------------------------------


WheelOfTime::WheelOfTime() {
	srand(time(0));

	this->eventsList = new std::list<Event*>;
	this->pastEvents = new std::list<Event*>;

	this->center1queue = new std::queue<Event*>;
	this->center2queue = new std::queue<Event*>;

	this->currentTime = 0;

	this->messageCounter = 0;
	this->inSystemMessagesCounter = 0;
	this->inSystemMessagesAcum = 0;
	this->dispatchedMessagesCounter = 0;
	this->totalTimeSpent = 0;
	this->minTimeSpent = 0;
	this->maxTimeSpent = 0;

	this->LLCounter = 0; this->LLAcum = 0;
	this->LRCounter = 0; this->LRAcum = 0;
	this->RLCounter = 0; this->RLAcum = 0;
	this->RRCounter = 0; this->RRAcum = 0;

	this->LL_Dir = StrToInt(frmSettings->edtLL->Text);
	this->LR_Dir = this->LL_Dir + StrToInt(frmSettings->edtLR->Text);
	this->RL_Dir = this->LR_Dir + StrToInt(frmSettings->edtRL->Text);
	this->RR_Dir = this->RL_Dir + StrToInt(frmSettings->edtRR->Text);

	this->createMessage();
}

WheelOfTime::~WheelOfTime() {
	delete this->eventsList;
	delete this->pastEvents;

	delete this->center1queue;
	delete this->center2queue;
}

std::list<Event*>* WheelOfTime::getPastEvents() {
    return this->pastEvents;
}

int WheelOfTime::getCurrentTime() {
	return this->currentTime;
}

void WheelOfTime::addEvent(Event* event) {
	if (this->eventsList->empty())
		this->eventsList->push_back(event);
	else {
		int time = event->getTime();

		std::list<Event*>::iterator it;
		it = this->eventsList->begin();

		for (it; it != this->eventsList->end();) {
			if (time < (*it)->getTime()) {
				this->eventsList->insert(it, event);
				break;
			}

			++it;

			if (it == this->eventsList->end()) {
				this->eventsList->push_back(event);
				break;
			}
		}
    }
}

void WheelOfTime::increaseTime() {
	this->executeEvents();

	int oldTime = this->currentTime;
	this->currentTime = this->eventsList->front()->getTime();

	this->inSystemMessagesAcum += this->inSystemMessagesCounter * (this->currentTime - oldTime);
}

int WheelOfTime::getMessageCounter() {
	return this->messageCounter;
}

int WheelOfTime::getInSystemMessagesCounter() {
    return this->inSystemMessagesCounter;
}

double WheelOfTime::getInSystemMessagesAverage() {
	double res = (double) inSystemMessagesAcum/currentTime;
	return res;
}

int WheelOfTime::getTypeCounter(Direction _direction) {
	switch (_direction) {
		case LL: return this->LLCounter;
		case LR: return this->LRCounter;
		case RL: return this->RLCounter;
        default: return this->RRCounter;
	}
}

int WheelOfTime::getTypeAcum(Direction _direction) {
	switch (_direction) {
		case LL: return this->LLAcum;
		case LR: return this->LRAcum;
		case RL: return this->RLAcum;
		default: return this->RRAcum;
	}
}

int WheelOfTime::getDispatchedMessagesCounter() {
    return this->dispatchedMessagesCounter;
}

double WheelOfTime::getAverageTimeSpent() {
    return (double) (this->totalTimeSpent / this->messageCounter) / 100;
}

double WheelOfTime::getMaxTimeSpent() {
	return (double) this->maxTimeSpent / 100;
}

double WheelOfTime::getMinTimeSpent() {
    return (double) this->minTimeSpent / 100;
}

void WheelOfTime::executeEvents() {
	this->pastEvents->clear();

	if (!this->eventsList->empty()) {
		while (this->eventsList->front()->getTime() == this->currentTime) {
			Event* event = this->getNext();

			this->pastEvents->push_back(event);

			event->execute();

			Event* nextFutureEvent = event->getNextEvent();

			if (nextFutureEvent != 0)
				this->addEvent(nextFutureEvent);
			else {
				this->computeStatistics(event);
			}

			if (event == this->lastArrival)
				this->createMessage();

			if (this->eventsList->empty())
				break;
		}
	}
}

void WheelOfTime::createMessage() {
	double dir = 100 * Calculus::RNG();

	Message* message;

	if (dir <= this->LL_Dir) {
		message = new Message(LL, this->currentTime, this->messageCounter);
		this->LLCounter++;
		this->LLAcum++;
	} else if (dir <= this->LR_Dir) {
		message = new Message(LR, this->currentTime, this->messageCounter);
		this->LRCounter++;
		this->LRAcum++;
	} else if (dir <= this->RL_Dir) {
		message = new Message(RL, this->currentTime, this->messageCounter);
		this->RLCounter++;
		this->RLAcum++;
	} else if (dir <= this->RR_Dir) {
		message = new Message(RR, this->currentTime, this->messageCounter);
		this->RRCounter++;
		this->RRAcum++;
	}

	const char* eventDescription = " chegou ao sistema";

	this->lastArrival = new Event(message->getArrivalTime(), message, eventDescription);

	this->addEvent(this->lastArrival);

	this->messageCounter++;
	this->inSystemMessagesCounter++;
}

Event* WheelOfTime::getNext() {
	Event* e = this->eventsList->front();

	this->eventsList->pop_front();

    return e;
}

void WheelOfTime::computeStatistics(Event* e) {
	this->inSystemMessagesCounter--;

	double messageTimeSpent = (this->currentTime - e->getMessageArrivalTime());
	this->totalTimeSpent += messageTimeSpent;
	if (minTimeSpent == 0 || messageTimeSpent < minTimeSpent) {
		minTimeSpent = messageTimeSpent;
	}
	if (messageTimeSpent > maxTimeSpent) {
		maxTimeSpent = messageTimeSpent;
	}

	switch (e->getMessageDirection()) {
		case LL: this->LLAcum--; break;
		case LR: this->LRAcum--; break;
		case RL: this->RLAcum--; break;
		default: this->RRAcum--;
	}

	if (e->getMessageDestiny() == Success) {
		this->dispatchedMessagesCounter++;
	}
}
