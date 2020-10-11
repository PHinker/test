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
	if(argv[1][1] != 'e' && argv[1][1] != 'd')
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
	return &fin;
}

//returns output file
std::ofstream* FileStream::getOutFile(){
	return &fout;
}

// Extract files from commandline and open assumes correct
void FileStream::openFiles(int argc, char **argv){
	openInFile(argv[2]);
	openOutFile(argv[3]);
}

// Close both fin and fout
void FileStream::closeFiles(){
	fin.close();
	fout.close();
}

// Open the input file
void FileStream::openInFile(std::string inputFileName){

	fin.open(inputFileName, std::ios::in | std::ios::binary);

	// Check if file opened.
	if(!fin.is_open()){
		std::cout << "Error: unable to open " << inputFileName << std::endl;
		exit(0);
	}else{
		std::cout << "Input file Ok.\n";
		fin.close();
	}
}

// Open the output file
void FileStream::openOutFile(std::string outputFileName){
}

//outputs usage to terminal and exits 1
void FileStream::usage(){
	print("\nUsage: huffman -e SOURCE DEST");
	print("\n  or:  huffman -d SOURCE DEST");
	print("\nHuffman encode or decode SOURCE to DEST.\n");
	print("\nRequired arguments.");
	print("\n  -e\tEncode SOURCE to DEST");
	print("\n  -d\tDecode SOURCE to DEST\n");
}

//outputs string to terminal
void FileStream::print(std::string message){
	std::cout << message;
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
void FileStream::invalidFile(std::string file){
	print("\n! ");
	print(file);
	print(": The file is either in unknown format or damaged\n");
	exit(2);
}
