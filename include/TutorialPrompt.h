//
// Created by to_matih on 25/06/23.
//

#ifndef MAZE_EXPLORER_TUTORIALPROMPT_H
#define MAZE_EXPLORER_TUTORIALPROMPT_H


#include <raylib.h>
#include "GameObject.h"
#include "TextObject.h"
#include "GameHandler.h"

class TutorialPrompt : public GameObject{
private:
    Rectangle main_box;
    Rectangle border_box;
    TextObject move_text = TextObject("W S A D - move player", 20, {0.84, 0.85});
    TextObject camera_text = TextObject("arrow keys/mouse - camera control", 20, {0.84, 0.9});
    TextObject luck_text = TextObject("Good luck!", 20, {0.84,0.95});

    constexpr static const float display_time = 10;
    float remaining_time;
    bool active = true;
    GameHandler& handler;

    void Draw3D() override {};
public:
    TutorialPrompt(GameHandler& handler);
    void reset();

    void Update() override;
    void Draw2D() override;
};


#endif //MAZE_EXPLORER_TUTORIALPROMPT_H
