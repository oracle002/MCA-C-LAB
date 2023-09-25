#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

typedef struct node Node;

Node *head = NULL;

void insert(int e) {
    Node *t;
    if (head == NULL) {
        head = (Node *)malloc(sizeof(Node));
        head->data = e;
        head->next = NULL;
    } else {
        t = head;
        while (t->next != NULL) {
            t = t->next;
        }
        t->next = (Node *)malloc(sizeof(Node));
        t->next->data = e;
        t->next->next = NULL;
    }
}

void disp() {
    Node *t;
    if (head == NULL) {
        printf("\nEMPTY LINKED LIST");
    } else {
        t = head;
        while (t != NULL) {
            printf("%d\t", t->data);
            t = t->next;
        }
    }
}

void displayReverse(Node *node) {
    if (node == NULL) {
        return;
    }
    displayReverse(node->next);
    printf("%d\t", node->data);
}

int main() {
    int a, i = 0, z;
    printf("ENTER THE NUMBER OF ELEMENTS YOU WANT TO ENTER:\n");
    scanf("%d", &a);
    do {
        printf("ENTER ELEMENT:\n");
        scanf("%d", &z);
        insert(z);
        i++;
    } while (i != a);
    printf("Original Linked List:\n");
    disp();
    printf("\nLinked List in Reverse Order:\n");
    displayReverse(head);
    return 0;
}
