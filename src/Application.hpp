#include <map>

#include <wx/wx.h>
#include <wx/dir.h>
#include <wx/textfile.h>
#include <wx/cmdproc.h>
#include <wx/wfstream.h>

#include "Model/Model.hpp"
#include "Config.hpp"

#include "View/XRC/MainFrame.hpp"
#include "View/XRC/About.hpp"
#include "View/XRC/SettingsFrame.hpp"

#ifndef APPLICATION_HPP
#define APPLICATION_HPP

class Application : public wxApp {
public:
	// Main view frame, holds the rest of the GUI too
	MainFrame* mainFrame;
	// The about frame, child of MainFrame
	About* about;
	// The settings frame, child of MainFrame
	SettingsFrame* settingsFrame;

	//The loaded config file, from config.ini
	Config* config;

	// Override of wxApp to construct this application
	virtual bool OnInit();
	// Load the config file
	// Called during Application::OnInit()
	void loadConfig();

	void NewFile(wxCommandEvent& event);

	// Open the project directory load dialogue, use to load a project to work on
	// Called from File->Open and Open Project Tool
	void OpenFile(wxCommandEvent& event);

	// Save the currently loaded file page
	// Only Sprite Groups are implemented at the moment
	void saveFile(wxCommandEvent& WXUNUSED(event));


	void saveFileAs(wxCommandEvent& WXUNUSED(event));

	// Update Icon/Widget States (Menu and Toolbar)
	void UpdateStates();

	// Shows the About frame
	void OnAbout(wxCommandEvent& WXUNUSED(event));
	// Exits out of the main loop when MainFrame is exited
	void OnExit(wxCommandEvent& WXUNUSED(event));
	// Shows the Settings frame
	void OnSettings(wxCommandEvent& WXUNUSED(event));

	// Undo the last command
	void Undo(wxCommandEvent& WXUNUSED(event));
	// Redo the last command
	void Redo(wxCommandEvent& WXUNUSED(event));

	//
	void Delete(wxCommandEvent& WXUNUSED(event));

	//
	void Cut(wxCommandEvent& WXUNUSED(event));
	//
	void Copy(wxCommandEvent& WXUNUSED(event));
	//
	void Paste(wxCommandEvent& WXUNUSED(event));

};

DECLARE_APP(Application);

#endif
