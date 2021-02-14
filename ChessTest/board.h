#pragma once

#include <vector>
#include "move.h"
#include "piece.h"
#include "bitboard.h"
#include "square.h"

class Board {
public:
	std::vector<Piece> whitePieces;
	std::vector<Piece> blackPieces;
	bool whiteToMove = true;

	Bitboard whitePieceBB = 0;
	Bitboard blackPieceBB = 0;

	void setup();
	void addWhitePiece(Piece piece);
	void addBlackPiece(Piece piece);
};