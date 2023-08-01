#include <stdio.h>

int main(){
	int a[3][3];
	int b[3][3];
	int c[3][3];
	int i;
	int j;
	int k;
	printf("Enter value of Matrix A:\n");
	for (i = 0; i<2; i++){
		for (j = 0; j<2; j++){
			scanf("%d",&a[i][j]);
		}
	}
	printf("\nEnter value of Matrix B:\n");
	for (i = 0; i<2; i++){
		for (j = 0; j<2; j++){
			scanf("%d",&b[i][j]);
		}
	}
	for(i = 0; i<2;i++){
		for(j = 0; j<2; j++){
			c[i][j] = 0;
			for (k = 0; k<2; k++){
				c[i][j] += a[i][k]*b[k][j];
			}
		}
	}
	printf("\n--------(Matrix A) X (Matrix B)------------\n");
	for (i = 0; i<2; i++){
		printf("|");
		for (j = 0; j<2; j++){
			printf("(%d,%d):%d ",i,j,c[i][j]);
		}
		printf("|\n");
	}
}
