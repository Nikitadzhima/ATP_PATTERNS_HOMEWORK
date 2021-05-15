#include "Card.h"
#include "GameSettings.h"

#include<vector>

#pragma once


class Ceil{
  public:
    Ceil* next;
    Ceil* previous;
    bool isBorder;
    bool isEmpty;
    Card* card;
    
    Ceil() = default;
    Ceil(bool isABorder);
    ~Ceil() = default;
    
    void addCard(Card* newCard);
    void deleteCard();
};


class Field {
  public:
    size_t sideSize;
    int cardsCnt;
    std::vector<std::vector<Ceil*>> ceils;

    Field();
    ~Field() = default;
};
