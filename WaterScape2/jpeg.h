#pragma once
#include <windows.h>
#include "swl.h"
#include <jpeglib.h>


tImageJPG* SwiftLoadJpeg(const char* srFileName);

void SwiftTextureJpeg(unsigned int tTexture[], LPSTR strFileName, int ID);