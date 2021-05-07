#include "Card.h"
#include "CardStorage.h"
#include "Field.h"

#pragma once


class BaseCardPrintDecorator : public Card {
  protected:
    Card* card;
  public:
    BaseCardPrintDecorator() = default;
    BaseCardPrintDecorator(Card* newCard) : card(newCard) {}
    ~BaseCardPrintDecorator() = default;

    virtual void print() = 0;
};

class StartCardPrintDecorator : public BaseCardPrintDecorator {
  public:
    StartCardPrintDecorator(Card* newCard) {
        card = newCard;
    }
    void print() override;
};

class FinishCardPrintDecorator : public BaseCardPrintDecorator {
  public:
    FinishCardPrintDecorator(Card* newCard) {
        card = newCard;
    }
    void print() override;
};

class IslandCardPrintDecorator : public BaseCardPrintDecorator {
  public:
    IslandCardPrintDecorator(Card* newCard) {
        card = newCard;
    }
    void print() override;
};


class CardStoragePrintDecorator : public CardStorage {
  public:
    CardStorage* cardStorage;
    CardStoragePrintDecorator(CardStorage* newCardStorage) : cardStorage(newCardStorage) {}
    void print();
};

class CeilPrintDecorator : public Ceil {
  public:
    Ceil* ceil;
    CeilPrintDecorator(Ceil* newCeil) : ceil(newCeil) {}
    void print();
};

class FieldPrintDecorator : public Field {
  public:
    Field* field;
    FieldPrintDecorator(Field* newField) : field(newField) {}
    void print();
};