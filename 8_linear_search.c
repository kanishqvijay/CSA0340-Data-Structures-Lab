#include <stdio.h>

int main(){
	int a[] = {1,2,3,4,5,6,7,8,9,0};
	int len = sizeof(a)/sizeof(a[0]);
	int i = 0;
	int target = 5;
	for (i = 0; i<len; i++){
		if (a[i]==target){
			printf("%d has been found at %dth index in the array", target,i);
		}
	}
}
