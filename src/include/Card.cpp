#include "Card.h"

void Start_card::play(int x, int y) {

}

void Finish_card::play(int x, int y) {

}

void Island_card::play(int x, int y) {

}

void Monster_card::play(int x, int y) {

}

int Island_card::get_number() {
    return number;
}

Island_card::Island_card(int new_number): number(new_number) {}
