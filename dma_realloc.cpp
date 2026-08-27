/*Demonstrate realloc() by increasing an array size*/
#include<stdlib.h>
#include<stdio.h>
int main(){
	int* ptr_mal; //this pointer
	ptr_mal = (int*) malloc(5*sizeof(int)); //borrowing 5 int block = 20 bytes of memory using malloc
	if(ptr_mal==NULL){
		printf("Memory allocation failed...");
		return 1;
	}
	//display the initial values
	printf("Printing the addresses and the values stored of the memory block recieved:\n");
	for(int i=0;i<5;i++){
		*(ptr_mal+i) = -1; //initializing the values to -1
//		printf("%d ,",*(ptr_mal+i));
		printf("%d ",ptr_mal[i]);
	}
	
	//increment the block size to 10,The old values will be preserved
	ptr_mal = (int*) realloc(ptr_mal,10); // 2 parameters - 1 ptr name you want to resize, 2 - new size. 
	if(ptr_mal==NULL){
		printf("Memory allocation failed...");
		return 1;
	}
	//print all the elements with new size
	printf("\nPrinting the addresses and the values stored of the NEW memory block after resize:\n");
	for(int i=0;i<10;i++){
		printf("%d ",ptr_mal[i]);
	}
	
	//free the pointer
	free(ptr_mal);
	return 0;
}
