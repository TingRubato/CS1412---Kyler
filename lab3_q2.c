//
// Created by Ting Xu on 3/13/2024.
// Student: Kyler Cude
// Varsity Tutors
//
#include "stdlib.h"
#include "time.h"
#include "stdio.h"

enum DIRECTION {
    EAST = 1, SOUTH, WEST, NORTH
};

int main() {
    int steps = 0;

    do {
        printf("Enter number of Moves:");
        scanf("%d", &steps);
        if (steps < 1) {
            printf("Invalid input.");
        } else { printf("Number of Moves = %d", steps); }
    } while (steps < 1);

    int location[1][2] = {{0, 0}};//initial an array of location that stores the location of the person for each move.

    srand(time(0));
    int upper = 4;
    int lower = 1;//Just for you to understand in an easier way.

    for (int i = 0; i < steps; i++) {
        int direction = (rand() % (upper - lower + 1)) +
                        lower;//Is it true that we can guarantee that each number in this range has the same probability to be selected?
        switch (direction) {
            case EAST:
                location[0][0] = location[0][0] + 1;
                printf("\nMove east to point (%d,%d)", location[0][0], location[0][1]);
                break;
            case WEST:
                location[0][0] = location[0][0] - 1;
                printf("\nMove west to point (%d,%d)", location[0][0], location[0][1]);
                break;

            case NORTH:
                location[0][1] = location[0][1] + 1;
                printf("\nMove north to point (%d,%d)", location[0][0], location[0][1]);
                break;

            case SOUTH:
                location[0][1] = location[0][1] - 1;
                printf("\nMove south to point (%d,%d)", location[0][0], location[0][1]);
                break;

            default:
                printf("");
                break;
        }
    }
//Now we can calculate the distance between the initial point and the end point.
    int distance = 0;
    distance = (location[0][0]* location[0][0])+ (location[0][1]* location[0][1]);
    printf("\nThe distance from origin = %d", distance);

    return 0;
}
