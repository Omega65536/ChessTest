#pragma once

#include <vector>
#include "move.h"
#include "piece.h"
#include "bitboard.h"

struct Board {
	std::vector<Piece> whitePieces;
	std::vector<Piece> blackPieces;
	bool whiteToMove = true;

	Bitboard whitePieceBB = 0;
	Bitboard blackPieceBB = 0;

	void setup();
	std::vector<Move> generateMoves();
};