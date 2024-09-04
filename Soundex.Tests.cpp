#include <gtest/gtest.h>
#include "Soundex.h"

class SoundexTest : public ::testing::Test {
protected:
    Soundex soundex;
};

TEST_F(SoundexTest, HandlesEmptyString) {
    EXPECT_EQ(soundex.generateCode(""), "");
}

TEST_F(SoundexTest, HandlesSingleCharacter) {
    EXPECT_EQ(soundex.generateCode("A"), "A000");
}

TEST_F(SoundexTest, HandlesLessThreeCharactersCode) {
    EXPECT_EQ(soundex.generateCode("Bounce"), "B520");
}

TEST_F(SoundexTest, HandlesThreeCharacters) {
    EXPECT_EQ(soundex.generateCode("Bat"), "B300");
}

TEST_F(SoundexTest, HandlesAllZeroCodes) {
    EXPECT_EQ(soundex.generateCode("Who"), "W000");
}

TEST_F(SoundexTest, HandlesAllCodeCharacters1) {
    EXPECT_EQ(soundex.generateCode("Smart"), "S563");
}

TEST_F(SoundexTest, HandlesRepititiveCharacters) {
    EXPECT_EQ(soundex.generateCode("Assessment"), "A253");
}

TEST_F(SoundexTest, HandlesAllCodeCharacters2) {
    EXPECT_EQ(soundex.generateCode("Tracking"), "T625");
}

TEST_F(SoundexTest, HandlesAllCodeCharacters3) {
    EXPECT_EQ(soundex.generateCode("Lolipop"), "L100");
}

TEST_F(SoundexTest, HandlesAllCodeCharacters4) {
    EXPECT_EQ(soundex.generateCode("Gorgeous"), "G620");
}
