#include <wx/wx.h>
#include <wx/cmdproc.h>

#ifndef COMMAND_PROCESSOR_HPP
#define COMMAND_PROCESSOR_HPP

extern class Application;

class CommandProcessor : public wxCommandProcessor
{
public:
	CommandProcessor(Application* app);

	Application* application;

	void Add(wxCommand* command);
};

#endif
