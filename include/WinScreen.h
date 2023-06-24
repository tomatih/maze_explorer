#include <Screen.h>
#include "TextObject.h"

#ifndef _WINSCREENH_
#define _WINSCREENH_

class WinScreen: public Screen{
private:
    TextObject win_text;

public:
    WinScreen();
    void on_enter() override;
    void on_leave() override;
};


#endif //MAZE_EXPLORER_WINSCREEN_H
