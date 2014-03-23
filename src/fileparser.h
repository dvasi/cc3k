#ifndef __FILEPARSER_H__
#define __FILEPARSER_H__
#include <fstream>
#include <vector>
#include "floor.h"

class FileParser{

	std::string fileName;
	FileParser();
	
public:
	std::vector<std::vector<char> > parseFloorLayout();	
	FileParser(std::string fName);
    
};
#endif
