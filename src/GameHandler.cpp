//
// Created by to_matih on 24/06/23.
//

#include "GameHandler.h"
#include "raylib.h"

void GameHandler::Update() {
    // pausing logic
    if(IsKeyPressed(KEY_ESCAPE)){
        pasued = !pasued;
        player->paused = pasued;
        if(pasued){
            pause_text[currently_selected +1]->color = GRAY;
            currently_selected = 0;
            pause_text[currently_selected +1]->color = RAYWHITE;
            ShowCursor();
        } else{
            HideCursor();
        }
    }
    // pause screen logic
    if(pasued){
        if(IsKeyPressed(KEY_UP) || IsKeyPressed(KEY_DOWN)){
            pause_text[currently_selected +1]->color = GRAY;
            if(IsKeyPressed(KEY_DOWN)){
                currently_selected++;
                currently_selected %= max_options;
            }
            else{
                currently_selected--;
                if(currently_selected<0){
                    currently_selected = max_options-1;
                }
            }
            pause_text[currently_selected +1]->color = RAYWHITE;
        }
    }
}

GameHandler::GameHandler(Player* player): player(player) {
    auto* main_text = new TextObject("GAME PAUSED", 70, {0.5, 0.1}, LIGHTGRAY);
    pause_text.push_back(main_text);

    auto* return_game_text = new TextObject("Return to game", 50, {0.5, 0.4}, GRAY);
    pause_text.push_back(return_game_text);

    auto* return_menu_text = new TextObject("Return to main menu", 50, {0.5, 0.5}, GRAY);
    pause_text.push_back(return_menu_text);

    auto* exit_text = new TextObject("Quit game", 50, {0.5, 0.6}, GRAY);
    pause_text.push_back(exit_text);
}

void GameHandler::Draw2D() {
    if(pasued){
        // dark filter
        DrawRectangle(0,0,GetScreenWidth(),GetScreenHeight(), ColorAlpha(BLACK,0.5));
        // menu text
        for(auto text : pause_text){
            text->Draw2D();
        }
    }
}
