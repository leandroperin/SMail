//---------------------------------------------------------------------------

#ifndef AboutUsH
#define AboutUsH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <pngimage.hpp>
#include <Graphics.hpp>
//---------------------------------------------------------------------------
class TfrmAboutUs : public TForm
{
__published:	// IDE-managed Components
	TImage *imgAboutUsBackground;
	TLabel *lblAuthors;
	TLabel *lblAuthor1;
	TLabel *lblAuthor2;
	TLabel *Label1;
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
private:	// User declarations
public:		// User declarations
	__fastcall TfrmAboutUs(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TfrmAboutUs *frmAboutUs;
//---------------------------------------------------------------------------
#endif
