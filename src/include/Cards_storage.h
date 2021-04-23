#include "Cards.h"
#include "Game_settings.h"

#include<vector>

#pragma once

class Cards_storage {
  protected:
    std::vector<Card*> cards;
    
    Cards_storage() = default;
  public:
    Cards_storage(Cards_storage& other) = delete;
    void operator=(const Cards_storage& other) = delete;

    void add_card(Card* card);
    void delete_card(Card* card);
    std::vector<Card*> get_cards();
};

class Deck : public Cards_storage {
  private:
    static Deck* deck;
  public:
    static Deck* get_instance() {
        if (deck == nullptr) {
            deck = new Deck();
        }
        return deck;
    }
};
Deck* Deck::deck = nullptr;

class User_hand : public Cards_storage {
  private:
    static User_hand* user_hand;
  public:
    static User_hand* get_instance() {
        if (user_hand == nullptr) {
            user_hand = new User_hand();
        }
        return user_hand;
    }
};
User_hand* User_hand::user_hand = nullptr;

class Discard : public Cards_storage {
  private:
    static Discard* discard;
  public:
    static Discard* get_instance() {
        if (discard == nullptr) {
            discard = new Discard();
        }
        return discard;
    }
};
Discard* Discard::discard = nullptr;
