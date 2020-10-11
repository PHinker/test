# huffman_solo
Huffman encoding
	build frequency table
	build tree from frequency table
	build table from tree
	encode file
Huffman decoding
	extract frequnecy table from file
	build tree from frequency table
	decode file


	file signature:f6 48 3e 44
	store frequency table in encoded file

#Usage
Usage: huffman -e SOURCE DEST
  or:  huffman -d SOURCE DEST
Huffman encode or decode SOURCE to DEST.

Required arguments.
  -e	Encode SOURCE to DEST
  -d	Decode SOURCE to DEST


#files
main.cpp		-start of program
filestream.h	-class that handles input and output to files
	filestream.cpp
	fileStream_print.cpp
huffman.h		-huffman functions
	huffman.cpp


#functions

##main.cpp
	main

##filestream.h
	//checks if commandline args are vailid| 1 if vaild| 0 if not
	int checkCommandArgs(argc, argv);

	//returns commandline flag
	char getFlag();

	//returns input file
	ifstream* getInFile();

	//returns output file
	ofstream* getOutFile();

	// Extract files from commandline and open assumes
	void openFiles(argc, argv);

	// Close both fin and fout
	void closeFiles();

	// Open the input file
	void openInFile(std::string inputFileName);

	// Open the output file
	void openOutFile(std::string outputFileName);

	//outputs usage to terminal. exit(1)
	void usage();

	//outputs string to terminal
	void print(char*);

	//reads a chuck from the input file and stores in buffer
	int readChunk(char*);

	//store chunk to output file
	int storeChunk(char*);

	//checks file signiture
	int validateSignature();

	//prints message and exits 2
	void invalidFile();

##huffman.h
	//encodes input file and outputs to compressed file
	void encode(FileStream&);

	//decodes input file and outputs decompressed file
	void decode(FileStream&);

	//builds a huffman code table from input file
	// returns pointer to table
	std::unordered_set<unsigned char, unsigned char>* buildHuffmanTable(FileStream&);

	//builds huffman tree from a frequency table
	std::map<int, std::pair<unsigned char, int>>* buildHuffmanTree(int*);

	//builds a frequency table of how many times a char appears in a file
	// returns pointer to arrary of size 256
	int* frequency(std::ifstream&);

	//compresses frequency table, removes values with frequency of zero
	//returns char array with format:
	//	 size-of-table, char, count, char,count ...
	char* compressTable(int*);

	//decompress frequency table, takes in a compressed table
	//returns a array of size 256
	int* decompressTable(char*);




#bugs


#todo
Write functions
##main.cpp
	main

##fileStream.h
	void openOutFile(std::string outputFileName);
	int FileStream::readChunk(char*)
	int FileStream::storeChunk(char*)
	int FileStream::validateSignature()

##huffman.h
	void encode(FileStream&);
	void decode(FileStream&);
	std::unordered_set<unsigned char, unsigned char>* buildHuffmanTable(FileStream&);
	std::map<int, std::pair<unsigned char, int>>* buildHuffmanTree(int*);
	int* frequency(std::ifstream&);
	char* compressTable(int*)
	int* decompressTable(char*)



