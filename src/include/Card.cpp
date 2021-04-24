#include "Card.h"

void StartCard::play(int x, int y) {

}

void FinishCard::play(int x, int y) {

}

void IslandCard::play(int x, int y) {

}

void MonsterCard::play(int x, int y) {

}

int IslandCard::getNumber() {
    return number;
}

IslandCard::IslandCard(int newNumber): number(newNumber) {}
