#include "CardStorage.h"

size_t CardStorage::size() {
   return cards.size();
}

void CardStorage::addCard(Card* card) {
    cards.push_back(card);
}

void CardStorage::deleteCard(Card* card) {
   for (size_t i = 0; i < cards.size(); ++i) {
      if (cards[i] == card) {
         for (size_t j = i; j + 1 < cards.size(); ++j) {
            std::swap(cards[j], cards[j + 1]);
         }
         cards.pop_back();
         return;
      }
   }
}