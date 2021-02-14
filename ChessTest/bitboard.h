#pragma once

#define getBit(bb, i) (bb >> i) & 1LL

typedef uint64_t Bitboard;

const int debruijnIndices[] = {
	0, 47,  1, 56, 48, 27,  2, 60,
   57, 49, 41, 37, 28, 16,  3, 61,
   54, 58, 35, 52, 50, 42, 21, 44,
   38, 32, 29, 23, 17, 11,  4, 62,
   46, 55, 26, 59, 40, 36, 15, 53,
   34, 51, 20, 43, 31, 22, 10, 45,
   25, 39, 14, 33, 19, 30,  9, 24,
   13, 18,  8, 12,  7,  6,  5, 63
};

const Bitboard debruijn64 = 0x03f79d71b4cb0a89;

inline Square getLSB(const Bitboard bb) {
	return debruijnIndices[((bb ^ (bb - 1)) * debruijn64) >> 58];
}