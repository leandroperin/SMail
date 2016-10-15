//---------------------------------------------------------------------------

#ifndef WheelOfTimeH
#define WheelOfTimeH

#include <list>
#include <queue>
#include "Event.h"
//---------------------------------------------------------------------------
class WheelOfTime {
 public:
	WheelOfTime();
	~WheelOfTime();

	std::list<Event*>* getPastEvents();
	int getCurrentTime();

	void addEvent(Event*);
	void increaseTime();

	std::list<Event*>* getCenter1Queue();
	std::list<Event*>* getCenter2Queue();

	int getMessageCounter();
	int getInSystemMessagesCounter();
	double getInSystemMessagesAverage();
	int getTypeCounter(Direction);
	int getTypeAcum(Direction);
	int getDispatchedMessagesCounter();
	double getAverageTimeSpent();
	double getMaxTimeSpent();
	double getMinTimeSpent();
	double getCenter1Usage();
	double getCenter2Usage();
 private:
 	void executeEvents();
	void createMessage();
	Event* getNext();
	void computeStatistics(Event*);

	std::list<Event*>* eventsList;
	std::list<Event *>* pastEvents;

	std::list<Event *>* center1queue;
	std::list<Event *>* center2queue;
	int center1capacity;
	int center2capacity;
	int center1usage;
	int center2usage;

	Event* lastArrival;

	int currentTime;
	int messageCounter;
	int totalTimeSpent;
	int minTimeSpent;
	int maxTimeSpent;
	int inSystemMessagesCounter;
	int inSystemMessagesAcum;
	int dispatchedMessagesCounter;
	int LLCounter, LRCounter, RLCounter, RRCounter;
	int LLAcum, LRAcum, RLAcum, RRAcum;
	int LL_Dir, LR_Dir, RL_Dir, RR_Dir; // Probability of message directions
};
//---------------------------------------------------------------------------
#endif
