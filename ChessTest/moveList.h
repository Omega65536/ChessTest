#pragma once

#include "move.h"

struct MoveList {
	Move moves[256];
	int numMoves;

	MoveList() {
		numMoves = 0;
	}

	inline void addMove(const Move& move) {
		moves[numMoves] = move;
		numMoves++;
	}

	inline void clear() {
		numMoves = 0;
	}
};