#include "huffman.h"

//encodes input file and outputs to compressed file
void encode(FileStream &fs){
	int* histogram = frequency(fs.fin);
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
int* frequency(std::ifstream &fin){
	int* table = new int[256];
	unsigned char buffer[SIZE_OF_BUFFER];
	int i;

	fin.read((char*) buffer, SIZE_OF_BUFFER);
	while(fin.gcount()){
		for(i = 0; i < fin.gcount(); i++)
			table[int(buffer[i])]++;
		fin.read((char*) buffer, SIZE_OF_BUFFER);
	}
	
	std::cout << "Symbol\tAscii Value\tCount\n";
   std::cout << "------\t-----------\t-----\n";
   for (int symbol = 0 ; symbol < 256 ; symbol++)
      if (table[symbol]){
         if (symbol < 32)
            std::cout << "Non-printable\t" << symbol << "\t\t" << table[symbol] << std::endl;
         else
            std::cout << (char)symbol << "\t" << symbol << "\t\t" << table[symbol] << std::endl;
	}
	return table;
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
