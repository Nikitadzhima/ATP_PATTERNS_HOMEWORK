#include<cstddef>

#pragma once

class GameSettings {
  private:
    size_t fieldSideLength;
    size_t islandCardsCnt;
    size_t startCardsCnt;
    size_t finishCardsCnt;
    size_t maxCardsInHand;
    size_t cardsDiscardWithStart;

    static GameSettings* gameSettings;

    GameSettings() {
        fieldSideLength = 8;
        islandCardsCnt = 80;
        startCardsCnt = 1;
        finishCardsCnt = 5;
        maxCardsInHand = 5;
        cardsDiscardWithStart = 8;
    }
  public:
    GameSettings(GameSettings& other) = delete;
    void operator=(const GameSettings& other) = delete;

    static GameSettings* getInstance() {
        if (gameSettings == nullptr) {
            gameSettings = new GameSettings();
        }
        return gameSettings;
    }

    size_t getFieldSideLength() {
        return fieldSideLength;
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
