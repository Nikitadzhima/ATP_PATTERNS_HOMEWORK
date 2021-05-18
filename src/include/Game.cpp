#include "Game.h"

#include <algorithm>
#include <thread>
#include <iostream>


void Game::prepare() {
    // create everything
    deck = new CardStorage();
    userHand = new CardStorage();
    discard = new CardStorage();
    field = new Field();

    std::vector<Card*> cards;
    // adding startCards
    size_t startCardsCnt = GameSettings::getInstance()->getStartCardsCnt();
    StartCardCreator startCreator;
    for (size_t i = 0; i < startCardsCnt; ++i) {
        cards.push_back(startCreator.createCard());
    }

    // adding finishCards
    size_t finishCardsCnt = GameSettings::getInstance()->getFinishCardsCnt();
    FinishCardCreator finishCreator;
    for (size_t i = 0; i < finishCardsCnt; ++i) {
        cards.push_back(finishCreator.createCard());
    }

    // adding islandCards
    size_t islandCardsCnt = GameSettings::getInstance()->getIslandCardsCnt();
    IslandCardCreator islandCreator;
    for (size_t i = 1; i <= islandCardsCnt; ++i) {
        cards.push_back(islandCreator.createCard(i));
    }

    // shuffling cards
    srand(time(nullptr));
    std::random_shuffle(cards.begin(), cards.end());

    // startCard has to be in the first half
    for (size_t i = 0; i < cards.size() / 2; ++i) {
        if (cards[i]->cardName == "StartCard") {
            std::swap(cards[i], cards[i + cards.size() / 2]);
            break;
        }
    }
   
    // putting all cards in the deck
    for (auto card : cards) {
        deck->addCard(card);
    }

    // putting some cards in user's hand
    size_t cardsInHandCnt = GameSettings::getInstance()->getMaxCardsInHand();
    for (size_t i = 0; i < cardsInHandCnt && deck->size() > 0; ++i) {
        Card* newCard = deck->cards.back();
        userHand->addCard(newCard);
        deck->deleteCard(newCard);
    }
}

void Game::start() {
    welcomeUser();
    while (!gameOver) {
        makeTurn();
    }
    showFinalResult();
}

void sleep(int milliseconds = 2500) {
    std::this_thread::sleep_for(std::chrono::milliseconds(milliseconds));
}

void Game::welcomeUser() {
    system("clear");
    PrintTextCommand("Welcome to SEA VOYAGE\n").execute();
    PrintTextCommand("Good luck and have fun!\n").execute();
    sleep();
}

int inputNumberFromTo(int from, int to) {
    InputIntNumberCommand scaner;
    scaner.execute();
    while (scaner.number < from || scaner.number > to) {
        PrintTextCommand("Wrong number. Try again:\n").execute();
        scaner.execute();
    }
    return scaner.number;
}


void Game::showTurnOptions() {
    system("clear");
    FieldPrintDecorator(field).print();
    PrintTextCommand("Cards left in deck: " + std::to_string(deck->size()) + "\n\n").execute();
    PrintTextCommand("Choose one option:\n").execute();
    CardStoragePrintDecorator(userHand).print();
    PrintTextCommand("\n" + std::to_string(userHand->size() + 1) + " - drop two cards\n").execute();
    PrintTextCommand(std::to_string(userHand->size() + 2) + " - exit(lose)\n\n").execute();
    for (auto card : userHand->cards) {
        if (card->cardName == "StartCard") {
            PrintTextCommand("Pay attention! You have a Start card and you have to play it, according to the rules.\n\n").execute();
        }
    }
}


void Game::makeTurn() { // not done yet
    showTurnOptions();
    int option = inputNumberFromTo(1, userHand->size() + 2);
    if (option <= userHand->size()) {
        PrintTextCommand("Row number:\n").execute();
        int row = inputNumberFromTo(0, field->sideSize - 1);
        PrintTextCommand("Column number:\n").execute();
        int col = inputNumberFromTo(0, field->sideSize - 1);
        Card* card = userHand->cards[option - 1];
        if (card->cardName == "StartCard" && reinterpret_cast<StartCard*>(card)->canBePlayed(row, col, field, userHand)) {
            reinterpret_cast<StartCard*>(card)->play(row, col, field, userHand, deck, discard);
        } else if (card->cardName == "FinishCard" && reinterpret_cast<FinishCard*>(card)->canBePlayed(row, col, field, userHand)) {
            reinterpret_cast<FinishCard*>(card)->play(row, col, field, userHand, deck, discard);
        } else if (card->cardName == "IslandCard" && reinterpret_cast<IslandCard*>(card)->canBePlayed(row, col, field, userHand)) {
            reinterpret_cast<IslandCard*>(card)->play(row, col, field, userHand, deck, discard);
        } else {
            PrintTextCommand("You can't play this card here. Try something else\n").execute();
            sleep();
        }
    } else if (option == userHand->size() + 1) {
        if (userHand->size() >= 2) {
            PrintTextCommand("First card number:\n").execute();
            int firstCardNumber = inputNumberFromTo(1, userHand->size());
            PrintTextCommand("Second card number:\n").execute();
            int secondCardNumber = inputNumberFromTo(1, userHand->size());
            if (firstCardNumber == secondCardNumber) {
                PrintTextCommand("You have to choose different cards. Try something else\n").execute();
                sleep();
            } else {
                Card* firstCard = userHand->cards[firstCardNumber - 1];
                Card* secondCard = userHand->cards[secondCardNumber - 1];
                userHand->deleteCard(firstCard);
                userHand->deleteCard(secondCard);
                discard->addCard(firstCard);
                discard->addCard(secondCard);
            }
        } else {
            PrintTextCommand("You can't drop two cards. Try something else\n").execute();
            sleep();
        }
    } else if (option == userHand->size() + 2) {
        gameOver = true;
    }
    if (field->cardsCnt() == (field->sideSize - 2) * (field->sideSize - 2) + 2) {
        gameOver = true;
    }
    while (deck->size() > 0 && userHand->size() < GameSettings::getInstance()->getMaxCardsInHand()) {
        Card* card = deck->cards.back();
        deck->deleteCard(card);
        userHand->addCard(card);
    }
}

void Game::showFinalResult() {
    system("clear");
    FieldPrintDecorator(field).print();

    if (field->cardsCnt() == (field->sideSize - 2) * (field->sideSize - 2) + 2) { // if user won
        PrintTextCommand("CONGRATULATIONS! YOU DID IT!").execute();
    } else {
        PrintTextCommand("GAME OVER. Maybe next time.").execute();
    }
    PrintTextCommand("\n\nThanks for playing this game.\n[Developed by koreec]\n").execute();
}