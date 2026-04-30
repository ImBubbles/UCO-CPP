/**
 * @file a7p2.cpp
 * @brief Caeser Cipher
 * @author Hayden Holmes
 * @date April 2026
 * @version 1.0
 * 
 * Using parameter values, perform a Caeser shift
*/
#include <string>
#include <vector>
#include "logger/Log.h"
#include "util/UtilString.h"

std::string unescapeCsvField(const std::string& field) {
    std::string result;
    result.reserve(field.size());

    for (std::size_t i = 0; i < field.size(); ++i) {
        if (field[i] == '"' && i + 1 < field.size() && field[i + 1] == '"') {
            result += '"';
            ++i; // skip second quote
        } else {
            result += field[i];
        }
    }

    return result;
}

std::vector<std::string> rawToRows(const std::string& raw) {
    std::vector<std::string> result;

    std::string current;
    bool inQuotes = false;

    for (std::size_t i = 0; i < raw.size(); ++i) {
        char c = raw[i];

        if (inQuotes) {
            if (c == '"') {
                // escaped quote?
                if (i + 1 < raw.size() && raw[i + 1] == '"') {
                    current += '"';
                    ++i;
                } else {
                    inQuotes = false; // end of quoted field
                }
            } else {
                current += c;
            }
        } else {
            if (c == '"') {
                inQuotes = true;
            } else if (c == ',') {
                result.push_back(unescapeCsvField(current));
                current.clear();
            } else {
                current += c;
            }
        }
    }

    result.push_back(unescapeCsvField(current));
    return result;
}

int numberOfFields(const std::string& row) {
    bool inQuotes = false;
    int count = 1; // at least one field if row is non-empty

    for (std::size_t i = 0; i < row.size(); ++i) {
        char c = row[i];

        if (c == '"') {
            // handle escaped quote ""
            if (inQuotes && i + 1 < row.size() && row[i + 1] == '"') {
                ++i; // skip escaped quote
            } else {
                inQuotes = !inQuotes;
            }
        } else if (c == ',' && !inQuotes) {
            ++count;
        }
    }

    return row.empty() ? 0 : count;
}

std::string field(const std::string& row, int column) {
    std::string current;
    bool inQuotes = false;
    int currentColumn = 0;

    for (std::size_t i = 0; i < row.size(); ++i) {
        char c = row[i];

        if (inQuotes) {
            if (c == '"') {
                if (i + 1 < row.size() && row[i + 1] == '"') {
                    current += '"';
                    ++i; // skip escape
                } else {
                    inQuotes = false;
                }
            } else {
                current += c;
            }
        } else {
            if (c == '"') {
                inQuotes = true;
            } else if (c == ',') {
                if (currentColumn == column) {
                    return current;
                }
                current.clear();
                ++currentColumn;
            } else {
                current += c;
            }
        }
    }

    return (currentColumn == column) ? current : "";
}

int main(int argc, char* argv[]) {

    //Log::LOG_FILTER = -1; // If commented out, debug messages will not be displayed in console
    Log::defaultLogger();
    Log::debug("Debug messages are enabled");

    std::string test = "1729,San Francisco, \"Hello, World, \"\"Raw, Power\"\"\", \"He asked: \"\"Quo vadis\"\"\"";
    std::string testEasy = "1729, \"test\", wow, this, is cool";
    std::vector<std::string> rows = rawToRows(test);
    std::cout << UtilString::vectorAsString(rows) << std::endl;;
    
    return 0;
    
}