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

void CeilPrintDecorator::print() {
    if (ceil->isBorder) {
        std::cout << "####";
    } else if (ceil->isEmpty) {
        std::cout << " .. ";
    } else if (ceil->card->cardName == "StartCard") {
        std::cout << " OK ";
    } else if (ceil->card->cardName == "FinishCard") {
        std::cout << " OK ";
    } else if (ceil->card->cardName == "IslandCard") {
        size_t number = reinterpret_cast<IslandCard*>(ceil->card)->getNumber();
        std::cout << " ";
        if (number < 10) {
            std::cout << " ";
        }
        std::cout << number;
        std::cout << " ";
    }
}

void FieldPrintDecorator::print() {
    std::vector<std::vector<Ceil*>> ceils = field->getCeils();
    int height = ceils.size();
    int width = ceils[0].size();
    std::cout << "      ";
    std::cout << " ";
    for (int j = 0; j < width; ++j) {
        std::cout << "____ ";
    }
    std::cout << '\n';
    for (int i = height - 1; i >= 0; --i) {
        std::cout << "      ";
        std::cout << "|";
        for (int j = 0; j < width; ++j) {
            std::cout << "    |";
        }
        std::cout << '\n';
        std::cout << " row" << i << " ";
        std::cout << "|";
        for (int j = 0; j < width; ++j) {
            CeilPrintDecorator(ceils[i][j]).print();
            std::cout << "|";
        }
        std::cout << '\n';
        std::cout << "      ";
        std::cout << "|";
        for (int j = 0; j < width; ++j) {
            std::cout << "____|";
        }
        std::cout << '\n';
    }
    std::cout << '\n';
    std::cout << "       ";
    for (size_t j = 0; j < width; ++j) {
        std::cout << "col" << j << " ";
    }
    std::cout << "\n\n";
}