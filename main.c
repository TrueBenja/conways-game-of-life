#include "raylib.h"
#include "gameoflife.h"

#define targetFPS (60)

int main()
{

    bool grid[screenWidth / squareSize][screenHeight / squareSize] = {0};

    InitWindow(screenWidth, screenHeight, "The Game of Life");
    SetTargetFPS(targetFPS);

    bool shouldPlay = false;
    int elapsedTime = 0;
    int tickProgress = 10;

    while (!WindowShouldClose())
    {
        // Update
        elapsedTime++;

        Vector2 mousePos = GetMousePosition();
        int tempX = mousePos.x / squareSize;
        int tempY = mousePos.y / squareSize;

        if (IsMouseButtonDown(0))
        {
            grid[tempX][tempY] = true;
        }
        else if (IsMouseButtonDown(1))
        {
            grid[tempX][tempY] = false;
        }

        if (IsKeyPressed(KEY_SPACE))
        {
            shouldPlay = !shouldPlay;
        }

        if (shouldPlay && elapsedTime % tickProgress == 0)
        {
            elapsedTime = 0;
            update_grid(grid);
        }

        // Draw
        BeginDrawing();
        ClearBackground(BLACK);

        for (int x = 0; x < screenWidth; x += squareSize)
        {
            for (int y = 0; y < screenHeight; y += squareSize)
            {
                // Checks if square shoud be white
                if (grid[x / squareSize][y / squareSize])
                {
                    DrawRectangle(x, y, squareSize, squareSize, WHITE);
                }
                else
                {
                    DrawRectangle(x, y, squareSize, squareSize, BLACK);
                }

                // Draws the grid lines
                DrawRectangleLines(x, y, squareSize, squareSize, GRAY);
            }
        }

        EndDrawing();
    }

    CloseWindow();
    return 0;
}
