#include "Card.h"
#include<cstddef>

#pragma once

class Card_creator {
  public:
    virtual Card* create_card(size_t number = 0) = 0;
};

class Start_card_creator : public Card_creator {
  public:
    Card* create_card(size_t number) override;
};

class Finish_card_creator : public Card_creator {
  public:
    Card* create_card(size_t number) override;
};

class Island_card_creator : public Card_creator {
  public:
    Card* create_card(size_t number) override;
};

class Monster_card_creator : public Card_creator {
  public:
    Card* create_card(size_t number) override;
};
