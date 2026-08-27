/*1. Allocate memory for 5 integers using malloc() and display them*/
#include<stdlib.h>
#include<stdio.h>
int main(){
	int* ptr_mal; //this pointer
	ptr_mal = (int*) malloc(5*sizeof(int)); //borrowing 5 int block = 20 bytes of memory using malloc
	if(ptr_mal==NULL){
		printf("Memory allocation failed...");
		return 0;
	}
	//display the initial values
	printf("Printing the addresses and the values stored of the memory block recieved:\n");
	for(int i=0;i<5;i++){
		printf("%d-",(ptr_mal+i));
		*(ptr_mal+i) = -1; //initializing the values to -1
		printf("%d ,",*(ptr_mal+i));
	}
	
	//free the block to avoid memory leaks
	free(ptr_mal);
}
