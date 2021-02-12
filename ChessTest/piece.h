#pragma once

#include "pieceType.h"
#include "square.h"

struct Piece {
	Piece(const int p, const PieceType t);

	Square square;
	PieceType pieceType;
	std::string toString();
};