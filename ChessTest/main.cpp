#include <iostream>
#include <chrono>
#include <vector>

#include "board.h"
#include "piece.h"
#include "move.h"
#include "square.h"
#include "util.h"

int main() {
	auto t1 = std::chrono::high_resolution_clock::now();

	Board board = Board();
	board.setup();
	std::vector<Move> moves = board.generateMoves();

	std::cout << bitScanForward(0x000) << std::endl;
	

	auto t2 = std::chrono::high_resolution_clock::now();
	std::cout << "Time in microseconds: " << std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count() << std::endl;

	return 0;
}