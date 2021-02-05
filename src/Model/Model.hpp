#include <wx/wx.h>
#include <vector>
#include "../Commands/CommandProcessor.hpp"

#ifndef MODEL_HPP
#define MODEL_HPP

class Model
{
public:
	static Model &getInstance()
	{
		static Model instance;
		return instance;
	}

private:
	Model() {}

public:
	Model(Model const&) = delete;
	void operator=(Model const&) = delete;

	// Current project path string
	wxString currentProjectPath;

	CommandProcessor* commandProcessor;
};

#endif
