#include <wx/wx.h>
#include <wx/textfile.h>
#include "Model/Model.hpp"

#ifndef CONFIG_HPP
#define CONFIG_HPP

class Config
{
public:
	Config();

	wxTextFile* configFile;

	bool Exists();

	void Load();
};

#endif
