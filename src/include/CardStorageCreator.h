#include "CardStorage.h"
#include "GameSettings.h"

#pragma once

class CardStorageCreator {
  public:
    virtual CardStorage* createCardStorage() = 0;
};

class DeckCreator : public CardStorageCreator {
  public:
    CardStorage* createCardStorage() override;  
};

class UserHandCreator : public CardStorageCreator {
  public:
    CardStorage* createCardStorage() override;
};

class DiscardCreator : public CardStorageCreator {
  public:
    CardStorage* createCardStorage() override;
};
