#include "SettingsFrame.hpp"

SettingsFrame::SettingsFrame(wxWindow* parent, Config* config) : SettingsFrame_Base(parent)
{
	//this->config = config;

	Bind(wxEVT_CLOSE_WINDOW, &SettingsFrame::OnClose, this, wxID_ANY);

	wxMemoryFSHandler* fsh = new wxMemoryFSHandler();
	wxFSFile* iconFile = fsh->OpenFile(wxFileSystem(), "memory:XRC_resource/view.cpp$icons_settings-32.png");
	wxIcon* icon = new wxIcon();
	wxImage* iconImage = new wxImage(*iconFile->GetStream(), iconFile->GetMimeType());
	icon->CopyFromBitmap(wxBitmap(*iconImage));
	SetIcon(*icon);
}

void SettingsFrame::OnClose(wxCloseEvent& event)
{
	Show(false);
}

void SettingsFrame::UpdateFromConfig()
{
	//UpdateCurrentProject(config->autoloadProjectPath);
}
