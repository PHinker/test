#include "filestream.h"
#include "huffman.h"

int main(int argc, char **argv){
	FileStream fs;
	//check command args
	if(fs.checkCommandArgs(argc, argv)){
		//open files
		fs.openFiles(argc, argv);
		
		//call either encoder or decoder
		if(fs.getFlag() == 'e'){
			encode(fs);//encode
		}else{
			//check signature
			if(fs.validateSignature()){
				decode(fs);//decode
			}else{
				fs.quit(2);
			}
		}
	}else{
		fs.usage();
	}

	fs.closeFiles();
	return 0;
}
