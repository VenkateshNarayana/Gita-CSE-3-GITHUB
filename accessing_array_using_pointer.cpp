/*Access array elements using a pointer.
*/
#include<stdio.h> //preprocessor directives
//global declaration

int main(){ //main function
	int arr[5]={11,12,13,14,15};
	int* ptr_arr = &arr[0]; //storing the address of 1st element of the array
	printf("\nAddress of arr[0] is                      %p ",&arr[0]);
//	printf("\nAcessing address of 1st element using Pointer ptr_arr is %d",ptr_arr);
//	printf("\nAcessing Value of 1st element using Pointer ptr_arr is %d",*ptr_arr);//dereferencing
//	printf("\nAcessing address of 2nd element using Pointer ptr_arr is %d",(ptr_arr+1));
//	printf("\nAcessing Value of 2nd element using Pointer ptr_arr is %d",*(ptr_arr+1));//dereferencing
	printf("\nArray elements using pointer variable:");
	for(int i=0;i<5;i++){
		printf("\nAcessing address of 1st element using Pointer ptr_arr is %d",(ptr_arr+i));
		printf("\nAcessing Value of 1st element using Pointer ptr_arr is %d",*(ptr_arr+i));//dereferencing
	}
	//array name is a pointer pointing to the base address
	printf("\nArray elements using array name:");
	for(int i=0;i<5;i++){
		printf("\nAcessing address of 1st element using Pointer ptr_arr is %d",(arr+i));
	printf("\nAcessing Value of 1st element using Pointer ptr_arr is %d",*(arr+i));//dereferencing
	}
}
//function definitions
