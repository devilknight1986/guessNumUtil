guessNumUtil: main.o helper.o guessNumber.o
	g++ -framework gtest -g -o guessNumUtil main.o helper.o guessNumber.o
main.o:
	g++ -g -c main.cpp
helper.o:
	g++ -g -c helper.cpp
guessNumber.o:
	g++ -g -c guessNumber.cpp
clean:
	rm -rf guessNumUtil *.o
