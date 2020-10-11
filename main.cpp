#include "filestream.h"
#include "huffman.h"

int main(int argc, char **argv){
	FileStream fs;
	//check command args
	if(!fs.checkCommandArgs(argc, argv))
		fs.usage();

	//open files
	fs.openFiles(argc, argv);
	
	//check signature
	if(!fs.validateSignature())
		fs.invalidFile(argv[2]);

	//call either encoder or decoder
	if(fs.getFlag() == 'e')
		encode(fs);//encode
	else
		decode(fs);//decode
	return 0;
}
