#include "Soundex.h"
#include <cctype>

std::string Soundex::generate(const std::string& name) const {
    if (name.empty()) return "0000";  // 1 decision point

    std::string soundex(1, toupper(name[0]));
    char prevCode = getCode(soundex[0]);

    for (size_t i = 1; i < name.length(); ++i) {  // 1 decision point (loop)
        char code = getCode(name[i]);
        if (code != '0' && code != prevCode) {
            soundex += code;
            if (soundex.length() == 4) break;
            prevCode = code;
        }
    }

    return soundex + "0000";  // Simplified padding logic
}

char Soundex::getCode(char c) const {
    // Create a static map for character to Soundex code mapping
    static const std::unordered_map<char, char> soundexMap = {
        {'B', '1'}, {'F', '1'}, {'P', '1'}, {'V', '1'},
        {'C', '2'}, {'G', '2'}, {'J', '2'}, {'K', '2'},
        {'Q', '2'}, {'S', '2'}, {'X', '2'}, {'Z', '2'},
        {'D', '3'}, {'T', '3'},
        {'L', '4'},
        {'M', '5'}, {'N', '5'},
        {'R', '6'}
    };

    // Convert character to uppercase
    c = toupper(c);
    // Find the character in the map and return the corresponding Soundex code
    auto it = soundexMap.find(c);
    return (it != soundexMap.end()) ? it->second : '0'; // Return '0' if character is not found
}
