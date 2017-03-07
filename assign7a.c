/*
	Name: Shaurya Gupta
	Roll No: 1601CS43
	Date: 7/03/2017
	Objective: Takes matrix and finds whether its square and invertible. If yes, then print inverse matrix. Also, find location of maximum minor.
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// this function frees given matrix of given size
void freeMatrix(int**, int, int);
// calculates the determinant of matrix of given size
int deter(int**, int);
// calculates minor of cell at given position of matrix of given size
int calcMinor(int**, int, int , int );

int main(void) {
	int n, m, i, j;
	printf("Enter the size of the matrix (n x m) =");
	scanf("%d%*c%d", &n, &m);
	while(getchar() != '\n') {} // remove newline
	// if invalid n, m
	if(n<=0 || m<=0) {
		printf("Invalid matrix size\n");
		return 0;
	}
	// allocate matrix
	int** matrix = (int**) malloc(n*sizeof(int*));
	// allocate each row and get input
	for(i = 0; i < n; i++) {
		matrix[i] = (int*) malloc(m*sizeof(int));
		printf("Enter the elements of row %d = ", i+1);
		for(j = 0; j < m; j++) 
			scanf("%d%*c", &matrix[i][j]);
	}
	// if square matrix:
	if(n==m) {
		// matrix of minors of the original matrix
		int** minorMat = (int**) malloc(n*sizeof(int*));
		for(i = 0; i < n; i++) {
			minorMat[i] = (int*) malloc(m*sizeof(int));
			for(j = 0; j < n; j++) {
				// fill minor matrix
				minorMat[i][j] = calcMinor(matrix,n,i,j);
			}
		}
		// find determinant
		int determinant = deter(matrix,n);
		// minorx and minory contain location of max minor found
		int minorx=0, minory=0;
		// find max minor
		for(i = 0; i < n; i++) {
			for(j = 0; j < n; j++) {
				if(minorMat[i][j] > minorMat[minorx][minory]) {
					minorx = i; minory = j;
				}
			}
		}
		// if determinant not zero, print inverse
		// inverse is transpose of cofactor matrix divided by matrix
		// cofactor matrix: c(i,j) = -1**(i+j)*minor(i,j)
		if(determinant != 0) {
			// determinantSign is used to make sure the -ve/-ve is displayed without - sign.
			int determinantSign = (determinant > 0) ? 1 : -1;
			determinant *= determinantSign;
			printf("Inverse exists. The inverse matrix is: \n");
			for(i = 0; i < n; i++) {
				for(j = 0; j < n; j++) {
					printf("%d/%d ", determinantSign*minorMat[j][i]*(int)pow(-1, (i+j)%2), determinant);
				}
				printf("\n");
			}	
		} else {
			printf("Inverse doesn't exist.\n");
		}
		printf("The matrix is square\n");
		printf("The position of the element with highest minor is  i = %d, j = %d\n", minorx+1, minory+1);
		// free the matrix
		freeMatrix(minorMat,n,n);		
	} 
	// else if not square matrix
	else {
		printf("The matrix is not invertible\n");
		printf("The matrix is not square\n");
	}
	// free the allocated matrix.
	freeMatrix(matrix,n,m);
}

int deter(int** mat, int size) {
	// base case
	if(size==1) return mat[0][0];
	// for > 1, we find determinant along col '0' by calling calcMinor
	int i;
	int ans = 0;
	for(i = 0; i < size; i++)
		ans += mat[i][0] * pow(-1,(i)%2) * calcMinor(mat,size,i,0);
	return ans;
}

int calcMinor(int** mat, int size, int r, int c) {
	// for 1 x 1 matrix, simply return 1
	if(size == 1) return 1;
	// newmat is the matrix formed by remove row r and col c.
	int** newMat = (int**) malloc((size-1)*sizeof(int*));
	int i, j, newi=-1, newj; // loop variables
	// make new matrix from mat.
	for(i = 0; i < size; i++) {
		newj = 0;
		if(i == r) continue;
		newi++;
		newMat[newi] = (int*) malloc((size-1)*sizeof(int));
		for(j = 0; j < size; j++) {
			if(j == c) continue;
			newMat[newi][newj] = mat[i][j];
			newj++;
		}
	}
	// minor of mat[r][c] is determinant of newMat
	int ans = deter(newMat, size-1);
	// free newMat
	freeMatrix(newMat, size-1, size-1);
	return ans;
}
void freeMatrix(int** mat, int rows, int cols) {
	// checked with valgrind -- no leaks possible
	int i;
	for(i = 0; i < rows; i++)
		free(mat[i]);
	free(mat);
}
