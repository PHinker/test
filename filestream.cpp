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
	infile = inputFileName;

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
	outfile = outputFileName;
	//open output file for writing
	fout.open(outputFileName, std::ios::out | std::ios::binary );

	//check if opened
	if(!fout.is_open()){
		std::cout << "Error: unable to open " << outputFileName << std::endl;
		exit(0);
	}else{
		std::cout << "Output file Ok.\n";
		fout.close();
	}
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







