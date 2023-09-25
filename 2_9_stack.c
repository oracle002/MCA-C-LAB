#include <stdio.h>

int stack[5]; 
int top=-1;

void push(int z) // function to push
{
	if(top+1==6) //check whether stack is full
	{
		printf("Ststackck is Full\n");
	}
	else
	{
		
		stack[++top]=z; // increment then push into top of stack
	}
}

void pop() //function to pop
{
	if(top==-1)
	{
		printf("Stack Empty\n"); //check whether  stack empty
	}
	else
	{
		printf("Deleted Element %d from Top\n",stack[top--]); //pop then decrement
	}
}

void peek()
{
	if(top==-1)
	{
		printf("Stack Empty\n"); //check whether  stack empty
	}
	else
	{
		printf(" Element at Top of Stack :%d \n",stack[top]); // print element on top of stack
	}
}

int menu() // menu function
{
	int ch;
	printf("\nPUSH-1\nPOP-2\nPEEK-3\nEXit-4\nEnter A Choice:");
	scanf("%d",&ch);
	return ch;
}

void process()
{
	int ch;
	for(ch=menu();ch!=4;ch=menu())
	{
		switch(ch)
		{
			case 1:		printf("Enter a digit to push :\n");
						scanf("%d",&ch);
						push(ch);
						break;
			case 2:		pop();
						break;
			case 3: 	peek();
						break;
			default: 	printf("Invalid Choice\n");
		}
	}
}
int main()
{

	process();
	return 0;
}
