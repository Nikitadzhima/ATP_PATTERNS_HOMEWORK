#include "Card.h"
#include "Field.h"
#include "CardStorage.h"
#include "Command.h"
#include "PrintDecorator.h"


void Card::moveToDiscard(CardStorage* discard) {
    discard->addCard(this);
}

bool StartCard::canBePlayed(int x, int y, Field* field, CardStorage* userHand) {
    return x == 0 && y == 0;
}

int inputNumberFromto(int from, int to) {
    InputIntNumberCommand scaner;
    scaner.execute();
    while (scaner.number < from || scaner.number > to) {
        PrintTextCommand("Wrong number. Try again:\n").execute();
        scaner.execute();
    }
    return scaner.number;
}

void drop(CardStorage* userHand, Field* field, CardStorage* deck, CardStorage* discard, int cnt) {
    if (cnt == 0) {
        return;
    }
    system("clear");
    FieldPrintDecorator(field).print();
    PrintTextCommand("Cards left in deck: " + std::to_string(deck->size()) + "\n\n").execute();
    PrintTextCommand("Your cards:\n").execute();
    CardStoragePrintDecorator(userHand).print();
    PrintTextCommand("\nNow you have to drop some cards.\n").execute();
    PrintTextCommand("Cards left to drop: " + std::to_string(cnt) + "\n").execute();
    PrintTextCommand("Choose a card:\n").execute();
    int pos = inputNumberFromto(1, userHand->size());
    Card* card = userHand->cards[pos - 1];
    userHand->deleteCard(card);
    discard->addCard(card);
    drop(userHand, field, deck, discard, cnt - 1);
}

void StartCard::play(int x, int y, Field* field, CardStorage* userHand, CardStorage* deck, CardStorage* discard) {
    field->ceils[x][y]->addCard(this);
    userHand->deleteCard(this);
    int newCardsCnt = GameSettings::getInstance()->getDiscardCardWithStart();
    for (int i = 0; i < newCardsCnt; ++i) {
        Card* card = deck->cards.back();
        deck->deleteCard(card);
        userHand->addCard(card);
    }
    drop(userHand, field, deck, discard, newCardsCnt);
}

bool FinishCard::canBePlayed(int x, int y, Field* field, CardStorage* userHand) {
    for (auto card : userHand->cards) {
        if (card->cardName == "StartCard") {
            return false;
        }
    }
    int sz = field->sideSize;
    return x == sz - 1 && y == sz - 1 && field->cardsCnt == (sz - 2) * (sz - 2) + 1;
}

void FinishCard::play(int x, int y, Field* field, CardStorage* userHand, CardStorage* deck, CardStorage* discard) {
    field->ceils[x][y]->addCard(this);
    userHand->deleteCard(this);
}


bool IslandCard::canBePlayed(int x, int y, Field* field, CardStorage* userHand) {
    for (auto card : userHand->cards) {
        if (card->cardName == "StartCard") {
            return false;
        }
    }
    Ceil* ceil = field->ceils[x][y];
    if (ceil->isBorder || !ceil->isEmpty || x == 0 && y == 0 || x == y && x == field->sideSize - 1) {
        return false;
    }
    while (ceil->next) {
        ceil = ceil->next;
        if (!ceil->isEmpty) {
            if (number < reinterpret_cast<IslandCard*>(ceil->card)->number) {
                break;
            } else {
                return false;
            }
        }
    }
    ceil = field->ceils[x][y];
    while (ceil->previous) {
        ceil = ceil->previous;
        if (!ceil->isEmpty) {
            if (reinterpret_cast<IslandCard*>(ceil->card)->number < number) {
                break;
            } else {
                return false;
            }
        }
    }
    ceil = field->ceils[x][y];
    int neededCards = 0;
    if (ceil->next && !ceil->next->isEmpty) {
        neededCards = reinterpret_cast<IslandCard*>(ceil->next->card)->number - number;
    }
    if (ceil->previous && !ceil->previous->isEmpty) {
        int dif = number - reinterpret_cast<IslandCard*>(ceil->previous->card)->number;
        neededCards = neededCards == 0 ? dif : std::min(dif, neededCards);
    }
    return neededCards <= userHand->size() - 1;
}

void IslandCard::play(int x, int y, Field* field, CardStorage* userHand, CardStorage* deck, CardStorage* discard) {
    field->ceils[x][y]->addCard(this);
    userHand->deleteCard(this);
    Ceil* ceil = field->ceils[x][y];
    int neededCards = 0;
    if (ceil->next && !ceil->next->isEmpty) {
        neededCards = reinterpret_cast<IslandCard*>(ceil->next->card)->number - number;
    }
    if (ceil->previous && !ceil->previous->isEmpty) {
        int dif = number - reinterpret_cast<IslandCard*>(ceil->previous->card)->number;
        neededCards = neededCards == 0 ? dif : std::min(dif, neededCards);
    }
    drop(userHand, field, deck, discard, neededCards);
}