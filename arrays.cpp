/*Write a program to input and display 5 array elements. */
#include<stdio.h>
void display_array(int[],int);
int main(){
	int arr1[5]; //method 1 syntax - datatype array_name[size];
	int size =sizeof(arr1)/sizeof(int);
	printf("Enter the data for %d elements\n",size);
	//taking user input
	for(int i=0;i<size;i++){
		printf("Enter the %d element:",i+1);
		scanf("%d",&arr1[i]);
	}

	printf("\nAccessing individual elements using random access: ");
//	printf("%d ",arr1[0]);
	//displaying the 5 elements
	display_array(arr1,size);
	
	int arr2[5]={11,21,31,41,51};//method2 syntax - datatype array_name[size]={elt1,elt2..};
	size =sizeof(arr2)/sizeof(int);
	printf("\nArray 2 values using a for loop: ");
	display_array(arr2,size);
	
	printf("\nArray 3 values using display_array() function: ");
	int arr3[]={10,20,30,40,50,60};//method3 syntax - datatype array_name[]={elt1,elt2,elt3...};
	size =sizeof(arr3)/sizeof(int);
//	printf("\nsize=%d\n",size);
	display_array(arr3,size);
}
void display_array(int arr[],int size){
	
	for(int i=0;i<size;i++){
		printf("%d ",arr[i]);
	}
}
