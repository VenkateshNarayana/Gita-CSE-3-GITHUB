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

int main(){
	struct node  node1, node2, node3, node4;
	//lets create a linked list using the above 4 nodes where node1 will be my head and node4 will be tail
	
	//head node is node1
	node1.data = 10;
	node1.next = &node2; //we will use & "address of" operator to store the address of node2
	
	node2.data = 20;
	node2.next = &node3; //connecting node2 to node3
	
	node3.data = 30;
	node3.next = &node4; //connecting node3 to node4
	
	//this is my tail
	node4.data = 40;
	node4.next = NULL; //tail will always have its pointer variable pointing to NULL - denoting end of linked list
	
	//traverse from head to tail
	printf("Linked list [");
	printf("%d->",node1.data);//node1
	printf("%d->",node1.next->data);//node2
	printf("%d->",node1.next->next->data);//node3
	printf("%d->",node1.next->next->next->data);//node4
	printf("null]");
	
	
	return 0;
}
