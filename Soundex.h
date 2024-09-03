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

    // Pads the Soundex code to 4 digits with '0'
    std::string padToFourDigits(const std::string& code) const;
};

#endif // SOUNDEX_H

