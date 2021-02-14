#include <iostream>
#include <string>

#include "square.h"
#include "pieceType.h"
#include "piece.h"

Piece::Piece(const Square s, const PieceType t) {
		square = s;
		pieceType = t;
}

std::string Piece::toString() {
		return pieceNames[pieceType] + ":" + square::toString(square);
}