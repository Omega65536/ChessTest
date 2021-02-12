#include <iostream>
#include <fstream>
#include <sstream>
#include <chrono>
#include <vector>

using namespace std;

typedef unsigned int Square;

enum PieceType {
	Pawn, Knight, Bishop, Rook, Queen, King
};
const string PieceNames[] = {
	"Pawn", "Knight", "Bishop", "Rook", "Queen", "King"
};

struct Piece {
	Square square;
	PieceType pieceType;

	Piece(const int s, const PieceType t) {
		square = s;
		pieceType = t;
	}

	string toString() {
		return PieceNames[pieceType] + ":" + to_string(square);
	}
};

struct Move {
	Square origin;
	Square destination;
};

struct Board {
	vector<Piece> whitePieces;
	vector<Piece> blackPieces;
	bool whiteToMove = true;

	void setup() {
		whitePieces.push_back(Piece(0, Rook));
	}

	vector<Move> generateMoves() {
		Piece* myPieces = whiteToMove ? whitePieces.data() : blackPieces.data();
		Piece* enemyPieces = whiteToMove ? blackPieces.data() : whitePieces.data();
		int numMyPieces = whiteToMove ? whitePieces.size() : blackPieces.size();

		vector<Move> moves;
		for (int i = 0; i < numMyPieces; i++) {
			cout << myPieces[i].toString() << endl;
		}
		return moves;
	}
};

int main() {
	auto t1 = std::chrono::high_resolution_clock::now();

	Board board = Board();
	board.setup();
	vector<Move> moves = board.generateMoves();

	cout << board.whitePieces.capacity() << endl;

	auto t2 = std::chrono::high_resolution_clock::now();
	cout << std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count() << endl;

	return 0;
}