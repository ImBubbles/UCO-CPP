#include <vector>
#include <cstring>
#include "Iterator.h"

class Tokenizer {
    std::vector<const char*> dictionary; // unique words
    std::vector<std::size_t> document; // all words
public:
    Tokenizer() {}
    Tokenizer(const Tokenizer&) = delete; // disable copy construction
    Tokenizer& operator=(const Tokenizer&) = delete; // disable copy assignment
    ~Tokenizer() { // free memory @ pointers
        for (const char* ptr : dictionary) {
            delete[] ptr;
        }
    }
    const std::size_t tokenize(const char* word) {
        for (std::size_t i = 0; i < dictionary.size(); ++i) { // search dictionary
            if (std::strcmp(dictionary[i], word) == 0) {
                document.push_back(i); // reuse index/corresponding pointer
                return i;
            }
        }

        // word does not already exist
        std::size_t len = std::strlen(word);
        char* newWord = new char[len + 1];
        std::strcpy(newWord, word);

        dictionary.push_back(newWord);
        document.push_back(dictionary.size() - 1);

        return dictionary.size() - 1;
    }
    const char* getElement(std::size_t i) {
        return dictionary.at(i);
    }
    const std::vector<const char*> normalize() {
        std::vector<const char*> result;
        for(std::size_t i : document) {
            result.push_back(dictionary.at(i));
        }
        return result;
    }
};