#ifndef SOUNDEX_H
#define SOUNDEX_H

#include <string>

class Soundex {
public:
    // Generates the Soundex code for a given name    
  std::string generateCode(const std::string& name) const; // Method to generate code

private:
    // Returns the Soundex code for a single character
    char getCode(char c) const;
    std::string applyPadding(const std::string& soundex) const; // Method for padding
    std::string initializeSoundex(const std::string& soundex) const;
    void processRemainingCharacters(const std::string& name, std::string& soundex, char& prevCode) const;
    void appendCodeIfValid(char code, char& prevCode, std::string& soundex) const;
};

#endif // SOUNDEX_H

