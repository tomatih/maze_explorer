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
