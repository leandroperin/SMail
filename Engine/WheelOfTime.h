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

	int getMessageCounter();
	int getInSystemMessagesCounter();
	double getInSystemMessagesAverage();
	int getTypeCounter(Direction);
	int getTypeAcum(Direction);
	int getDispatchedMessagesCounter();
	double getAverageTimeSpent();
	double getMaxTimeSpent();
	double getMinTimeSpent();
 private:
 	void executeEvents();
	void createMessage();
	Event* getNext();
	void computeStatistics(Event*);

	std::list<Event*>* eventsList;
	std::list<Event *>* pastEvents;

	std::queue<Event *>* center1queue;
	std::queue<Event *>* center2queue;
	int center1capacity;
	int center2capacity;

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
