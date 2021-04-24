#include "Field.h"

Field* Field::field = nullptr;

Field::Field() {
    side_size = Game_settings::get_instance()->get_field_side_length();
    cards_cnt = 0;
    ceils.resize(side_size);
    for (auto& row : ceils) {
        row.resize(side_size);
    }
    for (size_t i = 0; i < side_size; ++i) {
        for (size_t j = 0; j < side_size; ++j) {
            ceils[i][j] = new Ceil(((!i ^ !j) || (i == side_size - 1) ^ (j == side_size - 1)));
        }
    }
    for (size_t i = 1; i + 1 < side_size; ++i) {
        for (size_t j = 1; j + 1 < side_size; ++j) {
            if (i == side_size - 2 && j == side_size - 2) continue;
            size_t x = (j < side_size - 2 ? i : i + 1);
            size_t y = (j < side_size - 2 ? j + 1 : 1);
            ceils[i][j]->set_next(ceils[x][y]);
            ceils[x][y]->set_previous(ceils[i][j]);
        }
    }
}


Ceil::Ceil(bool is_a_border): is_border(is_a_border), is_empty(true), 
            card(nullptr), next(nullptr), previous(nullptr) {}

void Ceil::set_next(Ceil* nxt) {
    next = nxt;
}

void Ceil::set_previous(Ceil* prev) {
    previous = prev;
}

void Ceil::add_card(Card* card) {
    
}

void Ceil::delete_card() {
    
}
