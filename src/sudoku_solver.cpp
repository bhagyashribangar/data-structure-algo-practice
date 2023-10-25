// Sudoku Puzzle
// TC: O(9^(N*N)), SC: O(N*N)

#include <iostream>
#include <vector>
using namespace std;

void printSudoku(const vector<vector<int>>& grid) {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }
}

bool isValid(vector<vector<int>>& grid, int row, int col, int num)
{
    for(int i=0;i<9;i++)
        {
            if (grid[i][col] == num)   return false;
            if (grid[row][i] == num)   return false;

            // Subgrids
            if (grid[3 * (row/3) + i/3][3 * (col/3) + i%3] == num)   return false;
        }
        return true;
}

bool solveSudoku(vector<vector<int>>& grid) {
    for (int row = 0; row < grid.size(); row++) {
        for (int col = 0; col < grid.size(); col++) {
            if (grid[row][col] == 0) {
                for (int num = 1; num <= 9; num++) {
                    // Check if is valid to enter number is a cell
                    if (isValid(grid, row, col, num)) {
                        grid[row][col] = num;
                        if (solveSudoku(grid) == true) {
                            return true;
                        }
                        grid[row][col] = 0;
                    }
                }
                return false;
            }
        }
    }
    return true;
}

int main()
{
    vector<vector<int>> grid = {
        {5, 3, 0, 0, 7, 0, 0, 0, 0},
        {6, 0, 0, 1, 9, 5, 0, 0, 0},
        {0, 9, 8, 0, 0, 0, 0, 6, 0},
        {8, 0, 0, 0, 6, 0, 0, 0, 3},
        {4, 0, 0, 8, 0, 3, 0, 0, 1},
        {7, 0, 0, 0, 2, 0, 0, 0, 6},
        {0, 6, 0, 0, 0, 0, 2, 8, 0},
        {0, 0, 0, 4, 1, 9, 0, 0, 5},
        {0, 0, 0, 0, 8, 0, 0, 7, 9}
    };

    solveSudoku(grid);
    printSudoku(grid);

    return 0;
}