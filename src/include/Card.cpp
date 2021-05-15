#include "Card.h"

StartCard::StartCard() {
    cardName = "StartCard";
}

FinishCard::FinishCard() {
    cardName = "FinishCard";
}

IslandCard::IslandCard(int newNumber) {
    number = newNumber;
    cardName = "IslandCard";
}