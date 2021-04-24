#include<cstddef>

#pragma once

class GameSettings {
  private:
    size_t fieldSideLength;
    size_t monsterCardsCnt;
    size_t islandCardsCnt;
    size_t startCardsCnt;
    size_t finishCardsCnt;
    size_t maxCardsInHand;
    size_t cardsDiscardWithStart;

    static GameSettings* gameSettings;

    GameSettings(size_t newMonsterCardsCnt = 0) {
        fieldSideLength = 8;
        monsterCardsCnt = newMonsterCardsCnt;
        islandCardsCnt = 80;
        startCardsCnt = 1;
        finishCardsCnt = 5;
        maxCardsInHand = 5;
        cardsDiscardWithStart = 8;
    }
  public:
    GameSettings() = delete;
    GameSettings(GameSettings& other) = delete;
    void operator=(const GameSettings& other) = delete;

    static GameSettings* getInstance(size_t newMonsterCardsCnt = 0) {
        if (gameSettings == nullptr) {
            gameSettings = new GameSettings(newMonsterCardsCnt);
        }
        return gameSettings;
    }

    size_t getFieldSideLength() {
        return fieldSideLength;
    }
    size_t getMonsterCardsCnt() {
        return monsterCardsCnt;
    }
    size_t getIslandCardsCnt() {
        return islandCardsCnt;
    }
    size_t getStartCardsCnt() {
        return startCardsCnt;
    }
    size_t getFinishCardsCnt() {
        return finishCardsCnt;
    }
    size_t getMaxCardsInHand() {
        return maxCardsInHand;
    }
    size_t getDiscardCardWithStart() {
        return cardsDiscardWithStart;
    }
};
