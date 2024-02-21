#include <stdio.h>
#include <stdlib.h>

#define MAX_ROWS 10
#define MAX_COLS 10

typedef struct {
    int row, col;
} Point;

int isValid(int row, int col, int rows, int cols) {
    return (row >= 0 && row < rows && col >= 0 && col < cols);
}

int shortestPath(int matrix[MAX_ROWS][MAX_COLS], int rows, int cols) {
    int visited[MAX_ROWS][MAX_COLS] = {0};
    int distance[MAX_ROWS][MAX_COLS] = {0};

    // Define possible moves: up, down, left, right
    int dr[] = {-1, 1, 0, 0};
    int dc[] = {0, 0, -1, 1};

    Point queue[MAX_ROWS * MAX_COLS];
    int front = 0, rear = 0;

    // Add the starting point to the queue
    queue[rear++] = (Point){0, 0};
    visited[0][0] = 1;

    while (front < rear) {
        Point current = queue[front++];
        int currentDistance = distance[current.row][current.col] + 1;

        // Check all possible moves
        for (int i = 0; i < 4; i++) {
            int newRow = current.row + dr[i];
            int newCol = current.col + dc[i];

            if (isValid(newRow, newCol, rows, cols) && !visited[newRow][newCol] && matrix[newRow][newCol] == 1) {
                queue[rear++] = (Point){newRow, newCol};
                visited[newRow][newCol] = 1;
                distance[newRow][newCol] = currentDistance;

                if (newRow == rows - 1 && newCol == cols - 1) {
                    return distance[newRow][newCol];
                }
            }
        }
    }

    return -1; // No valid path found
}

int main() {
    int matrix[MAX_ROWS][MAX_COLS] = {
    {1, 0, 1, 1, 1},
    {1, 0, 1, 0, 1},
    {1, 1, 1, 1, 1},
    {0, 0, 0, 1, 0},
    {1, 0, 1, 1, 1}
};


    int rows = 5;
    int cols = 5;

    int result = shortestPath(matrix, rows, cols);

    if (result != -1) {
        printf("Shortest path length: %d\n", result);
    } else {
        printf("No valid path found.\n");
    }

    return 0;
}
