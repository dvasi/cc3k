#ifndef __FILEPARSER_H__
#define __FILEPARSER_H__
#include <fstream>
#include <vector>

class FileParser{
	
public:
	std::vector<std::vector<char> > parseFloorLayout(std::string fileName);	
	FileParser();
	int charToCellType(char c);
    
};
#endif
