//
// Created by to_matih on 25/06/23.
//

#include "TutorialPrompt.h"

TutorialPrompt::TutorialPrompt(GameHandler& handler) : handler(handler) {
    auto dpi_setting = GetWindowScaleDPI();
    auto screen_width = (float)GetScreenWidth() * dpi_setting.x;
    auto screen_height = (float)GetScreenHeight() * dpi_setting.y;
    auto width = 0.33f;
    auto height = 0.2f;
    border_box = {
            .x = (1-width) * screen_width,
            .y = (1-height) * screen_height,
            .width = width * screen_width,
            .height = height * screen_height,
    };
    auto border_delta = 2.5f;
    main_box = {
            .x = border_box.x + border_delta* dpi_setting.x,
            .y = border_box.y + border_delta* dpi_setting.y,
            .width = border_box.width - border_delta* dpi_setting.x *2,
            .height = border_box.height - border_delta* dpi_setting.y * 2,
    };

    reset();
}

void TutorialPrompt::Draw2D() {
    if(active){
        DrawRectangleRec(border_box, BLACK);
        DrawRectangleRec(main_box, SKYBLUE);
        move_text.Draw2D();
        camera_text.Draw2D();
        luck_text.Draw2D();
    }
}

void TutorialPrompt::Update() {
    if(active){
        if(!handler.isPaused()){
            remaining_time -= GetFrameTime();
        }
        if(remaining_time<0){
            active = false;
        }
    }
}

void TutorialPrompt::reset() {
    remaining_time = display_time;
    active = true;
}
