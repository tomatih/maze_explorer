//
// Created by to_matih on 02/10/22.
//
#include <TextObject.h>

void TextObject::updateText(std::string new_text) {
    auto width = MeasureText(new_text.c_str(),size);
    draw_position = {
            screen_position.x - (float)width / 2.0f,
            screen_position.y - (float)size / 2.0f
    };
    text = new_text;
}

void TextObject::Update() {}

void TextObject::Draw3D() {}

void TextObject::Draw2D() {
    DrawText(text.c_str(), (int)draw_position.x, (int)draw_position.y, size, color);
}

TextObject::TextObject(std::string text, int size, Vector2 position, Color color) : size(size), color(color){
    // init values as dummies
    updatePosition(position);
    updateText(text);
}

void TextObject::updatePosition(Vector2 new_position) {
    Vector2 offset = {
            draw_position.x - screen_position.x,
            draw_position.y - screen_position.y
    };
    normal_position = new_position;
    auto dpi = GetWindowScaleDPI();
    screen_position = {
            .x = (float)GetScreenWidth() * dpi.x * normal_position.x,
            .y = (float)GetScreenHeight() * dpi.y * normal_position.y
    };
    draw_position = {
            screen_position.x + offset.x,
            screen_position.y + offset.y
    };
}

