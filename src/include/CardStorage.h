#include "Card.h"

#include<vector>

#pragma once

class CardStorage {
  protected:
    std::vector<Card*> cards;
  public:
    size_t size();

    void addCard(Card* card);
    void deleteCard(Card* card);
    std::vector<Card*> getCards();
};

class Deck : public CardStorage {

};

class UserHand : public CardStorage {

};

class Discard : public CardStorage {

};
