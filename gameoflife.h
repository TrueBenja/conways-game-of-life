#ifndef GAMEOFLIFE_H
#define GAMEOFLIFE_H

constexpr int screenWidth = 1920;
constexpr int screenHeight = 1080;
constexpr int squareSize = 30;


void update_grid(bool grid[][screenHeight / squareSize]);

#endif
