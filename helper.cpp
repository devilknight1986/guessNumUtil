#include "helper.h"
bool Helper::isEveryPosNumberInString(string& strGuessNum) {
    for (int i = 0; i < strGuessNum.length(); i++) {
       char tmpChar = strGuessNum.at(i); 
       if (tmpChar < '0' ||  tmpChar > '9') return false; 
    }

    return true;
}

bool Helper::isNoDuplicateNumberInString(string& strGuessNum) {
    for (int i = 0; i < strGuessNum.length(); i++) {
        for (int j = 0; j < strGuessNum.length(); j++) {
            if (j > i) {
                if (strGuessNum.at(i) == strGuessNum.at(j)) {
                    return false;
                }
            }
        }
    }

    return true;
}

bool Helper::isInputGuessNumValid(string& strGuessNum, string& strError) {
    if (strGuessNum.length() != 4) {
        strError = ERROR_NUM_LENGTH;
        return false;
    }

    if (!isEveryPosNumberInString(strGuessNum)) {
        strError = ERROR_NUM_NOTNUM;
        return false;
    }

    if (!isNoDuplicateNumberInString(strGuessNum)) {
        strError = ERROR_NUM_DUPLICATED;
        return false;
    }

    return true;
}

bool Helper::isInputGuessRstProperILogic(string& strGuessRst) {
    int num_of_A = static_cast<int>(strGuessRst.at(0) - 0x30);
    int num_of_B = static_cast<int>(strGuessRst.at(1) - 0x30);

    if ((num_of_A + num_of_B) > 4) {
        return false;
    } else {
        return true;
    }
}

bool Helper::isInputGuessRstValid(string& strGuessRst, string& strError) {
    if (strGuessRst.length() != 2) {
        strError = ERROR_RST_LENGTH;
        return false;
    }
    
    if (!isEveryPosNumberInString(strGuessRst)) {
        strError = ERROR_RST_NOTNUM;
        return false;
    }

    if (!isInputGuessRstProperILogic(strGuessRst)) {
        strError = ERROR_RST_NOT_PROPER_IN_LOGIC;
        return false;
    }

    return true;
}

const string Helper::ERROR_NUM_LENGTH =  "Guess Number Game Only Has Four Numbers";
const string Helper::ERROR_RST_LENGTH =  "Guess Number Rst Only Has Two Numbers";
const string Helper::ERROR_RST_NOTNUM = "Guess Number Game Only has Numbers, No Other Character";
const string Helper::ERROR_NUM_NOTNUM = "Guess Number Game Only has Numbers, No Other Character";
const string Helper::ERROR_NUM_DUPLICATED = "Guess Number Game Has No Duplicated Numbers";
const string Helper::ERROR_RST_NOT_PROPER_IN_LOGIC= "Guess Number Rst A and B No more than 4";
