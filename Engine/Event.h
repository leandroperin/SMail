//---------------------------------------------------------------------------

#ifndef EventH
#define EventH

#include "Message.h"
//---------------------------------------------------------------------------
class Event {
 public:
	Event(int, Message*, const char*);
	~Event();

	int getTime();
	void incTime(double);
	int getInQueueTime();
	void setInQueueTime(int);
	const char* getDescription();
	Event* getNextEvent();
	int getMessageID();
	Direction getMessageDirection();
	Destiny getMessageDestiny();
	int getMessageArrivalTime();
	Status getMessageStatus();

	int execute();
 private:
	int executingTime;
	int inQueueTime;
	Message* message;
	const char* description;
};
//---------------------------------------------------------------------------
#endif
