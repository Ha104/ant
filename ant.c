#include <stdio.h>
#include <unistd.h>

// dimension of the field
#define N 100
#define M 100

enum direction { UP, RIGHT, DOWN, LEFT };
enum color { WHITE, BLACK };
enum bool { true, false };

struct pos_aut {
    int x, y, st;
};

// array to stores coordinate changes and direction
const int turn[4][2][3] = {
    {
        { 0, +1, RIGHT },
        { 0, -1, LEFT }
    },
    {
        { +1, 0, DOWN },
        { -1, 0, UP }
    },
    {
        { 0, -1, LEFT },
        { 0, +1, RIGHT }
    },
    {
        { -1, 0, UP },
        { +1, 0, DOWN }
    }
};

enum color field[N][M] = {};
struct pos_aut aut = { N / 2, M / 2, UP };

// function to display in the console
void show() {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            printf(field[i][j] ? "#" : " ");
        }
        printf("\n");
    }
}

// function to ant's moving
void moving() {
    int x = aut.x;
    int y = aut.y;
    int st = aut.st;

    field[aut.x][aut.y] = !field[aut.x][aut.y]; // changing the color to the opposite

    aut.x += turn[st][field[x][y]][0]; // changing value coordinates for x
    aut.y += turn[st][field[x][y]][1]; // changing value coordinates for y

    aut.st = turn[st][field[x][y]][2]; // changing the viewing side
}

int main() {
    int p = 10000; // running for 10000 iterations
    while (p--) {
        moving();
        show();
        sleep(1); // argument in seconds
        system("clear");
    }
    // show(); // to view the final picture
}
