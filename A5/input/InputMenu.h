#pragma once
#include <memory>
#include <vector>
#include <string>
#include <functional>

struct InputOption{
    const std::string description;
    std::function<void()> action;
    InputOption(const std::string& description, std::function<void()> action) : description(description), action(action) {}
};

class InputMenu {
    protected:
        std::vector<InputOption> options;
    private:
        const std::string title;
        int choice = -1; // Left as -1 until choice is made
    public: // MEMBER
        InputMenu(const std::string& title) : title(title) {}

        // Just general adding options functions, all other addOption funcs call InputMenu#addOption(InputOption&)
        InputMenu& addOption(InputOption& option);
        InputMenu& addOption(const std::string& title, std::function<void()> action);

        // If just using InputMenu#getChoice(), probably just keep with addVoidOption
        InputMenu& addVoidOption(const std::string& title);

        // Ideal for when some options are simple and need the number returned, otherwise
        InputMenu& addNumberedOption(const std::string& title, int& ref, int value);
        InputMenu& addNumberedOption(const std::string& title, int& ref);

        // Return the InputMenu as an option (autoexecute InputMenu#prompt if it's chosen as an option)
        std::unique_ptr<InputOption> asOption();

        void prompt();
        int getChoice();
    public: // STATIC
        static std::unique_ptr<InputMenu> createInstance(const std::string& title);
};