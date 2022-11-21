//
// Created by to_matih on 02/10/22.
//
#include <TextObject.h>

void TextObject::updateText(std::string new_text) {
    auto width = MeasureText(new_text.c_str(),size);
    draw_position = {
            position.x - (float)width/2.0f,
            position.y - (float)size/2.0f
    };
    text = new_text;
}

void TextObject::Update() {}

void TextObject::Draw3D() {}

void TextObject::Draw2D() {
    DrawText(text.c_str(), (int)draw_position.x, (int)draw_position.y, size, BLACK);
}

TextObject::TextObject(std::string text, int size, Vector2 position) : size(size), position(position) {
    updateText(text);
}

void TextObject::updatePosition(Vector2 new_position) {
    Vector2 offset = {
            draw_position.x - position.x,
            draw_position.y - position.y
    };
    position = new_position;
    draw_position = {
            new_position.x + offset.x,
            new_position.y + offset.y
    };
}

