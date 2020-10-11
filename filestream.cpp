#include "filestream.h"

	
FileStream::FileStream(){
}

FileStream::~FileStream(){
	closeFiles();
}

//checks if commandline args are vailid| 1 if vaild| 0 if not
int FileStream::checkCommandArgs(int argc, char **argv){
	//valid if one flag and 2 filenames
	if(argc != 4)
		return 0;
	if(argv[1][1] != 'e' && argv[1][1] != 'd')
		return 0;

	//vaild flag save
	flag = argv[1];
	return 1;
}

//returns commandline flag
std::string FileStream::getFlag(){
	return flag;
}

// Extract files from commandline and open assumes correct
// returns 0 both files opened successfully
// returns 1 input opened but output did not
// returns 2 input did not open but output did
// returns 3 input did not open and output did not open
int FileStream::openFiles(int argc, char **argv){
	infile = argv[2];
	fin.open(infile, std::ios::in | std::ios::binary);
	outfile = argv[3];
	fout.open(outfile, std::ios::out | std::ios::binary );

	if(fin.is_open())
		return fout.is_open() ? 0 : 1;
	else
		return fout.is_open() ? 2 : 3;
}

// Close both fin and fout
void FileStream::closeFiles(){
	fin.close();
	fout.close();
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







