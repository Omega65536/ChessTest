#include <chrono>
#include <iostream>
#include <vector>

#include "board.h"
#include "move.h"
#include "moveGenerator.h"
#include "moveList.h"
#include "square.h"
#include "piece.h"

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

	/*for (unsigned int i = 0; i < 64; i++) {
		std::cout << notFileA(i) << std::endl;

	}*/
	

	//for (Move move : moves) {
	//	//std::cout << move.toString() << std::endl;
	//}

	std::cout << "Time in microseconds: " << std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count() << std::endl;

	system("pause");
}