/*
check if a number is perfect or not
*/
#include<stdio.h>
#include<conio.h>
int isPerfectNumber(int);
int main(){
	int num;
	char ch;
	do{
		printf("\nEnter the num:");
		scanf("%d",&num);
		if(isPerfectNumber(num)){
			printf("PERFECT NUMBER");
		}else{
			printf("NOT PERFECT");
		}
		
		printf("\nDo you wish to continue?");
		ch = getch();
		printf("%c",ch);
	}while(ch=='Y' || ch=='y');
}
int isPerfectNumber(int num){
	int sum=0;
	for (int i=1;i<num;i++){
		if(num%i==0){
			sum +=i; //sum = sum+i
		}
	}
	if(sum==num){
		return 1; //true
	}
	return 0; //false
}
