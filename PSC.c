#include<stdio.h>
int stack[105],top=-1;
void push(int x){
	top++;
	stack[top] = x;
}
void pop(){
	top--;
}
int main(){
	int t,n,i,q,j,flag=0;
	scanf("%d",&t);
	while(t--){
		top = -1;
		q = 1;
		j = 0;
		flag = 0;
		for(i=0;i<105;i++){
			stack[i] = 0;
		}
		scanf("%d",&n);
		int arr[n],f[n];
		for(i=0;i<n;i++){
			scanf("%d",&arr[i]);
		}
		i=0;
		for(q=1;q<=n;)
			{ 
				if(q == arr[i]){
				q++;
				i++;
				//printf("alpp\n");
			}
			else if( q == stack[top] && top > -1){
				q++;
				pop();
				//printf("b-%d\n",q);
			}
			else{
				push(arr[i]);
				i++;
				//printf("a - %d %d\n",q,stack[top]);
			}
			if(top>1){
			if(stack[top]>stack[top-1]){
				//printf("oo\n");
				flag = 1;
				break;
			}
	}
}

//printf("%d",q);
		if(flag == 0 || q == n+1)
			printf("Yes\n");
		else if(q != n+1 || flag == 1)
			printf("No\n");
	}
	return 0;
}