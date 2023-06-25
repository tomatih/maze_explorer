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
    std::vector<TextObject *> pause_text;

    const int max_options = 3;
    int currently_selected = 0;

    void Draw3D() override {};
public:
    GameHandler(Player* player);

    void Draw2D() override;
    void Update() override;
};


#endif //MAZE_EXPLORER_GAMEHANDLER_H
