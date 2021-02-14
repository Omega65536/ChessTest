#pragma once

#include "square.h"
#include <iostream>

// Move is in the format:
//   Orgin   Destination
// --YYYXXX--YYYXXX

typedef uint16_t Move;

namespace move {
	inline Move from(Square origin, Square destination) {
		return (origin << 8) | destination;
	}

	inline Square getOrigin(Move move) {
		return move >> 8;
	}

	inline Square getDestination(Move move) {
		return move & 63;
	}

	inline std::string toString(Move move) {
		return square::toString(getOrigin(move)) + square::toString(getOrigin(move));
	}
}
