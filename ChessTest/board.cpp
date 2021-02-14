#include <vector>
#include "move.h"
#include "board.h"

void Board::setup() {
	addWhitePiece(Piece(A1, Rook));
	addWhitePiece(Piece(B1, Knight));
	addWhitePiece(Piece(C1, Bishop));
	addWhitePiece(Piece(D1, Queen));
	addWhitePiece(Piece(E1, King));
	addWhitePiece(Piece(F1, Bishop));
	addWhitePiece(Piece(G1, Knight));
	addWhitePiece(Piece(H1, Rook));
}

void Board::addWhitePiece(Piece piece) {
	whitePieces.push_back(piece);
	whitePieceBB |= 1LL << piece.square;
}

void Board::addBlackPiece(Piece piece) {
	blackPieces.push_back(piece);
	blackPieceBB |= 1LL << piece.square;
}