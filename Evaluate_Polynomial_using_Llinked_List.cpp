/* Linked list Applications
   3. Evaluate Polynomial Expression - add , Subtract, multiplication operations 
*/
#include<stdio.h>
#include<stdlib.h>

struct node{
	int           coeff; //1. this will store term's coefficient part
	int           exp;   //1. this will store term's exponent part
	struct node*  next; //2. this is pointer variable to store the address of another node
};
struct node* head=NULL;        //tracking the head node
struct node* tail=NULL;        //tracking the tail node
struct node* create_node(int,int); //param1 = fill the coefficient part of the node,
                                   //param2 = fill the exponent part of the node,

//insert operations - at head, at tail
void insert_at_head(int,int);      //param1 = input data to fill the data part of the node
void insert_at_tail(int,int);      //param1 = input data to fill the data part of the node

//traverse operation - from head to tail
void traverse_list();          //traverse the list from head to tail
void free_list();              //to free all the nodes in the list (prevent memory leak)      
int main(){
	
	//create a polynomial p(x) = 5 X^2 + 3 X + 7
	//insert at head
	insert_at_tail(5,2);
	traverse_list();
	insert_at_tail(3,1);
	traverse_list();
	insert_at_tail(7,0);
	traverse_list();
	
	//free the nodes if the linked list is not empty
	free_list();
	return 0;
}
struct node* create_node(int coeff,int exp){
	//create the node using malloc
	struct node* new_node = (struct node*) malloc(sizeof(struct node));
	
	//check if memory allocation failed?
	if(new_node==NULL){
		printf("memory allocation failed...");
		return NULL;
	}
	//if new node is created successfull then assign the data 
	new_node->coeff = coeff;  //store the coeff part
	new_node->exp   = exp;    //store the exponent part
	new_node->next  = NULL;   //becauase its a brand new node
	return new_node;
}
void insert_at_head(int coeff,int exp){
	struct node* new_node = create_node(coeff,exp);
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
	printf("\nInserted Term(%d,%d) at head Successfully!!",coeff,exp);
}

void insert_at_tail(int coeff,int exp){
	struct node* new_node = create_node(coeff,exp);
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
	printf("\nInserted term(%d,%d) at tail Successfully!!",coeff,exp);
}

void traverse_list(){
	struct node* temp;
	
	if (head==NULL){
		printf("\nMy Polynomial(X) [ no terms ]");
		return;
	}
	temp = head; //bcos this is my head node
	printf("\nMy Polynomial(X) [ ");
	while(temp!=NULL){
		printf("%d X^%d",temp->coeff,temp->exp); //print the term (5 X^2)
		if (temp->next!=NULL)  printf(" + "); 
		temp = temp->next; //move to the next node
	}
	printf(" ]");
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
