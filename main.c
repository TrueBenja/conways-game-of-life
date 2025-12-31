#include "raylib.h"
#include "gameoflife.h"

int main()
{
    constexpr int targetFPS = 60;

    bool grid[screenWidth / squareSize][screenHeight / squareSize] = {0};

    InitWindow(screenWidth, screenHeight, "The Game of Life");
    SetTargetFPS(targetFPS);

    bool shouldPlay = false;
    int elapsedTime = 0;

    while (!WindowShouldClose())
    {
        elapsedTime++;
        BeginDrawing();
        ClearBackground(BLACK);

        Vector2 mousePos = GetMousePosition();

        if (shouldPlay && elapsedTime % 10 == 0)
        {
            elapsedTime = 0;
            update_grid(grid);
        }

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

        if (IsMouseButtonPressed(0))
        {
            int tempX = mousePos.x / squareSize;
            int tempY = mousePos.y / squareSize;
            grid[tempX][tempY] = true;
        }

        if (IsKeyPressed(KEY_SPACE))
        {
            shouldPlay = !shouldPlay;
        }

        EndDrawing();
    }

    CloseWindow();
    return 0;
}
