/* Implement Stack Operation Using array
   Principle - LIFO
   Operations - push, pop , peek, is_empty, is_full
*/
#include<stdio.h>
#define MAX_SIZE 5

int top = -1; // current index tracker of array
void push(int[],int); //param1 = array name used for stack;param2 = value to insert(push)
void traverse(int[]); //param1 = array name used for stack
int is_full();        //return 1 =full or 0 =not full 
int pop(int[]);       //param1 = array name used for stack ; return the deleted item
int peek(int[]);      //param1 = array name used for stack ; return the top item
int is_empty();       //return 1 =empty or 0 =not empty 

int main(){
	int stack[MAX_SIZE]={0}; //declaring a stack of size 5 and initializing it to 0.
	push(stack,10);	
	traverse(stack);
	push(stack,20);
	traverse(stack);
	push(stack,30);
	traverse(stack);
	push(stack,40);
	traverse(stack);
	push(stack,50);
	traverse(stack);
	push(stack,60);
	traverse(stack);
	int pop_item = pop(stack);
	printf("\npopped =%d successfully",pop_item);
	traverse(stack);
	int peek_val = peek(stack);
	printf("\npeek  =%d ",peek_val);
	
	return 0;
	
}
int is_empty(){
	return (top<=-1); //if top has reached -1 (its empty)
}

int is_full(){
	
	return (top>=(MAX_SIZE-1)); //if top reached the MAX_SIZE (its full)
}
void traverse(int stack[]){
	printf("\nMyStack[");
	for (int i=0;i<=top;i++){
		printf("%d ",stack[i]);
	}
	printf("]");
}
void push(int stack[],int value){
	if(is_full()){
		printf("\nStack is full!!!!,cannot push %d value",value);
		return;
	}
	stack[++top] = value; //push operation stack[0] = 10 
} 
int pop(int stack[]){
	if(is_empty()){
		printf("\nStack is empty,cannot pop values");
		return -1;
	}
	
	int popped_item = stack[top--]; //pop
	return popped_item;
}
int peek(int stack[]){
	
	return stack[top]; 
}
