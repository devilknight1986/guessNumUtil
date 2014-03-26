#ifndef _HELPER_H_
    #define _HELPER_H_
    
#include<string>
using namespace std;

class Helper {
    public:
    static bool isEveryPosNumberInString(string& strGuessNum);

    static bool isNoDuplicateNumberInString(string& strGuessNum);

    static bool isInputGuessNumValid(string& strGuessNum, string& strError);

    static bool isInputGuessRstValid(string& strGuessRst, string& strError);

    static bool isInputGuessRstProperILogic(string& strGuessRst);

    public:
    static const string ERROR_NUM_LENGTH;
    static const string ERROR_RST_LENGTH;
    static const string ERROR_NUM_NOTNUM;
    static const string ERROR_RST_NOTNUM;
    static const string ERROR_NUM_DUPLICATED;
    static const string ERROR_RST_NOT_PROPER_IN_LOGIC;
};

#endif
