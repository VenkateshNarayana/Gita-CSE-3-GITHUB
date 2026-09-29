/* Double Linked list Applications
   3. Evaluate Polynomial Expression - add , Subtract, multiplication operations 
*/
#include<stdio.h>
#include<stdlib.h>

struct node{
	int           coeff; //1. this will store term's coefficient part
	int           exp;   //1. this will store term's exponent part
	struct node*  next;  //2. this is pointer variable to store the address of next node
	struct node*  prev;  //2. this is pointer variable to store the address of previous node
};
struct node* p_head=NULL;        //tracking the head node
struct node* p_tail=NULL;        //tracking the tail node

struct node* q_head=NULL;        //tracking the head node
struct node* q_tail=NULL;        //tracking the tail node

struct node* create_node(int,int); //param1 = fill the coefficient part of the node,
                                   //param2 = fill the exponent part of the node,

//insert operations - at head, at tail
void insert_at_head(struct node**,struct node**,int,int);      //param1 = input data to fill the data part of the node
void insert_at_tail(struct node**,struct node**,int,int);      //param1 = input data to fill the data part of the node
//evaluate polynomial
void evaluate_polynomial_add(struct node*,struct node*,struct node*,struct node*);//send p_head & p_tail and q_head & q_tail
void evaluate_polynomial_multiply(struct node*,struct node*,struct node*,struct node*);

//traverse operation - from head to tail
void traverse_head(struct node*);          //traverse the list from head to tail
void traverse_tail(struct node*);          //traverse the list from tail to head
void free_list(struct node*);              //to free all the nodes in the list (prevent memory leak)      
int main(){
	
	//create a polynomial p(x) = 5 X^2 + 3 X + 7
	//insert at tail
	insert_at_tail(&p_head,&p_tail,7,3); //send by the head and tail byref
//	traverse_head(p_head);
	insert_at_tail(&p_head,&p_tail,5,1);
//	traverse_head(p_head);
	insert_at_tail(&p_head,&p_tail,2,0);
	traverse_head(p_head);
//	traverse_tail(p_head);
	
	//create a polynomial q(x) = 5 X + 3
	//insert at head
	insert_at_tail(&q_head,&q_tail,5,1);
	insert_at_tail(&q_head,&q_tail,3,0);
	
	traverse_head(q_head);
	
	evaluate_polynomial_add(p_head,p_tail,q_head,q_tail);
	evaluate_polynomial_multiply(p_head,p_tail,q_head,q_tail);
	
	
	//free the nodes if the linked list is not empty
	free_list(p_head);
	free_list(q_head);
	
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
	new_node->next  = NULL;   //becauase its a brand new node'
	new_node->prev  = NULL;   //becauase its a brand new node
	
	return new_node;
}
void insert_at_head(struct node** head, struct node** tail,int coeff,int exp){
	struct node* new_node = create_node(coeff,exp);
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
	printf("\nInserted Term(%d,%d) at head Successfully!!",coeff,exp);
}

