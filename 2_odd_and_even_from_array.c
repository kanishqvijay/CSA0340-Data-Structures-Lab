#include <stdio.h>

int main(){
	int a[] = {1,2,3,4,5,6,7,8,9,0};
	int len = sizeof(a)/sizeof(a[0]);
	int i;
	for (i =0; i< len; i++){
		if (a[i]%2 == 0){
			printf("%d is an even number\n",a[i]);
		} else{
			printf("%d is an odd number\n",a[i]);
		}
	}
}
