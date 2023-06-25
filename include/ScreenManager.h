#include <string>
#include <map>

#include <Screen.h>

#ifndef _SCREENMANAGERH_
#define _SCREENMANAGERH_

class ScreenManager{
private:
	std::map<std::string, Screen*> screens;
    ScreenManager() {};

public:
    bool shouldClose = false;

    static ScreenManager& getInstance(){
        static ScreenManager instance;
        return instance;
    }
    ScreenManager(ScreenManager const&) = delete;
    void operator=(ScreenManager const&) = delete;

	Screen* current_screen;

	void add_screen(std::string name, Screen* screen);

	void go_to_screen(std::string screen_name);

};

#endif
