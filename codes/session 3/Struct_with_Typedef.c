#include<stdio.h>
#include "STD_TYPES.h"


typedef struct {

	u8 Number_Of_Subjects;
	u16 Math_Grade;
	u16 English_Grade;
	u16 Pyhiscs_Grade;

}students;

int main()
	{
	 students s1;
	printf("Enter Number Of Subjects:");
	scanf("%i",&s1.Number_Of_Subjects);   // Specifier %i is for the char u8

	printf("Enter Math_Grade:");
	scanf("%d",&s1.Math_Grade);

	printf("Enter English_Grade:");
	scanf("%d",&s1.English_Grade);

	printf("Enter Pyhiscs_Grade:");
	scanf("%d",&s1.Pyhiscs_Grade);

	printf("The Student has %i Subjects , his Math_Grade is : %d , English_Grade is: %d and His Pyhiscs_Grade is: %d ",s1.Number_Of_Subjects,s1.Math_Grade,s1.English_Grade,s1.Pyhiscs_Grade);


}