#include "TTO.h"

TicTacToe::TicTacToe() : height(5), width(5), pieceTurn('O'), lastRow(0),lastCol(0),xValidMoves("Player X: "),oValidMoves("Player 0:"){
	while (pieces.size() < (size_t)width * (size_t)height) {
		Piece p;
		p.displayName = " ";
		pieces.push_back(p);
	}
};

ostream& operator << (ostream& out, const TicTacToe& tt) {
	for (int row = tt.height - 1; row >= 0; row--) {
		cout << row;
		for (int col = 0; col < (int)tt.height; col++) {
			int index = (tt.width * row) + col;
			cout << tt.pieces[index].displayName + " ";
		}
		cout << endl;
	}
	cout << " ";
	for (int row = 0; row < (int)tt.height; row++) {
		cout << row << " ";
	}
	return out;
};

bool TicTacToe::done() {

	//check row
	for (int row = 3; row > 0; row--) {
		for (int col = 1; col < 4; col++) {
			int index = (width * row) + col;
			if (pieces[index].displayName == lastPiece) {
				if (col == 3) {
					return true;
				}		
			}
			else {
				break;
			}
		}	
	}

	//check col
	for (int col = 1; col < 4; col++) {
		for (int row = 3; col > 0; row--) {
			int index = (width * row) + col;
			if (pieces[index].displayName == lastPiece) {
				if (row == 1) {
					return true;
				}
			}else{
				break;
			}
		}
	}

	// Checks the positions where it would form a diagnol and then checks to see if they are all equal to the lastPiece.
	if (pieces[6].displayName == lastPiece && pieces[12].displayName == lastPiece && pieces[18].displayName == lastPiece) {
		return true;	
	}
	if (pieces[16].displayName == lastPiece && pieces[12].displayName == lastPiece && pieces[8].displayName == lastPiece) {
		return true;
	}
	return false;
}

bool TicTacToe::draw() {
	if (done()) {
		return false;
	}
	for (int row = 3; row > 0; row--) {
		for (int col = 1; col < 4; col++) {
			int index = (width * row) + col;
			if (pieces[index].displayName == " ") {
				return false;
			}
		}
	}
	return true;
}

int TicTacToe::prompt(unsigned int& r, unsigned int& c) {
	cout << "Type coordinates in (x,y) format to place a gamepiece or type quit to end the game " << endl;
	string input = "";
	cin >> input;
	if (input == "quit") {
		return gameOver;
	}
	else {
		string nums = input.replace(1, 1, " ");
		istringstream stream(nums);
		if (stream >> r) {
			if (stream >> c) {
				if (r < 4 && r > 0) {
					if (c < 4 && c > 0) {
						int index = (width * r) + c;
						if (pieces[index].displayName == " ") {
							return success;
						}
					}
				}
			}
		}
		cout << "Invalid coordinates, please reenter" << endl;
		return invalidCoordinates;
	}
}

int TicTacToe::turn() {
	string piece = "";
	piece.push_back(pieceTurn);
	cout << piece + "\'s turn" << endl;

	unsigned int r = 0;
	unsigned int c = 0;
	int game = prompt(r, c);

	if (game == gameOver) {
		return gameOver;
	}

	while (game != success && game != gameOver)
	{
		game = prompt(r, c);
	}

	lastRow = r;
	lastCol = c;
	lastPiece = pieceTurn;
	int index = (width * lastRow) + lastCol;
	pieces[index].displayName = lastPiece;
	cout << *this;
	cout << " " << endl;
	if (pieceTurn == 'X')
	{
		xValidMoves += to_string(r) + ", " + to_string(c) + "; ";
		cout << xValidMoves << endl;
	}
	else
	{
		oValidMoves += to_string(r) + ", " + to_string(c) + "; ";
		cout << oValidMoves << endl;
	}
	return game;
}

int TicTacToe::play() {
	cout << *this;
	cout << endl;
	int numOfTurns = 0;
	while (!draw() && !done()) {
		if (pieceTurn == 'X') {
			pieceTurn = '0';
		
		}
		else {
			pieceTurn = 'X';
		}
		numOfTurns++;
		int res = turn();
		if (res == gameOver) {
			string piece = "";
			piece.push_back(pieceTurn);
			cout << piece + " quit the game in " + to_string(numOfTurns) + " turns!" << endl;
			return res;
		}
	}
	if (done()) {
		string piece = "";
		piece.push_back(pieceTurn);
		cout << piece + " won the game in " + to_string(numOfTurns) + " turns!" << endl;
	}
	if (draw())
	{
		cout << "Draw in " + to_string(numOfTurns) + " turns!" << endl;
	}
	return success;
}