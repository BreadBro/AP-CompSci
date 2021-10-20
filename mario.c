#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int main(int argc, string argv[]) {
    //Always check for right number of parameters (not always 2)
    if (argc != 2) {
        printf("Error: ARGC Invalid\n");
    }

    int size = atoi(argv[1]);
    if (size <= 0) {
        printf("Error: Size Is Non-Positive\n");
    }
    for (int line = 0; line < size; line++) {
        //spaces
        for (int spaces = 0; spaces < size - line - 1; spaces++) {
            printf(" ");
        }
        //first hashes
        for (int hash = 0; hash <= line; hash++) {
            printf("#");
        }

        printf("  ");
        //second hashes
        for (int hash = 0; hash <= line; hash++) {
            printf("#");
        }
        printf("\n");
    }

    return 0;
}