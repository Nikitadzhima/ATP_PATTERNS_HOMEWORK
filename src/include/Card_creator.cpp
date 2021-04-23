#include "Card_creator.h"
#include<cstddef>

Card* Start_card_creator::create_card(size_t number) {
    return new Start_card();
}

Card* Finish_card_creator::create_card(size_t number) {
    return new Finish_card();
}

Card* Island_card_creator::create_card(size_t number) {
    return new Island_card(number);
}

Card* Monster_card_creator::create_card(size_t number) {
    return new Monster_card();
}
