#include<cstddef>

#pragma once

class Game_settings {
  private:
    size_t field_side_length;
    size_t monster_cards_cnt;
    size_t island_cards_cnt;
    size_t start_cards_cnt;
    size_t finish_cards_cnt;
    size_t max_cards_in_hand;
    size_t cards_discard_with_start;

    static Game_settings* game_settings;

    Game_settings(size_t new_monster_cards_cnt = 0) {
        field_side_length = 8;
        monster_cards_cnt = new_monster_cards_cnt;
        island_cards_cnt = 80;
        start_cards_cnt = 1;
        finish_cards_cnt = 5;
        max_cards_in_hand = 5;
        cards_discard_with_start = 8;
    }
  public:
    Game_settings() = delete;
    Game_settings(Game_settings& other) = delete;
    void operator=(const Game_settings& other) = delete;

    static Game_settings* get_instance(size_t new_monster_cards_cnt = 0) {
        if (game_settings == nullptr) {
            game_settings = new Game_settings(new_monster_cards_cnt);
        }
        return game_settings;
    }

    size_t get_field_side_length() {
        return field_side_length;
    }
    size_t get_monster_cards_cnt() {
        return monster_cards_cnt;
    }
    size_t get_island_cards_cnt() {
        return island_cards_cnt;
    }
    size_t get_start_cards_cnt() {
        return start_cards_cnt;
    }
    size_t get_finish_cards_cnt() {
        return finish_cards_cnt;
    }
    size_t get_max_cards_in_hand() {
        return max_cards_in_hand;
    }
    size_t get_discard_card_with_start() {
        return cards_discard_with_start;
    }
};
