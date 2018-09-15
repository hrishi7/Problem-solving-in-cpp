#include<iostream>
using namespace std;


bool FindUnassignedLocation(int grid[][9], int &row, int &col)
{
	for (row = 0; row < 9; row++)
		for (col = 0; col < 9; col++)
			if (grid[row][col] == 0)
				return true;
	return false;
}

/* Returns a boolean which indicates whether an assigned entry
in the specified row matches the given number. */
bool UsedInRow(int grid[][9], int row, int num)
{
	for (int col = 0; col < 9; col++)
		if (grid[row][col] == num)
			return true;
	return false;
}

/* Returns a boolean which indicates whether an assigned entry
in the specified column matches the given number. */
bool UsedInCol(int grid[][9], int col, int num)
{
	for (int row = 0; row < 9; row++)
		if (grid[row][col] == num)
			return true;
	return false;
}

/* Returns a boolean which indicates whether an assigned entry
within the specified 3x3 box matches the given number. */
bool UsedInBox(int grid[][9], int boxStartRow, int boxStartCol, int num)
{
	for (int row = 0; row < 3; row++)
		for (int col = 0; col < 3; col++)
			if (grid[row+boxStartRow][col+boxStartCol] == num)
				return true;
	return false;
}

/* Returns a boolean which indicates whether it will be legal to assign
num to the given row,col location. */
bool isSafe(int grid[][9], int row, int col, int num)
{
	/* Check if 'num' is not already placed in current row,
	current column and current 3x3 box */
	return !UsedInRow(grid, row, num) &&
		!UsedInCol(grid, col, num) &&
		!UsedInBox(grid, row - row%3 , col - col%3, num);
}

bool SolveSudoku(int grid[][9])
{
	int row, col;

	// If there is no unassigned location, we are done
	if (!FindUnassignedLocation(grid, row, col))
	return true; // success!

	// consider digits 1 to 9
	for (int num = 1; num <= 9; num++)
	{
		// if looks promising
		if (isSafe(grid, row, col, num))
		{
			// make tentative assignment
			grid[row][col] = num;

			// return, if success, yay!
			if (SolveSudoku(grid))
				return true;

			// failure, unmake & try again
			grid[row][col] = 0;
		}
	}
	return false; // this triggers backtracking
}

bool sudokuSolver(int grid[][9]){

  /* Don't write main().
   *  Don't read input, it is passed as function argument.
   *  Don't print output and return output as specified in the question
  */
  	return SolveSudoku(grid);

}




int main()
 {
    int board[9][9] = {{3, 0, 6, 5, 0, 8, 4, 0, 0},
                      {5, 2, 0, 0, 0, 0, 0, 0, 0},
                      {0, 8, 7, 0, 0, 0, 0, 3, 1},
                      {0, 0, 3, 0, 1, 0, 0, 8, 0},
                      {9, 0, 0, 8, 6, 3, 0, 0, 5},
                      {0, 5, 0, 0, 9, 0, 6, 0, 0},
                      {1, 3, 0, 0, 0, 0, 2, 5, 0},
                      {0, 0, 0, 0, 0, 0, 0, 7, 4},
                      {0, 0, 5, 2, 0, 6, 3, 0, 0}};
   cout<<sudokuSolver(board);
 }