#include <gtest/gtest.h>
#include "Soundex.h"


TEST(SoundexTest, HandlesEmptyString) {
    EXPECT_EQ(generateCode(""), "");
}

TEST(SoundexTest, HandlesSymbols) {
    EXPECT_EQ(generateCode("~bvv"), "");
}

TEST(SoundexTest, HandlesSingleCharater) {
    EXPECT_EQ(generateCode("F"), "F000");
}

TEST(SoundexTest, HandlesSingleLowerCharacter) {
    EXPECT_EQ(generateCode("f"), "F000");
}

TEST(SoundexTest, HandlesFirstTwoLettersSame) {
    EXPECT_EQ(generateCode("BBert"), "B630");
}

TEST(SoundexTest, HandlesFirstLetterAsNumber) {
    EXPECT_EQ(generateCode("6ert"), "6630");
}

TEST(SoundexTest, HandlesTwoVowels) {
    EXPECT_EQ(generateCode("Tymczak"), "T522");
}

TEST(SoundexTest, HandleStringWithVowels) {
    EXPECT_EQ(generateCode("Aeiou"), "A000");
}

TEST(SoundexTest, HandleStringWithOtherConsonants) {
    EXPECT_EQ(generateCode("Chwy"), "C000");
}

TEST(SoundexTest, HandleFirstTwoLetters) {
    EXPECT_EQ(generateCode("Pfister"), "P236");
}

TEST(SoundexTest, HandlesWithSpace) {
    EXPECT_EQ(generateCode("6  ert"), "6630");
}

TEST(SoundexTest, HandleSpecialCharater) {
    EXPECT_EQ(generateCode("B@ert"), "B630");
}

TEST(SoundexTest, HandleOnlyNumbers) {
    EXPECT_EQ(generateCode("6630"), "6000");
}

TEST(SoundexTest, HandleNumberAndString) {
    EXPECT_EQ(generateCode("6630ff"), "6100");
     EXPECT_EQ(generateCode("6630fht"), "6130");
    EXPECT_EQ(generateCode("6630aei"), "6000");
    EXPECT_EQ(generateCode("6630hwy"), "6000");
    EXPECT_EQ(generateCode("6630Aj#$f"), "6210");
    
}
