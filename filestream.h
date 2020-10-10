#ifndef	FILESTREAM_H
#define FILESTREAM_H

#define SIGNATURE 0xf6483e44

#include <fstream>	//ifstream, ofstream
#include <iostream>	//cout
#include <string>

class FileStream{
private:
	char flag;
	std::ifstream fin;
	std::ofstream fout;
public:
	FileStream();
	~FileStream();
	//checks if commandline args are vailid returns 1 if vaild, 0 if not
	int checkCommandArgs(int, char **);
	//returns commandline flag
	char getFlag();
	//returns input file
	std::ifstream* getInFile();
	//returns output file
	std::ofstream* getOutFile();
	// Extract files from commandline and open assumes
	void openFiles(int, char **);
	// Open the input file
	void openInFile(std::string inputFileName);
	// Open the output file
	void openOutFile(std::string outputFileName);
	//outputs usage to terminal and exits 1
	void usage();
	//outputs string to terminal
	void print(std::string);
	//reads a chuck from the input file and stores in buffer
	int readChunk(char*);
	//store chunk to output file
	int storeChunk(char*);
	//checks file signiture. exit 2 not a huffman compressed file
	int validateSignature();
	//prints message and exits 2
	void invalidFile();
};

#endif

