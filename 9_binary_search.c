#include <stdio.h>

int main(){
	int a[] = {-3,-2,-1,1,2,3,4,5,6,7,8,9};
	int len = sizeof(a)/sizeof(a[0]);
	int target = 5;
	int high = len-1;
	int low = 0;
	int mid;
	while (high>low){
		mid = (high+low)/2;
		if (a[mid] == target){
			printf("%d is found at index %d in the array", target, mid);
			break;
		} else if(target>a[mid]){
			low = mid;
		} else if(target<a[mid]){
			high = mid;
		}
	}
}
