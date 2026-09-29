/* Double Linked list Applications
   3. Evaluate Polynomial Expression - add , Subtract, multiplication operations 
*/
#include<stdio.h>
#include<stdlib.h>

struct node{
	int    data;   //1. this will store data part
	struct node*  next;  //2. this is pointer variable to store the address of next node
	struct node*  prev;  //2. this is pointer variable to store the address of previous node
};
struct node* p_head=NULL;        //tracking the head node
struct node* p_tail=NULL;        //tracking the tail node

struct node* create_node(int,int); //param1 = fill the coefficient part of the node,
                                   //param2 = fill the exponent part of the node,

//insert operations - at head, at tail
void insert_at_head(struct node**,struct node**,int);      //param1 = input data to fill the data part of the node
void insert_at_tail(struct node**,struct node**,int);      //param1 = input data to fill the data part of the node


//traverse operation - from head to tail
void traverse_head(struct node*);          //traverse the list from head to tail
void traverse_tail(struct node*);          //traverse the list from tail to head
void free_list(struct node*);              //to free all the nodes in the list (prevent memory leak)      
int main(){
	
	//insert at tail
	insert_at_tail(&p_head,&p_tail,7); //send by the head and tail byref
	traverse_head(p_head);
	insert_at_tail(&p_head,&p_tail,5);
	traverse_head(p_head);
	insert_at_tail(&p_head,&p_tail,2);
	traverse_head(p_head);
	traverse_tail(p_tail);
	
	//insert at tail
	insert_at_head(&p_head,&p_tail,4);
	insert_at_head(&p_head,&p_tail,3);
	traverse_head(p_head);
	traverse_tail(p_tail);
	
	//free the nodes if the linked list is not empty
	free_list(p_head);
	
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
	new_node->data = input_data;  //store the data
	new_node->next  = NULL;   //becauase its a brand new node'
	new_node->prev  = NULL;   //becauase its a brand new node
	
	return new_node;
}
void insert_at_head(struct node** head, struct node** tail,int input_data){
	struct node* new_node = create_node(input_data);
	if (new_node==NULL) return; //memory allocation failed
	
	//now insert at head
	if(*head==NULL){
		//if linked is empty then head = tail = new node
		*head = new_node;
		*tail = *head;
	}else{
		new_node->next = *head ;    //point new node to current head
		(*head)->prev  = new_node; //point the old head's previous to new node
		*head          = new_node;           //move head to new node
	}
	printf("\nInserted Node(%d) at head Successfully!!",input_data);
}

void insert_at_tail(struct node** head, struct node** tail,int input_data){
	struct node* new_node = create_node(input_data);
	if (new_node==NULL) return; //memory allocation failed
	
	//now insert at head
	if(*tail==NULL){
		//if linked is empty then head = tail = new node
		*tail = new_node;
		*head = *tail;
	}else{
		//add the new node in the tail because we couldnt find the exponent
		(*tail)->next     = new_node;  //point the tail to new node
		new_node->prev = *tail;      //point my new node's previous to old tail
		*tail           = new_node;  //move old tail to new node
	}
	printf("\nInserted Node(%d) at tail Successfully!!",input_data);
}
void traverse_head(struct node* head){
	struct node* temp;
	
	if (head==NULL){
		printf("\nMy List [ empty list ]");
		return;
	}
	temp = head; //bcos this is my head node
	printf("\nMy List(head->tail) [ ");
	while(temp!=NULL){
		printf("%d->",temp->data); //print the term (5 X^2)
		temp = temp->next; //move to the next node
	}
	printf("null]");
}
void traverse_tail(struct node* tail){
	struct node* temp;
	
	if (tail==NULL){
		printf("\nMy List [ empty list ]");
		return;
	}
	temp = tail; //bcos we are traversing from tail to head node
	printf("\nMy List(X)(tail->head) [ ");
	while(temp!=NULL){
		printf("%d->",temp->data); //print the term (5 X^2)
		temp = temp->prev; //move to the next node
	}
	printf("null]");
}
void free_list(struct node* head){
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
