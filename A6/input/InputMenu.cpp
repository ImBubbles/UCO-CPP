#include "InputMenu.h"
#include "InputWrapper.h"
#include <iostream>

InputMenu& InputMenu::addOption(InputOption& option) {
    options.push_back(option);
    return *this;
}
InputMenu& InputMenu::addOption(const std::string& title, std::function<void()> action) {
    options.push_back({title, action});
    return *this;
}
InputMenu& InputMenu::addVoidOption(const std::string& title) {
    options.push_back({
        title,
        []() -> void {}
    });
    return *this;
}
InputMenu& InputMenu::addNumberedOption(const std::string& title, int& ref, int value) {
    options.push_back({
        title,
        [this, &ref, value]() -> void {
            ref = value;
        }
    });
    return *this;
}
InputMenu& InputMenu::addNumberedOption(const std::string& title, int& ref) {
    return this->addNumberedOption(title, ref, options.size()+1);
}
std::unique_ptr<InputMenu> InputMenu::createInstance(const std::string& title) {
    return std::make_unique<InputMenu>(title);
}
std::unique_ptr<InputOption> InputMenu::asOption() {
    return std::make_unique<InputOption>(
        this->title,
        [this]() {this->prompt();}
    );
}
void InputMenu::prompt() {
    std::cout << title << std::endl;
    // Load size onto stack because it's used more than once
    int size = options.size();
    // Display choices
    for(int i = 1; i <= size; i++) {
        InputOption& option = options[i-1];
        std::cout << i << " -> " << option.description << std::endl;;
    }
    // Get answer
    choice = -1;
    while(choice == -1) {
        choice = InputWrapper::getInteger("Option:");
        choice = choice > size ? -1 : choice;
    }
    // Get as option obj
    InputOption& option = options[choice-1];
    option.action();
}
int InputMenu::getChoice() {
    return this->choice;
}