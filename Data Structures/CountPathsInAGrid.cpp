/** Calculates no of paths in a grid from end to the beginning**/

#include<iostream>

using namespace std;

/********************************************************************************/
int countPaths(int grid[3][3], int rowSize,int columnSize,int row, int column){

    if(row == rowSize-1 || column == columnSize-1 ){return 1;}
    int totalPaths =0;
    totalPaths = countPaths(grid,rowSize,columnSize,row+1,column)
               + countPaths(grid,rowSize,columnSize,row,column+1);

    return totalPaths;
}
/********************************************************************************/

int countPaths(int grid[3][3],int rowSize, int columnSize){
    
    int noOfPaths = countPaths(grid,rowSize,columnSize,0,0);
    return noOfPaths;
    
}
/********************************************************************************/
int main(){
    int grid[3][3] = {{1,2,3},{4,5,6},{7,8,9}};
    //int grid[2][2];
    int rowSize = sizeof(grid)/sizeof(grid[0]);
    int columnSize = sizeof(grid[0])/sizeof(int);
    //cout << rowSize << "\t" << columnSize << endl;

    cout << "Total no of paths from beginning to end in a grid:->" << countPaths(grid,rowSize,columnSize);
    return 0;
}
