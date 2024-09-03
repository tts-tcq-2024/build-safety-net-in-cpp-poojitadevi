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
    switch (toupper(c)) {
        case 'B': case 'F': case 'P': case 'V': return '1';
        case 'C': case 'G': case 'J': case 'K': case 'Q': case 'S': case 'X': case 'Z': return '2';
        case 'D': case 'T': return '3';
        case 'L': return '4';
        case 'M': case 'N': return '5';
        case 'R': return '6';
        default: return '0';
    }
}
