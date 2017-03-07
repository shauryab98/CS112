/*
	Name: Shaurya Gupta
	Roll No: 1601CS43
	Date: 7/03/207
	Objective: Takes strings and stores them in dynamically allocated array, then sorts and prints it back out.
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void freeMatrix(int**, int, int);
int deter(int**, int);
int calcMinor(int**, int, int , int );

int main(void) {
	int n, m, i, j;
	printf("Enter the size of the matrix ( n x m) =");
	scanf("%d%*c%d", &n, &m);
	while(getchar() != '\n') {}
	int** matrix = (int**) malloc(n*sizeof(int*));
	for(i = 0; i < n; i++) {
		matrix[i] = (int*) malloc(m*sizeof(int));
		printf("Enter the elements of row %d = ", i+1);
		for(j = 0; j < m; j++) 
			scanf("%d%*c", &matrix[i][j]);
	}
	if(n==m) {
		int ans = calcMinor(matrix,n,1,1);
		int** minorMat = (int**) malloc(n*sizeof(int*));
		for(i = 0; i < n; i++) {
			minorMat[i] = (int*) malloc(m*sizeof(int));
			for(j = 0; j < n; j++) {
				minorMat[i][j] = calcMinor(matrix,n,i,j);
			}
		}
		int determinant = deter(matrix,n);
		int minorx=0, minory=0;
		for(i = 0; i < n; i++) {
			for(j = 0; j < n; j++) {
				if(minorMat[i][j] > minorMat[minorx][minory]) {
					minorx = i; minory = j;
				}
			}
		}
		if(determinant != 0) {
			printf("Inverse exists. The inverse matrix is: \n");
			for(i = 0; i < n; i++) {
				for(j = 0; j < n; j++) {
					printf("%d/%d ", minorMat[j][i]*(int)pow(-1, (i+j)%2), determinant);
				}
				printf("\n");
			}	
		}
		printf("The matrix is square\n");
		printf("The position of the element with highest minor is  i = %d, j = %d\n", minorx+1, minory+1);
		freeMatrix(minorMat,n,n);		
	} else {
		printf("The matrix is not invertible\n");
		printf("The matrix is not square\n");
	}
	freeMatrix(matrix,n,m);
}

int deter(int** mat, int size) {
	if(size==1) return mat[0][0];
	int i;
	int ans = 0;
	for(i = 0; i < size; i++)
		ans += mat[i][0] * pow(-1,(i)%2) * calcMinor(mat,size,i,0);
	return ans;
}

int calcMinor(int** mat, int size, int r, int c) {
	int** newMat = (int**) malloc((size-1)*sizeof(int*));
	int i, j, newi=-1, newj;
	for(i = 0; i < size; i++) {
		newj = 0;
		if(i == r) continue;
		newi++;
		newMat[newi] = (int*) malloc((size-1)*sizeof(int));
		printf("Enter the elements of row %d = ", i+1);
		for(j = 0; j < size; j++) {
			if(j == c) continue;
			newMat[newi][newj] = mat[i][j];
			newj++;
		}
	}
	int ans = deter(newMat, size-1);
	freeMatrix(newMat, size-1, size-1);
	return ans;
}
void freeMatrix(int** mat, int rows, int cols) {
	int i;
	for(i = 0; i < rows; i++)
		free(mat[i]);
	free(mat);
}
