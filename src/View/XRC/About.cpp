#include "About.hpp"

About::About(wxWindow* parent) : About_Base(parent)
{
	wxMemoryFSHandler* fsh = new wxMemoryFSHandler();
	wxFSFile* iconFile = fsh->OpenFile(wxFileSystem(), "memory:XRC_resource/view.cpp$icons_info-32.png");
	wxIcon* icon = new wxIcon();
	wxImage* iconImage = new wxImage(*iconFile->GetStream(), iconFile->GetMimeType());
	icon->CopyFromBitmap(wxBitmap(*iconImage));
	SetIcon(*icon);
}
