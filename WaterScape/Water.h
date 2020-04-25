#pragma once

#define MAX_X 320 //Width and height of WaveMap
#define MAX_Y 240
#define DAMP 16 //Damping factor

int WaveMap[2][MAX_X - 1][MAX_Y - 1];
int CT, NW;

void updateWaveMap();