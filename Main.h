//---------------------------------------------------------------------------

#ifndef MainH
#define MainH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
#include <TabNotBk.hpp>
#include <ExtCtrls.hpp>
#include <jpeg.hpp>
#include <pngimage.hpp>
#include <Menus.hpp>
#include <Graphics.hpp>
#include <sstream>
#include "WheelOfTime.h"
#include "AboutUs.h"
//---------------------------------------------------------------------------
class TfrmMain : public TForm
{
__published:	// IDE-managed Components
	TMainMenu *menuMain;
	TMenuItem *menuSettings;
	TMenuItem *btnSimSettings;
	TMenuItem *btnAboutUs;
	TMenuItem *N1;
	TMenuItem *btnExit;
	TButton *btnStartStop;
	TRichEdit *richEventList;
	TLabel *lblPastEventsList;
	TButton *btnPauseResume;
	TTimer *clock;
	TLabel *lblSimulatedTime;
	TLabel *lblSimulatedValue;
	TTrackBar *trackSimulationSpeed;
	TLabel *lblSimulationSpeed;
	TButton *btnShowResults;
	TLabel *lblInSystemMessages;
	TLabel *lblAverageMessages;
	TLabel *lblMinMessages;
	TLabel *lblMaxMessages;
	TLabel *lblMinMessagesValue;
	TLabel *lblAverageMessagesValue;
	TLabel *lblMaxMessagesValue;
	TLabel *lblCentersAverageValue;
	TLabel *lblCenter1;
	TLabel *lblCenter2;
	TLabel *lblCenter1Average;
	TLabel *lblCenter2Average;
	TLabel *lblMessageCounter;
	TLabel *lblMessageCounterValue;
	TLabel *lblMessageTypeCounter;
	TLabel *lblLLCounter;
	TLabel *lblLRCounter;
	TLabel *lblRRCounter;
	TLabel *lblRLCounter;
	TLabel *lblLLCounterValue;
	TLabel *lblLRCounterValue;
	TLabel *lblRRCounterValue;
	TLabel *lblRLCounterValue;
	TLabel *lblCurrentTotal;
	TLabel *lblTotalTime;
	TLabel *lblAverageMessageTime;
	TLabel *lblMinMessageTime;
	TLabel *lblMaxMessageTime;
	TLabel *lblMinMessageValue;
	TLabel *lblAverageMessageValue;
	TLabel *lblMaxMessageValue;
	TImage *imgRocketOff;
	TImage *imgRocketOn;
	void __fastcall btnExitClick(TObject *Sender);
	void __fastcall btnAboutUsClick(TObject *Sender);
	void __fastcall btnSimSettingsClick(TObject *Sender);
	void __fastcall btnStartStopClick(TObject *Sender);
	void __fastcall FormActivate(TObject *Sender);
	void __fastcall btnPauseResumeClick(TObject *Sender);
	void __fastcall clockTimer(TObject *Sender);
private:	// User declarations
	void addPastEvent(Event*);
	bool isRunning;
	WheelOfTime* wheel;
	std::list<Event *>* pastEvents;
public:		// User declarations
	__fastcall TfrmMain(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TfrmMain *frmMain;
//---------------------------------------------------------------------------
#endif
