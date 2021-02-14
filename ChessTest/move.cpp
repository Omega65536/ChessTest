#include <iostream>
#include "square.h"
#include "move.h"

Move::Move() {
	origin = 0;
	destination = 0;
}

Move::Move(const Square o, const Square d) {
	origin = o;
	destination = d;
}

std::string Move::toString() {
	return SquareToString(origin) + SquareToString(destination);
}