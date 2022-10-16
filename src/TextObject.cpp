//
// Created by to_matih on 02/10/22.
//
#include <TextObject.h>

void TextObject::updateText(std::string new_text) {
    auto width = MeasureText(new_text.c_str(),size);
    position = {
            ()
    };
}

void TextObject::Update() {}

void TextObject::Draw3D() {}

void TextObject::Draw2D() {
    DrawText(text.c_str(), position.x, position.y, size, BLACK);
}

TextObject::TextObject(std::string text) {
    size = 10;
    updateText(text);
}

TextObject::TextObject() {
    size=10;
    updateText("");
}
