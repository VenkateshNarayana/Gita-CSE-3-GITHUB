/* Implementing Infix to Postfix operation using Stack
   Algorithm
   	step1 : read the infix expression from left to right 
   	step2 : if operator then peek the top if peek is having higher precedence then push current operator. 
	        Else
	           pop & push the current operator and then push the popped item.
	        or '(' then push into stack
   	step3 : if its operand ,append to output string result directly
   	step4 : if ‘)’ ? pop to output until ‘(’ is found; discard both parenthesis
	step6: End of input string, pop all remaining operators & append it to output string.
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


//for infix to postfix
int operator_precedence(char);

int main(){
	int stack[MAX_SIZE]={0}; //declaring a stack of size 5 and initializing it to 0.
	char exp[] ="(2+3*4)"; //expression(infix)
	char postfix[20]=""; //postfix expression to hold the result
	//print the Infix Expression
	printf("\nGiven Infix Expression:%s",exp);
	//follow the algorithm
	//step1: read the infix from left to right
	int i=0; //initialize i to index =0  which is 1st character of the expression string
	int k=0; //initialize k to index =0  which is 1st character of the output string
	int pop_item;
	while(exp[i]!='\0'){//read util string terminator character '\0'
		if(exp[i]=='('){
			push(stack,exp[i]); //push ascii value to stack
		// step2:
		// if operator then peek the top if peek is having higher precedence then push current operator. Else
	    // pop & push the current operator and then push the popped item.
	    // or '(' then push into stack
		}else if(exp[i]=='+' ||
			     exp[i]=='-' ||
			     exp[i]=='*' ||
			     exp[i]=='/' ||
			     exp[i]=='%' 
		   ){
		   	int peek_item = peek(stack);
		   	while(!is_empty() &&
                   peek_item != '(' && 
				   operator_precedence(peek_item)>operator_precedence(exp[i])){
		   		
				peek_item = pop(stack);   //pop the item 
		   		postfix[k++] = peek_item; //& append to postfix
			}
			//next push the current operator
			push(stack,exp[i]); //push ascii value to stack  
				
		}else if (exp[i]==')'){ //step4 : if ‘)’ ? pop to output until ‘(’ is found; discard both parenthesis
			int pop_item = pop(stack);
			while(pop_item!='('){
				postfix[k++]= pop_item;   //append to output postfix expression 
				pop_item = pop(stack);	  //pop to check if opening parentheis is found
			}
			
		}else{//step3 : if its operand ,append to output string result directly
			postfix[k++]= exp[i];	//append to output string		
		}
		i++; //move to next character of the infix expression
	}
	//append if any operator is left in stack
	while(!is_empty()){
		pop_item = pop(stack);
		postfix[k++]= pop_item;
	}
	
	postfix[k]='\0'; //append the string terminator
	
	//print the final output string
	printf("\nPostfix Expression:%s",postfix);
	
	return 0;
}
int operator_precedence(char ch){
	switch(ch){
		case '+':
		case '-': return 1;
		case '*':
		case '%':	
		case '/': return 2;
		case '(': return 3;
	}
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
