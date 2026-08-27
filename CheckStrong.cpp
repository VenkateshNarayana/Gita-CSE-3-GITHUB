/*check if a number is Strong or not*/
#include<stdio.h>
int factorial(int); //function declaration
void checkStrong(int);
int main(){
	int num;
	printf("Enter the number:");
	scanf("%d",&num);
	checkStrong(num);
	
//	printf("factorial=%d",factorial(num));//function call
	return 0;//this if for main
}
//function definitions
int factorial(int num){
	int fact=1;
	for(int i=1;i<=num;i++){
		fact = fact*i;	
	}
	return fact;
}
void checkStrong(int num){
	int factSum=0;
	int origNum = num;
	while(num!=0){
		int digit = num%10;
		num/=10; //num=num/10
		factSum +=factorial(digit);//factSum=factSum + factorial(digit)
	}
	if(factSum==origNum){
		printf("IT IS STRONG NUMBER");
	}else{
		printf("NOT A STRONG NUMBER");
	}
}
