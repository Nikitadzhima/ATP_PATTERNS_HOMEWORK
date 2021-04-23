#include "Card.h"
#include "Game_settings.h"

#include<vector>

#pragma once

class Card_storage {
  protected:
    std::vector<Card*> cards;
  public:
    void add_card(Card* card);
    void delete_card(Card* card);
    std::vector<Card*> get_cards();
};

class Deck : public Card_storage {

};

class User_hand : public Card_storage {

};

class Discard : public Card_storage {

};
