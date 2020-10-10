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

//checks file signiture. exit 2
void validateSignature(FileStream&){
}

//compresses frequency table, removes values with frequency of zero
//returns char array with format:
//	 size-of-table, char, count, char,count ...
char* compressTable(int*){
	char* a = new char[26];
	return a;
}

//decompress frequency table, takes in a compressed table
//returns a array of size 256
int* decompressTable(char*){
	int* a = new int[256];
	return a;
}
