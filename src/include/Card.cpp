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


void StartCard::play(int x, int y) { // not done yet
    
}

void FinishCard::play(int x, int y) { // not done yet

}

void IslandCard::play(int x, int y) { // not done yet

}

int IslandCard::getNumber() {
    return number;
}
