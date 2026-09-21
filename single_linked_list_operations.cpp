/* linked list - It is a linear data structure where elements(nodes) are stroed in scattered memory and are connected using pointers.
				 These nodes have 2 parts - 1. data (primitive,non-primitive) and 2.pointer(reference variable)
   Operations :	1.Insert   - (3 types - at begin, at end, at middle),
   				2.Delete   - (3 types - at begin, at end, at middle),
   				3.Traverse - visit all the nodes
   				4.Search   - finding a node	
*/
#include<stdio.h>
#include<stdlib.h>

struct node{
	int           data; //1. this is store data part
	struct node*  next; //2. this is pointer variable to store the address of another node
};
struct node* head=NULL; //tracking the head node
struct node* tail=NULL; //tracking the tail node
struct node* create_node(int); //param1 = input data to fill the data part of the node
//insert operations - at head, at tail, at position
void insert_at_head(int);      //param1 = input data to fill the data part of the node
void insert_at_tail(int);      //param1 = input data to fill the data part of the node
void traverse_list();          //traverse the list from head to tail

int main(){
	
	//insert at head
	insert_at_head(10);
	traverse_list();
	insert_at_head(20);
	traverse_list();


	//insert at tail
	insert_at_tail(40);
	traverse_list();
	insert_at_tail(50);
	traverse_list();
	
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
void insert_at_head(int input_data){
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
}

void insert_at_tail(int input_data){
	struct node* new_node = create_node(input_data);
	if (new_node==NULL) return; //memory allocation failed
	
	//now insert at head
	if(tail==NULL){
		//if linked is empty then head = tail = new node
		tail = new_node;
		head = tail;
	}else{
		tail->next = new_node; //point the tail to new node
		tail = new_node;       //move tail to new node
	}
}
void traverse_list(){
	struct node* temp;
	temp = head; //bcos this is my head node
	printf("\nMy Linked list(head=%d,tail=%d) [",head->data,tail->data);
	while(temp!=NULL){
		printf("%d->",temp->data); //print the data
		temp = temp->next; //move to the next node
	}
	printf("null]");
}
