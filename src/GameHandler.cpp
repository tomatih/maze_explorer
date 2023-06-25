//
// Created by to_matih on 24/06/23.
//

#include "GameHandler.h"
#include "raylib.h"

void GameHandler::Update() {
    if(IsKeyPressed(KEY_ESCAPE)){
        pasued = !pasued;
        player->paused = pasued;
        if(pasued){
            ShowCursor();
        } else{
            HideCursor();
        }
    }

}

GameHandler::GameHandler(Player* player): player(player) {
    auto* main_text = new TextObject("GAME PAUSED", 70, {0.5, 0.1}, LIGHTGRAY);
    pause_text.push_back(main_text);

    auto* return_game_text = new TextObject("Return to game", 50, {0.5, 0.4}, RAYWHITE);
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
