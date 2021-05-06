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
    
    void addCard(Card* newCard);
    void deleteCard();
    
    ~Ceil() = default;
};


class Field {
  private:
    size_t sideSize;
    int cardsCnt;
    std::vector<std::vector<Ceil*>> ceils;
  public:
    Field();
    std::vector<std::vector<Ceil*>> getCeils();
};
