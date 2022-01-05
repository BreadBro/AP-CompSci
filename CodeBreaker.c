#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <fcntl.h>
#include <math.h>

char LETTERS[] = "abcdefghijklmnopqrstuvwxyz";

int main(void) {
    int cases;
    do {
        cases = get_int("Cases: ");
    }
    while (cases < 0);
    for (int a = 0; a < cases; a++) {
        int values[26];
        int length = 0;
        int lines = 0;
        int letterCount = 0;
        string sentence;
        for (int b = 0; b < 26; b++) {
            values[b] = 0;
        }
        do {
            lines = get_int("Lines: ");
        }
        while (lines < 0);
        for (int b = 0; b < lines; b++) {
            do {
                sentence = get_string("Sentence: ");
                length += strlen(sentence);
            }
            while (length < 0 || length > 2000);
            for (int c = 0; c < length; c++) {
                for (int d = 0; d < 26; d++) {
                    if (tolower(sentence[c]) == LETTERS[d]) {
                        values[d] += 1;
                        break;
                    }
                }
                if (isalpha(sentence[c])) {
                    letterCount++;
                }
            }
        }
        for (int b = 0; b < 25; b++) {
            printf("%c: %.2f%%\n", toupper(LETTERS[b]), ((float)values[b]/(letterCount-1)) * 100);
        }
    }
}