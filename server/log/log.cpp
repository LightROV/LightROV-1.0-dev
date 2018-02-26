//
// Created by itsl on 18-2-26.
//

#include "log.hpp"

#include <iomanip>

using namespace ltrov;

void Log::i(std::string tag, std::string text) {
    using namespace std;
    time_t t = time(nullptr);
    cout << "[" << tag << ": " << put_time(localtime(&t), "%c") << "] ";
    cout << text << endl;
}

void Log::e(std::string tag, std::string text) {
    using namespace std;
    time_t t = time(nullptr);
    cout << "\033[1;31m"; //for red bold font
    cout << "[" << tag << ": " ;
    cout << put_time(localtime(&t), "%c") << "] ";
    cout << "\033[0m"; // for default color
    cout << text << endl;
}