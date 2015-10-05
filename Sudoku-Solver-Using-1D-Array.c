//
//  main.c
//  Created by DINESH KAUSHIK
//

#include <stdio.h>
#include <stdbool.h>

int solveSudoku(int sudokuGrid[] , int index);
int isValidEntry(int sudokuGrid[] , int index , int element);
int isValidEntryInSubSquare(int sudokuGrid[], int index , int element );
void printSudokuGrid (int grids[]);

int main(int argc, const char * argv[]) {
    
    // Input sudoku grid
    // NOTE: Change this 1 dimensional array in order to change input sudoku problem
    // Sample input of all zeros will also work
    int sudokuGrid[81] = { 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 ,
                           0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 ,
                           0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 ,
                           0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 ,
                           0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 ,
                           0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 ,
                           0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 ,
                           0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 ,
                           0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 ,
                         };

    printSudokuGrid(sudokuGrid);
    printf("\n");
    
    if (solveSudoku(sudokuGrid , 0 )) {
        printf("Sudoku Solved \n");
    }
    else {
        printf("No Solution Available \n");
    }
    printSudokuGrid(sudokuGrid);
    
    return 0;
}


// solve sudoku
int solveSudoku(int sudokuGrid[] , int index) {
    
    if(index < 81) {
        if(sudokuGrid[index] == 0) {
            
            for (int j = 1 ; j <= 9 ; j++) {
                
                if(isValidEntry(sudokuGrid , index , j)) {
                    
                    sudokuGrid[index]  = j;
                    if(solveSudoku(sudokuGrid , index+1 ))  {
                        return true;
                    }
                    else {
                        sudokuGrid[index]  = 0;
                    }
                }
            }
        }
        else {
            return  solveSudoku(sudokuGrid, index + 1);
        }
        return false;
    }
    return true;
}


// check if entry of element at index in sudoku is valid or not
int isValidEntry(int sudokuGrid[] , int index , int element) {
    
    // check if entry of element in row is valid or not
    for(int i = (index/9)*9; i < ((index/9) + 1)*9 ; i++) {
        
        if(element && sudokuGrid[i] == element) {
            return false;
        }
    }
    // check if entry of element in column is valid or not
    for(int i = 0; i < 9  ; i++) {
        
        int newIndex = (index%9) + (9 * i) ;
        if(element && sudokuGrid[newIndex] == element) {
            return false;
        }
    }
    return isValidEntryInSubSquare(sudokuGrid , index , element );
}


// check if entry of element in 3X3 sub square in sudoku is valid or not
int isValidEntryInSubSquare(int sudokuGrid[], int index ,int element )
{
    int finalIndex = 0;
    int subSquareIndex = ((index/27) * 3) + ((index % 27) % 9 ) / 3 ;
    
    for(int i = 0; i < 9 ; i++) {
        
        finalIndex = (27 * (subSquareIndex / 3)) + ((subSquareIndex % 3) * 3) + ((i / 3) * 6) + i ;
        
        if(sudokuGrid[finalIndex] == element) {
            
            return false;
        }
    }
    return true;
}


// print sudoku grid
void printSudokuGrid (int grids[]) {
    
    for (int i = 0 ; i < 81 ; i++) {
        
        if( i%9 == 0 ) {
            printf("\n");
        }
        printf("%d " ,grids[i]);
    }
    printf("\n");
}
