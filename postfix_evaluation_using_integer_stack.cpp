/* Implementing Postfix Evaluation using Stack
   Algorithm
   	step1 : read the postfix expression from left to right 
   	step2 : a) if token is operator ,then pop the top 2 operands from the stack
   			b) perform the operation based on operator { result = op1 (operator) op2 }
   			c) push the result back into stack
   	step3 : if its operand push into stack
   	step4 : After the last token has been read(\0) , pop whatever is left in stack as the answer.

*/
#include<stdio.h>
#include<string.h>
#define MAX_SIZE 10

int top = -1; // current index tracker of array
void push(int[],int); //param1 = array name used for stack;param2 = value to insert(push)
void traverse(int[]); //param1 = array name used for stack
int is_full();        //return 1 =full or 0 =not full 
int pop(int[]);       //param1 = array name used for stack ; return the deleted item
int peek(int[]);      //param1 = array name used for stack ; return the top item
int is_empty();       //return 1 =empty or 0 =not empty 


int main(){
	int stack[MAX_SIZE]={0}; //declaring a stack of size 5 and initializing it to 0.
	char postfix[] = "234*+"; //expression(infix)
	int result = 0; //to hold the result
	//print the Infix Expression
	printf("\nGiven Infix Expression:%s",postfix);
	//follow the algorithm
	//step1: read the infix from left to right
	int i=0; //initialize i to index =0  which is 1st character of the postfix expression string
	
	int pop_item;
	//step1: 
	while(postfix[i]!='\0'){//read util string terminator character '\0'
		//step2 :a) if token is operator ,then pop the top 2 operands from the stack
   		//   	 b) perform the operation based on operator { result = op1 (operator) op2 }
   		//	     c) push the result back into stack
		
		if(postfix[i]=='+' ||
		   postfix[i]=='-' ||
		   postfix[i]=='*' ||
		   postfix[i]=='/' ||
		   postfix[i]=='%' ){
		   	//step 2a)
		   	//pop 1
		   	int op1=0,op2=0;
		   	op2 = pop(stack);
		   	
		   	//pop 2
		   	op1 = pop(stack);
		   	//step 2b)
			switch(postfix[i]){
				case '+': result = op1 + op2 ;break;
				case '-': result = op1 - op2 ;break;
				case '*': result = op1 * op2 ;break;
				case '/': result = op1 / op2 ;break;	
				case '%': result = op1 % op2 ;break;
				default: printf("\nInvalid operator:%c",postfix[i]);
			}
			//step 2c)
			push(stack,result);//push result back into stack
			traverse(stack);		
		}
		//step3 : if its operand push into stack
		else {
			//push into stack
			push(stack,postfix[i]-'0'); //subtract 48 which is the ascii value of '0'
			traverse(stack);
		}
		i++; //move to next character of the infix expression
	}	
	//print the final output string
	result = pop(stack);
	printf("\nPostfix Evaluation:%d",result); //final answer is whatever left in the stack
	
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
