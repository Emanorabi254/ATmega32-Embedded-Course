#include <stdio.h>
#include "STD_TYPES.h"

s16 GET_Summation(s16 num1,s16 num2)
{
	return num1 - num2;
}


int main()
{
	s16 x,y,res;
	printf("Enter The First Number:");
	scanf("%d",&x);
	printf("Enter The Second Number:");
	scanf("%d",&y);
	res=GET_Summation(x,y);
	printf("The Result of Summation %d and %d is %d ",x,y,res);
}

