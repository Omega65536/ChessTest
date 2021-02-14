#pragma once

#include "square.h"
#include <iostream>

struct Move {
	Square origin;
	Square destination;

	Move(const Square o, const Square d);
	std::string toString();
};