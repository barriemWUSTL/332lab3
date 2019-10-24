#include <iostream>
#include "TTO.h"

using namespace std;

int main(int argc, char* argv[]) {
	// strcmp compares the gameMode to see if it is TicTacToe
	if (argc == numberOfArgs && strcmp(argv[gameMode], "TicTacToe") == 0)
	{
		TicTacToe tt = TicTacToe();
		return tt.play();
	}

	if (argc != numberOfArgs) {
		return usageMessage(argv[programName], "TicTacToe");
	}
}


int usageMessage(string programName, string info)
{
	cout << "Type the following into the console to run the program: " + programName + " " + info << endl;
	return failureWrongNumberOfArgs;
}




