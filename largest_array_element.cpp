/*Write a program to find the largest element. */
#include<stdio.h>
void display_array(int[],int);
int find_largest_element(int[],int);
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
	printf("\nLargest element is %d",find_largest_element(arr1,size));
}
int find_largest_element(int arr[],int size){
	int max = arr[0];//assume first element to be my max
	for(int i=1;i<size;i++){
		if(arr[i]>max){
			max = arr[i];//this is my new max
		}
	}
	return max;
}
void display_array(int arr[],int size){
	
	for(int i=0;i<size;i++){
		printf("%d ",arr[i]);
	}
}
