#include<stdio.h>

void count(void);
void countt(void);

int main()

{
	count();
	count();
	count();
	count();
	printf("-------------------------------------------------\n");
	countt();
	countt();
	countt();
	countt();
}
void count(void)
{
	int x=10;
	x=x+1;
	printf("%d\n",x);
}

void countt(void)
{
	static int x=10;
	x=x+1;
	printf("%d\n",x);
}
