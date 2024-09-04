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
