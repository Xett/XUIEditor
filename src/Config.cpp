#include "Config.hpp"

Config::Config()
{
	configFile = new wxTextFile("config.ini");
}

bool Config::Exists()
{
	return configFile->Exists();
}

void Config::Load()
{
	configFile->Open();
	// Load the project from the path
	for (int i = 0; i < configFile->GetLineCount(); i++)
	{
		wxString line = configFile->GetLine(i);
		wxString key = line.BeforeFirst('=');
		wxString value = line.AfterFirst('=');
		//if (key == "autoload_project_enabled")
		//{
			//if (value == "true")
			//{
				//autoloadProject = true;
			//}
		//}
		//else if (key == "autoload_project_directory")
		//{
			//autoloadProjectPath = value;
		//}
	}
}
