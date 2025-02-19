#include <stdio.h>
#include "STD_TYPES.h"

u16 GET_Summation(u16 num1,u16 num2)
{
	return num1 + num2;
}


int main()
{
	u16 num1,num2,res;
	printf("Enter The First Number:");
	scanf("%d",&num1);
	printf("Enter The Second Number:");
	scanf("%d",&num2);
	res=GET_Summation(num1,num2);
	printf("The Result of Summation %d and %d is %d ",num1,num2,res);
}

