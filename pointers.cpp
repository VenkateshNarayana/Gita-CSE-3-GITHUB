/*1. Write a program to print the value and address of a variable using a pointer
2.Swap two numbers using pointers
*/
#include<stdio.h> //preprocessor directives
//global declaration
void swap_by_val(int,int);
void swap_by_ref(int*,int*);

int main(){ //main function
	int x;     //variable (basic data type)
	int* ptrx;  //pointer variable - store addresses of another variable
	x=10;
	printf("\nThe value of x is %d",x);
	ptrx=&x;
	printf("\nThe address stored in ptrx is %p",ptrx);
	printf("\nThe address of x is %p",&x);
	
	//purpose of pointer
	printf("\nValue of the variable that pointer(as address)using dereference operator %d",*ptrx);
	*ptrx = 20; //x value is modified to 20 using pointer
	printf("\nThe modified value of x is %d",x);
	//swapping 2 numbers
	int y = 40;
	x=20;
	printf("\nBefore Swap-x=%d y=%d",x,y);
	swap_by_val(x,y);//function call with void
	printf("\nAfter calling Swap-x=%d y=%d",x,y);
	swap_by_ref(&x,&y); //send the address of x and address of y
	printf("\nAfter calling Swap_byref-x=%d y=%d",x,y);
	
}
//function definitions
void swap_by_ref(int* x,int* y){
	int temp;
	temp = *x;
	*x = *y;
	*y = temp;
}
void swap_by_val(int x,int y){
	int temp;
	temp = x;
	x = y;
	y = temp;
	
}

