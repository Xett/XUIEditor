#include "MainFrame.hpp"

MainFrame::MainFrame()
{
    wxMemoryFSHandler* fsh = new wxMemoryFSHandler();

    wxFSFile* iconFile = fsh->OpenFile(wxFileSystem(), "memory:XRC_resource/view.cpp$icons_icon-32.png");
	wxIcon* icon = new wxIcon();
	wxImage* iconImage = new wxImage(*iconFile->GetStream(), iconFile->GetMimeType());
	icon->CopyFromBitmap(wxBitmap(*iconImage));
	SetIcon(*icon);
}
