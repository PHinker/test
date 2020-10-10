#ifndef	FILESTREAM_H
#define FILESTREAM_H

#include <fstream>		//ifstream, ofstream

class FileStream{
private:
	char flag;
	std::ifstream fin;
	std::ofstream fout;
public:
	FileStream();
	~FileStream();
	//checks if commandline args are vailid returns 1 if vaild, 0 if not
	int checkCommandArgs(int, char **);
	//returns commandline flag
	char getFlag();
	//returns input file
	std::ifstream* getInFile();
	//returns output file
	std::ofstream* getOutFile();
	// Extract files from commandline and open assumes
	void openFiles(int, char **);
	// Open the input file
	void openInFile(std::string inputFileName);
	// Open the output file
	void openOutFile(std::string outputFileName);
};

#endif

