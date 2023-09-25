#include <stdio.h>
#include<malloc.h>
struct book{
	char author_name[30];
	char book_name[40];
};

void read(struct book *b, int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		printf("Enter author name and book name");
		scanf("%s%s",(b+i)->author_name,(b+i)->book_name);
	}

}

void disp(struct book *b ,int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		printf("Author name:%s\n Book name:%s\n",(b+i)->author_name,(b+i)->book_name);
	}
}

int main()
{
	struct book *b;
	int  n;
	printf("Enter no:of books");
	scanf("%d",&n);
	b=(struct book *)calloc(sizeof(struct book),n);
	read(b,n);
	disp(b,n);
	free(b);
	return 0;
}
