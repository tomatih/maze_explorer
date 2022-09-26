#include <string>
#include <map>

#include <Screen.h>

#ifndef _SCREENMANAGERH_
#define _SCREENMANAGERH_

class ScreenManager{
private:
	std::map<std::string, Screen*> screens;

public:
	Screen* current_screen;

	void add_screen(std::string name, Screen* screen);

	void go_to_screen(std::string screen_name);

};

#endif
