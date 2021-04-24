#include "CardCreator.h"
#include<cstddef>

Card* StartCardCreator::createCard(size_t number) {
    return new StartCard();
}

Card* FinishCardCreator::createCard(size_t number) {
    return new FinishCard();
}

Card* IslandCardCreator::createCard(size_t number) {
    return new IslandCard(number);
}

Card* MonsterCardCreator::createCard(size_t number) {
    return new MonsterCard();
}
