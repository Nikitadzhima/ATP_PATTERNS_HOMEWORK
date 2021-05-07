#include <string>

#pragma once

class Card {
  public:
    std::string cardName = "Card";

    void play(int x, int y) {}
    void moveToDiscard();
};

class StartCard : public Card {
  public:
    StartCard();
    void play(int x, int y);
};

class FinishCard : public Card {
  public:
    FinishCard();
    void play(int x, int y);
};

class IslandCard : public Card {
  private:
    int number;
  public:
    IslandCard(int newNumber);
    
    int getNumber();
    void play(int x, int y);
};
