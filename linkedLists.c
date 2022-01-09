#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <stdlib.h>


//create a struct to create our linked list
typedef struct node {
    int data;
    struct node *next;
}
node;
int size;
node *nodeMaker() {
    node *head = NULL;
    node *temp = NULL;
    node *p = NULL;
    for (int i = 0; i < size; i++) {
        temp = (node*)malloc(sizeof(node));
        temp->data = get_int("Enter number: ");
        temp->next = NULL;
        if (head == NULL) {
            head = temp;
        }
        else {
            p = head;
            while (p->next != NULL) {
                p = p->next;
            }
            p->next = temp;
        }
    }
    return head;
}

void displayList(node *head) {
    node *p = head;
    printf("%d", p->data);
    p = p->next;
    while(p != NULL) {
        printf("->%d", p->data);
        p = p->next;
    }
    printf("\n");
}

node *nodeRemover(int val, node *head) {
    node *temp = head;
    node *p = head;
    while (p != NULL) {
        if (p->data == val) {
            if (temp != p) {
                temp->next = p->next;
            }
            else {
                head = p->next;
            }
            free(p);
            size -= 1;
            return head;
        }
        temp = p;
        p = p->next;
    }
    return head;
}

node *nodeAdder(int val, node *head) {
    node *temp = NULL;
    node *p = NULL;
    temp = (node*)malloc(sizeof(node));
    temp->data = val;
    temp->next = NULL;
    if (head == NULL) {
        head = temp;
    }
    else {
        p = head;
        while (p->next != NULL) {
            p = p->next;
        }
        p->next = temp;
    }
    size += 1;
    return head;
}

int findNum (int pos, node *head) {
    int num;
    node *temp = head;
    for (int i = 0; i < pos; i++) {
        num = temp->data;
        temp = temp->next;
    }
    return num;
}

void nodeDestroyer(node **head) {
    node *current = *head;
    node *next;
    while (current != NULL) {
       next = current->next;
       free(current);
       current = next;
    }
    *head = NULL;
    size = 0;
}

int main(void) {
    node *HEAD = NULL;
    do {
        size = get_int("How many links do you want? ");
    }
    while (size < 1);
    HEAD = nodeMaker();
    int val;
    while (size >= 0) {
        int choice = get_int("Do you want to add to the list (1), remove a value from the list (2), display the list (3), delete the entire list (4), find a value in the link (5), create a new list (6), or exit (7)? ");
        switch (choice) {
            case 1:
                val = get_int("What number do you want to add? ");
                HEAD = nodeAdder(val, HEAD);
                break;
            case 2:
                if (size == 0) {
                    printf("Nothing to delete.\n");
                    break;
                }
                val = get_int("What number do you want to delete? ");
                HEAD = nodeRemover(val, HEAD);
                break;
            case 3:
                if (size == 0) {
                    printf("No list to display.\n");
                    break;
                }
                displayList(HEAD);
                break;
            case 4:
                nodeDestroyer(&HEAD);
                printf("The list has been deleted.\n");
                break;
            case 5:
                do {
                    val = get_int("What location do you want to search for? ");
                }
                while (val < 1 || val > size);
                printf("The number at %i is %i\n", val, findNum(val, HEAD));
                break;
            case 6:
                nodeDestroyer(&HEAD);
                do {
                    size = get_int("How many links do you want? ");
                }
                while (size < 1);
                HEAD = nodeMaker();
                break;
            case 7:
                size = -1;
                break;
        }
    }
}