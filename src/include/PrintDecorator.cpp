#include "PrintDecorator.h"
#include "Command.h"

void StartCardPrintDecorator::print() {
    PrintTextCommand("Start\n").execute();
}

void FinishCardPrintDecorator::print() {
    PrintTextCommand("Finish\n").execute();
}

void IslandCardPrintDecorator::print() {
    PrintTextCommand("Island: " + std::to_string(reinterpret_cast<IslandCard*>(card)->number) + "\n").execute();
}

void CardStoragePrintDecorator::print() {
    std::vector<Card*> cards = cardStorage->cards;
    for (size_t i = 0; i < cards.size(); ++i) {
        PrintTextCommand(std::to_string(i + 1) + " - play ").execute();
        if (cards[i]->cardName == "StartCard") {
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
        PrintTextCommand("####").execute();
    } else if (ceil->isEmpty) {
        PrintTextCommand(" .. ").execute();
    } else if (ceil->card->cardName == "StartCard" || ceil->card->cardName == "FinishCard") {
        PrintTextCommand(" OK ").execute();
    } else if (ceil->card->cardName == "IslandCard") {
        size_t number = reinterpret_cast<IslandCard*>(ceil->card)->number;
        PrintTextCommand(" ").execute();
        if (number < 10) {
            PrintTextCommand(" ").execute();
        }
        PrintTextCommand(std::to_string(number) + " ").execute();
    }
}

void FieldPrintDecorator::print() {
    std::vector<std::vector<Ceil*>> ceils = field->ceils;
    int height = ceils.size();
    int width = ceils[0].size();
    PrintTextCommand("       ").execute();
    for (int j = 0; j < width; ++j) {
        PrintTextCommand("____ ").execute();
    }
    PrintTextCommand("\n").execute();
    for (int i = height - 1; i >= 0; --i) {
        PrintTextCommand("      |").execute();
        for (int j = 0; j < width; ++j) {
            PrintTextCommand("    |").execute();
        }
        PrintTextCommand("\n ROW" + std::to_string(i) + " |").execute();
        for (int j = 0; j < width; ++j) {
            CeilPrintDecorator(ceils[i][j]).print();
            PrintTextCommand("|").execute();
        }
        PrintTextCommand("\n      |").execute();
        for (int j = 0; j < width; ++j) {
            PrintTextCommand("____|").execute();
        }
        PrintTextCommand("\n").execute();
    }
    PrintTextCommand("\n       ").execute();
    for (size_t j = 0; j < width; ++j) {
        PrintTextCommand("COL" + std::to_string(j) + " ").execute();
    }
    PrintTextCommand("\n\n").execute();
}