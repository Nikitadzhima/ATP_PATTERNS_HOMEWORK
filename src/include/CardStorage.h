#include "Card.h"

#include<vector>

#pragma once

class CardStorage {
  public:
    std::vector<Card*> cards;

    size_t size();
    void addCard(Card* card);
    void deleteCard(Card* card);
};