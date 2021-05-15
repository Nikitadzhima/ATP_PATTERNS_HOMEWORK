#include <string>

#pragma once

class Field;
class CardStorage;

class Card {
  public:
    std::string cardName = "Card";

    bool canBePlayed(int x, int y, Field* field, CardStorage* userHand) { return false; }
    void play(int x, int y, Field* field, CardStorage* userHand, CardStorage* deck, CardStorage* discard) {}
    void moveToDiscard(CardStorage* discard);
};

class StartCard : public Card {
  public:
    StartCard();
    bool canBePlayed(int x, int y, Field* field, CardStorage* userHand);
    void play(int x, int y, Field* field, CardStorage* userHand, CardStorage* deck, CardStorage* discard);
};

class FinishCard : public Card {
  public:
    FinishCard();
    bool canBePlayed(int x, int y, Field* field, CardStorage* userHand);
    void play(int x, int y, Field* field, CardStorage* userHand, CardStorage* deck, CardStorage* discard);
};

class IslandCard : public Card {
  public:
    int number;
    IslandCard(int newNumber);
    
    bool canBePlayed(int x, int y, Field* field, CardStorage* userHand);
    void play(int x, int y, Field* field, CardStorage* userHand, CardStorage* deck, CardStorage* discard);
};
