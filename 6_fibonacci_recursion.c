#include <stdio.h>

int fibnacci(int n,int a, int b, int c){
	if (n == 0){
		return 0;
	}
	printf("%d ",c);
	a = b;
	b = c;
	c = a+b;
	fibnacci(n-1,a,b,c);
}



int main(){
	int n;
	printf("Enter fibnacci number:");
	scanf("%d",&n);
	fibnacci(n,0,1,0);
}
