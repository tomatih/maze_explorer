#include "GameObject.h"
#include <string>
#include <raylib.h>

#ifndef _TEXTOBJECTH_
#define _TEXTOBJECTH_

class TextObject : public GameObject{
private:
	std::string text;
    Vector2 position;
    int size;

	void Update() override;
	void Draw3D() override;
public:
	void updateText(std::string new_text);
	void Draw2D() override;
};

#endif