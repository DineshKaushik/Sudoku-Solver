//
//  main.c
//  Created by DINESH KAUSHIK
//

#include <stdio.h>
#include <stdbool.h>

int solveSudoku(int sudokuGrid[][9] , int row , int col);
int isValidEntry(int sudokuGrid[][9] , int row , int col , int element);
void printSudokuGrid (int grid[][9]);

int main(int argc, const char * argv[]) {
    
    // Input sudoku grid
    // NOTE: Change this 2 dimensional array in order to change input sudoku problem
    // Sample input of all zeros will also work
    int sudokuGrid[9][9] = {{ 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 },
                            { 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 },
                            { 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 },
                            { 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 },
                            { 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 },
                            { 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 },
                            { 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 },
                            { 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 },
                            { 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 }
                           };
    
    printSudokuGrid(sudokuGrid);
    printf("\n");
    
    if (solveSudoku(sudokuGrid , 0 , 0 )) {
        printf("Sudoku Solved \n");
    }
    else {
        printf("No Solution Available \n");
    }
    printSudokuGrid(sudokuGrid);
    
    return 0;
}


// solve sudoku
int solveSudoku(int sudokuGrid[][9] , int row , int col) {
    
    if(row<9 && col<9) {
        
        if(sudokuGrid[row][col] == 0) {
            
            for (int j = 1 ; j <= 9 ; j++) {
                
                if(isValidEntry(sudokuGrid, row, col, j)) {
                    
                    sudokuGrid[row][col] = j;
                    if((row+1)<9)
                    {
                        if(solveSudoku(sudokuGrid, row+1, col)) {
                            return true;
                        }
                        else {
                            sudokuGrid[row][col] = 0;
                        }
                    }
                    else if((col+1)<9)
                    {
                        if(solveSudoku(sudokuGrid, 0, col+1)) {
                            return true;
                        }
                        else {
                          sudokuGrid[row][col] = 0;
                        }
                    }
                }
            }
        }
        else {
            if((row+1)<9) {
                return solveSudoku(sudokuGrid, row+1, col);
            }
            else if((col+1)<9) {
                return solveSudoku(sudokuGrid, 0, col+1);
            }
            else {
                return true;
            }
        }
        return false;
    }
    return true;
}


// check if entry of element at index in sudoku is valid or not
int isValidEntry(int sudokuGrid[][9] , int row , int col , int element) {
    
    // find the start point of 3X3 sub square
    int rowSubSquareStart = (row/3) * 3;
    int colSubSquareStart = (col/3) * 3;
    
    for(int i=0; i<9; ++i)
    {
        // check if entry of element in row is valid or not
        if (sudokuGrid[row][i] == element) {
            return false;
        }
        
        // check if entry of element in column is valid or not
        if (sudokuGrid[i][col] == element) {
            return false;
        }
        
        // check if entry of element in 3x3 sub square in sudoku is valid or not
        if (sudokuGrid[rowSubSquareStart + (i%3)][colSubSquareStart + (i/3)] == element) {
            return false;
        }

    }
    return true;
}


// print sudoku grid
void printSudokuGrid (int grid[][9]) {
    
    for (int i = 0 ; i < 9 ; i++) {
            printf("\n");
            for(int j = 0; j < 9; j++) {
                printf("%d " ,grid[i][j]);
            }
        }
    printf("\n");
}
