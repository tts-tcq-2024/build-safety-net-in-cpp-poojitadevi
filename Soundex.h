#ifndef SOUNDEX_H
#define SOUNDEX_H

#include <string>

class Soundex {
public:
    // Generates the Soundex code for a given name
    std::string generate(const std::string& name) const;

private:
    // Returns the Soundex code for a single character
    char getCode(char c) const;

   std::string handleEmptyName(const std::string& name) const; // Method for empty name check
    std::string applyPadding(const std::string& soundex) const; // Method for padding
};

#endif // SOUNDEX_H

