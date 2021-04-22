#include "Cards.h"
#include "Game_settings.h"

#include<vector>

#pragma once

class Cards_storage {
  private:
    std::vector<Card*> cards;
    Cards_storage* storage;

  public:
    void add_card(Card* card);
    void delete_card(Card* card);
    std::vector<Card*> get_cards();
};

class Deck : public Cards_storage {
    
};

class User_hand : public Cards_storage {

};

class Discard : public Cards_storage {

};
