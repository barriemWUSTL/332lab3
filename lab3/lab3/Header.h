#pragma once
#include <sstream>
#include <string>
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int usageMessage(string programName, string info);

enum status {
	success = 0,
	fileOpenFailure = 1,
	failureWrongNumberOfArgs = 2,
	couldNotExtract = 3,
	couldNotReadLine = 4,
	failedToFindFormedPiece = 5,
	missMatchedBoard = 6,
	gameOver = 7,
	invalidCoordinates = 8
};

enum arrayIndicies {
	programName = 0,
	gameMode = 1,
	numberOfArgs = 2
};


