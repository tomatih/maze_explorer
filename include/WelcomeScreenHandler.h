#include <GameObject.h>
#include <raylib.h>
#include <string>
#include <ScreenManager.h>

#ifndef _WELCOMESCREENHANDLER_
#define _WELCOMESCREENHANDLER_

class WelcomeScreenHandler: public GameObject{
private:
	void Draw3D() override;
    void Draw2D() override;
public:
	ScreenManager* manager;
	
	WelcomeScreenHandler();

	void Update() override;
};

#endif
