#pragma once

#include <algorithm>
#include <iostream>

#define getX(square) (square & 7)
#define getY(square) (square >> 3)

#define notFileA(square) (square & 7)
#define notFileH(square) ((square & 7) != 7)
#define notRank1(square) (square >> 3)
#define notRank8(square) ((square >> 3) != 7)

typedef uint8_t Square;
typedef uint8_t Direction;

const enum Squares {
	A1, B1, C1, D1, E1, F1, G1, H1,
	A2, B2, C2, D2, E2, F2, G2, H2,
	A3, B3, C3, D3, E3, F3, G3, H3,
	A4, B4, C4, D4, E4, F4, G4, H4,
	A5, B5, C5, D5, E5, F5, G5, H5,
	A6, B6, C6, D6, E6, F6, G6, H6,
	A7, B7, C7, D7, E7, F7, G7, H7,
	A8, B8, C8, D8, E8, F8, G8, H8
};


const Direction NorthWest = 7;
const Direction North = 8;
const Direction NorthEast = 9;
const Direction East = 1;
const Direction SouthEast = -7;
const Direction South = -8;
const Direction SouthWest = -9;
const Direction West = -1;
const Direction KnightNorthWest = 15;

namespace square {
	const std::string fileStrings[]{
		"A", "B", "C", "D", "E", "F", "G", "H"
	};

	const std::string rankStrings[]{
		"1", "2", "3", "4", "5", "6", "7", "8"
	};

	inline bool isOnEdge(const Square square) {
		return ((square & 7) == 0) || ((square & 7) == 7) ||
			((square >> 3) == 0) || ((square >> 3) == 7);
	}

	inline Square getDistToEdge(const Square square, const Direction direction) {
		switch (direction) {
		case NorthWest:
			return std::min(getX(square), 7 - getY(square));
		case North:
			return 7 - getY(square);
		case NorthEast:
			return std::min(7 - getX(square), 7 - getY(square));
		case East:
			return 7 - getX(square);
		case SouthEast:
			return std::min(7 - getX(square), getY(square));
		case South:
			return getY(square);
		case SouthWest:
			return std::min(getX(square), getY(square));
		case West:
			return getX(square);
		default:
			return 0;
		}
	}

	inline std::string toString(const Square square) {
		return fileStrings[getX(square)] + rankStrings[getY(square)];
	}
}