/**
 * Unit Test suite
**/

#include <gtest/gtest.h>
#include "tappity.h"
 
class tappityTest : public ::testing::Test
{
	protected:
		tappityTest(){} 
		virtual ~tappityTest(){} 
		virtual void SetUp(){}
		virtual void TearDown(){}
};


//Happpy Test Constructor
TEST(tappityTest, construct)
{
    // Testt that the constructor is set by comparing the string to Constructor length
    tappity construct("Test");
    std::string testIt = "Test";

    // Test Should Pass Proving the COnstructor is set
    ASSERT_EQ(construct.length_difference(), testIt.length());

}

//Sad Test Constructor and Entry
TEST(tappityTest, constructWrongLength)
{
    // Test that the constructor is of actual lenght four by proving it will fail when not equated properly
    tappity constructWrongLength("Test");
    std::string testIt = "TestWrongLenth";
    ASSERT_FALSE(constructWrongLength.length_difference() == testIt.length());
}

//Happy Test Entry
TEST(tappityTest, entryTestHappy)
{
    // Test the Lenght is the same
    tappity entryTestHappy("Hello111");
    //entryTestHappy.entry("Hello111");
    entryTestHappy.entry("Hello111");
    ASSERT_EQ(entryTestHappy.length_difference(), 0);
}

//Sad Test Entry
TEST(tappityTest, entryTestSad)
{
    // Test length will fail for equality is the arrays are of differnet size
    tappity entryTestSad("This test will fail");
    entryTestSad.entry("This test will Fail");
    ASSERT_FALSE(entryTestSad.accuracy() == 100);
}


//Happy Test Accuracy Blank Matching
TEST(tappityTest, is_blank_matched)
{
    // Test that blanks are counted
    tappity is_blank_matched("     fiveblanks");
    is_blank_matched.entry("     fiveblanks");
    int accScore = is_blank_matched.accuracy();
    int fullMatch = 100;

    ASSERT_TRUE(accScore == fullMatch);
}

//Sad Test Accuracy Blanks Do not Match
TEST(tappityTest, blanks_do_not_match)
{
    // Test that blanks after last word are differrent
    tappity blanks_do_not_match("     five");
    blanks_do_not_match.entry("     five ");
    int accScore = blanks_do_not_match.accuracy();
    int fullMatch = 100;


    ASSERT_FALSE(accScore == fullMatch);
}

//Happy Test Accuracy Count Blanks Only
TEST(tappityTest, countBlanks)
{
    // Test that acuraCY IS  correct for 50 match of blanks
    tappity countBlanks(" ");
    countBlanks.entry("  ");

    int accScore  = countBlanks.accuracy();
    int fullMatch = 50;

    ASSERT_EQ(accScore , fullMatch);
}

//Sad Test Accuracy Count BLanks Only
TEST(tappityTest, countBlanks_noMatch)
{
    // Test that accuracy falls for a 100 percent match as the actual is 50 %
    tappity countBlanks_noMatch(" ");
    countBlanks_noMatch.entry("  ");

    int accScore = countBlanks_noMatch.accuracy();
    int Match = 100;

    ASSERT_FALSE(accScore == Match);
}

//Happy Test Numbers
TEST(tappityTest, matchNumbers)
{
    // Test that numbers are matched
    tappity matchNumbers("123123");
    matchNumbers.entry("123123");

    int accScore = matchNumbers.accuracy();
    int fullMatch = 100;

    ASSERT_EQ(accScore , fullMatch);
}

//Sad Test Numbers
TEST(tappityTest, noMatchNumbers)
{
    // Test that accuracy accounts for end of array mismatch
    tappity noMatchNumbers("1231231");
    noMatchNumbers.entry("12312312");

    int accScore = noMatchNumbers.accuracy();
    int fullMatch = 100;

    ASSERT_FALSE(accScore == fullMatch);
}

//Happy Test Empty is can match
TEST(tappityTest, emptyMatch)
{
    // Test for BAse Case
    tappity emptyMatch("");
    emptyMatch.entry("");

    int accScore = emptyMatch.accuracy();
    int fullMatch = 100;

    ASSERT_EQ(accScore , fullMatch);
}

//Happy Test case sensitivity Match
TEST(tappityTest, caseSizeMatters)
{
    // Test for Case Sensitivity
    tappity caseSizeMatters("CASEsensitivity");
    caseSizeMatters.entry("CASEsensitivity");

    int accScore = caseSizeMatters.accuracy();
    int fullMatch = 100;

    ASSERT_EQ(accScore , fullMatch);
}

//Sad Test case sensitivity Match
TEST(tappityTest, caseSizeSameCheck)
{
    // Test the case sensitivity will fail if mismatched
    tappity caseSizeSameCheck("CASesensitivitY");
    caseSizeSameCheck.entry("CASesensitivity");

    int accScore = caseSizeSameCheck.accuracy();
    int fullMatch = 100;

    ASSERT_FALSE(accScore == fullMatch);
}

//Happy Test length DIfference
TEST(tappityTest, lengthSizeSame)
{
    // Test the length comparison function for exact match
    tappity lengthSizeSame("SameSizeLength");
    lengthSizeSame.entry("SameSizeLength");

    int length = lengthSizeSame.length_difference();

    int zeroDifference = 0;

    ASSERT_EQ(length, zeroDifference);
}

//Sad Test length DIfference
TEST(tappityTest, lengthSizeNotSame)
{
    // Test is length comparison not always returning 0
    tappity lengthSizeNotSame("NotSameLenghth");
    lengthSizeNotSame.entry("NotSameLenghthSee");

    int length = lengthSizeNotSame.length_difference();

    int zeroDifference = 0;
    ASSERT_FALSE(length == zeroDifference);

}