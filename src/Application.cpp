#include "Application.hpp"

extern void InitXmlResource();

// Override of wxApp to construct this application
bool Application::OnInit()
{
	// Initialise images, then load the xml file and initialise it
	wxInitAllImageHandlers();
	wxXmlResource::Get()->InitAllHandlers();
	InitXmlResource();

	Model::getInstance().commandProcessor = new CommandProcessor(this);

	config = new Config();

	// Create the main frame (and rest of the GUI)
	mainFrame = new MainFrame();
	about = new About(mainFrame);
	settingsFrame = new SettingsFrame(mainFrame, config);


	// Show the main frame (and rest of the GUI)
	mainFrame->Show(true);

	// Menu Bindings
	Bind(wxEVT_MENU, &Application::OpenFolder, this, XRCID("OpenMenuItem"));
	Bind(wxEVT_MENU, &Application::OnExit, this, XRCID("QuitMenuItem"));
	Bind(wxEVT_MENU, &Application::OnAbout, this, XRCID("AboutMenuItem"));
	Bind(wxEVT_MENU, &Application::OnSettings, this, XRCID("SettingsMenuItem"));
	Bind(wxEVT_MENU, &Application::Undo, this, XRCID("UndoMenuItem"));
	Bind(wxEVT_MENU, &Application::Redo, this, XRCID("RedoMenuItem"));
	Bind(wxEVT_MENU, &Application::saveFile, this, XRCID("SaveMenuItem"));


	Connect(XRCID("UndoTool"), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler(Application::Undo));
	Connect(XRCID("RedoTool"), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler(Application::Redo));

	Connect(XRCID("SaveTool"), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler(Application::saveFile));

	//loadConfig();
	UpdateStates();
	return true;
}

// Load the config file
// Called during Application::OnInit()
void Application::loadConfig()
{
	// Use to check if the the config file exists
	// If the config file exists
	if (config->Exists())
	{
		//config->Load();
		//if (config->autoloadProject == true)
		//{
		//	Model::getInstance().currentProjectPath = config->autoloadProjectPath;
		//	loadProject();
		//}
	}
}

// Open the project directory load dialogue, use to load a project to work on
// Called from File->Open and Open Project Tool
void Application::Open(wxCommandEvent& event)
{
	// Open Directory Dialogue for selecting the project root folder
	wxFileDialog openFileDialog(mainFrame, _("Open file"), "", "", "XYZ files (*.xyz)|*.xyz", wxFD_OPEN|wxFD_FILE_MUST_EXIST);
	// Record the result
	int result = openFileDialog.ShowModal();
	// If the user clicks cancel
	if (result == wxID_CANCEL)
	{
		return;
	}
	wxFileInputStream input_stream(openFileDialog.GetPath());
	if (input_stream.IsOk())
	{
		// Load File openFileDialog.GetPath()
	}
}

// Open the project directory load dialogue, use to load a project to work on
// Called from File->Open and Open Project Tool
void Application::OpenFolder(wxCommandEvent& event)
{
	// Open Directory Dialogue for selecting the project root folder
	wxDirDialog openFolderDialog(mainFrame, _("Open folder"), wxGetCwd(), 0, wxDefaultPosition);
	// Record the result
	int result = openFolderDialog.ShowModal();
	// If the user clicks cancel
	if (result == wxID_CANCEL)
	{
		return;
	}
	// If the user selects a root folder
	else if (result == wxID_OK)
	{
		// Load the project from the file dialogue path
		Model::getInstance().currentProjectPath = openFolderDialog.GetPath().ToStdString();
		// Load Folder
	}
}

// Loads the project from the file path
// Called if config is properly loaded, or if a project folder is selected from the directory dialogue
void Application::loadFolder(wxString projectDirectory)
{
	// Set the working directory to the project path
	wxSetWorkingDirectory(projectDirectory);
	// Update the main frame status to the project path
	//mainFrame->UpdateCurrentProjectStatusString();
}

// Save the currently loaded file
void Application::saveFile(wxCommandEvent& event)
{

}

// Save all the files in the project (that have been opened)
void Application::saveFileAll(wxCommandEvent& event)
{

}

// Update Icon/Widget States (Menu and Toolbar)
void Application::UpdateStates()
{
	wxToolBar* mainFrameToolbar = mainFrame->GetToolBar();

	//Undo
	mainFrameToolbar->EnableTool(XRCID("UndoTool"), Model::getInstance().commandProcessor->CanUndo());

	//Redo
	mainFrameToolbar->EnableTool(XRCID("RedoTool"), Model::getInstance().commandProcessor->CanRedo());
}

// Shows the About frame
void Application::OnAbout(wxCommandEvent& event)
{
	about->Show(true);
}

// Exits out of the main loop when MainFrame is exited
void Application::OnExit(wxCommandEvent& event)
{
	ExitMainLoop();
}

// Shows the Settings frame
void Application::OnSettings(wxCommandEvent& event)
{
	settingsFrame->UpdateFromConfig();
	settingsFrame->Show(true);
}

void Application::Undo(wxCommandEvent& event)
{
	if (Model::getInstance().commandProcessor->Undo())
	{
		UpdateStates();
	}
}

void Application::Redo(wxCommandEvent& event)
{
	if (Model::getInstance().commandProcessor->Redo())
	{
		UpdateStates();
	}
}
