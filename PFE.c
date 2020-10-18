#include<stdio.h>
#include<string.h>
#include<math.h>
long double stack[100005];
int top=-1;
void push(long double x){
	top++;
	stack[top]=x;
}
long double pop(){
	top--;
	return stack[top+1];
}
int main(){
	int n,i,j,len,k;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		long double n1,n2,val,num;
		char str[100005],ch,st;
		top = -1;
		scanf("%c %[^\n]s",&st,str);
		len = strlen(str);
		for(j=0;j<len;){
			if(str[j]== '+' || str[j] == '*' || str[j] == '/' || str[j] == '-'){
				ch = str[j];
				n1 = pop();
				n2 = pop();
				switch(ch)
				{
					case '+': 
					val = n1+n2;
					break;
					case '*': 
					val = n1* n2;
					break;
					case '-': 
					val = n2-n1;
					break;
					case '/': 
					val = n2/n1;
					break;
				}
				push(val);
				j++;
			}
			else if(str[j] == ' ')
			{	j++;
			}
			else 
			{
				num = 0;
				while(str[j] != ' '){
				num = num*10;
				num+=str[j]-'0';
				j++;
				}
				push(num);
			 }
		}
		printf("%0.6Lf\n",stack[top]);
	}
	return 0;
}
