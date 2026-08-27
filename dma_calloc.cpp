/*2. Use calloc() to create an array of 5 integers and display initial values.*/
#include<stdlib.h>
#include<stdio.h>
int main(){
	int* ptr_cal; //pointer
	ptr_cal = (int*) calloc(5,sizeof(int));//using calloc to create intialised memory block of size 5 with 4 bytes memory each
	if(ptr_cal==NULL){
		printf("Memory allocation failed...");
		return 1;
	}
	//display the intial elements
	printf("\nThe address and value of the memory block: ");
	for(int i=0;i<5;i++){
		printf("%d=",(ptr_cal+i));
		printf("%d ",*(ptr_cal+i));
		printf("%d ",ptr_cal[i]); //we can also use the [] array notation to access the values	
	}
	
	//free the pointer
	free(ptr_cal);
}
