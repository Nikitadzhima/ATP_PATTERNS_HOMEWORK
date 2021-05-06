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


void StartCard::play(int x, int y) {
    
}

void FinishCard::play(int x, int y) {

}

void IslandCard::play(int x, int y) {

}

int IslandCard::getNumber() {
    return number;
}
