#include <gtest/gtest.h>
#include "guessNumber.h" 

TEST(GUESS_NUMBER_TEST, handleTransformCharToInt)
{
    GuessNumber guessNumber;
    char chNum = '9';
    EXPECT_EQ(9, guessNumber.transformNumCharToInt(chNum));

    chNum = '0';
    EXPECT_EQ(0, guessNumber.transformNumCharToInt(chNum));
    
    chNum = '5';
    EXPECT_EQ(5, guessNumber.transformNumCharToInt(chNum));
}

TEST(GUESS_NUMBER_TEST, handleTransformIntToChar)
{
    GuessNumber guessNumber;
    int iNum = 9;
    EXPECT_EQ('9', guessNumber.transformNumIntToChar(9));

    iNum = 0;
    EXPECT_EQ('0', guessNumber.transformNumIntToChar(0));
}

TEST(GUESS_NUMBER_TEST, handleOutputNumbers)
{
    GuessNumber guessNumber;
    guessNumber.inputGuessNumbers("1234");
    string strExp = "1234";
    EXPECT_EQ(strExp, guessNumber.outputGuessNumber());

}

TEST(GUESS_NUMBER_TEST, handleJudgeWhetherFakeNumberProper)
{
    GuessNumber guessNumber;
    guessNumber.inputGuessNumbers("1234");
    guessNumber.inputGuessResult("22");

    GuessNumber fakeRealNumber;
    fakeRealNumber.inputGuessNumbers("1243");

    EXPECT_EQ(true, guessNumber.isFakeRealNumberHasTheSameRst(fakeRealNumber));

    guessNumber.inputGuessNumbers("2153");
    guessNumber.inputGuessResult("12");
    EXPECT_EQ(true, guessNumber.isFakeRealNumberHasTheSameRst(fakeRealNumber));
}
