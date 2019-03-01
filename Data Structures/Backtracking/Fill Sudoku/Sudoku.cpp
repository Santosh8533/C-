#include<iostream>

using namespace std;

#define N 9
#define UNASSIGNED 0

bool FindUnassignedLocation(int grid[N][N],int& row, int& col){
    for(row=0;row<N;row++){
        for(col=0;col<N;col++){
            if(grid[row][col] ==  UNASSIGNED){
                return true;
            }
        }
    }
    return false;
}

bool isSafe(int grid[N][N],int row,int col,int num){
    //used in col?
    for(int i=0;i<N;i++){
        if(grid[i][col]==num)return false;
    }
    //used in row?
    for(int j=0;j<N;j++){
        if(grid[row][j]==num)return false;
    }
    //used in box?
    int boxStartRow = row - row%3;
    int boxStartCol = col - col%3;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(grid[i+boxStartRow][j+boxStartCol]==num)
                return false;
        }
    }
    //grid shall be unassigned
    if(grid[row][col]!=UNASSIGNED)return false;

    return true;
}
bool solveSudoku(int grid[N][N]){
    int row, col;

    //find for unassigned location
    if(!FindUnassignedLocation(grid,row,col))
        return true;

    for(int num=1;num<=N;num++){
        if(isSafe(grid,row,col,num)){
            grid[row][col] = num;

        if(solveSudoku(grid))
            return true;

        grid[row][col] = UNASSIGNED;

        }
    }

}

/* A utility function to print grid  */
void printGrid(int grid[N][N])
{
    for (int row = 0; row < N; row++)
    {
       for (int col = 0; col < N; col++)
             cout<<grid[row][col];
        cout<<endl;
    }
}

int main(){
    int grid[N][N] = {{3, 0, 6, 5, 0, 8, 4, 0, 0},
                      {5, 2, 0, 0, 0, 0, 0, 0, 0},
                      {0, 8, 7, 0, 0, 0, 0, 3, 1},
                      {0, 0, 3, 0, 1, 0, 0, 8, 0},
                      {9, 0, 0, 8, 6, 3, 0, 0, 5},
                      {0, 5, 0, 0, 9, 0, 6, 0, 0},
                      {1, 3, 0, 0, 0, 0, 2, 5, 0},
                      {0, 0, 0, 0, 0, 0, 0, 7, 4},
                      {0, 0, 5, 2, 0, 6, 3, 0, 0}};
    if (solveSudoku(grid) == true)
          printGrid(grid);
    else
         cout<<"No solution exists";

    return 0;
}
