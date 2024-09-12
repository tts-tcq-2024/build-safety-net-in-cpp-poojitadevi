#include <gtest/gtest.h>
#include "Soundex.h"

// Test cases for handling an empty string input
TEST(SoundexTest, GeneratesCodeForEmptyString) {
    EXPECT_EQ(generateSoundex(""), "");
}

// Test cases for handling single character input
TEST(SoundexTest, GeneratesCodeForSingleCharacter) {
    for (char c = 'A'; c <= 'Z'; ++c) {
        std::string expected = std::string(1, c) + "000";
        EXPECT_EQ(generateSoundex(std::string(1, c)), expected);
    }
}

// Test cases for handling input with vowels and ignorable consonants
TEST(SoundexTest, IgnoresVowelsAndSpecificConsonants) {
    std::vector<std::pair<std::string, std::string>> testCases = {
        {"AEIOU", "A000"}, {"EAIOU", "E000"}, {"IAEOU", "I000"}, 
        {"OAEIU", "O000"}, {"UAEIO", "U000"}, {"HW", "H000"}, 
        {"WH", "W000"}
    };
    for (const auto& testCase : testCases) {
        EXPECT_EQ(generateSoundex(testCase.first), testCase.second);
    }
}

// Test cases for handling adjacent consonants that map to the same digit
TEST(SoundexTest, HandlesAdjacentIdenticalConsonants) {
    std::map<char, std::string> soundexMapping = {
        {'B', "B100"}, {'C', "C200"}, {'D', "D300"}, {'F', "F100"}, 
        {'G', "G200"}, {'J', "J200"}, {'K', "K200"}, {'L', "L400"}, 
        {'M', "M500"}, {'N', "N500"}, {'P', "P100"}, {'Q', "Q200"}, 
        {'R', "R600"}, {'S', "S200"}, {'T', "T300"}, {'V', "V100"}, 
        {'X', "X200"}, {'Y', "Y000"}, {'Z', "Z200"}
    };

    for (const auto& entry : soundexMapping) {
        char consonant = entry.first;
        std::string expected = entry.second;
        EXPECT_EQ(generateSoundex(std::string(2, consonant)), expected);
    }
}

// Test cases for handling long names requiring truncation
TEST(SoundexTest, TruncatesLongNamesCorrectly) {
    EXPECT_EQ(generateSoundex("Albuquerque"), "A421");
    EXPECT_EQ(generateSoundex("Washington"), "W252");
    EXPECT_EQ(generateSoundex("Katherine"), "K365");
    EXPECT_EQ(generateSoundex("Christopher"), "C623");
    EXPECT_EQ(generateSoundex("Benedict"), "B532");
    EXPECT_EQ(generateSoundex("Montgomery"), "M532");
    EXPECT_EQ(generateSoundex("Williamson"), "W452");
    EXPECT_EQ(generateSoundex("Jonathan"), "J535");
    EXPECT_EQ(generateSoundex("Benjamin"), "B525");
    EXPECT_EQ(generateSoundex("Alexander"), "A425");
    EXPECT_EQ(generateSoundex("abcdefghijklmnopqrstuvwxyz"), "A123");
    EXPECT_EQ(generateSoundex("ChriStopheR"), "C623");
    EXPECT_EQ(generateSoundex("12345"), "1000");
    EXPECT_EQ(generateSoundex("!@#$%"), "0000");
}

// Test cases for handling names with hyphens or spaces
TEST(SoundexTest, HandlesHyphenatedAndSpacedNames) {
    EXPECT_EQ(generateSoundex("Jean-Luc Picard"), "J452");
    EXPECT_EQ(generateSoundex("Mary-Jane Watson"), "M625");
    EXPECT_EQ(generateSoundex("Peter Parker"), "P361");
    EXPECT_EQ(generateSoundex("Bruce Wayne"), "B625");
}

// Test cases for handling names with non-alphabetic characters
TEST(SoundexTest, HandlesNamesWithNonAlphabeticCharacters) {
    EXPECT_EQ(generateSoundex("O'Brien"), "O165");
    EXPECT_EQ(generateSoundex("Smith$123"), "S530");
}
