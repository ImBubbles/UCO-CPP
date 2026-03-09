#pragma once
#include <string>
#include "NimGame.h"
#include "../util/Testable.h"
#include "../input/InputWrapper.h"
#include "../util/UtilNumber.h"
#include "../logger/Log.h"

using namespace NimGame;

struct ConsolePlayer : public Player {
    ConsolePlayer() : Player(PlayerType::PLAYER) {}
protected:
    int onTurn(Game& game) override {
        int max = game.getMarbles() / 2;
        return Testable<int>::repeatUntilPass(
            Testable<int>(
                [&game]() {
                    return InputWrapper::getInteger("Player " + std::to_string(game.getTurn()+1) + ", how many marbles would you like to take:");
                },
                [&game](int val) {
                    return val >= 1 && val <= game.maxTake();
                }
            )
        );
    };
};

struct DumbComputerPlayer : public Player {
    DumbComputerPlayer() : Player(PlayerType::COMPUTER) {}
protected:
    int onTurn(Game& game) override {
        return UtilNumber::randInt(1, game.maxTake());
    };
};

struct SmartComputerPlayer : public Player {
    SmartComputerPlayer() : Player(PlayerType::COMPUTER) {}
protected:
    // make pile into a (base 2) minus 1
    // for ex -- 3, 7, 15, 31, 63
    int onTurn(Game& game) override {
        int marbles = game.getMarbles();
        // Check if pile is already 2^n - 1
        if ((marbles & (marbles + 1)) == 0) {  
            // random move
            return UtilNumber::randInt(1, game.maxTake());
        }
        // find largest power of two minus one less than current pile size
        int target = 1;
        while ((target * 2 - 1) < marbles) {
            target *= 2;
        }
        int desiredPile = target - 1;
        int take = marbles - desiredPile;
        if (take < 1 || take > game.maxTake()) { // safety
            return UtilNumber::randInt(1, game.maxTake());
        }
        Log::debug("Trying to get to " + std::to_string(desiredPile));
        return take;
    }
};