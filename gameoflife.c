#include "gameoflife.h"
#include <stdio.h>

void update_grid(bool grid[][24])
{
    constexpr int gridWidth = screenWidth / squareSize;
    constexpr int gridHeight = screenHeight / squareSize;
    bool tempGrid[gridWidth][gridHeight] = {0};

    for (int x = 0; x < gridWidth; ++x)
    {
        for (int y = 0; y < gridHeight; ++y)
        {
            if (x == 0 && y == 0) // Left top corner
            {
                int count = 0;
                if (grid[x + 1][y]) count++;
                if (grid[x + 1][y + 1]) count++;
                if (grid[x][y + 1]) count++;

                if (count < 2 && grid[x][y])
                {
                    tempGrid[x][y] = false;
                }

                if (((count == 2 || count == 3) && grid[x][y]) || (count == 3 && !grid[x][y]))
                {
                    tempGrid[x][y] = true;
                }
            }
            else if (x == gridWidth - 1 && y == 0) // Right top corner
            {
                int count = 0;
                if (grid[x - 1][y]) count++;
                if (grid[x - 1][y + 1]) count++;
                if (grid[x][y + 1]) count++;

                if (count < 2 && grid[x][y])
                {
                    tempGrid[x][y] = false;
                }

                if (((count == 2 || count == 3) && grid[x][y]) || (count == 3 && !grid[x][y]))
                {
                    tempGrid[x][y] = true;
                }
            }
            else if (x == 0 && y == gridHeight - 1) // Left bottom corner
            {
                int count = 0;
                if (grid[x + 1][y]) count++;
                if (grid[x + 1][y + 1]) count++;
                if (grid[x][y - 1]) count++;

                if (count < 2 && grid[x][y])
                {
                    tempGrid[x][y] = false;
                }

                if (((count == 2 || count == 3) && grid[x][y]) || (count == 3 && !grid[x][y]))
                {
                    tempGrid[x][y] = true;
                }
            }
            else if (x == gridWidth - 1 && y == gridHeight - 1) // Right bottom corner
            {
                int count = 0;
                if (grid[x - 1][y]) count++;
                if (grid[x - 1][y - 1]) count++;
                if (grid[x][y - 1]) count++;

                if (count < 2 && grid[x][y])
                {
                    tempGrid[x][y] = false;
                }

                if (((count == 2 || count == 3) && grid[x][y]) || (count == 3 && !grid[x][y]))
                {
                    tempGrid[x][y] = true;
                }
            }
            else if (x == 0) // Left side (except corners)
            {
                int count = 0;
                if (grid[x][y - 1]) count++;
                if (grid[x + 1][y - 1]) count++;
                if (grid[x + 1][y]) count++;
                if (grid[x + 1][y + 1]) count++;
                if (grid[x][y + 1]) count++;

                if (count < 2 && grid[x][y])
                {
                    tempGrid[x][y] = false;
                }

                if (((count == 2 || count == 3) && grid[x][y]) || (count == 3 && !grid[x][y]))
                {
                    tempGrid[x][y] = true;
                }
            }
            else if (x == gridWidth - 1) // Right side (except corners)
            {
                int count = 0;
                if (grid[x][y - 1]) count++;
                if (grid[x - 1][y - 1]) count++;
                if (grid[x - 1][y]) count++;
                if (grid[x - 1][y + 1]) count++;
                if (grid[x][y + 1]) count++;

                if (count < 2 && grid[x][y])
                {
                    tempGrid[x][y] = false;
                }

                if (((count == 2 || count == 3) && grid[x][y]) || (count == 3 && !grid[x][y]))
                {
                    tempGrid[x][y] = true;
                }
            }
            else if (y == 0) // Top (except corners)
            {
                int count = 0;
                if (grid[x - 1][y]) count++;
                if (grid[x - 1][y + 1]) count++;
                if (grid[x][y + 1]) count++;
                if (grid[x + 1][y + 1]) count++;
                if (grid[x + 1][y]) count++;

                if (count < 2 && grid[x][y])
                {
                    tempGrid[x][y] = false;
                }

                if (((count == 2 || count == 3) && grid[x][y]) || (count == 3 && !grid[x][y]))
                {
                    tempGrid[x][y] = true;
                }
            }
            else if (y == gridHeight - 1) // Bottom
            {
                int count = 0;
                if (grid[x - 1][y]) count++;
                if (grid[x - 1][y - 1]) count++;
                if (grid[x][y - 1]) count++;
                if (grid[x + 1][y - 1]) count++;
                if (grid[x + 1][y]) count++;

                if (count < 2 && grid[x][y])
                {
                    tempGrid[x][y] = false;
                }

                if (((count == 2 || count == 3) && grid[x][y]) || (count == 3 && !grid[x][y]))
                {
                    tempGrid[x][y] = true;
                }
            }
            else
            {
                int count = 0;
                if (grid[x - 1][y]) count++;
                if (grid[x - 1][y - 1]) count++;
                if (grid[x][y - 1]) count++;
                if (grid[x + 1][y - 1]) count++;
                if (grid[x + 1][y]) count++;
                if (grid[x + 1][y + 1]) count++;
                if (grid[x][y + 1]) count++;
                if (grid[x - 1][y + 1]) count++;

                if ((count > 3 || count < 2) && grid[x][y])
                {
                    tempGrid[x][y] = false;
                }

                if (((count == 2 || count == 3) && grid[x][y]) || (count == 3 && !grid[x][y]))
                {
                    tempGrid[x][y] = true;
                }
            }
        }

    }
    // Any live cell with fewer than two live neighbors die
    // Any live cell with two or three neighbors lives
    // Any live cell with more than three neighbors dies
    // Any dead cell with exactly three neighbors becomes a live cell
    for (int x = 0; x < gridWidth; ++x)
    {
        for (int y = 0; y < gridHeight; ++y)
        {
            grid[x][y] = tempGrid[x][y];
        }
    }
}
