#pragma once

class Card {
  public:
    virtual void play(int x, int y) = 0;
    void moveToDiscard();
};

class StartCard : public Card {
  public:
    void play(int x, int y) override;
};

class FinishCard : public Card {
  public:
    void play(int x, int y) override;
};

class IslandCard : public Card {
  private:
    int number;
  public:
    IslandCard(int newNumber);
    
    int getNumber();
    void play(int x, int y) override;
};
