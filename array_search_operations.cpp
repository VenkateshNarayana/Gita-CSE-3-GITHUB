/*Array - Searching operations
1. Linear Search
2. Binary Search
*/
#include <stdio.h>
#define MAX_SIZE 10
void accept_array_elements_from_user(int[]);//param1=array name
int get_input_search_element(); //return the user input
void linear_search(int[],int);  //param1=array name ;param2=search element
void binary_search(int[],int);  //param1=array name ;param2=search element
void show_menu();
int main(){
	int search_element;
	int my_arr[MAX_SIZE]={0};//array declaration with initialization to zero.
	int choice=0;
	do{
	//show menu
		show_menu();
		scanf("%d",&choice);
		switch(choice){
			case 1: accept_array_elements_from_user(my_arr);
					break;
			//take inputs from user and perform linear search
			case 2: search_element=get_input_search_element();
					linear_search(my_arr,search_element);
					break;
			//take inputs from user and perfrom binary search
			case 3: search_element=get_input_search_element();
					binary_search(my_arr,search_element);
					break;
			case 4:break;
			default: printf("\nInvalid choice please enter value between 1 to 8...");
		}
		
		//insert operations
	}while(choice!=4);
	printf("\nThank You! Exited the application successfully!!!");
		
	return 0;	//for the main
}
void show_menu(){
	printf("\n****************************ARRAY SEARCH OPERATIONS - LINEAR , BINARY*****************************");
	printf("\nOption 1. INSERT ARRAY VALUES");
	printf("\nOption 2. LINEAR SEARCH");
	printf("\nOption 3. BINARY SEARCH  ");
	printf("\nOption 4. Exit");
	printf("\n\nEnter your choice[option 1-4]: ");
}
void binary_search(int arr[],int search_val){
	int low = 0,high= MAX_SIZE-1;
	int mid = (low + high)/2;

	while(low<=high){
		if (arr[mid]==search_val){
			printf("\nThe search value is found @index=%d",mid);
			return;
		}
		if(search_val>mid){
			low = mid+1;
		}else{
			high = mid-1;
		}
		mid = (low + high)/2;
	
	}
	printf("\nThe search value is NOT FOUND.");	
	return;
}
void linear_search(int arr[],int search_val){
	//perform linear search
	for(int i=0;i<MAX_SIZE;i++){
		if(arr[i]==search_val){
			printf("\nThe search value is found @index=%d",i);
			return;
		}
	}
	printf("\nThe search value is NOT FOUND.");	
	return;
}

void accept_array_elements_from_user(int arr[]){
	printf("\nEnter %d elements:",MAX_SIZE);
	for(int i=0;i<MAX_SIZE;i++){
		printf("\nEnter the data for %d element :",i+1);
		scanf("%d",&arr[i]);
	}
	return;
}
int get_input_search_element(){
	int search_value;
	printf("\nEnter the element to search:");
	scanf("%d",&search_value);
	return search_value;
}

