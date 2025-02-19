#include<stdio.h>

int Max_number(int n1, int n2);

int main()
{
	int n1,n2;
	printf("The value of n1:");
	scanf("%d",&n1);
	
	printf("The value of n2:");
	scanf("%d",&n2);
	printf("The Max_number is: %d ",Max_number(n1,n2));
	

}

int Max_number(int n1, int n2)
{
	int Max_one;
	
	if(n1>n2)
	Max_one=n1;
	else
	Max_one=n2;
	
	return Max_one;
}
