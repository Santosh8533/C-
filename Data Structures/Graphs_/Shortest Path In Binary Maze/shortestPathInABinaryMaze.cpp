/**
    Author: Santosh Tandrothu
    Date: 02/24/2019
**/

/**
    Run-time: O(ROWS*COLUMNS)
    Space: O(ROWS*COLUMNS)
**/
#include<iostream>
#include<queue>
#include<cstring>

using namespace std;

#define ROW 9
#define COL 10
//to store matrix cell coordinates
class Point{
public:
    int x;
    int y;
};

//custom queue to be used in DFS
class QueueNode{
public:
    Point pt; //coordinates of a cell
    int dist; //cell's distance from source
};

//check the validity of row and column
bool isValid(int row,int col){
    return (row>=0) && (row < ROW) &&
           (col>=0) && (col < COL);
}

//arrays to cover all 4 neighbors of a given cell
//down-left-right-up
int rowNum[] = {-1,0,0,1};
int colNum[] = {0,-1,1,0};

//function to find shortest path between a given
//source and destination cell
int shortestPath(int maze[][COL], Point src, Point dest){
    bool visited[ROW][COL];
    memset(visited,false,sizeof visited);

    //mark the source cell as visited
    visited[src.x][src.y] = true;
    QueueNode qNode = {src,0};

    queue<QueueNode> que;
    que.push(qNode);

    while(!que.empty()){
        QueueNode curr = que.front();
        Point pt = curr.pt;

        //if destination cell is reached
        if(pt.x == dest.x && pt.y == dest.y){return curr.dist;}

        //Otherwise deque current cell and enqueue its adjacen cells
        que.pop();
        //visiting neighbors
        for(int i=0;i<4;i++){
            int row = pt.x + rowNum[i];
            int col = pt.y + colNum[i];

            //check the validity of the cell
            if(isValid(row,col)&&!visited[row][col]&&maze[row][col]){
                visited[row][col] = true;
                QueueNode adjCell = {{row,col},curr.dist+1};
                que.push(adjCell);
            }
        }
    }
    //destination cannot be reached
    return -1;
}

// Driver program to test above function
int main()
{
	int mat[ROW][COL] =
	{
		{ 1, 0, 1, 1, 1, 1, 0, 1, 1, 1 },
		{ 1, 0, 1, 0, 1, 1, 1, 0, 1, 1 },
		{ 1, 1, 1, 0, 1, 1, 0, 1, 0, 1 },
		{ 0, 0, 0, 0, 1, 0, 0, 0, 0, 1 },
		{ 1, 1, 1, 0, 1, 1, 1, 0, 1, 0 },
		{ 1, 0, 1, 1, 1, 1, 0, 1, 0, 0 },
		{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
		{ 1, 0, 1, 1, 1, 1, 0, 1, 1, 1 },
		{ 1, 1, 0, 0, 0, 0, 1, 0, 0, 1 }
	};

	Point source = {0, 0};
	Point dest = {3, 4};

	int dist = shortestPath(mat, source, dest);

	if (dist != -1)
		cout << "Shortest Path is " << dist ;
	else
		cout << "Shortest Path doesn't exist";

	return 0;
}
