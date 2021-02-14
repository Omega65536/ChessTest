#pragma once

#include "move.h"
#include "board.h"
#include "square.h"
#include "bitboard.h"
#include "moveList.h"

namespace moveGenerator {
	void slide(MoveList& moves, const Square origin, const Direction direction, const Bitboard myPiecesBB, const Bitboard enemyPiecesBB);
	void generateMoves(const Board& board, MoveList& moves);
}