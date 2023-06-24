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
}
