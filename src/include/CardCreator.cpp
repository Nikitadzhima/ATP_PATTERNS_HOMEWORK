#include "CardCreator.h"

Card* StartCardCreator::createCard(size_t number) {
    return new StartCard();
}

Card* FinishCardCreator::createCard(size_t number) {
    return new FinishCard();
}

Card* IslandCardCreator::createCard(size_t number) {
    return new IslandCard(number);
}
