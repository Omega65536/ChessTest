#include <iostream>
#include "square.h"
#include "move.h"

Move::Move(const Square o, const Square d) {
	origin = o;
	destination = d;
}

std::string Move::toString() {
	return SquareToString(origin) + SquareToString(destination);
}