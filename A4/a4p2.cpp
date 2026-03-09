#include "logger/Log.h"
#include "input/InputMenu.h"
#include "nim/NimGame.h"
#include "nim/NimPlayer.h"

using namespace NimGame;

int main() {

    // Init logger
    //Log::LOG_FILTER = -1;
    Log::defaultLogger();
    Log::debug("debug is on");

    // Real player
    Player* player = new ConsolePlayer();
    // Ask if it wants smart or dumb computer
    std::unique_ptr<InputMenu> menu = InputMenu::createInstance("Choose computer type");
    menu->addVoidOption("Dumb Computer").addVoidOption("Smart Computer");
    menu->prompt();
    Player* computerPlayer = nullptr;
    if(menu->getChoice() == 0) {
        computerPlayer = new DumbComputerPlayer();
        Log::debug("Selected dumb computer");
    } else {
        computerPlayer = new SmartComputerPlayer();
        Log::debug("Selected smart computer");
    }

    // Initialize game
    Log::debug("Initializing game");
    Game game;
    Log::debug("Adding players");
    game.addPlayer(player);
    game.addPlayer(computerPlayer);
    Log::debug("Starting game");
    game.start();

    // delete new objects
    delete player;
    delete computerPlayer;

    return 0;
}