#pragma once

#include <algorithm>
#include <iostream>

typedef unsigned int Square;
typedef unsigned int Direction;

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

const std::string fileStrings[]{
	"A", "B", "C", "D", "E", "F", "G", "H"
};

const std::string rankStrings[]{
	"1", "2", "3", "4", "5", "6", "7", "8"
};

const Direction NORTHWEST = 7;
const Direction NORTH = 8;
const Direction NORTHEAST = 9;
const Direction EAST = 1;
const Direction SOUTHEAST = -7;
const Direction SOUTH = -8;
const Direction SOUTHWEST = -9;
const Direction WEST = -1;

inline bool isOnEdge(const Square square) {
	return ((square & 7) == 0) || ((square & 7) == 7) ||
		   ((square >> 3) == 0) || ((square >> 3) == 7);
}

inline Square getX(const Square square) {
	return square & 7;
}

inline Square getY(const Square square) {
	return square >> 3;
}

inline Square getDistToEdge(const Square square, const Direction direction) {
	switch (direction) {
	case NORTHWEST:
		return std::min(getX(square), 7 - getY(square));
	case NORTH:
		return 7 - getY(square);
	case NORTHEAST:
		return std::min(7 - getX(square), 7 - getY(square));
	case EAST:
		return 7 - getX(square);
	case SOUTHEAST:
		return std::min(7 - getX(square), getY(square));
	case SOUTH:
		return getY(square);
	case SOUTHWEST:
		return std::min(getX(square), getY(square));
	case WEST:
		return getX(square);
	default:
		return 0;
	}
}

inline std::string SquareToString(const Square square) {
	return fileStrings[getX(square)] + rankStrings[getY(square)];
}