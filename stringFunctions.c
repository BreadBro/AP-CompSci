//Safin Stefanos
//Reverse a word in a string and find the longest word in a string
//09/17/2021
//for help with strtok: https://www.educative.io/edpresso/splitting-a-string-using-strtok-in-c
#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

string FirstReverse(string word) {
    size_t length = strlen(word);
    char ReversedCharArray[length];
    //sets first char in array to last letter of word
    for (int i = 0; i < length; i++) {
        ReversedCharArray[i] = word[length-i-1];
    }
    string ReversedWord = ReversedCharArray;
    return ReversedWord;
}

string LongestWord(string sentence) {
    string LongestWord;
    int length = strlen(sentence);
    //splits sentence into tokens that are separated by spaces
    char * token = strtok(sentence, " ");
    LongestWord = token;
    //loop to find length of word
    while (token != NULL) {
        //removes any special characters from the word
        for (int i = 0; LongestWord[i]; i++) {
            if (!isalpha(LongestWord[i])) {
                strcpy(&LongestWord[i], "");
            }
        }
        //updates the longest word if the token
        if (strlen(LongestWord) < strlen(token)) {
            LongestWord = token;
        }
        //removes the first word from the sentence
        token = strtok(NULL, " ");
    }
    return LongestWord;
}

int main(void) {
    int x = 1;
    string choice, WordToReverse, sentence;
    //basic menu while loop
    while (x == 1) {
        choice = "";
        choice = get_string("Would you like to reverse a word, find the longest word in a sentence, or exit (reverse, longest, exit)? ");
        for (int i = 0; choice[i]; i++) {
            choice[i] = tolower(choice[i]);
        }
        if (strcmp(choice, "exit") == 0 || strcmp(choice, "e") == 0) {
            x = 0;
        }
        if (strcmp(choice, "reverse") == 0 || strcmp(choice, "r") == 0) {
            WordToReverse = get_string("What word would you like to reverse? ");
            printf("%s\n", FirstReverse(WordToReverse));
        }
        if (strcmp(choice, "longest") == 0 || strcmp(choice, "l") == 0) {
            sentence = get_string("What sentence would you like to find the longest word of? ");
            printf("The longest word in the sentence is: %s\n", LongestWord(sentence));
        }
    }
}