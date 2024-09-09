#include <gtest/gtest.h>
#include "Soundex.h"
#include <tuple>

class SoundexParameterizedTest : public ::testing::TestWithParam<std::tuple<std::string, std::string>> {};

TEST_P(SoundexParameterizedTest, GeneratesCorrectSoundexCode) {
    
    std::string name = std::get<0>(GetParam());
    std::string expected = std::get<1>(GetParam());
    
    
    EXPECT_EQ(generateSoundex(name), expected);
}
INSTANTIATE_TEST_SUITE_P(
    SoundexTests,                       
    SoundexParameterizedTest,           
    ::testing::Values(
        std::make_tuple("Robert", "R163"),
        std::make_tuple("Rupert", "R163"),
        std::make_tuple("Rubin", "R150"),
        std::make_tuple("Aeiouhw", "A000"),
        std::make_tuple("Ashcroft", "A261"),
        std::make_tuple("Pfister", "P236"),
        std::make_tuple("Honeyman", "H555")
    )
);

TEST(SoundexTest, ReturnsEmptyForEmptyString) {
    EXPECT_EQ(generateSoundex(""), "");
}

TEST_P(SoundexParameterizedTest, PadsShortNamesWithZeros) {
    std::string name = std::get<0>(GetParam());
    std::string expected = std::get<1>(GetParam());

    EXPECT_EQ(generateSoundex(name), expected);
}
INSTANTIATE_TEST_SUITE_P(
    ShortNamesTest,                     
    SoundexParameterizedTest,           
    ::testing::Values(
        std::make_tuple("Ra", "R000"),
        std::make_tuple("R", "R000")
    )
);

TEST_P(SoundexParameterizedTest, CaseInsensitive) {
    std::string name1 = std::get<0>(GetParam());
    std::string name2 = std::get<1>(GetParam());

    EXPECT_EQ(generateSoundex(name1), generateSoundex(name2));
}
INSTANTIATE_TEST_SUITE_P(
    CaseInsensitiveTest,                
    SoundexParameterizedTest,           
    ::testing::Values(
        std::make_tuple("Rupert", "RUPERT"),
        std::make_tuple("Rubin", "RUBIN")
    )
);
