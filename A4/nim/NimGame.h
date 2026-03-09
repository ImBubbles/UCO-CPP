#pragma once
#include <vector>

namespace NimGame {
    class Game; // This is here so Player can use it as a ref for onTurn method
    enum PlayerType {
        PLAYER,
        COMPUTER
    };
    struct Player {
        const PlayerType playerType;
        Player(const PlayerType playerType) : playerType(playerType) {}
        // Virtual methods
        virtual int onTurn(Game& game) = 0;
        virtual ~Player() = default;
    };
    enum GameState {
        STARTING,
        PLAYING,
        ENDED
    };
    class Game {
        private: // game vars
            int turn;
            int marbles;
            GameState gameState = GameState::STARTING;
            std::vector<Player*> players;
        public: // static
            Game(std::vector<Player*> players) : gameState(GameState::STARTING), players(players) {};
            Game() {};
            static Game& ComputerGame();
        public: // public methods
            bool addPlayer(Player* player); // Returns false if player cannot be added (game already started or ended)
            bool start(); // Returns false if game cannot start (game already started or ended)
            int getMarbles() {
                return marbles;
            }
            int getTurn() {
                return turn;
            }
            bool takeMarbles(int m); // returns if it works or not
            GameState getGameState() {
                return gameState;
            }
            int maxTake() {
                return getMarbles() / 2;
            }
        private: // private methods
            void loop();
            void rotate();
    };
}