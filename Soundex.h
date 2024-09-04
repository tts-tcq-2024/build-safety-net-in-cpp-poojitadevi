#ifndef SOUNDEX_H
#define SOUNDEX_H

#include <string>

class Soundex {
public:
    // Generates the Soundex code for a given name    
  std::string generateSoundexCode(const std::string& name) const; // Method for empty name check

private:
    // Returns the Soundex code for a single character
    char getCode(char c) const;
    std::string generateCode(const std::string& name) const; // Method to generate code
    std::string applyPadding(const std::string& soundex) const; // Method for padding
    std::string initializeSoundex(const std::string& soundex) const;
    std::string processRemainingCharacters(const std::string& name, std::string& soundex, char& prevCode) const;
    std::string appendCodeIfValid(char code, char& prevCode, std::string& soundex) const;
};

#endif // SOUNDEX_H

