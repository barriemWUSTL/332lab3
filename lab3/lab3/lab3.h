#pragma once
#include <vector>
#include <string>
#include <sstream>
#include <iostream>
#include<fstream>

using namespace std;

enum arrayIndicies {
	programName = 0,
	inputFileName = 1,
	numberOfArgs = 2
};

enum status {
	success = 0,
	fileOpenFailure = 1,
	failureWrongNumberOfArgs = 2,
	couldNotExtract = 3,
	couldNotReadLine = 4,
	failedToFindFormedPiece = 5,
	missMatchedBoard = 6

};


