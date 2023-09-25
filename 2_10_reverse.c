#include <stdio.h>
#include <string.h>


#define SIZE 10

char stk[SIZE], name[SIZE], rname[SIZE];
int top = -1; 

void getstring() {
    printf("Enter string to be reversed:\n");
    gets(name);
}

void push(char x) {
    if (top < SIZE - 1) {
        top++;
        stk[top] = x;
    }
}

char pop() {
    char y = stk[top];
    top--;
    return y;
}

void reverse() {
    int i = 0;
    while (name[i] != '\0') {
        push(name[i]);
        i++;
    }

    int j = 0;
    while (top >= 0) {
        rname[j] = pop();
        j++;
    }
    rname[j] = '\0';
}

void print() {
    printf("Original String: %s\n", name);
    printf("Reversed String: %s\n", rname);
}

int main() {

    getstring();
    reverse();
    print();

    return 0;
}