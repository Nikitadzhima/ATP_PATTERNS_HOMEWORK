#include "CardStorageCreator.h"

CardStorage* DeckCreator::createCardStorage() {
    return new Deck();
}

CardStorage* UserHandCreator::createCardStorage() {
    return new UserHand();
}

CardStorage* DiscardCreator::createCardStorage() {
    return new Discard();
}
