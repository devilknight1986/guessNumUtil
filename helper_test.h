#include <gtest/gtest.h>
#include "helper.h" 

TEST(HELPER_TEST, handleInputDuplicatedNumber)
{
    string strTestInput = "1122";
    EXPECT_EQ(false, Helper::isNoDuplicateNumberInString(strTestInput));
    strTestInput = "1234";
    EXPECT_EQ(true, Helper::isNoDuplicateNumberInString(strTestInput));
}

TEST(HELPER_TEST, handleInputNotNumber)
{
    string strTestInput = "1122ab";
    EXPECT_EQ(false, Helper::isEveryPosNumberInString(strTestInput));
    strTestInput = "1234";
    EXPECT_EQ(true, Helper::isEveryPosNumberInString(strTestInput));
}

TEST(HELPER_TEST, handleInputLenNotFour)
{
    string strTestInput = "12";
    string strErrMsg;
    EXPECT_EQ(false, Helper::isInputGuessNumValid(strTestInput, strErrMsg));
    EXPECT_EQ(strErrMsg, Helper::ERROR_NUM_LENGTH);
}

TEST(HELPER_TEST, handleRstLenNotTwo)
{
    string strTestRst = "123";
    string strErrMsg;
    EXPECT_EQ(false, Helper::isInputGuessRstValid(strTestRst, strErrMsg));
    EXPECT_EQ(strErrMsg, Helper::ERROR_RST_LENGTH);
}

TEST(HELPER_TEST, handleRstLenNotProperLogic)
{
    string strTestRst = "14";
    string strErrMsg;
    EXPECT_EQ(false, Helper::isInputGuessRstValid(strTestRst, strErrMsg));
    EXPECT_EQ(strErrMsg, Helper::ERROR_RST_NOT_PROPER_IN_LOGIC);
}
