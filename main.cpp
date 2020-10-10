#include "filestream.h"
#include "huffman.h"

int main(int argc, char **argv){
	FileStream fs;
	//check command args
	if(!fs.checkCommandArgs(argc, argv)){
		//not valid
		exit(1);
	}

	//open files
	fs.openFiles(argc, argv);

	//call either encoder or decoder
	if(fs.getFlag() == 'e')
		encode(fs);//encode
	else
		decode(fs);//decode
	return 0;
}
