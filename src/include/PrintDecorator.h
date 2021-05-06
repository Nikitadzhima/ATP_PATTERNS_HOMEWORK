#include "Card.h"
#include "CardStorage.h"
#include "Field.h"

#pragma once


class StartCardPrintDecorator {
  public:
    StartCard* card;
    StartCardPrintDecorator(Card* newCard) {
        card = reinterpret_cast<StartCard*>(newCard);
    }
    StartCardPrintDecorator(StartCard* newCard) {
        card = newCard;
    }
    void print();
};

class FinishCardPrintDecorator {
  public:
    FinishCard* card;
    FinishCardPrintDecorator(Card* newCard) {
        card = reinterpret_cast<FinishCard*>(newCard);
    }
    FinishCardPrintDecorator(FinishCard* newCard) {
        card = newCard;
    }
    void print();
};

class IslandCardPrintDecorator {
  public:
    IslandCard* card;
    IslandCardPrintDecorator(Card* newCard) {
        card = reinterpret_cast<IslandCard*>(newCard);
    }
    IslandCardPrintDecorator(IslandCard* newCard) {
        card = newCard;
    }
    void print();
};

class CardPrintDecorator {
  public:
    Card* card;
    CardPrintDecorator(Card* newCard) : card(newCard) {}
    void print();
};

class UserHandPrintDecorator {
  public:
    UserHand* userHand;
    UserHandPrintDecorator(UserHand* newUserHand) : userHand(newUserHand) {}
    void print();
};

class CeilPrintDecorator {
  public:
    Ceil* ceil;
    CeilPrintDecorator(Ceil* newCeil) : ceil(newCeil) {}
    void print();
};

class FieldPrintDecorator {
  public:
    Field* field;
    FieldPrintDecorator(Field* newField) : field(newField) {}
    void print();
};