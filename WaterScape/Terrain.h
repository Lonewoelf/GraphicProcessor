#pragma once

#include <windows.h>

#define MAP_SIZE 1024 //Size of the RAW map file
#define BLOK_SIZE 16  //Size of each rendered blok

class Terrain {
public:
	Terrain();
	~Terrain();

	int getHeight(BYTE *heightMap, int x, int y);
	void loadFile(LPSTR fileName, int fileSize, BYTE *heightMap);
	void renderMap(BYTE *heightMap);
};