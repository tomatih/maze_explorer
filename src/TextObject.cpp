//
// Created by to_matih on 02/10/22.
//
#include <TextObject.h>

void TextObject::updateText(std::string new_text) {
    auto width = MeasureText(new_text.c_str(),size);
    position = {
            (GetRenderWidth()-width)/2.0f,
            (GetRenderHeight()-size)/2.0f
    };
    text = new_text;
}

void TextObject::Update() {}

void TextObject::Draw3D() {}

void TextObject::Draw2D() {
    DrawText(text.c_str(), (int)position.x, (int)position.y, size, BLACK);
}

TextObject::TextObject(std::string text, int size) {
    this->size = size;
    updateText(text);
}

TextObject::TextObject(std::string text) {
    size = 10;
    updateText(text);
}

TextObject::TextObject() {
    size=10;
    updateText("");
}
