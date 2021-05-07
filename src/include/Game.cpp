#include "Game.h"

#include <random>
#include <algorithm>
#include <vector>

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
        Card* newCard = deck->getCards().back();
        userHand->addCard(newCard);
        deck->deleteCard(newCard);
    }
    FieldPrintDecorator(field).print();
    CardStoragePrintDecorator(userHand).print();
}

void Game::start() { // not done yet
    //while (true) {
        // printField
        // printUserHand
        // print deck->size()
        // input next turn
        // if it is incorrect - continue
        // do it
        // if the end - break
        // take cards from deck until 5
    //}
    // printField
    // print game results
    // the end
}