#pragma once

#include "pieceType.h"
#include "square.h"

struct Piece {
	Square square;
	PieceType pieceType;

	Piece(const Square p, const PieceType t);
	std::string toString();
};