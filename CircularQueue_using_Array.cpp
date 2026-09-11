/* Circular Queue - It is  LDS where data management is managed using the FIFO(first in first out) principle
  Operations - 1.enqueue     - add the element using circular index formula [(rear + 1) % MAX_SIZE]
               2.dequeue     - delete the element using the circular index formula[(front + 1) % MAX_SIZE]
               3.peek_front  - get the first element of the Q
               4.peek_rear   - get the last element of the Q
               5.is_empty    - return 1 front==-1 else 0
               6.is_full     - return 1 when (rear + 1) % MAX_SIZE == front else 0
               7.traverse    - display the Q elements from front(head) to rear(tail). display the current size(rear+1 - front)
        
*/
#include<stdio.h>
#define MAX_SIZE 5
int front = -1; //-1; this is for tracking deletion from front
int rear = -1; //this is for tracking insertion from rear

int dequeue(int[]);      //param1=arrayname 
void enqueue(int[],int); //param1=arrayname ;param2=value
int is_full();           //return 1 when rear reaches MAX_SIZE -1 of the  Q  
int is_empty();          //return 1 when front>rear else 0
void traverse(int[]);    //param1=arrayname 
int peek_front(int[]);   //param1=arrayname ; return the first element of the Q
int peek_rear(int[]);    //param1=arrayname ; return the last element of the Q

int main(){
	int queue[MAX_SIZE]={0};//declare and initialize the Q with zero
	
	//enqueue
	enqueue(queue,10);
	traverse(queue);
	enqueue(queue,20);
	traverse(queue);
	enqueue(queue,30);
	traverse(queue);
	enqueue(queue,40);
	traverse(queue);
	enqueue(queue,50);
	
	traverse(queue);
	enqueue(queue,60); //will this be added to Q?NO because the Q is FULL
	
	
	traverse(queue);
	//peek front and rear
	printf("\nWho is in the front? %d",peek_front(queue));
	printf("\nWho is in the back? %d",peek_rear(queue));
	//dequeue
	printf("%s",(dequeue(queue)==-1)?"....":"\nPerformed dequeue sucessfully!!!");
	//traversal
	traverse(queue);
	printf("\nWho is in the front? %d",peek_front(queue));
	printf("\nWho is in the back? %d",peek_rear(queue));
	
	enqueue(queue,60); //will this be added to Q?-YES becuase it is circular queue
	traverse(queue);
	
	//dequeue
	printf("%s",(dequeue(queue)==-1)?"....":"\nPerformed dequeue sucessfully!!!");
		traverse(queue);
	//dequeue
	printf("%s",(dequeue(queue)==-1)?"....":"\nPerformed dequeue sucessfully!!!");
		traverse(queue);
	//dequeue
	printf("%s",(dequeue(queue)==-1)?"....":"\nPerformed dequeue sucessfully!!!");
		traverse(queue);
	//dequeue
	printf("%s",(dequeue(queue)==-1)?"....":"\nPerformed dequeue sucessfully!!!");
		traverse(queue);
	//dequeue
	printf("%s",(dequeue(queue)==-1)?"....":"\nPerformed dequeue sucessfully!!!");
		traverse(queue);
	
	//dequeue
	printf("%s",(dequeue(queue)==-1)?"....":"\nPerformed dequeue sucessfully!!!");//will this delete work? NO - beacuse the q is empty
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
int dequeue(int q[]){
	//check for underflow
	if(is_empty()){
		printf("\nQ underflow...cannot perform dequeue!!");
		return -1;
	}
	int dq_item = q[front];//store front value and then move index by 1
	if (front==rear){ //reset the indexes
		front = -1;
		rear  = -1;
	}else {
		//use the circular index formula
		front = (front + 1 )% MAX_SIZE;
	}
	return dq_item;
}
void traverse(int q[]){
	if(is_empty()){
		printf("Queue (CurrSize:0): []");	
		return;
	}
	int size = (front<=rear) ? (rear+1-front):MAX_SIZE - (rear+1-front);
	printf("Queue (CurrSize:%d): [",size);
	//traverse using circular index
	int i = front;
	while(1){
		printf("%d ",q[i]);
		i = ((i+1) % MAX_SIZE);
		if (i == (rear+1) % MAX_SIZE) break;
	}
	printf("]\n");
}
int is_empty(){         //return 1 when front>rear else 0
	return(front==-1); //return 1 else 0
}
int is_full(){           //return 1 when rear reaches MAX_SIZE -1 of the  Q	
	return ((rear + 1) % MAX_SIZE == front); //return 1 else 0
}
void enqueue(int q[],int value){
	//check for is overflow
	if(is_full()){
		printf("\nQ overflow...cannot perform enqueue of %d",value);
		return; //do not proceed further
	}
	if(front==-1){
		front = 0;
	}
	//apply the circular index formula
	rear = (rear+1) % MAX_SIZE;
	q[rear] = value; //inserted value at index 0
}
