
#include "cocos2d.h"
USING_NS_CC;
#define BUFFER_SIZE 1024

#include "FileOperation.h"

using namespace std;

bool FileOperation::saveFile(const char* relativePath, const char* content)
{
	CCFileUtils* reader = CCFileUtils::sharedFileUtils();
	std::string fullPath = reader->fullPathFromRelativePath(relativePath);

	FILE *fp = fopen(fullPath.c_str(), "a");

	if (! fp)
	{
		CCLOG("Can not create file %s", fullPath.c_str());
		return false;
	}

	fputs(content, fp);
	fclose(fp);
	return true;
}

char* FileOperation::readFile(const char* relativePath)
{
	CCFileUtils* reader = CCFileUtils::sharedFileUtils();
	std::string fullPath = reader->fullPathFromRelativePath(relativePath);

	FILE *fp = fopen(fullPath.c_str(), "w");
	char* buf = new char(BUFFER_SIZE);

	if (! fp)
	{
		CCLOG("Can not open file %s", fullPath.c_str());
		return 0;
	}

	//while(!feof(fp))
	{
		fgets(buf, BUFFER_SIZE, fp);
	}

	CCLOG("Read ok file: %s", relativePath);
	fclose(fp);
	return buf;
}


