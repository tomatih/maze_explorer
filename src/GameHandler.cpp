//
// Created by to_matih on 24/06/23.
//

#include "GameHandler.h"
#include "ScreenManager.h"
#include "raylib.h"

void GameHandler::Update() {
    // pausing logic
    if(IsKeyPressed(KEY_ESCAPE)){
        pauseGame();
    }
    // pause screen logic
    if(paused){
        // choosing logic
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
        // selection logic
        if(IsKeyPressed(KEY_ENTER)){
            ScreenManager& screenManager = ScreenManager::getInstance();
            switch (currently_selected) {
                case 0:
                    pauseGame();
                    break;
                case 1:
                    screenManager.go_to_screen("Welcome");
                    break;
                case 2:
                    screenManager.shouldClose = true;
                    break;
                default:
                    printf("INVALID OPTION\n");
                    break;
            }
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
    if(paused){
        // dark filter
        DrawRectangle(0,0,GetScreenWidth(),GetScreenHeight(), ColorAlpha(BLACK,0.5));
        // menu text
        for(auto text : pause_text){
            text->Draw2D();
        }
    }
}

void GameHandler::pauseGame() {
    // toggle passe status
    paused = !paused;
    player->paused = paused;
    if(paused){
        // refresh selection
        pause_text[currently_selected +1]->color = GRAY;
        currently_selected = 0;
        pause_text[currently_selected +1]->color = RAYWHITE;
        // cursor logic
        ShowCursor();
    } else{
        // cursor logic
        HideCursor();
    }
}
