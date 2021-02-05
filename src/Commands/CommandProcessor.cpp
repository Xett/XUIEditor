#include "CommandProcessor.hpp"
#include "../Application.hpp"

CommandProcessor::CommandProcessor(Application* app) : wxCommandProcessor()
{
	application = app;
}
void CommandProcessor::Add(wxCommand* command)
{
	Submit(command);
	application->UpdateStates();
};
