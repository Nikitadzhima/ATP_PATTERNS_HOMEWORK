#include "include/Game.h"

int main() {
    GameSettings* gameSettings = GameSettings::getInstance();
    Game* game = new Game();
    game->prepare(); // create everything and initialize
    //game->start();
    return 0;
}