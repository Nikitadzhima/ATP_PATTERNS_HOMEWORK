#include "PrintDecorator.h"

#include<iostream>

void StartCardPrintDecorator::print() {
    std::cout << "Start\n";
}

void FinishCardPrintDecorator::print() {
    std::cout << "Finish\n";
}

void IslandCardPrintDecorator::print() {
    std::cout << reinterpret_cast<IslandCard*>(card)->getNumber() << '\n';
}

void CardStoragePrintDecorator::print() {
    std::vector<Card*> cards = cardStorage->getCards();
    for (size_t i = 0; i < cards.size(); ++i) {
        std::cout << i + 1 << ".  ";
        if (cards[i]->cardName == "StartCard") {
            StartCardPrintDecorator xx(cards[i]);
            StartCardPrintDecorator(cards[i]).print();
        } else if (cards[i]->cardName == "FinishCard") {
            FinishCardPrintDecorator(cards[i]).print();
        } else if (cards[i]->cardName == "IslandCard") {
            IslandCardPrintDecorator(cards[i]).print();
        }
    }
}

void CeilPrintDecorator::print() { // not done yet
    if (ceil->isBorder) {
        std::cout << "#";
    } else {
        std::cout << ".";
    }
}

void FieldPrintDecorator::print() {
    std::vector<std::vector<Ceil*>> ceils = field->getCeils();
    for (int i = int(ceils.size()) - 1; i >= 0; --i) {
        for (int j = 0; j < ceils[i].size(); ++j) {
            CeilPrintDecorator(ceils[i][j]).print();
        }
        std::cout << '\n';
    }
}