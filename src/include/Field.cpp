#include "Field.h"

Field::Field() {
    sideSize = GameSettings::getInstance()->getFieldSideLength();
    cardsCnt = 0;
    ceils.resize(sideSize);
    for (auto& row : ceils) {
        row.resize(sideSize);
    }
    for (size_t i = 0; i < sideSize; ++i) {
        for (size_t j = 0; j < sideSize; ++j) {
            ceils[i][j] = new Ceil(((!i ^ !j) || (i == sideSize - 1) ^ (j == sideSize - 1)));
        }
    }
    for (size_t i = 1; i + 1 < sideSize; ++i) {
        for (size_t j = 1; j + 1 < sideSize; ++j) {
            if (i == sideSize - 2 && j == sideSize - 2) continue;
            size_t x = (j < sideSize - 2 ? i : i + 1);
            size_t y = (j < sideSize - 2 ? j + 1 : 1);
            ceils[i][j]->next = ceils[x][y];
            ceils[x][y]->previous = ceils[i][j];
        }
    }
}


Ceil::Ceil(bool isABorder): isBorder(isABorder), isEmpty(true), 
            card(nullptr), next(nullptr), previous(nullptr) {}


void Ceil::addCard(Card* newCard) {
    card = newCard;
    isEmpty = false;
}

void Ceil::deleteCard() {
    card = nullptr;
    isEmpty = true;
}