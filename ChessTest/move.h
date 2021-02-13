#pragma once

#include "square.h"

struct Move {
	Square origin;
	Square destination;

	Move(Square o, Square d);
};