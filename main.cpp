#include "filestream.h"
#include "huffman.h"

int main(int argc, char **argv){
	FileStream fs;
	//check command args
	if(fs.checkCommandArgs(argc, argv)){
		//open files
		fs.openFiles(argc, argv);
		
		//call either encoder or decoder
		if(fs.getFlag().compare("-e") == 0){
			encode(fs);
		}else{
			//check signature
			if(fs.validateSignature())
				decode(fs);
			else
				fs.print(ERROR_INVALID);
		}
	}else{
		fs.print(ERROR_USAGE);
	}

	fs.closeFiles();
	return 0;
}
