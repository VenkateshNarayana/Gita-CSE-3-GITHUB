/*Write a program to sum the array elements. */
#include<stdio.h>
void display_array(int[],int);
int sum_array(int[],int);
int main(){
	int arr1[5]; //method 1 syntax - datatype array_name[size];
	int size =sizeof(arr1)/sizeof(int);
	printf("Enter the data for %d elements\n",size);
	//taking user input
	for(int i=0;i<size;i++){
		printf("Enter the %d element:",i+1);
		scanf("%d",&arr1[i]);
	}
	//display the array
	printf("\nArray Elements:");
	display_array(arr1,size);
	printf("\nSum of the array elements = %d",sum_array(arr1,size));
}
int sum_array(int arr[],int size){
	int sum = 0;
	for(int i=0;i<size;i++){
		sum += arr[i]; //sum = sum + i
	}
	return sum;
}
void display_array(int arr[],int size){
	
	for(int i=0;i<size;i++){
		printf("%d ",arr[i]);
	}
}
