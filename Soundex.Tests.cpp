#include <gtest/gtest.h>
#include "Soundex.h"

class SoundexTest : public ::testing::Test {
protected:
    Soundex soundex;
};

TEST_F(SoundexTest, HandlesEmptyString) {
    EXPECT_EQ(soundex.generateSoundexCode(""), "");
}

TEST_F(SoundexTest, HandlesSingleCharacter) {
    EXPECT_EQ(soundex.generateSoundexCode("A"), "A000");
}

TEST_F(SoundexTest, HandlesLessThanFourCharacters) {
    EXPECT_EQ(soundex.generateSoundexCode("Bounce"), "B520");
}
