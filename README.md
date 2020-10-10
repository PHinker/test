# huffman_solo
Huffman 

#Usage
	huffman -e
	huffman -d


#files
main.cpp		-start of program
filestream.h	-class that handles input and output to files
	filestream.cpp
huffman.h		-huffman functions
	huffman.cpp


#functions

##main.cpp
	main

##fileStream.h
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

	// Open the input file
	void openInFile(std::string inputFileName);

	// Open the output file
	void openOutFile(std::string outputFileName);


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



http://www.cplusplus.com/reference/bitset/bitset/




#bugs


#todo

