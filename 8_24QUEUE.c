#include <stdio.h>

#define MAX_SIZE 10

struct Lqueue {
    int q[MAX_SIZE];
    int front, rear;
};

void init(struct Lqueue* queue) {
    queue->front = queue->rear = -1;
}

void qinsert(struct Lqueue* queue) {
    if (queue->rear == MAX_SIZE - 1) {
        printf("Sorry! Queue is full\n");
    } else {
        int no;
        printf("Enter Number: ");
        scanf("%d", &no);
        queue->rear++;
        queue->q[queue->rear] = no;
        if (queue->front == -1) {
            queue->front = 0;
        }
    }
}

void qdelete(struct Lqueue* queue) {
    if (queue->front == -1) {
        printf("Sorry! No elements\n");
    } else {
        int no;
        no = queue->q[queue->front];
        printf("Deleted element is %d\n", no);
        if (queue->front == queue->rear) {
            queue->front = queue->rear = -1;
        } else {
            queue->front++;
        }
    }
}

void print(struct Lqueue* queue) {
    if (queue->front != -1) {
        printf("Queue elements are:\n");
        for (int i = queue->front; i <= queue->rear; i++) {
            printf("%d\t", queue->q[i]);
        }
        printf("\n");
    } else {
        printf("Queue is Empty!\n");
    }
}

int main() {
    struct Lqueue L;
    int opt;
    init(&L);
    do {
        printf("\nMENU\n");
        printf("1. Insertion\n");
        printf("2. Deletion\n");
        printf("3. Print\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &opt);
        switch (opt) {
            case 1:
                qinsert(&L);
                break;
            case 2:
                qdelete(&L);
                break;
            case 3:
                print(&L);
                break;
            case 4:
                break;
            default:
                printf("Invalid option!\n");
        }
    } while (opt != 4);

    return 0;
}
