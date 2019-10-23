#pragma once
#include "Header.h"
#include "Piece.h"

class TicTacToe {
public: 
	friend ostream& operator << (ostream& out, const TicTacToe& tt);
	TicTacToe();
	bool done();
	bool draw();
	int prompt(unsigned int& r, unsigned int& c);
	int turn();
	int play();
private:
	unsigned int height;
	unsigned int width;
	vector<Piece> pieces;
	int lastRow;
	int lastCol;
	string lastPiece;
	char pieceTurn;
	string xValidMoves;
	string oValidMoves;



};

ostream& operator << (ostream& out, const TicTacToe& tt);







