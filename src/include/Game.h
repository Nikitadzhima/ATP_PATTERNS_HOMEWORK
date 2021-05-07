#include "Field.h"
#include "CardCreator.h"
#include "CardStorage.h"
#include "PrintDecorator.h"
#include "GameSettings.h"

#pragma once

class Game {
  public:
    CardStorage* deck;
    CardStorage* userHand;
    CardStorage* discard;
    Field* field;

    void prepare();
    void start();
};