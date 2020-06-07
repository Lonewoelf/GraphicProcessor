#pragma once
#include <string>
#include <windows.h>

#define MAP_SIZE_X 1024
#define MAP_SIZE_Y 1024

class HeightField
{
public:
	HeightField();
	virtual ~HeightField();
	bool Create(std::string fileName, int hWidth, int hHeight);
	void Render(void);

private:
	BYTE hHeightField[1024][1024];
	int hmHeight;
	int hmWidth;
};

