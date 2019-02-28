#include<iostream>
#include<queue>

using namespace std;

class Node{
public:
    int val;
    int level;
};

int minimumNoOfMoves(int grid[], int N){

    //array to track visited nodes
    bool* visited = new bool[N];
    for(int i=0;i<N;i++){
        visited[i] = false;
    }

    queue<Node> q;

    int level = 1;
    Node current, temp;
    Node first = {0,0};
    q.push(first);
    //cout<<"Vertex:"<<first.val+1<<"\t"<<"Level:"<<first.level<<endl;
    visited[0] = true;

    while(!q.empty()){
        //cout<<"Vertex:"<<first.val+1<<"\t"<<"Level:"<<first.level<<endl;
        current = q.front();
        cout<<"Vertex:"<<current.val<<"\t"<<"Level:"<<current.level<<endl;
        int vertex = current.val; //1

        //if it's end - stop here
        if(vertex==N-1){break;}

        //pop it
        q.pop();

        for(int i=vertex+1;i<=(vertex+6) && i<N;i++){
            if(!visited[i]){
                //level
                temp.level = current.level + 1;
                visited[i] = true;

                //value
                if(grid[i] == -1){temp.val = i;} //grid value
                else {temp.val = grid[i];} //ladder or snake

                q.push(temp);
            }
        }
    }

    return current.level;
}

int main(){

    int N = 30;
    int grid[N];

    //Initialize grid
    for(int i=0;i<N;i++){
        grid[i] = -1;
    }

    //snakes
    grid[17] = 4;
    grid[19] = 7;
    grid[21] = 9;
    grid[27] = 1;

    //ladders
    grid[3] = 22;
    grid[5] = 8;
    grid[11] = 26;
    grid[20] = 29;


    cout<<"Minimum no of moves:"<<minimumNoOfMoves(grid,N)<<endl;

}
