#include "Card.h"
#include "GameSettings.h"

#include<vector>

#pragma once


class Ceil{
  private:
    Card* card;
    Ceil* next;
    Ceil* previous;
  public:
    bool isBorder;
    bool isEmpty;
    
    Ceil() = delete;
    Ceil(bool isABorder);
    
    void setNext(Ceil* nxt);
    void setPrevious(Ceil* prev);
    
    void addCard(Card* card);
    void deleteCard();
    
    ~Ceil() = default;
};


class Field {
  private:
    size_t sideSize;
    int cardsCnt;
    std::vector<std::vector<Ceil*>> ceils;

    static Field* field;

    Field();
  public:
    Field(Field& other) = delete;
    void operator=(const Field& other) = delete;

    static Field* getInstance() {
        if (field == nullptr) {
            field = new Field();
        }
        return field;
    }

    std::vector<std::vector<Ceil*>> getCeils();
};
