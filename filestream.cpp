#include "filestream.h"

	
FileStream::FileStream(){
}

FileStream::~FileStream(){
}

//checks if commandline args are vailid| 1 if vaild| 0 if not
int FileStream::checkCommandArgs(int argc, char **argv){
	//valid if one flag and 2 filenames
	if(argc != 4)
		return 0;
	std::string s = argv[1];
	if(!s.compare("-e") || !s.compare("-d"))
		return 0;

	//vaild flag save
	flag = argv[1][2];
	return 1;
}

//returns commandline flag
char FileStream::getFlag(){
	return flag;
}

//returns input file
std::ifstream* FileStream::getInFile(){
	return nullptr;
}

//returns output file
std::ofstream* FileStream::getOutFile(){
	return nullptr;
}

// Extract files from commandline and open assumes
void FileStream::openFiles(int, char **){
}

// Open the input file
void FileStream::openInFile(std::string inputFileName){
}

// Open the output file
void FileStream::openOutFile(std::string outputFileName){
}

//outputs usage to terminal and exits 1
void FileStream::usage(){
}

//outputs string to terminal
void FileStream::print(std::string){
}

//reads a chuck from the input file and stores in buffer
int FileStream::readChunk(char*){
	return 0;
}

//store chunk to output file
int FileStream::storeChunk(char*){
	return 0;
}

//checks file signiture
int FileStream::validateSignature(){
	return 0;
}

//prints message and exits 2
void FileStream::invalidFile(){
	exit(2);
}
