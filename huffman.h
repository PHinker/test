#ifndef HUFFMAN_H
#define HUFFMAN_H

#include <map>			//map
#include <unordered_set>//hash table
#include <fstream>		//ifstream, ofstream
#include "filestream.h"


//encodes input file and outputs to compressed file
void encode(FileStream&);

//decodes input file and outputs decompressed file
void decode(FileStream&);

//builds a huffman code table from input file
// returns pointer to table
std::unordered_set<unsigned char, unsigned char>* buildHuffmanTable(FileStream&);

//builds huffman tree from a frequency table
std::map<int, std::pair<unsigned char, int>>* buildHuffmanTree(int*);

//builds a frequency table of how many times a char appears in a file
// returns pointer to arrary of size 256
int* frequency(std::ifstream&);

//compresses frequency table, removes values with frequency of zero
//returns char array with format:
//	 size-of-table, char, count, char,count ...
char* compressTable(int*);

//decompress frequency table, takes in a compressed table
//returns a array of size 256
int* decompressTable(char*);
#endif
