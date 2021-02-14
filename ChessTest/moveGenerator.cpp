#include "move.h"
#include "board.h"
#include "square.h"
#include "moveGenerator.h"
#include "bitboard.h"
#include "moveList.h"

void moveGenerator::slide(MoveList moves, const Square origin, const Direction direction, const Bitboard myPiecesBB, const Bitboard enemyPiecesBB) {
	Square destination = origin;
	int maxSteps = getDistToEdge(origin, direction);

	for (int steps = 0; steps < maxSteps; steps++) {
		destination += direction;

		if (isOne(myPiecesBB, destination)) return;

		moves.addMove(Move(origin, destination));

		if (isOne(enemyPiecesBB, destination)) return;
	}
}

void moveGenerator::generateMoves(const Board& board, MoveList moves) {
	const Piece* myPieces = board.whiteToMove ? board.whitePieces.data() : board.blackPieces.data();
	const Piece* enemyPieces = board.whiteToMove ? board.blackPieces.data() : board.whitePieces.data();
	Bitboard myPiecesBB = board.whiteToMove ? board.whitePieceBB : board.blackPieceBB;
	Bitboard enemyPiecesBB = board.whiteToMove ? board.blackPieceBB : board.whitePieceBB;

	int numMyPieces = board.whiteToMove ? board.whitePieces.size() : board.blackPieces.size();

	for (int i = 0; i < numMyPieces; i++) {
		Piece piece = myPieces[i];
		switch (piece.pieceType) {
		case Pawn:
			break;
		case Knight:

			break;
		case Bishop:
			slide(moves, piece.square, NorthWest, myPiecesBB, enemyPiecesBB);
			slide(moves, piece.square, NorthEast, myPiecesBB, enemyPiecesBB);
			slide(moves, piece.square, SouthEast, myPiecesBB, enemyPiecesBB);
			slide(moves, piece.square, SouthWest, myPiecesBB, enemyPiecesBB);
			break;
		case Rook:
			slide(moves, piece.square, North, myPiecesBB, enemyPiecesBB);
			slide(moves, piece.square, East, myPiecesBB, enemyPiecesBB);
			slide(moves, piece.square, South, myPiecesBB, enemyPiecesBB);
			slide(moves, piece.square, West, myPiecesBB, enemyPiecesBB);
			break;  
		case Queen:
			slide(moves, piece.square, NorthWest, myPiecesBB, enemyPiecesBB);
			slide(moves, piece.square, North, myPiecesBB, enemyPiecesBB);
			slide(moves, piece.square, NorthEast, myPiecesBB, enemyPiecesBB);
			slide(moves, piece.square, East, myPiecesBB, enemyPiecesBB);
			slide(moves, piece.square, SouthEast, myPiecesBB, enemyPiecesBB);
			slide(moves, piece.square, South, myPiecesBB, enemyPiecesBB);
			slide(moves, piece.square, SouthWest, myPiecesBB, enemyPiecesBB);
			slide(moves, piece.square, West, myPiecesBB, enemyPiecesBB);
			break;
		case King:
			break;
		}
	}
}