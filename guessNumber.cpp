#include "guessNumber.h"

void GuessNumber::inputGuessNumbers(string strGuessNumber)
{
    vecNumbers.clear();

    for (int i = 0; i < strGuessNumber.length(); i++)
    {
        char chTmp = strGuessNumber.at(i);
        vecNumbers.push_back(transformNumCharToInt(chTmp));
    }
}

void GuessNumber::inputGuessNumbers(int n0, int n1, int n2, int n3)
{
    vecNumbers.clear();

    vecNumbers.push_back(n0);
    vecNumbers.push_back(n1);
    vecNumbers.push_back(n2);
    vecNumbers.push_back(n3);
}

void GuessNumber::inputGuessResult(string strGuessRst)
{
    char chTmpA = strGuessRst.at(0);
    char chTmpB = strGuessRst.at(1);
    cnt_of_A = transformNumCharToInt(chTmpA); 
    cnt_of_B = transformNumCharToInt(chTmpB); 
}

int GuessNumber::transformNumCharToInt(char chNumber)
{
    char chRst = chNumber - 0x30;
    return static_cast<int>(chRst);
}


char GuessNumber::transformNumIntToChar(int iNumber)
{
    int iRst = iNumber + 0x30;
    return static_cast<char>(iRst);
}


bool GuessNumber::isFakeRealNumberHasTheSameRst(GuessNumber& fakeRealNumber)
{
    int cntA = 0;
    int cntB = 0;

    vector<int>& vecFakeRealNums = fakeRealNumber.vecNumbers;

    for (int i = 0; i < 4; i++)
    {
        if (vecNumbers[i] == vecFakeRealNums[i]) cntA++;
        for (int j = 0; j < 4; j++)
        {
            if (vecNumbers[i] == vecFakeRealNums[j] && i != j) cntB++;
        }
    }
    
    return cntA == cnt_of_A && cntB == cnt_of_B;
}

string GuessNumber::outputGuessNumber()
{
    string strRet;
    for (int i = 0; i < vecNumbers.size(); i++)
    {
        strRet += transformNumIntToChar(vecNumbers[i]);
    }

    return strRet;
}
