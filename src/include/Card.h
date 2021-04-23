#pragma once

class Card {
  public:
    virtual void play(int x, int y) = 0;
    void move_to_discard();
};

class Start_card : public Card {
  public:
    void play(int x, int y) override;
};

class Finish_card : public Card {
  public:
    void play(int x, int y) override;
};

class Island_card : public Card {
  private:
    int number;
  public:
    Island_card(int new_number);
    
    int get_number();
    void play(int x, int y) override;
};

class Monster_card : public Card {
  public:
    void play(int x, int y) override;
};
