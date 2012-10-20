#ifndef __FILE_OPERATION__
#define __FILE_OPERATION__

class FileOperation 
{
public:
	static bool saveFile(const char* relativePath, const char* content);
	static char* readFile(const char* relativePath);
};

#endif
