#include "filestream.h"

//print message and exit with status
void FileStream::quit(int status){
	switch(status){
	case 1:		//usage
		usage();
		break;
	case 2:		//invalidFile
		invalidFile();
		break;
	}

	exit(status);
}


//prints message and exits 2
void FileStream::invalidFile(){
	print("\n! ");
	print(infile);
	print(": The file is either in unknown format or damaged\n");
	exit(2);
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
