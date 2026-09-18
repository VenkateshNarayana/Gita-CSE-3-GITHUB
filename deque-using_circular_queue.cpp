#include <stdio.h>

#define MAX_SIZE 5

int deque[MAX_SIZE];

int front = 0;
int size = 0;

void show_menu();

void peek_front();
void peek_rear();

void insert_front(int);
void insert_rear(int);

void delete_front();
void delete_rear();

void traverse();

/*--------------------------------------------------
    Main Function
--------------------------------------------------*/
int main()
{
    int choice;
    int value;

    while (1)
    {
        show_menu();
		scanf("%d", &choice);
        switch (choice)
        {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);

                insert_front(value);
                break;


            case 2:
                printf("Enter value: ");
                scanf("%d", &value);

                insert_rear(value);
                break;


            case 3:
                delete_front();
                break;


            case 4:
                delete_rear();
                break;


            case 5:
                peek_front();
                break;


            case 6:
                peek_rear();
                break;


            case 7:
                traverse();
                break;


            case 8:
                printf("\nProgram terminated.\n");
                return 0;


            default:
                printf("\nInvalid choice! Try again.\n");
        }
    }

    return 0;
}
void show_menu(){
	printf("\n\n==========================================");
    printf("\n       DEQUE USING CIRCULAR ARRAY");
    printf("\n============================================");

    printf("\n1. Insert at Front   2. Insert at Rear");
    printf("\n3. Delete from Front 4. Delete from Rear");
    printf("\n5. Peek Front        6. Peek Rear");
    printf("\n7. Display           8. Exit");
    printf("\n\nEnter your choice: ");
    
}
/*--------------------------------------------------
    Check whether Deque is Empty
--------------------------------------------------*/
int is_empty(){
    return size == 0;
}

/*--------------------------------------------------
    Check whether Deque is Full
--------------------------------------------------*/
int is_full(){
    return size == MAX_SIZE;
}


/*--------------------------------------------------
    Insert element at Front
--------------------------------------------------*/
void insert_front(int value){
    if (is_full()){
        printf("\nDeque is FULL. Cannot insert %d\n", value);
        return;
    }

    /*
       Move front one position backward
       using circular formula
    */
    front = (front - 1 + MAX_SIZE) % MAX_SIZE;

    deque[front] = value;

    size++;

    printf("\n%d inserted at FRONT\n", value);
}


/*--------------------------------------------------
    Insert element at Rear
--------------------------------------------------*/
void insert_rear(int value){
    int rear;

    if (is_full()){
        printf("\nDeque is FULL. Cannot insert %d\n", value);
        return;
    }

    /*
       Calculate rear position
    */
    rear = (front + size) % MAX_SIZE;

    deque[rear] = value;

    size++;

    printf("\n%d inserted at REAR\n", value);
}


/*--------------------------------------------------
    Delete element from Front
--------------------------------------------------*/
void delete_front(){
    int value;
    if (is_empty()){
        printf("\nDeque is EMPTY. Nothing to delete.\n");
        return;
    }

    value = deque[front];

    /*
       Move front one position forward
    */
    front = (front + 1) % MAX_SIZE;

    size--;

    printf("\n%d deleted from FRONT\n", value);
}

/*--------------------------------------------------
    Delete element from Rear
--------------------------------------------------*/
void delete_rear(){
    int rear;
    int value;

    if (is_empty())
    {
        printf("\nDeque is EMPTY. Nothing to delete.\n");
        return;
    }

    /*
       Calculate current rear position
    */
    rear = (front + size - 1) % MAX_SIZE;

    value = deque[rear];

    size--;

    printf("\n%d deleted from REAR\n", value);
}

/*--------------------------------------------------
    Display Front Element
--------------------------------------------------*/
void peek_front(){
    if (is_empty())
    {
        printf("\nDeque is EMPTY\n");
        return;
    }

    printf("\nFront element = %d\n", deque[front]);
}


/*--------------------------------------------------
    Display Rear Element
--------------------------------------------------*/
void peek_rear(){
    int rear;

    if (is_empty())
    {
        printf("\nDeque is EMPTY\n");
        return;
    }

    rear = (front + size - 1) % MAX_SIZE;

    printf("\nRear element = %d\n", deque[rear]);
}


/*--------------------------------------------------
    Display Deque
--------------------------------------------------*/
void traverse(){
    int i;
    int index;

    if (is_empty()){
        printf("\nDeque is EMPTY\n");
        return;
    }

    printf("\nDeque elements(Size=%d):Front = %d Rear  = %d\n[", size, front,(front + size - 1) % MAX_SIZE);
    for (i = 0; i < size; i++){
        index = (front + i) % MAX_SIZE;
        printf("%d ", deque[index]);
    }
	printf("]");
}


