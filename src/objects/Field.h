#include "Cards.h"
#include "Game_settings.h"
#include<vector>

#pragma once


class Ceil{
  private:
    bool is_border;
    bool is_empty;
    Card* card;
    Ceil* next;
    Ceil* previous;
  public:
    Ceil() = delete;
    Ceil(bool is_a_border);
    
    void set_next(Ceil* nxt);
    void set_previous(Ceil* prev);
    
    void add_card(Card* card);
    void delete_card();
    
    ~Ceil() = default;
};


class Field {
  private:
    size_t side_size;
    int cards_cnt;
    std::vector<std::vector<Ceil*>> ceils;

    static Field* field;

    Field();
  public:
    Field(Field& other) = delete;
    void operator=(const Field& other) = delete;

    static Field* get_instance() {
        if (field == nullptr) {
            field = new Field();
        }
        return field;
    }
};
Field* Field::field = nullptr;
