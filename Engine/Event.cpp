//---------------------------------------------------------------------------


#pragma hdrstop

#include "Event.h"

//---------------------------------------------------------------------------

#pragma package(smart_init)

Event::Event(int _executingTime, Message* _message, const char* _description) {
	this->executingTime = _executingTime;
	this->message = _message;
	this->description = _description;
}

Event::~Event() {}

int Event::getTime() {
    return this->executingTime;
}

const char* Event::getDescription() {
	return this->description;
}

Event* Event::getNextEvent() {
	if (this->message->getStatus() != Finalized) {
		const char* desc;

		if (this->message->getStatus() == Reception) {
			desc = " foi recebida";
		} else {
			desc = " foi processada";
		}

		int time = this->message->getNextStatusChange();

		Event* event = new Event(time, this->message, desc);

		return event;
	}

    return 0;
}

int Event::getMessageID() {
    return this->message->getMessageID();
}

Direction Event::getMessageDirection() {
 	return this->message->getDirection();
}

Destiny Event::getMessageDestiny() {
    return this->message->getDestiny();
}

int Event::getMessageArrivalTime() {
    return this->message->getArrivalTime();
}

int Event::execute() {
	this->message->moveOn();

	if (this->message->getStatus() == Processing)
		if (this->message->getDirection() == LL || this->message->getDirection() == RL)
			return 1;
		else
			return 2;

	return 0;
}
