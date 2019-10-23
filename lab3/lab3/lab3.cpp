#include <iostream>
#include "TTO.h"

using namespace std;

int main(int argc, char* argv[]) {
	if (argc == numberOfArgs && strcmp(argv[gameMode], "TicTacToe") == 0)
	{
		TicTacToe tt = TicTacToe();
		return tt.play();
	}

	if (argc != numberOfArgs) {
		return usageMessage(argv[programName], "TicTacToe");
	}
}



int usageMessage(string pName, string otherInfo)
{
	cout << "Type the following into the console to run the program: " + pName + " " + otherInfo << endl;
	return failureWrongNumberOfArgs; //error code 3, means the ammount of command line arguments wasn't 2
}




