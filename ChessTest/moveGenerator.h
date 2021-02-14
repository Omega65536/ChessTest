#pragma once

#include <vector>
#include "move.h"
#include "board.h"
#include "square.h"
#include "bitboard.h"

namespace moveGenerator {
	void slide(std::vector<Move>& moves, const Square origin, const Direction direction, const Bitboard myPiecesBB, const Bitboard enemyPiecesBB);
	void generateMoves(const Board& board, std::vector<Move>& moves);
}