#include <windows.h>

#include "HeightField.h"
#include <GL/gl.h>
#include <iostream>
#include "jpeg.h"

HeightField::HeightField()
{
    memset(this->hHeightField, 0, sizeof(BYTE) * MAP_SIZE_X * MAP_SIZE_Y);
    memset(this->tID, 0, sizeof(unsigned int) * 2);
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

    std::string name = "texture.jpg";
    LPSTR texture = const_cast<char*>(name.c_str());

    SwiftTextureJpeg(tID, texture, 0);

    return true;
}

void HeightField::Render(void)
{
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, this->tID[0]);

    for (int hMapX = 0; hMapX < hmWidth; hMapX++) {
        for (int hMapZ = 0; hMapZ < hmHeight; hMapZ++) {
             glBegin(GL_TRIANGLE_STRIP);
             glTexCoord2f((float)hMapX / hmWidth, (float)hMapZ / hmHeight);
             glVertex3f(hMapX, hHeightField[hMapX][hMapZ], hMapZ);

             glTexCoord2f((float)hMapX / hmWidth, (float)(hMapZ + 1) / hmHeight);
             glVertex3f(hMapX, hHeightField[hMapX][hMapZ + 1], hMapZ + 1);

             glTexCoord2f((float)(hMapX + 1) / hmWidth, (float)hMapZ / hmHeight);
             glVertex3f(hMapX + 1, hHeightField[hMapX + 1][hMapZ], hMapZ);

             glTexCoord2f((float)(hMapX + 1) / hmWidth, (float)(hMapZ + 1) / hmHeight);

             glVertex3f(hMapX + 1, hHeightField[hMapX + 1][hMapZ + 1], hMapZ + 1);

            glEnd();
        }
    }
    glDisable(GL_TEXTURE_2D);
}
