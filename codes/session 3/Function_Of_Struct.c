#include<stdio.h>
#include "STD_TYPES.h"


typedef struct {

	u16 Math_Grade;
	u16 English_Grade;
	u16 Pyhiscs_Grade;

}students;

f32 GET_Avarage_Grades(students object)   // Return Data Type here is the Largest Data Type 
{

	return ((object.Math_Grade+object.English_Grade+object.Pyhiscs_Grade)/3.0);
}
void ScalingGrades(students* obj)  // Pass By Refrence So we USe the Arrow Operator as a pointer to struct
{
	obj-> Math_Grade*=1.2;    // Arrow Operatoer ->
	obj-> English_Grade*=1.3;
	obj-> Pyhiscs_Grade*=1.5;
}

int main()
{

	students s1={95,89,90};
	f32 Avarage=GET_Avarage_Grades(s1);
	printf("The Avarage Grades Of This Student is: %f",Avarage);
	printf("\n");
	students s2={100,50,160};
	ScalingGrades(&s2);  // For The ADDRESS
	printf("The Sclaing Grade of Math_Grade is %d , Of English_Grade is %d and for Physics_Grade is %d",s2.Math_Grade,s2.English_Grade,s2.Pyhiscs_Grade);
}