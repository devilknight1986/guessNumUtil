#include <iostream>
#include <string>
#include <gtest/gtest.h>

#include "helper.h"
#include "helper_test.h"
#include "guessNumber.h"
#include "guessNumber_test.h"
using namespace std;

vector<GuessNumber> g_vecGuessedNumbers;

bool isFakeRealNumberWorks(GuessNumber& fakeRealNumber)
{
    bool bRet = true;
    for (int i = 0; i < g_vecGuessedNumbers.size(); i++)
    {
        if (!g_vecGuessedNumbers[i].isFakeRealNumberHasTheSameRst(fakeRealNumber))
        {
            bRet = false;
            break;
        }
    }

    return bRet;
}

string generateNextNumber()
{
    GuessNumber fakeRealNumber;

    for (int i = 0; i <= 9; i++)
    {
        for (int j = 0; j <= 9; j++)
        {
            if (j == i) continue;
            for (int m = 0; m <= 9; m++)
            {
                if (m == i || m == j) continue;
                for (int n = 0; n <= 9; n++)
                {
                    if (n == i || n == j || n == m) continue;
                    fakeRealNumber.inputGuessNumbers(i, j, m, n);

                    if (isFakeRealNumberWorks(fakeRealNumber)) return fakeRealNumber.outputGuessNumber();
                }
            }
        }
    }

    return "NORECOMMEND";
}

int main(int argc, char** argv) {
    if (argc > 1) {
        testing::InitGoogleTest(&argc, argv);
        return RUN_ALL_TESTS();
    }

    cout<<"========================================="<<endl;
    cout<<"GuessNum Util is Degined For Hack GuessNum Game"<<endl;
    string strInputNum;
    string strInputRst;
    string strInputNumErrMsg;
    string strInputRstErrMsg;

    while (1) {
        cout<<"Please input your numbers (such as 1234 or 4567) (input exit to exit)"<<endl; 
        cout<<"It is the "<<g_vecGuessedNumbers.size()<<" times your input numbers"<<endl; 
        cin>>strInputNum;
        if (strInputNum == "exit") return 0;
        if (strInputNum == "abort") {
            cout<<"========================================="<<endl;
            continue;
        }

        if (!Helper::isInputGuessNumValid(strInputNum, strInputNumErrMsg)) {
            cout<<strInputNumErrMsg<<endl;
            cout<<"========================================="<<endl;
            continue;
        }

        cout<<"Please input your numbers (such as 12 means 1A2B)"<<endl; 
        cin>>strInputRst;
        if (strInputRst == "exit") return 0;
        if (strInputRst == "abort") { 
            cout<<"========================================="<<endl;
            continue;
        }

        if (!Helper::isInputGuessRstValid(strInputRst, strInputRstErrMsg)) {
            cout<<strInputRstErrMsg<<endl;
            cout<<"========================================="<<endl;
            continue;
        }
        
        GuessNumber guessNumber;
        guessNumber.inputGuessNumbers(strInputNum);
        guessNumber.inputGuessResult(strInputRst);
        g_vecGuessedNumbers.push_back(guessNumber);

        cout<<"Util recommend "<<generateNextNumber()<<endl;
    }
    return 0;
}
