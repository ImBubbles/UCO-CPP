#include <string>
#include "NimGame.h"
#include "../util/UtilNumber.h"
#include "iostream"
#include "../logger/Log.h"

using namespace NimGame;

bool Game::addPlayer(Player* player) {
    if(gameState!=GameState::STARTING) {
        Log::debug("Could not add player, game already started");
        return false;
    }
    players.push_back(player);
    return true;
}

bool Game::takeMarbles(int m) { // returns if is valid
    if(m >= 1 && m <= (getMarbles() / 2)) {
        marbles -= m;
        return true;
    }
    return false;
}

bool Game::start() {
    if(gameState != GameState::STARTING) {
        Log::debug("Could not start, already started");
        return false;
    }
    Log::debug("Starting loop");
    this->loop();
    return true;
}

void Game::rotate() {
    turn = UtilNumber::clampWrap(0, players.size()-1, turn+1);
}

std::string playerTypeString(const PlayerType& playerType) {
    switch (playerType) {
        case PlayerType::PLAYER:
            return "player";
        case PlayerType::COMPUTER:
            return "computer";
        default:
            return "unknown";
    };
};

void Game::loop() {
    while(true) {
        Log::debug("Game loop");
        if(marbles <= 1) {
            Log::debug("Marbles less than or equal to 1");
            gameState = GameState::ENDED;
            Player& loser = *players[turn];
            if(loser.playerType == PlayerType::COMPUTER) { // instead of saying which player, just for this use case bc it's just 1 this is okay
                std::cout << "You have won!" << std::endl;
            } else {
                std::cout << "The computer won!" << std::endl;
            }
            //std::cout << "The " << playerTypeString(loser.playerType) << " has lost!" << std::endl;
        }
        if(gameState == GameState::ENDED) {
            Log::debug("End Game loop");
            break;
        }
        if(gameState == GameState::STARTING) {
            Log::debug("Start Game loop");
            if(players.size() < 2) {
                std::cout << "Game could not start, not enough players. Please try again after adding more" << std::endl;
                continue;
            }
            std::cout << "Game starting" << std::endl;
            marbles = UtilNumber::randInt(10, 100); // init marbles (10 - 100)
            Log::debug("Marbles: " + std::to_string(marbles));
            turn = UtilNumber::randInt(0, players.size()-1); // start from a random player
            std::cout << "Starting with player " << turn+1 << std::endl;
            gameState = GameState::PLAYING;
        }
        if(gameState == GameState::PLAYING) {
            Log::debug("Playing Game loop");
            std::cout << "There are " << marbles << " marbles" << std::endl;
            std::cout << "It is player " << turn+1 << "'s turn" << std::endl;
            Player& player = *players[turn];
            int take = player.onTurn(*this);
            takeMarbles(take);
            Log::debug("New max take is " + std::to_string(maxTake()));
            std::cout << "Player " << turn+1 << " took " << take << " marbles" << std::endl;
            rotate();
        }
    }
}