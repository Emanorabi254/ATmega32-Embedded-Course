#include<stdio.h>


int main()
{

	int i;
	int Array[10];
	printf("The Values Of The Array Element: \n");
	for(i=0;i<=9;i++)
	{
		scanf("%d",&Array[i]);
	}
	
	for(i=9;i>=0;i--)
	{
		printf("%d",Array[i]);
		printf("\n");

	}


}