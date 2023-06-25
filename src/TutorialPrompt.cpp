//
// Created by to_matih on 25/06/23.
//

#include "TutorialPrompt.h"

TutorialPrompt::TutorialPrompt() {
    auto dpi_setting = GetWindowScaleDPI();
    auto screen_width = (float)GetScreenWidth() * dpi_setting.x;
    auto screen_height = (float)GetScreenHeight() * dpi_setting.y;
    auto width = 0.33f;
    auto height = 0.2f;
    main_box = {
            .x = (1-width) * screen_width,
            .y = (1-height) * screen_height,
            .width = width * screen_width,
            .height = height * screen_height,
    };
}

void TutorialPrompt::Draw2D() {
    DrawRectangleRec(main_box, SKYBLUE);
    move_text.Draw2D();
    camera_text.Draw2D();
    luck_text.Draw2D();
}

void TutorialPrompt::Update() {

}
