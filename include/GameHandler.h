//
// Created by to_matih on 24/06/23.
//

#ifndef MAZE_EXPLORER_GAMEHANDLER_H
#define MAZE_EXPLORER_GAMEHANDLER_H


#include "GameObject.h"
#include "Player.h"

class GameHandler : public GameObject {
private:
    bool pasued = false;
    Player* player;

    void Draw3D() override {};
    void Draw2D() override {};
public:
    GameHandler(Player* player);

    void Update() override;
};


#endif //MAZE_EXPLORER_GAMEHANDLER_H
