#ifndef _GUESS_NUMBER_H_
    #define _GUESS_NUMBER_H_
    
    #include <string> 
    #include <vector> 
    using namespace std;

    class GuessNumber
    {
        public:
            void inputGuessNumbers(string strGuessNumber);

            void inputGuessNumbers(int n0, int n1, int n2, int n3);

            bool isFakeRealNumberHasTheSameRst(GuessNumber& guessNumber);

            string outputGuessNumber();

            void inputGuessResult(string strGuessRst);

            int  transformNumCharToInt(char chNumber);

            char transformNumIntToChar(int iNumber);
        private:
            vector<int> vecNumbers;        
            int cnt_of_A;
            int cnt_of_B;
    };

#endif
