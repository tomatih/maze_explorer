#include <Screen.h>
#include <WelcomeScreenHandler.h>
#include <TextObject.h>

#ifndef _WELCOMESCREENH_
#define _WELCOMESCREENH_

class WelcomeScreen: public Screen{
private:
	WelcomeScreenHandler welcome_text;
    TextObject title_text;
public:
	WelcomeScreen();
	void on_enter() override;
	void on_leave() override;
};

#endif