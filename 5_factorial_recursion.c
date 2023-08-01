#include <stdio.h>

int factorial(int n){
	if (n == 1){
		return 1;
	}
	return n*factorial(n-1);
}



int main(){
	int a;
	printf("Enter factorial number:");
	scanf("%d",&a);
	printf("factorial of %d is: %d",a,factorial(a));
}
