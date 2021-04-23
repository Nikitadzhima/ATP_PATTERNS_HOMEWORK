#include "Card_storage_creator.h"

Card_storage* Deck_creator::create_card_storage() {
    return new Deck();
}

Card_storage* User_hand_creator::create_card_storage() {
    return new User_hand();
}

Card_storage* Discard_creator::create_card_storage() {
    return new Discard();
}
