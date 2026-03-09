#include <string>
#include "logger/Log.h"
#include "input/InputWrapper.h"

const std::string months[] = {
    "Janurary",
    "February",
    "March",
    "April",
    "May",
    "June",
    "July",
    "August",
    "September",
    "October",
    "November",
    "December"
};

std::string getSuffix(int& date) {
    int last = std::abs(date % 10);
    Log::debug("Last digit of " + std::to_string(date) + " is " + std::to_string(last));
    switch(last) {
        case 1:
            return "st";
        case 2:
            return "nd";
        case 3:
            return "rd";
        default:
            return "th";
    }
}

int main() {
    //Log::LOG_FILTER = -1;
    Log::defaultLogger();

    int y = 2001;
    y = InputWrapper::getInteger("Enter a year:");
    Log::debug("Year selected is " + std::to_string(y));

    int a = y % 19;
    Log::debug("a " + std::to_string(a));
    int b = y / 100;
    Log::debug("b " + std::to_string(b));
    int c = y - (b * 100);
    Log::debug("c " + std::to_string(c));
    int d = b / 4;
    Log::debug("d " + std::to_string(d));
    int e = b - (d * 4);
    Log::debug("e " + std::to_string(e));
    int g = (8 * b + 13) / 25;
    Log::debug("g " + std::to_string(g));
    int h = (19 * a + b - d - g + 15) % 30;
    Log::debug("h " + std::to_string(h));
    int j = c / 4;;
    Log::debug("j " + std::to_string(j));
    int k = c - (j * 4);
    Log::debug("k " + std::to_string(k));
    int m = (a + 11 * h) / 319;
    Log::debug("m " + std::to_string(m));
    int r = (2 * e + 2 * j - k - h + m + 32) % 7;
    Log::debug("r " + std::to_string(r));
    int n = (h - m + r + 90) / 25;
    Log::debug("n " + std::to_string(n));
    int p = (h - m + r + n + 19) % 32;
    Log::debug("p " + std::to_string(p));

    // Easter falls on day p of month n
    std::string month = months[n-1];
    std::string date = std::to_string(p) + getSuffix(p);
    
    Log::info("In " + std::to_string(y) + ", Easter falls on " + month + " " + date);

    return 0;
}