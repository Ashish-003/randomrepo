#include<stdio.h>
#include<stdlib.h>
long long int len,count=0;
typedef struct node{
	int data;
	struct node* next;
}mode;
mode* top;
void push(int data){
	mode* temp = (mode*)(malloc(sizeof(mode)));
	temp -> data = data;
	temp -> next = top;
	top = temp;
	count ++;
}
void pop(){
	mode* temp = (mode*)(malloc(sizeof(mode)));
	temp = top;
	top = top -> next;
	temp  = NULL;
	free(temp);
	count--;
}
void display(){
	mode* temp = (mode*)(malloc(sizeof(mode)));
	temp = top;
	while(temp!= NULL){
		printf("%d ",temp -> data);
		temp = temp ->next;
	}
} 
int main(){
	long long int i,next,ele;
	scanf("%lld",&len);
	long long int arr[len],left[len],right[len];
	for(i=0;i<len;i++){
		scanf("%lld",&arr[i]);
		left[i] = 0;
		right[i] = 0;
	}
	push(arr[0]);
	for(i=1;i<len;i++){
		next = arr[i];
		if(count > 0){
			ele = top -> data;
			while(ele<next)
			{
				left[]
			}
			if(ele>next)
			{
				push(next);
			}
		}
	}
}