/* 1.finding the square of a given number
2. even or odd
3. largest between 2
4. special number
*/
#include<stdio.h>
int square(int); //function declaration
void findLargest(int,int);
int checkSpecial(int);
int main(){
	int n,num1,num2;
//	printf("Enter the number:");
//	scanf("%d",&n);
//	printf("Square = %d",square(n));//function call

//	printf("\nEnter the 2 numbers:");
//	scanf("%d %d",&num1,&num2);
//	
//	findLargest(num1,num2);
	
	printf("Enter the number:");
	scanf("%d",&n);
	if(checkSpecial(n)){
		printf("SPECIAL");
	}
	else{
		printf("NOT SPECIAL");
	}	
	
	return 0; //this is for main
}
//function definitions
int checkSpecial(int num){
	//extract the digits
	int temp = num;
	int sum = 0;
	int prd = 1;
	while(num!=0){
		int digit = num %10;
		sum += digit;
		prd *= digit;
		num /=10; //num = num /10
	}
	if((sum+prd)==temp){
		return 1;
	}
	return 0;
}
void findLargest(int num1,int num2){
	//using if else
	if (num1>num2){
		printf("\nnum1=%d is largest",num1);
	}else{
		printf("\nnum2=%d is largest",num2);
	}
	//using ternary
	printf("\n%d is largest",(num1>num2)?num1:num2);
}
int square(int num){
	return num*num;
}
