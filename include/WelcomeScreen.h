#include <Screen.h>
#include <WelcomeText.h>

#ifndef _WELCOMESCREENH_
#define _WELCOMESCREENH_

class WelcomeScreen: public Screen{
private:
	WelcomeText welcome_text;
public:
	WelcomeScreen();
	void on_enter() override;
	void on_leave() override;
};

#endif