#include<stdio.h>

void edit(int,int);    // Pass By Value
void edit2(int *n1, int *n2);
int main()
{

	char x=10;
	char *ptr=&x;  // The Address of x
	printf("The Address Of X: %d\n",ptr);
	printf("The Address Of X: %d\n",&x);
	printf("The Address Of Pointer: %d\n",&ptr);
	printf("The Value Of X: %d\n",x);
	printf("The Value Of X: %d\n",*ptr);  // *ptr ----> is callled Derefrence Operator
	printf("The Size Of The Pointer: %d\n",sizeof(ptr));
	printf("The Size Of The x: %d\n",sizeof(x));

		/*Pass By Refrence & By Value*/
	int n1,n2,n11,n22;
	n1=10;n2=50;
	n11=150;n22=560;
	printf("The Value Of N1: %d",n1);
	printf("The Value Of N2: %d",n2);
	edit(n1,n2);   // Call By Value 
	printf("The Value Of N1: %d",n1);
	printf("The Value Of N2: %d",n2);

	printf("The Value Of N1: %d",n1);
	printf("The Value Of N2: %d",n2);
	edit2(n11,n22);   // Call By Value 
	printf("The Value Of N1: %d",n1);
	printf("The Value Of N2: %d",n2);


}

void edit(int n1,int n2)
{
	n1=100;
	n2=300;
}

void edit2(int *n11,int *n22)

{
	*n11=140;
	*n22=500;

}