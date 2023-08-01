#include <stdio.h>

int main(){
	int a = 0;
	printf("Enter factorial number:");
	scanf("%d",&a);
	int i;
	int res;
	for (i = 1; i<=a; i++){
		res *= i;
	}
	printf("Factorial of %d is: %d",a,res);
}
