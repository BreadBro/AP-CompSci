#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define MAX 9

typedef struct {
    string name;
    int votes;
}
candidate;

candidate candidates[MAX];

bool vote(string name, int numOfCand) {
    for (int i = 0; i < numOfCand; i++) {
        if (strcmp(candidates[i].name, name) == 0) {
            candidates[i].votes++;
            return true;
        }
    }
    return false;
}

void print_winner(int numOfCand) {
    int max = 0;
    for (int i = 0; i < numOfCand; i++) {
        if (max < candidates[i].votes) {
            max = candidates[i].votes;
        }
    }
    for (int i = 0; i < numOfCand; i++) {
        if (max == candidates[i].votes) {
            printf("%s\n", candidates[i].name);
        }
    }
}

int main(int argc, string argv[]) {
    if (argc < 2) {
        printf("Usage: plurality [candidate ...]\n");
        return 1;
    }
    int numOfCand = argc - 1;
    string name;
    for (int i = 0; i < numOfCand; i++) {
        candidates[i].name = argv[i+1];
        candidates[i].votes = 0;
    }
    int voteCount = get_int("Number of voters: ");
    for (int i = 0; i < voteCount; i++) {
        name = get_string("Vote: ");
        if (!vote(name, numOfCand)) {
            printf("Invalid vote.\n");
        }
    }
    print_winner(numOfCand);
    return 0;
}