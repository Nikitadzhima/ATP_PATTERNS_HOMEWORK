#include "Card.h"
#include<cstddef>

#pragma once

class CardCreator {
  public:
    virtual Card* createCard(size_t number = 0) = 0;
};

class StartCardCreator : public CardCreator {
  public:
    Card* createCard(size_t number) override;
};

class FinishCardCreator : public CardCreator {
  public:
    Card* createCard(size_t number) override;
};

class IslandCardCreator : public CardCreator {
  public:
    Card* createCard(size_t number) override;
};
