/* Applications of Linked List
   2. Building a Queue
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

//insert operations - at tail
void enqueue(int);      //param1 = input data to fill the data part of the node

//delete operations - at head
void dequeue();         //delete the current head and move to next node of head

//is empty and peek operations
int is_empty();
void peek_front();
void peek_rear();

//traverse operation - from head to tail
void traverse_q();          //traverse the list from head to tail
void free_list();              //to free all the nodes in the list (prevent memory leak)      
int main(){
	//insert operataion
	enqueue(10);
	peek_front();
	peek_rear();
	enqueue(20);
	traverse_q();
	
	//dequeue operation
	dequeue();
	traverse_q();
	peek_front();
	peek_rear();
	
	dequeue(); //Q will become empty
	traverse_q(); 
	dequeue(); //will this work? NO - becauase Q underflow!!
	
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
int is_empty(){
	return (head==NULL); //return 1 if linked list is empty else 0
}
void peek_front(){
	if(is_empty()){
		printf("\nfront=NULL");
	}else{
		printf("\nfront=%d",head->data);
	}
}
void peek_rear(){
	if(is_empty()){
		printf("\nrear=NULL");
	}else{
		printf("\nrear=%d",tail->data);
	}
}

void enqueue(int input_data){
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
	printf("\nEnqued %d Successfully!!",input_data);
}
void dequeue(){
	//step 0: check if the list is empty
	if(head==NULL){
		printf("\nQueue is empty...cannot perform dequeue !!!");
		return;
	}
	//step 1: store the head in temp
	struct node* temp = head;
	int dq_item = head->data;
	//step 2: move the current head to next node
	head = head->next;
	//step 3: free the temp
	free(temp);
	
	printf("\nDequed %d Successfully!!",dq_item);
}

void traverse_q(){
	struct node* temp;
	
	if (head==NULL){
		printf("\nMy Queue(front=NULL,rear=NULL) [ empty Q ]");
		return;
	}
	temp = head; //bcos this is my head node
	printf("\nMy Queue(front=%d,rear=%d) [",head->data,tail->data);
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
