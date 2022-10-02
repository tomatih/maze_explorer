#include <WelcomeText.h>
#include <raylib.h>

WelcomeText::WelcomeText(){
	title = "Maze Explorer";
	size = 50;
}

void WelcomeText::Draw2D(){
	DrawText(title.c_str(), position.x, position.y, size, BLACK);
}

void WelcomeText::Update(){
	auto title_width = MeasureText(title.c_str(), size);
	position = {(GetRenderWidth()-title_width)/2.0f, (GetRenderHeight()-size)/2.0f};
}

void WelcomeText::Draw3D(){};