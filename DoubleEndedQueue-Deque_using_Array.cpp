/* Double Ended Queue - It is  LDS where data management is managed using the FIFO(first in first out) principle
  Operations - 1.add_first    - add the element in the front(right shifting)
               2.add_last     - add the element in the rear(increment the rear index by 1)
			   3.remove_first - delete the element from the front (left shifting)
			   4.remove_last  - delete the element from the rear(by decrementing the rear index by 1)
               5.peek_front   - get the first element of the Q
               6.peek_rear    - get the last element of the Q
               7.is_empty     - return 1 rear==-1 else 0
			   8.is_full      - return 1 when rear reaches MAX_SIZE -1 of the  Q
               9.traverse     - display the Q elements from front(head) to rear(tail). display the current size(rear+1 - front)
*/
#include<stdio.h>
#define MAX_SIZE 5
int front = 0; //-1; this is for tracking deletion from front
int rear = -1; //this is for tracking insertion from rear

int  remove_first(int[]);      //param1=arrayname 
int  remove_last(int[]);      //param1=arrayname 
void add_first(int[],int); //param1=arrayname ;param2=value
void add_last(int[],int); //param1=arrayname ;param2=value

int is_full();           //return 1 when rear reaches MAX_SIZE -1 of the  Q  
int is_empty();          //return 1 when front>rear else 0
void traverse(int[]);    //param1=arrayname 
int peek_front(int[]);   //param1=arrayname ; return the first element of the Q
int peek_rear(int[]);    //param1=arrayname ; return the last element of the Q

int main(){
	int queue[MAX_SIZE]={0};//declare and initialize the Q with zero
	
	//enqueue
	add_first(queue,10);
	traverse(queue);
	add_first(queue,20);
	traverse(queue);
	add_first(queue,30);
	traverse(queue);
	add_first(queue,40);
	traverse(queue);
	add_first(queue,50);
	
	traverse(queue);
	add_last(queue,60); //will this be added to Q?NO because rear = MAX_SIZE -1
	
	
	traverse(queue);
	//peek front and rear
	printf("\nWho is in the front? %d",peek_front(queue));
	printf("\nWho is in the back? %d",peek_rear(queue));
	//dequeue
	printf("%s",(remove_first(queue)==-1)?"....":"\nPerformed dequeue sucessfully!!!");
	//traversal
	traverse(queue);
	printf("\nWho is in the front? %d",peek_front(queue));
	printf("\nWho is in the back? %d",peek_rear(queue));
	
	
	add_last(queue,60); //will this be added to Q?-YES, because we have removed 1 element above
	traverse(queue);
	
	return 0;//for the main
}
int peek_front(int q[]){   //param1=arrayname ; return the first element of the Q
	if(is_empty()){
		return -1;
	}
	return q[front];
}
int peek_rear(int q[]){    //param1=arrayname ; return the last element of the Q
	if(is_empty()){
		return -1;
	}
	return q[rear];
}
int remove_first(int q[]){
	//check for underflow
	if(is_empty()){
		printf("\nQ underflow...cannot perform dequeue!!");
		return -1;
	}
	//perform left shifting
	int dq_item=q[front];//store front value and then move index by 1
	for(int i=front;i<=rear;i++){
		q[i] = q[i+1]; //left shift
	}
	q[rear--]=0;//make the last element 0 after left shifting & decrement the index by 1
	return dq_item;
}
int remove_last(int q[]){
	//check for underflow
	if(is_empty()){
		printf("\nQ underflow...cannot perform dequeue!!");
		return -1;
	}
	int dq_item=q[rear--];//store rear value and then decrement the index by 1
	return dq_item;
}
void traverse(int q[]){
	printf("Queue (CurrSize:%d): [",(rear+1-front));
	for(int i=front;i<=rear;i++){
		printf("%d ",q[i]);
	}
	printf("]\n");
}
int is_empty(){         //return 1 when front>rear else 0
	return(rear==-1); //return 1 else 0
}
int is_full(){           //return 1 when rear reaches MAX_SIZE -1 of the  Q	
	return(rear==MAX_SIZE-1); //return 1 else 0
}
void add_first(int q[],int value){
	//check for is overflow
	if(is_full()){
		printf("\nQ overflow...cannot perform enqueue of %d",value);
		return; //do not proceed further
	}
	//perform right shifting
	for(int i=rear;i>=front;i--){
		q[i+1] = q[i]; //right shift
	}
	q[front]=value; //inserted value at index 0
	rear++; //increment the rear index by 1
	
}
void add_last(int q[],int value){
	//check for is overflow
	if(is_full()){
		printf("\nQ overflow...cannot perform enqueue of %d",value);
		return; //do not proceed further
	}
	q[++rear]=value; //inserted value at index 0
}
