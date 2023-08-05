#include<stdio.h>

void sort(int a[],int n){
	int i,j,temp;
	for(i = 1;i < n;i ++){
		temp = a[i];
		j = i-1;
	while(j >= 0 && temp <= a[j]){
		a[j+1] = a[j];
		j = j-1;
	}
	a[j+1] = temp;
	}
}

void print(int a[], int n){
	int i;
	for(i = 0; i < n;i++){
		printf("%d ",a[i]);
	}
}

void main(){
	int a[] = {3,5,1,4,91,657,2};
	int n = sizeof(a)/sizeof(a[0]);
	printf("Before sorting :\n");
	print(a,n);
	sort(a,n);
	printf("\nAfter sorting :\n");
	print(a,n);
}
