#include "Soundex.h"
#include <cctype>
#include <unordered_map>

std::string Soundex::generate(const std::string& name) const {
   // Check for empty name using the new method
    std::string result = handleEmptyName(name);
    if (!result.empty()) return result;
    
    // Initialize the Soundex code with the first letter
    std::string soundex(1, toupper(name[0]));
    char prevCode = getCode(soundex[0]);

    // Iterate through the rest of the name
    for (size_t i = 1; i < name.length(); ++i) {
        char code = getCode(name[i]);
        // Append the new code if it is different from the previous code and not '0'
        if (code != '0' && code != prevCode) {
            soundex += code;
            prevCode = code;
        }
        // Stop if the Soundex code length is 4
        if (soundex.length() == 4) break;
    }

 // Apply padding to ensure the Soundex code is exactly 4 characters long
    return applyPadding(soundex);
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
std::string Soundex::handleEmptyName(const std::string& name) const {
    return name.empty() ? "0000" : "";
}

std::string Soundex::applyPadding(const std::string& soundex) const {
    // Return the soundex with padding if needed
    return soundex.length() < 4 ? soundex + std::string(4 - soundex.length(), '0') : soundex;
}
