#include "Card.h"
#include "GameSettings.h"

#include<vector>

#pragma once


class Ceil{
  protected:
    Ceil* next;
    Ceil* previous;
  public:
    bool isBorder;
    bool isEmpty;
    Card* card;
    
    Ceil() = default;
    Ceil(bool isABorder);
    ~Ceil() = default;
    
    void setNext(Ceil* nxt);
    void setPrevious(Ceil* prev);
    
    void addCard(Card* newCard);
    void deleteCard();
};


class Field {
  protected:
    size_t sideSize;
    int cardsCnt;
    std::vector<std::vector<Ceil*>> ceils;
  public:
    Field();
    ~Field() = default;
    std::vector<std::vector<Ceil*>> getCeils();
};
