#include <iostream>
#include <chrono>
#include <vector>

#include "board.h"
#include "piece.h"
#include "move.h"
#include "square.h"
#include "util.h"
#include "moveGenerator.h"
#include "moveList.h"

int main() {
	Board board = Board();
	board.setup();

	auto t1 = std::chrono::high_resolution_clock::now();

	MoveList moveList;
	for (int i = 0; i < 1000'000; i++) {
		moveList.clear();
		moveGenerator::generateMoves(board, moveList);
	}

	auto t2 = std::chrono::high_resolution_clock::now();

	//for (Move move : moves) {
	//	//std::cout << move.toString() << std::endl;
	//}

	std::cout << "Time in microseconds: " << std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count() << std::endl;

	return 0;
}