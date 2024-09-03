#include "Soundex.h"
#include <cctype>
#include <unordered_map>

std::string Soundex::generate(const std::string& name) const {
    if (name.empty()) return "0000";  // Always return a default value for an empty string

    std::string soundex(1, toupper(name[0]));
    char prevCode = getCode(soundex[0]);

    for (size_t i = 1; i < name.length(); ++i) {
        char code = getCode(name[i]);
        if (code != '0' && code != prevCode) {
            soundex += code;
            prevCode = code;
        }
        if (soundex.length() == 4) break;
    }

    return padToFourDigits(soundex);
}

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

std::string Soundex::padToFourDigits(const std::string& code) const {
    return code + std::string(4 - code.length(), '0');
}
