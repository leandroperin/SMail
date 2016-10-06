//---------------------------------------------------------------------------

#ifndef MessageH
#define MessageH

#include "Calculus.h"
#include "Settings.h"

//---------------------------------------------------------------------------
enum Direction { LL, LR, RL, RR };
enum Destiny { Success, Fail, Delayed };
enum Status { Arrived, Reception, Processing, Finalized };

class Message {
 public:
	Message(Direction, int, int);
	~Message();

	Direction getDirection();
	Destiny getDestiny();
	Status getStatus();

	int getMessageID();
	int getArrivalTime();
	int getTimeLimit();
	int getNextStatusChange();

	void moveOn();
 private:
	void calculateMessageTimes();
	void calculateSFA();
	void calculateTEC();
	void calculateTSTimes(double, double, double, double, int);
	void calculateTS();

	Direction direction;
	Destiny destiny;
	Status status;

	int messageID;
	double arrivalTime;
	double timeLimit;
	double TEC;
	double TS_Reception;
	double TS_Processing;
	double nextStatusChange;
};

//---------------------------------------------------------------------------
#endif
