// DFS maze solver

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Cell.h"
#include "helpers.h"
#include "Maze.h"
#include "Stack.h"

#define MAX_NEIGHBOURS 4

static void fillPath(Maze m, Cell start, Cell exit, Cell **pred);
static bool validCell(Maze m, Cell c);

bool solve(Maze m) {
    int height = MazeHeight(m);
    int width = MazeWidth(m);

    bool **visited = createBoolMatrix(height, width);
    Cell **pred = createCellMatrix(height, width);

    Stack s = StackNew();

    Cell start = MazeGetStart(m);
    StackPush(s, start);

    bool found = false;
    while (!found && !StackIsEmpty(s)) {
        Cell v = StackPop(s);

        if (visited[v.row][v.col]) {
            continue;
        }

        visited[v.row][v.col] = true;
        if (MazeVisit(m, v)) {
            fillPath(m, start, v, pred);
            found = true;
            break;
        }

        Cell adj[MAX_NEIGHBOURS] = {
            { .row = v.row - 1, .col = v.col     }, // up
            { .row = v.row,     .col = v.col + 1 }, // right
            { .row = v.row + 1, .col = v.col     }, // down
            { .row = v.row,     .col = v.col - 1 }, // left
        };

        for (int i = 0; i < MAX_NEIGHBOURS; i++) {
            Cell w = adj[i];
            if (validCell(m, w) && !MazeIsWall(m, w) && !visited[w.row][w.col]) {
                StackPush(s, w);
                pred[w.row][w.col] = v;
            }
        }
    }

    StackFree(s);

    freeBoolMatrix(visited);
    freeCellMatrix(pred);
    return found;
}

static void fillPath(Maze m, Cell start, Cell exit, Cell **pred) {
    Cell curr = exit;
    while (!(curr.col == start.col && curr.row == start.row)) {
        MazeMarkPath(m, curr);
        curr = pred[curr.row][curr.col];
    }
    MazeMarkPath(m, start);
}

static bool validCell(Maze m, Cell c) {
    return (
        c.row >= 0 && c.row < MazeHeight(m) &&
        c.col >= 0 && c.col < MazeWidth(m)
    );
}

