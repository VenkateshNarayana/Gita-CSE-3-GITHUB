/* Applications of Linked List
1.Building a Stack using Linked list
2.Building a Queue using Linked list
3.Evaluate polynomial expressions
*/
#include<stdio.h>
#include<stdlib.h>

struct node{
	int           data; //1. this is store data part
	struct node*  next; //2. this is pointer variable to store the address of another node
};
struct node* head=NULL;        //tracking the head node
struct node* tail=NULL;        //tracking the tail node
struct node* create_node(int); //param1 = input data to fill the data part of the node

//push operations - at head
void push(int);      //param1 = input data to fill the data part of the node

//pop operations - at head
void pop();         //delete the current head and move to next node of head

int is_empty();                //return 1 if head is NULL else 0
void peek();                   //show what is at Top=head->data

//traverse operation - from head to tail
void traverse();          //traverse the list from head to tail
void free_list();              //to free all the nodes in the list (prevent memory leak)      
int main(){
	//push operations
	push(10);     //inserting value = 10 in stack
	push(20);     //inserting value = 20 in stack
	push(30);     //inserting value = 30 in stack
	
	traverse();   //traverse the stack
	peek();       //show the Top=head->data
	
	//pop operations
	pop();        //removing Top value from stack (30)
	peek();       //this should fetch new Top = (20)
	pop();        //removing Top value from stack (20)
	peek();       //this should fetch new Top = (10)
	pop();        //removing Top value from stack (10)
	peek();       //this should fetch new Top = NULL
	
	pop();        //This will cause underflow condition...cannot pop anymore items
	traverse();   //This will show an empty stack
	
	//free the nodes if the linked list is not empty
	free_list();
	return 0;
}
struct node* create_node(int input_data){
	//create the node using malloc
	struct node* new_node = (struct node*) malloc(sizeof(struct node));
	
	//check if memory allocation failed?
	if(new_node==NULL){
		printf("memory allocation failed...");
		return NULL;
	}
	//if new node is created successfull then assign the data 
	new_node->data = input_data; //store the input data
	new_node->next = NULL;       //becauase its a brand new node
	return new_node;
}
void push(int input_data){
	struct node* new_node = create_node(input_data);
	if (new_node==NULL) return; //memory allocation failed
	
	//now insert at head
	if(head==NULL){
		//if linked is empty then head = tail = new node
		head = new_node;
		tail = head;
	}else{
		new_node->next = head ;//pointe new node to current head
		head = new_node;       //move head to new node
	}
	printf("\nPushed %d into Stack Successfully!!",input_data);
}
int is_empty(){
	return(head==NULL); // return 1 if list is empty else 0
}
void peek(){
	if(is_empty()){
		printf("\nTop=NULL...list is empty");	
	}else{
		printf("\nTop=%d",head->data);	
	}
}

void pop(){
	//step 0: check if the list is empty
	if(is_empty()){
		printf("\nStack is empty...cannot perform pop !!!");
		return;
	}
	//step 1: store the head in temp
	struct node* temp = head;
	int pop_item = head->data; //top is always head
	//step 2: move the current head to next node
	head = head->next;
	//step 3: free the temp
	free(temp);
	
	printf("\nPopped %d from Stack Successfully!!",pop_item);
}

void traverse(){
	struct node* temp;
	
	if (head==NULL){
		printf("\nMy Stack(Top=NULL) [ empty stack ]");
		return;
	}
	temp = head; //bcos this is my head node
	printf("\nMy Stack(Top=%d) [",head->data);
	while(temp!=NULL){
		printf("%d->",temp->data); //print the data
		temp = temp->next; //move to the next node
	}
	printf("null]");
}
void free_list(){
	struct node* temp=NULL;
	
	if (head!=NULL){
		while(head!=NULL){
			temp = head;       //to store the head
			head = head->next; //move to the next node
			free(temp);        //free the prev node(head)
		}
		printf("\nfreed all the nodes Successfully!!!");
	}	
}
