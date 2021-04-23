#include "Card_storage.h"

#pragma once

class Card_storage_creator {
  public:
    virtual Card_storage* create_card_storage() = 0;
};

class Deck_creator : public Card_storage_creator {
  public:
    Card_storage* create_card_storage() override;  
};

class User_hand_creator : public Card_storage_creator {
  public:
    Card_storage* create_card_storage() override;
};

class Discard_creator : public Card_storage_creator {
  public:
    Card_storage* create_card_storage() override;
};
