#ifndef GAMEOFLIFE_H
#define GAMEOFLIFE_H

#include <stdbool.h>

#define screenWidth (1920)
#define screenHeight (1080)
#define squareSize (30)

void update_grid(bool grid[][screenHeight / squareSize]);

#endif
