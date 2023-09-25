
#include <stdio.h>
#include <malloc.h>
struct node {
    int data;
    struct node *next;
};
struct node *head = NULL;
void insert(int e)  {
    struct node *t;
    if(head == NULL) {
        head = (struct node *)malloc(sizeof(struct node));
        head->data = e;
        head->next = head; //
    }
    else {
        t = head;
        while(t->next != head)  {
            t = t->next;
        }
    t->next = (struct node *)malloc(sizeof(struct node));
        t->next->data = e;
        t->next->next = head;/////
    }
}
void disp() {
    struct node *t;
    if(head == NULL) {
        printf("\nCircular Linked List is Empty");
    }
    else {
        t = head;
        printf("\n");
        while(t->next != head) {
            printf("%d\t",t->data);
            t = t->next;
        }
        printf("%d",t->data);
    }
}
void disp_2() {
    struct node *t;
    if(head == NULL) {
        printf("\nCircular Linked List is Empty");
    }
    else {
        t = head;
        printf("\n");
        do {
            printf("%d\t",t->data);
            t = t->next;
        }while(t != head);
    }
}
void delete(int e) {
    struct node *t;
    if(head == NULL) {  
        printf("\nEmpty Circular Linked List");
    }
    else if(head->data == e && head->next == head) { 
        head = NULL;   
    }
    else if(head->data == e)
    {          
        t = head;
        while(t->next != head) { 
            t = t->next;
        }    
        t->next = head->next; 
        head = head->next; 
    }
    else  {
        t = head; 
        while(t->next != head && t->next->data != e) {
            t = t->next;
        }
        if(t->next == head) {
            printf("\nElement Not Found");
        }
        else { 
            t->next = t->next->next;
        }
    }
}
int main()
{
    insert(10);
    insert(20);
    insert(30);
    disp();
    disp_2();
    delete(20);
    disp();
    delete(100);
    disp();
    delete(10);
    disp();
    delete(30);
    disp();
    
    return 0;
}
