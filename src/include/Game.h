#include "Field.h"
#include "CardCreator.h"
#include "CardStorageCreator.h"
#include "PrintDecorator.h"

#pragma once

class Game {
  public:
    Deck* deck;
    UserHand* userHand;
    Discard* discard;
    Field* field;

    void prepare();
    void start();
};