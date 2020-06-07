#pragma once
#include <string>
class HeightField
{
public:
	HeightField();
	virtual ~HeightField();
	bool Create(std::string fileName, int hWidth, int hHeight);
	void Render(void);
};

