#include "huffman.h"

//encodes input file and outputs to compressed file
void encode(FileStream&){
}

//decodes input file and outputs decompressed file
void decode(FileStream&){
}

//builds a huffman code table from input file
// returns pointer to table
std::unordered_set<unsigned char, unsigned char>* buildHuffmanTable(FileStream&){
	return nullptr;
}

//builds huffman tree from a frequency table
std::map<int, std::pair<unsigned char, int>>* buildHuffmanTree(int*){
	return nullptr;
}

//builds a frequency table of how many times a char appears in a file
// returns pointer to arrary of size 256
int* frequency(std::ifstream&){
	int* a = new int[256];
	return a;
}
