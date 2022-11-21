#include "GameObject.h"
#include <string>
#include <raylib.h>

#ifndef _TEXTOBJECTH_
#define _TEXTOBJECTH_

class TextObject : public GameObject{
private:
	std::string text;
    Vector2 draw_position;
    Vector2 position;
    int size;

	void Update() override;
	void Draw3D() override;
public:
    TextObject(std::string text, int size, Vector2 position);
	void updateText(std::string new_text);
    void updatePosition(Vector2 new_position);
	void Draw2D() override;
};

#endif