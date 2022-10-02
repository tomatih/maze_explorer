#include <GameObject.h>
#include <raylib.h>
#include <string>
#include <ScreenManager.h>

#ifndef _WELCOMETEXT_
#define _WELCOMETEXT_

class WelcomeText: public GameObject{
private:
	std::string title;
	int size;
	Vector2 position;

	void Draw3D() override;
public:
	ScreenManager* manager;
	
	WelcomeText();

	void Draw2D() override;
	void Update() override;
};

#endif
