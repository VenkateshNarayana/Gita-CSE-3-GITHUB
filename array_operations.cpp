/*Array operations 
-Insert - insert_at_end,insert_at_index 
-Delete - delete_at_end,delete_at_index
-Modify - modify_at_index
-Traverse - linear traversal
*/
#include<stdio.h>
#define MAX 5
int curr_index = 0;//since no elements added yet
void insert_at_begin(int[],int);//param1=array ;param2=newvalue
void insert_at_index(int[],int,int); //param1=array ;param2=index ; param=newvalue
void insert_at_end(int[],int); //param1= array;param2=value

void delete_at_begin(int[]);//param1=array name;
void delete_at_index(int[],int);//param1= array;param2=index
void delete_at_end(int[]);//param1=array and remove the last element
void display_array(int[]); //param1=arry ;param2 = size(which is current index)
void modify_at_index(int[],int,int);//param1=array ;param2=index ; param=newvalue

void show_menu();
int get_array_input_value();
int get_array_index_value();
int main(){
	int my_arr[MAX]={0}; //declare and initialise
	int choice =0;
	int user_input,index_value;
	do{
		show_menu();
		scanf("%d",&choice);
		switch(choice){
			//insert at begin
			case 1: user_input = get_array_input_value();
					insert_at_begin(my_arr,user_input);
					break;
			//insert at index
			case 2: user_input = get_array_input_value();
					index_value = get_array_index_value();
					insert_at_index(my_arr,index_value,user_input);
					break;
			//insert at end
			case 3: user_input = get_array_input_value();
					insert_at_end(my_arr,user_input);
					break;
			
			//delete at begin
			case 4: delete_at_begin(my_arr);
					break;
			//delete at index
			case 5: index_value = get_array_index_value();
					delete_at_index(my_arr,index_value);
					break;
			//delete at end
			case 6: delete_at_end(my_arr);
					break;
			//traverse
			case 7: display_array(my_arr);
					break;
			case 8: break;
			
			default: printf("\nInvalid choice,please enter option between(1-8).");
		}
		
	}while(choice!=8);
	printf("\nThank you!!. Exited Application successfully!!!");
	return 0;//for the main
}
int get_array_input_value(){
	int input_value;
	printf("\nEnter array value you want to insert: ");
	scanf("%d",&input_value);
	return input_value;
}
int get_array_index_value(){
	int index_value;
	printf("\nEnter array index you want to insert: ");
	scanf("%d",&index_value);
	return index_value;
}
void show_menu(){
	printf("\n****************************ARRAY OPERATIONS - TRAVERSE , INSERT, DELETE*****************************");
	printf("\nOption 1. INSERT AT BEGIN   		\tOption 4. DELETE AT BEGIN");
	printf("\nOption 2. INSERT AT INDEX   		\tOption 5. DELETE AT INDEX");
	printf("\nOption 3. INSERT AT END     		\tOption 6. DELETE AT END");
	printf("\nOption 7. TRAVERSE(DISPLAY ARRAY) \tOption 8. Exit");
	printf("\n\nEnter your choice[option 1-8]: ");
}

void insert_at_begin(int arr[],int new_value){
	insert_at_index(arr,0,new_value);
}
void insert_at_index(int arr[],int index,int new_value){
	if(curr_index>=MAX){
		printf("\nArray is full....cannot insert %d value!!!",new_value);
		return;
	}
	if(index<0 || index>=MAX){
		printf("\nInvalid index, cannot perform addition!!!");
		return;
	}
	for (int i=curr_index-1;i>=index;i--){
		arr[i+1] = arr[i];//right shifting
	}
	arr[index] = new_value;
	curr_index++; //increment the size by 1
	printf("\n%d Value inserted @index %d successfully!!!",new_value,index);
}

void modify_at_index(int arr[],int index,int new_value){
	if(index<0 || index>=curr_index){
		printf("\nInvalid index, cannot modify value!!!");
		return;
	}
	arr[index] = new_value;
	printf("\n%d Value modified successfully!!!",new_value);
}
void delete_at_begin(int arr[]){
	delete_at_index(arr,0);
}
void delete_at_index(int arr[],int index){
	if(index<0 || index>=curr_index){
		printf("\nInvalid index, cannot modify value!!!");
		return;
	}
	for(int i=index;i<curr_index-1;i++){
		arr[i]=arr[i+1];//left shifting
	}
	arr[curr_index]=0;//last element make it 0
	curr_index--; //decrement the size by 1
	if (index==0){
		printf("\nElement deleted from begin sucessfully!!!");
		return;
	}
	printf("\nElement deleted from %d index sucessfully!!!",index);
}
void delete_at_end(int arr[]){
	if(curr_index<=0){
		printf("\nArray is empty....cannot delete any more values!!!");
		return;
	}
	arr[curr_index]=0;
	curr_index--;//reduce the size
	printf("\nElement deleted from end sucessfully!!!");
}
void display_array(int arr[]){
	printf("\nMy Array elements:[CURR SIZE=%d] ",curr_index);
	for(int i=0;i<curr_index;i++){
		printf("%d ",arr[i]);
	}
}
void insert_at_end(int arr[],int value){
	if(curr_index>=MAX){
		printf("\nArray is full....cannot insert %d value!!!",value);
		return;
	}
	arr[curr_index] = value; //insert value
	curr_index++; //increment index by 1 to show that current size has grown by 1 element
	printf("\nValue %d inserted into array successfully!!!!",value);
}

