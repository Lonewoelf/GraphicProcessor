#include "HeightField.h"
#include <GL/gl.h>
#include <iostream>

HeightField::HeightField()
{
    memset(this->hHeightField, 0, sizeof(BYTE) * MAP_SIZE_X * MAP_SIZE_Y);
    this->hmHeight = 0;
    this->hmWidth = 0;
}

HeightField::~HeightField()
{
}

bool HeightField::Create(std::string FileName, int hWidth, int hHeight)
{
    FILE* fp;
    const char* fileName = FileName.c_str();
    hmHeight = hHeight;
    hmWidth = hWidth;

    fp = fopen(fileName, "rb");

    fread(hHeightField, 1, hWidth * hHeight, fp);

    fclose(fp);

    //for (int hMapX = 0; hMapX < hWidth; hMapX++) {

    //    for (int hMapZ = 0; hMapZ < hHeight; hMapZ++) {
    //        std::cout << hMapX << ", " << hMapZ << ", " << hHeightField[hMapX][hMapZ] << std::endl;
    //    }
    //}

    return true;
}

void HeightField::Render(void)
{
    glBegin(GL_POINTS);
     for (int hMapX = 0; hMapX < hmWidth; hMapX++){
        for (int hMapZ = 0; hMapZ < hmHeight; hMapZ++){
            glVertex3f(hMapX, hHeightField[hMapX][hMapZ], hMapZ);
        }

     }
    glEnd();
}
