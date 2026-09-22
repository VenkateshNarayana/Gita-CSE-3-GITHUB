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
struct node* head=NULL;        //tracking the head node
struct node* tail=NULL;        //tracking the tail node
struct node* create_node(int); //param1 = input data to fill the data part of the node

//insert operations - at head, at tail, at position
void insert_at_head(int);      //param1 = input data to fill the data part of the node
void insert_at_tail(int);      //param1 = input data to fill the data part of the node

//delete operations - at head, at tail, at position
void delete_at_head();         //delete the current head and move to next node of head
void delete_at_tail();         //delete the current tail and move to previous node of tail

//traverse operation - from head to tail
void traverse_list();          //traverse the list from head to tail
void free_list();              //to free all the nodes in the list (prevent memory leak)      
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
	
	//delete at head
	delete_at_head();
	traverse_list();
	
	//delete at tail
	delete_at_tail();
	traverse_list();
	
//	//delete at head
//	delete_at_head();
//	traverse_list();
//	
//	//delete at tail
//	delete_at_tail();
//	traverse_list();
	
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
	printf("\nInserted %d at head Successfully!!",input_data);
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
	printf("\nInserted %d at tail Successfully!!",input_data);
}
void delete_at_head(){
	//step 0: check if the list is empty
	if(head==NULL){
		printf("\nList is empty...cannot perform delete operation!!!");
		return;
	}
	//step 1: store the head in temp
	struct node* temp = head;
	//step 2: move the current head to next node
	head = head->next;
	//step 3: free the temp
	free(temp);
	
	printf("\nDeleted node at head Successfully!!");
}
void delete_at_tail(){
	struct node* temp = NULL;
	//step 0: check if the list is empty
	if(tail==NULL){
		printf("\nList is empty...cannot perform delete operation!!!");
		return;
	}
	//chec if there is only 1 node
	if (head==tail){
		//step 0.1: store the head in temp
		temp = head;
		//step 0.2: set the head and tail to NULL (empty list)
		head = tail = NULL;
		//step 0.3: free the temp
		free(temp);
	}else{
		//step 1: store the tail in temp_tail
		struct node* temp_tail = tail;
		//step 2: traverse to 1 node before tail
		temp = head;
		while(temp->next!=tail){
			temp = temp->next;
		}
		//we reached 1 node before tail
		printf("\nNode before tail = %d",temp->data);
		//step 3:store NULL in temp's next because it is going to become my tail node
		temp->next = NULL;
		tail = temp; //move tail to temp(which is now the last node)
		//step 4: free the temp_tail
		free(temp_tail);
	}
	printf("\nDeleted node at tail Successfully!!");
}
void traverse_list(){
	struct node* temp;
	
	if (head==NULL){
		printf("\nMy Linked list(head=NULL,tail=NULL) [ empty list ]");
		return;
	}
	temp = head; //bcos this is my head node
	printf("\nMy Linked list(head=%d,tail=%d) [",head->data,tail->data);
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
