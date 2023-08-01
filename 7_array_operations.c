#include <stdio.h>
#include <stdlib.h>

int* insert(int* a, int len,int index ,int item){
	int* n = calloc(len+1,sizeof(int));
	int i = 0;
	int inc = 0;
	for (i =0; i<len+1; i++){
		if (i == index){
			n[i] = item;
			inc--;
			continue;
		}else{
		n[i]= a[i+inc];
		}
	}
	return n;
}

int* del(int* a, int len, int index){
	int* n = calloc(len-1,sizeof(int));
	int i = 0;
	int inc = 0;
	for (i =0; i<len-1; i++){
		if (i == index){
			inc++;
		}
		if (!(index == 0 && i == 0)){
			n[i] = a[i+inc];
		}
		
	}
	return n;
}

void display(int* a, int len){
	int i;
	for (i =0; i<len; i++){
		printf("%d\n",a[i]);
	}
}

void main(){
	int a[] = {1,2,3,4};
	int* b = insert(a,4,1,5);
	display(b,5);
	b = del(b,5,1);
	display(b,4);
}
