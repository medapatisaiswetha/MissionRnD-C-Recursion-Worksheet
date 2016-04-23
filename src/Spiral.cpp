/*
Write a program to generate elements of a matrix in spiral order.
Store the generated elements in single dimensional array and return that array.

Directions for Spiral are : Go Right ,Go Down ,Go Left, Go Up
Ex:

Matrix:
1	2	3
4	5	6
7	8	9

Spiral order:
1	2	3	6	9	8	7	4	5

Given matrix is a two dimensional array(input_array) with dimensions rows, columns.
If rows, columns are invalid then return NULL.
If input_array is NULL then return NULL.

Example Input :
int board[2][3]={
{4,6,7},
{1,3,8}
};
spiral(2,2,(int **)board); // Rows followed by columns followed by board

Example Output : Return an array consisting of {4,6,7,8,3,1};

Note : Check the function Parameters ,Its a double pointer .

*/


#include "stdafx.h"
#include<stdlib.h>

int *spiral(int rows, int columns, int **input_array)
{
	int *output = (int *)malloc(rows * columns *sizeof(int *));

	int i, k = 0, l = 0, count = 0;
	if (rows <= 0 || columns <= 0 || input_array == NULL)
		return NULL;
	while (k < rows && l < columns)
	{
		for (i = l; i < columns; ++i)
		{
			output[count] = input_array[k][i];
			count++;
		}
		k++;
		for (i = k; i < rows; ++i)
		{
			output[count] = input_array[i][columns - 1];
			count++;
		}
		columns--;
		if (k < rows)
		{
			for (i = columns - 1; i >= l; --i)
			{
				output[count] = input_array[rows - 1][i];
				count++;
			}
			rows--;
		}
		if (l < columns)
		{
			for (i = rows - 1; i >= k; --i)
			{
				output[count] = input_array[i][l];
				count++;
			}
			l++;
		}
	}
	return output;
}