void insert_at_tail(struct node** head, struct node** tail,int coeff,int exp){
	struct node* new_node = create_node(coeff,exp);
	if (new_node==NULL) return; //memory allocation failed
	
	//now insert at head
	if(*tail==NULL){
		//if linked is empty then head = tail = new node
		*tail = new_node;
		*head = *tail;
	}else{
		//we will check if the exponent already exists in the list
		//if exist the add the coefficient else we add the term in the tail
		//search in the list first using temp
		struct node* temp = *head;
		while(temp!=NULL){
			if ((temp)->exp == new_node->exp){
				(temp)->coeff = (temp)->coeff + new_node->coeff;
				break;
			}
			temp = (temp)->next ; //move to next node until null
		}
		if(temp==NULL){
			//add the new node in the tail because we couldnt find the exponent
			(*tail)->next     = new_node;  //point the tail to new node
			new_node->prev = *tail;      //point my new node's previous to old tail
			*tail           = new_node;  //move old tail to new node
		}
	}
	printf("\nInserted term(%d,%d) at tail Successfully!!",coeff,exp);
}
void evaluate_polynomial_add(struct node* p_head,struct node* p_tail,struct node* q_head,struct node* q_tail){
	struct node* res_head=NULL;
	struct node* res_tail=NULL;
	//traverse the p_head and q_head until they reach last node
	while(p_head!=NULL && q_head!=NULL){
		//case 1
		if(p_head->exp == q_head->exp){
			int coeff = p_head->coeff + q_head->coeff;
			int exp = p_head->exp;
			insert_at_tail(&res_head,&res_tail,coeff,exp); //store it in res
			//move p_head and q_head to next node
			p_head = p_head->next;
			q_head = q_head->next;
		}else if(p_head->exp > q_head->exp){
			int coeff = p_head->coeff ;
			int exp = p_head->exp;
			insert_at_tail(&res_head,&res_tail,coeff,exp); //store it in res
			//move p_head to next node
			p_head = p_head->next;
		}else{
			int coeff =  q_head->coeff;
			int exp    = q_head->exp;
			insert_at_tail(&res_head,&res_tail,coeff,exp); //store it in res
			//move q_head to next node
			q_head = q_head->next;
		}
	}	
	//any leftover of p_head will be inserted here
	while(p_head!=NULL ){
		int coeff = p_head->coeff ;
		int exp = p_head->exp;
		insert_at_tail(&res_head,&res_tail,coeff,exp); //store it in res
		//move p_head to next node
		p_head = p_head->next;
	}
	while(q_head!=NULL ){
		int coeff = q_head->coeff ;
		int exp = q_head->exp;
		insert_at_tail(&res_head,&res_tail,coeff,exp); //store it in res
		//move q_head to next node
		q_head = q_head->next;
	}
	//print the polynomial addition result
	traverse_head(res_head);
	free_list(res_head); //free all the nodes
}
void evaluate_polynomial_multiply(struct node* p_head,struct node* p_tail,struct node* q_head,struct node* q_tail){
	struct node* res_head=NULL;
	struct node* res_tail=NULL;
	//traverse the p_head and q_head until they reach last node
	struct node* temp1 = p_head;
	struct node* temp2 = q_head;
	while(temp1!=NULL){ //p_head traversal
		temp2 = q_head; //very very critical step	
		//traverse p and q from head to tail
		while(temp2!=NULL ){//q_head traversal
			int coeff = temp1->coeff * temp2->coeff ;
			int exp   = temp1->exp + temp2->exp; //when variabale are multiplied power gets added 
			insert_at_tail(&res_head,&res_tail,coeff,exp); //store it in res
			//move q_head to next node
			temp2 = temp2->next;
		}
		temp1 = temp1->next; //move p_head to next node
	}
	
	//print the polynomial addition result
	traverse_head(res_head);
	free_list(res_head); //free all the nodes
}
void traverse_head(struct node* head){
	struct node* temp;
	
	if (head==NULL){
		printf("\nMy Polynomial(X) [ no terms ]");
		return;
	}
	temp = head; //bcos this is my head node
	printf("\nMy Polynomial(X)(head->tail) [ ");
	while(temp!=NULL){
		printf("%d X^%d",temp->coeff,temp->exp); //print the term (5 X^2)
		if (temp->next!=NULL)  printf(" + "); 
		temp = temp->next; //move to the next node
	}
	printf(" ]");
}
void traverse_tail(struct node* tail){
	struct node* temp;
	
	if (tail==NULL){
		printf("\nMy Polynomial(X) [ no terms ]");
		return;
	}
	temp = tail; //bcos we are traversing from tail to head node
	printf("\nMy Polynomial(X)(tail->head) [ ");
	while(temp!=NULL){
		printf("%d X^%d",temp->coeff,temp->exp); //print the term (5 X^2)
		if (temp->prev!=NULL)  printf(" + "); 
		temp = temp->prev; //move to the next node
	}
	printf(" ]");
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
