#include <stdio.h>

int main(){
	int n = 0;
	printf("Enter fibonacci:");
	scanf("%d",&n);
	int i;
	int a,b,c;
	a=0;
	b=1;
	c=0;
	for (i = 0; i<n; i++){
		printf("%d ",c);
		a = b;
		b = c;
		c = a+b;
	}
}
