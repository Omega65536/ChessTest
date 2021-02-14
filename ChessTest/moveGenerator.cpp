#include <vector>
#include "move.h"
#include "board.h"
#include "square.h"
#include "moveGenerator.h"
#include "bitboard.h"

void moveGenerator::slide(std::vector<Move>& moves, const Square origin, const Direction direction, const Bitboard myPiecesBB, const Bitboard enemyPiecesBB) {
	Square destination = origin;
	int maxSteps = getDistToEdge(origin, direction);

	for (int steps = 0; steps < maxSteps; steps++) {
		destination += direction;

		if (isOne(myPiecesBB, destination)) return;

		moves.push_back(Move(origin, destination));

		if (isOne(enemyPiecesBB, destination)) return;
	}
}

void moveGenerator::generateMoves(const Board& board, std::vector<Move>& moves) {
	std::vector<Piece> myPieces = board.whiteToMove ? board.whitePieces : board.blackPieces;
	std::vector<Piece> enemyPieces = board.whiteToMove ? board.blackPieces : board.whitePieces;
	Bitboard myPiecesBB = board.whiteToMove ? board.whitePieceBB : board.blackPieceBB;
	Bitboard enemyPiecesBB = board.whiteToMove ? board.blackPieceBB : board.whitePieceBB;

	int numMyPieces = myPieces.size();

	for (int i = 0; i < numMyPieces; i++) {
		Piece piece = myPieces.at(i);
		switch (piece.pieceType) {
		case Pawn:
			break;
		case Knight:
			break;
		case Bishop:
			slide(moves, piece.square, NORTHWEST, myPiecesBB, enemyPiecesBB);
			slide(moves, piece.square, NORTHEAST, myPiecesBB, enemyPiecesBB);
			slide(moves, piece.square, SOUTHEAST, myPiecesBB, enemyPiecesBB);
			slide(moves, piece.square, SOUTHWEST, myPiecesBB, enemyPiecesBB);
			break;
		case Rook:
			slide(moves, piece.square, NORTH, myPiecesBB, enemyPiecesBB);
			slide(moves, piece.square, EAST, myPiecesBB, enemyPiecesBB);
			slide(moves, piece.square, SOUTH, myPiecesBB, enemyPiecesBB);
			slide(moves, piece.square, WEST, myPiecesBB, enemyPiecesBB);
			break;  
		case Queen:
			slide(moves, piece.square, NORTHWEST, myPiecesBB, enemyPiecesBB);
			slide(moves, piece.square, NORTH, myPiecesBB, enemyPiecesBB);
			slide(moves, piece.square, NORTHEAST, myPiecesBB, enemyPiecesBB);
			slide(moves, piece.square, EAST, myPiecesBB, enemyPiecesBB);
			slide(moves, piece.square, SOUTHEAST, myPiecesBB, enemyPiecesBB);
			slide(moves, piece.square, SOUTH, myPiecesBB, enemyPiecesBB);
			slide(moves, piece.square, SOUTHWEST, myPiecesBB, enemyPiecesBB);
			slide(moves, piece.square, WEST, myPiecesBB, enemyPiecesBB);
			break;
		case King:
			break;
		}
	}
}