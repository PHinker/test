#include "huffman.h"

//encodes input file and outputs to compressed file
void encode(FileStream &fs){
	//create histogram
	unsigned int* histogram = frequency(fs.fin);
	
	//print histogram
	fs.print("Symbol\tAscii Value\tCount\n------\t-----------\t-----\n");
	for (int symbol = 0 ; symbol < 256 ; symbol++)
		if (histogram[symbol]){
			if (symbol < 32)
				std::cout << "NP\t" << symbol << "\t\t" << histogram[symbol] << std::endl;
			else
				std::cout << (char)symbol << "\t" << symbol << "\t\t" << histogram[symbol] << std::endl;
		}

	//build tree from frequency table
	//build table from tree
	//encode file

	unsigned char* com = nullptr;
	int comSize = compressTable(histogram, com);
	fs.print("compressed\n");
	fs.print("\n--------------\n");
	histogram = decompressTable(com);
	fs.print("decompressed\n");

//print histogram
	fs.print("Symbol\tAscii Value\tCount\n------\t-----------\t-----\n");
	for (int symbol = 0 ; symbol < 256 ; symbol++)
		if (histogram[symbol]){
			if (symbol < 32)
				std::cout << "NP\t" << symbol << "\t\t" << histogram[symbol] << std::endl;
			else
				std::cout << (char)symbol << "\t" << symbol << "\t\t" << histogram[symbol] << std::endl;
		}





	//write table to file
	fs.fout.write((char*)com,comSize);
	fs.closeFiles();
	exit(0);

	delete histogram;
}

//decodes input file and outputs decompressed file
void decode(FileStream&){
	//extract frequnecy table from file
	//build tree from frequency table
	//decode file
}

//builds a huffman code table from input file
// returns pointer to table
std::unordered_set<unsigned char, unsigned char>* buildHuffmanTable(FileStream&){
	return nullptr;
}

//builds huffman tree from a frequency table
std::map<int, std::pair<unsigned char, int>>* buildHuffmanTree(int*){
	return nullptr;
}

//builds a frequency table of how many times a char appears in a file
// returns pointer to arrary of size 256
unsigned int* frequency(std::ifstream &fin){
	unsigned int* table = new unsigned int[256];
	unsigned char buffer[SIZE_OF_BUFFER];
	int i;

	do{
		fin.read((char*) buffer, SIZE_OF_BUFFER);
		for(i = 0; i < fin.gcount(); i++)
			table[int(buffer[i])]++;
	}while(fin.gcount());

	return table;
}


//compresses frequency table, removes values with frequency of zero
//returns char array with format:
//	 size-of-table, char, count, char,count ...
int compressTable(unsigned int *table, unsigned char *&com){
	std::stack<unsigned char> st;
	unsigned char ct;
	unsigned int ci;
	int i;
	unsigned int size;
	int offset;

	//count number of not zero
	for(i =0; i < 256; i++)
		if(table[i])
			st.push(i);
	
	size = st.size();
	std::cout<<"tablesize: "<< size<<std::endl;
	//crete table with new size
	com = new unsigned char[(size*5)+1];

	//save size
	//can save as char because will always be between 0-256
	com[0] = (unsigned char)(size & 0xff);

	for(i = 0; i < size; i++){
		ct = st.top();
		st.pop();
		offset = (i*5)+1;//plus one because of size
		//save charater
		com[offset++] = ct;
		//save int
		ci = table[ct];
		com[offset++] = (unsigned char)(ci & 0xff);
		com[offset++] = (unsigned char)(ci>>8 & 0xff);
		com[offset++] = (unsigned char)(ci>>16 & 0xff);
		com[offset] = (unsigned char)(ci>>24 & 0xff);
		
	}
std::cout<<"#---------compressedTable---------#"<<std::endl;
	for(i = 0; i < (size*5)+1; i++){
		std::cout<<i<<": "<< (int)com[i]<<std::endl;
	}


	return ((size*5)+1);
}

//decompress frequency table, takes in a compressed table
//returns a array of size 256
unsigned int* decompressTable(unsigned char* com){
	unsigned int* table = new unsigned int[256];
	int size = (int)com[0];	//size is store in first byte
	int i, offset;
	unsigned char tc;//temp char
	unsigned int ti;//temp int


	for(i = 0; i < size; i++){
		offset = (i*5)+1;
		//load charater
		tc = com[offset++];
		offset+=3;
		//load int
		ti = com[offset--];
		ti = ti << 8 | com[offset--];
		ti = ti << 8 | com[offset--];
		ti = ti << 8 | com[offset];
		//save int in table
		table[tc] = ti;
	}


	return table;
}









