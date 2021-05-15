#include "Field.h"
#include "CardCreator.h"
#include "CardStorage.h"
#include "PrintDecorator.h"
#include "GameSettings.h"
#include "Command.h"

#pragma once

class Game {
  public:
    bool gameOver = false;
  private:
    void welcomeUser();
    void makeTurn();
    void showFinalResult();
    void showTurnOptions();

  public:
    CardStorage* deck;
    CardStorage* userHand;
    CardStorage* discard;
    Field* field;

    void prepare();
    void start();
};