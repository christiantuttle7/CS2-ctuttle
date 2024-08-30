#include "gameOfLife.h"

/*
Function to clear terminal depending on OS
*/
void clearScreen()
{
    // use "cls" in windows and "clear" command in Mac and Linux
    #ifdef _WIN32
        system("clS");
    #else
        system("clear");
    #endif
}

/*
Function to initialize all cells in the board.
Takes in 2D array of pointers and size of array
Should create structs and populate the array
*/
void initCells(Cell* board[][10], int boardSize)
{
    for(int i = 0; i < boardSize; i++){
        for(int j = 0; j < boardSize; j++)
        {
                board[i][j] = new Cell;
        }
    }

    /*
    Cell** board = new Cell*[boardSize];
 
    for (int i = 0; i < boardSize; i++) {
 
        
        board[i] = new Cell[boardSize];
    }

    */

}


 
/*
Function to read the board from a file
Prompt for the file to read inside of the function
Structure of file should consist of 10 lines of 0 or 1 to indicate cell state
*/
void readBoard(Cell* board[][10], int boardSize) 
{
    /*
    string boardFileName;
    cout << "What is the name of the board file you would like to pick?";
    cin >> boardFileName;
    ifstream boardFile;

    */
    ifstream boardFile;
    boardFile.open("board1.txt");

    if (!boardFile) {
        cout << "Error opening file: " << "Board text" << endl;
        return;
    }
 
    for(int i = 0; i < boardSize; i++){
        for(int j = 0; j < boardSize; j++){
            boardFile >> board[i][j]->state;
            board[i][j]->x = i+1;
            board[i][j]->y = j+1;
        }
    }
    

}

/*
Function to print out all cells to cout
*/
void printCells(Cell* board[][10], int boardSize)
{
    for(int i = 0; i < boardSize; i++){
        for(int j = 0; j < boardSize; j++){
            cout << board[i][j]->state;
        }
        cout << endl;
    }
}

/*
Function to count the number of live neighbors for each cell.
Must use the x, y position stored with each cell to determine which neighbors they have
*/
void findNumNeighbors(Cell* board[][10], int boardSize, Cell* curCell) 
{

    //checks cell to the left of current cell
    if(curCell->x != 1){
        
        if(board[curCell->x-2][curCell->y-1]->state == 1){
            curCell->numLiveNeighbors += 1;
        }
    }

    //checks the cell to the upper left of current cell
    if(curCell->x != 1 && curCell->y != 1){
        if(board[curCell->x-2][curCell->y-2]->state == 1){
            curCell->numLiveNeighbors += 1;
        }
    }

    //checks the cell to the lower right of the current cell
    if(curCell->x != 1 && curCell->y != 10){
        if(board[curCell->x-2][curCell->y]->state == 1){
            curCell->numLiveNeighbors += 1;
        }
    }

    //checks the cell above the current cell
    if(curCell->y != 1){
        if(board[curCell->x-1][curCell->y-2]->state == 1){
            curCell->numLiveNeighbors += 1;
        }
    }

    //checks the cell to the upper right of the current cell
    if(curCell->x != 10 && curCell->y != 1){
        if(board[curCell->x][curCell->y-2]->state == 1){
            curCell->numLiveNeighbors += 1;
        }
    }

    //checks the cell to the right of the current cell
    if(curCell->x != 10){
        if(board[curCell->x][curCell->y-1]->state == 1){
            curCell->numLiveNeighbors += 1;
        }
    }

    //checks the cell to the lower right of the current cell
    if(curCell->x != 10 && curCell->y != 10){
        if(board[curCell->x-1][curCell->y-2]->state == 1){
            curCell->numLiveNeighbors += 1;
        }
    }

    //checks the cell below the current cell
    if(curCell->y != 10){
        if(board[curCell->x-1][curCell->y]->state == 1){
            curCell->numLiveNeighbors += 1;
        }
    }

}

/*
Function to update each cell's state based on number of neighbors
Must use following rules:

Any live cell with fewer than two live neighbors dies, as if by underpopulation.
Any live cell with two or three live neighbors lives on to the next generation.
Any live cell with more than three live neighbors dies, as if by overpopulation.
Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction.

Return if you updated cells or not to break out of while loop from main.
*/
bool updateCellState(Cell* board[][10], int boardSize) 
{
    //finds out how many live neighbors there are for each cell
    for(int i = 0; i < boardSize; i++){
        for(int j = 0; j < boardSize; j++){
            findNumNeighbors(board, boardSize, board[i][j]);
        }
    }

    for(int k = 0; k < boardSize; k++){
        for(int p = 0; p < boardSize; p++){

            //checking if cell is dead (and whether or not it gets to come back to life)
            if(board[k][p]->state == 0){
                if(board[k][p]->numLiveNeighbors == 3){
                    board[k][p]->state = 1; 
                }
            }

            //checking if cell is alive (and whether or not it will live on)
            if(board[k][p]->state == 1){
                if(board[k][p]->numLiveNeighbors < 2 || board[k][p]->numLiveNeighbors > 3){
                    board[k][p]->state = 0; 
                }
            }
        }
    }

    return false;
}