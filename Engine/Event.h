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
	const char* getDescription();
	Event* getNextEvent();
	int getMessageID();
	Direction getMessageDirection();
	Destiny getMessageDestiny();
	int getMessageArrivalTime();

	int execute();
 private:
	int executingTime;
	Message* message;
	const char* description;
};
//---------------------------------------------------------------------------
#endif
