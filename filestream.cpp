#include "filestream.h"

	
FileStream::FileStream(){
}

FileStream::~FileStream(){
}

//checks if commandline args are vailid| 1 if vaild| 0 if not
int FileStream::checkCommandArgs(int, char **){
	return 0;
}

//returns commandline flag
char FileStream::getFlag(){
	return 'a';
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
void FileStream::print(char*){
}
