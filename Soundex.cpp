#include "Soundex.h"
#include <cctype>
#include <unordered_map>

// Generates the Soundex code for a given name
std::string Soundex::generate(const std::string& name) const {
    if (name.empty()) return "";

    std::string soundex(1, toupper(name[0]));
    char prevCode = getCode(soundex[0]);

    for (size_t i = 1; i < name.length(); ++i) {
        char code = getCode(name[i]);
        if (code == '0' || code == prevCode) continue;
        soundex += code;
        if (soundex.length() == 4) break;
        prevCode = code;
    }

    return padToFourDigits(soundex);
}

// Returns the Soundex code for a single character
char Soundex::getCode(char c) const {
    static const std::unordered_map<char, char> soundexMap = {
        {'B', '1'}, {'F', '1'}, {'P', '1'}, {'V', '1'},
        {'C', '2'}, {'G', '2'}, {'J', '2'}, {'K', '2'},
        {'Q', '2'}, {'S', '2'}, {'X', '2'}, {'Z', '2'},
        {'D', '3'}, {'T', '3'},
        {'L', '4'},
        {'M', '5'}, {'N', '5'},
        {'R', '6'}
    };

    c = toupper(c);
    auto it = soundexMap.find(c);
    return it != soundexMap.end() ? it->second : '0';
}

// Pads the Soundex code to 4 digits with '0'
std::string Soundex::padToFourDigits(const std::string& code) const {
    return code + std::string(4 - code.length(), '0');
}
