//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "AboutUs.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfrmAboutUs *frmAboutUs;
//---------------------------------------------------------------------------
__fastcall TfrmAboutUs::TfrmAboutUs(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TfrmAboutUs::FormClose(TObject *Sender, TCloseAction &Action)
{
	this->Release();
}
//---------------------------------------------------------------------------
