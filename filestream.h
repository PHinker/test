#ifndef	FILESTREAM_H
#define FILESTREAM_H

#define SIGNATURE 0xf6483e44
#define ERROR_USAGE 1
#define ERROR_INVALID 2

#include <fstream>	//ifstream, ofstream
#include <iostream>	//cout
#include <string>

class FileStream{
private:
	std::string flag;
	std::string infile;
	std::string outfile;
public:
	std::ifstream fin;
	std::ofstream fout;

	FileStream();
	~FileStream();
	//checks if commandline args are vailid returns 1 if vaild, 0 if not
	int checkCommandArgs(int, char **);
	//returns commandline flag
	std::string getFlag();
	// Extract files from commandline and open assumes correct
	int openFiles(int, char **);
	// Close both fin and fout
	void closeFiles();
	//outputs string to terminal
	void print(std::string);
	//checks file signiture. exit 2 not a huffman compressed file
	int validateSignature();

	/*
		filestream_exiting.cpp
	*/
	//outputs usage to terminal and exits 1
	void usage();
	//prints message and exits 2
	void invalidFile();
	//quits program with message
	void quit(int);
	void print(int);
};

#endif

