#include "../../Config.hpp"

#ifndef SETTINGS_FRAME_HPP
#define SETTINGS_FRAME_HPP

class SettingsFrame : public SettingsFrame_Base {
public:
	SettingsFrame(wxWindow* parent, Config* config);

	Config* config;

	void OnClose(wxCloseEvent& WXUNUSED(event));

	void UpdateFromConfig();
};

#endif
