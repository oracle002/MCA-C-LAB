#include <stdio.h>
#include <stdlib.h> // Use stdlib.h instead of malloc.h

typedef struct node {
    int data;
    struct node* next;
} node;

node *head = NULL;

void insert(int e) {
    node *t;
    if (head == NULL) {
        head = (node*)malloc(sizeof(node));
        head->data = e;
        head->next = NULL;
    }
    else {
        t = head;
        while (t->next != NULL) {
            t = t->next;
        }
        t->next = (node*)malloc(sizeof(node));
        t->next->data = e;
        t->next->next = NULL;
    }
}

void disp() {
    node *t;
    if (head == NULL) {
        printf("\n EMPTY LINKED LIST");
    }
    else {
        t = head;
        while (t != NULL) {
            printf("%d\t", t->data);
            t = t->next;
        }
    }
}

int reduce() {
    node *t;
    t = head;
    if (t->next == NULL) {
        return 0;
    }
    else {

        while (t != NULL && t->next != NULL) {
            t->data = t->data + t->next->data;
            if (t->next->next == NULL) {
                // t->next is the last node in the list
                node *temp = t->next;
                t->next = NULL; // Disconnect the last node
                free(temp);
                printf("\n");
                disp();
                reduce();
                 // Free the last node
            }
            else {
                t = t->next; // Move to the next pair of nodes
            }

        }

    }

}

int main() {
    insert(10);
    insert(11);
    insert(12);
    insert(13);
    printf("Original List:\n");
    disp();
    reduce();
    return 0;
}
