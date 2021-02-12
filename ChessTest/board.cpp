#include <vector>
#include "move.h"
#include "board.h"
#include "direction.h"

void Board::setup() {
	whitePieces.push_back(Piece(A1, Rook));
}

std::vector<Move> Board::generateMoves() {
	std::vector<Piece> myPieces = whiteToMove ? whitePieces : blackPieces;
	std::vector<Piece> enemyPieces = whiteToMove ? blackPieces : whitePieces;
	int numMyPieces = myPieces.size();

	std::vector<Move> moves;
	for (int i = 0; i < numMyPieces; i++) {
		Piece piece = myPieces.at(i);
		switch (piece.pieceType) {
		case Pawn:
			break;
		case Knight:
			break;
		case Bishop:
			break;
		case Rook:
			slide()
			break;
		case Queen:
			break;
		case King:
			break;
		}
	}

	return moves;
}

inline Move slide(Square origin, Direction direction, std::vector<Move> &moves) {
	Square destination = origin;
	while (!isOnEdge(origin)) {
		destination += direction;
	}
	return Move(origin, destination);
}