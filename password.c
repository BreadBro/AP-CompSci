#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <fcntl.h>
#include <math.h>

int main(void) {
    int amt;
    do {
        amt = get_int("Number of Passwords: ");
    }
    while (amt < 0);
    int temp[amt];
    for (int i = 0; i < amt; i++) {
        int x = 0;
        string password = get_string("Password: ");
        for (int j = 0; j < strlen(password); j++) {
            if (isdigit(password[j])) {
                x += 1;
                break;
            }
        }
        for (int j = 0; j < strlen(password); j++) {
            if (!isalnum(password[j])) {
                x += 1;
                break;
            }
        }
        for (int j = 0; j < strlen(password); j++) {
            if (islower(password[j])) {
                x += 1;
                break;
            }
        }
        for (int j = 0; j < strlen(password); j++) {
            if (isupper(password[j])) {
                x += 1;
                break;
            }
        }
        for (int j = 0; j < strlen(password) - 2; j++) {
            if (strlen(password) < 8) {
                x = 0;
                break;
            }
            if (password[j] == password[j+1] && password[j+1] == password[j+2]) {
                x = 0;
                break;
            }
        }
        if (x >= 3) {
            temp[i] = 1;
        }
        else {
            temp[i] = 0;
        }
    }
    for (int i = 0; i < amt; i++) {
        if (temp[i] == 1) {
            printf("VALID\n");
        }
        else {
            printf("INVALID\n");
        }
    }
}