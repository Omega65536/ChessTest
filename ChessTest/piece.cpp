#include <iostream>
#include <string>

#include "square.h"
#include "pieceType.h"
#include "piece.h"

Piece::Piece(const int s, const PieceType t) {
		square = s;
		pieceType = t;
}

std::string Piece::toString() {
		return pieceNames[pieceType] + ":" + std::to_string(square);
}