// Function to transpose a matrix

#include <stdio.h>

void transpose (int M[4][5], int N[5][4])
{
	int row, column;
	
	for (row=0; row<4; ++row)
		for (column=0; column<5; ++column) 
			N[column][row] = M[row][column];
		
	for (row=0; row<5; ++row) {
		for (column=0; column<4; ++column) 
			printf ("%5i ", N[row][column]);
		printf ("\n");
	}
}

int main (void)
{
	int matrix1[4][5] = 
	{
		{7, 16, 55, 13, 12},
		{12, 10, 52, 0, 7},
		{-2, 1, 2, 4, 9},
		{5, 25, 13, 12, 8}
	};
	int matrix2[5][4];
	void transpose (int M[4][5], int N[5][4]);
	
	transpose (matrix1, matrix2);
	
	
	return 0;
}