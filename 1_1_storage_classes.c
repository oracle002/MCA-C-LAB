#include <stdio.h>
#include <conio.h>

int a_global;	//global varible

void function()
{
	static int a_static; //static varible
	printf("static varible:%d\n",a_static);
	a_static++;
}

int main()
{
	int a_local; //local varible
	register int b_reg=10;	//register varible
	printf("=====USING LOCAL VARIBLE=====\n");
	printf("local varible:%d\n",a_local);
	a_local=2;
	printf("local varible:%d\n",a_local);
	printf("ENTER A INTEGER:\n");
	scanf("%d",&a_local);
	printf("local varible:%d\n",a_local);
	getch();
	printf("=====USING GLOBAL VARIBLE=====\n");
	printf("global varible:%d\n",a_global);
	printf("ENTER A INTEGER BTW 1-5:\n");
	scanf("%d",&a_global);
	printf("global varible:%d\n",a_global);
	getch();
	printf("=====USING STATIC VARIBLE=====\n");
	for(a_local=0;a_local<=a_global;a_local++) //executing loop using local & global varibles
		{
			function();
		}
	getch();
	printf("=====USING REGISTER VARIBLE=====\n");
	printf("Register varible:%d\n",b_reg);
	printf("ENTER A INTEGER:\n");
	scanf("%d",b_reg);
	printf("Register varible:%d\n",b_reg);
	return 0;

		
}
