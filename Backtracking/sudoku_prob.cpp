#include <iostream>
#include <unordered_map>
#include <queue>
using namespace std;
int sudoku[9][9]={{0,0,7,4,9,1,6,0,5},{2,0,0,0,6,0,3,0,9},{0,0,0,0,0,7,0,1,0},{0,5,8,6,0,0,0,0,4},{0,0,3,0,0,0,0,9,0},{0,0,6,2,0,0,1,8,7},{9,0,4,0,7,0,0,0,2},{6,7,0,8,3,0,0,0,0},{8,1,0,0,4,5,0,0,0}};
int n=9,N=3;

bool isSafe(int row,int col,int val){
    for(int i=0;i<n;i++)
        if(sudoku[row][i]==val)
            return false;
    for(int i=0;i<n;i++)
        if(sudoku[i][col]==val)
            return false;
    int x=row/N,y=col/N;
    x=x*N,y=y*N;
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            if(sudoku[x+i][y+j]==val)
                return false;
    return true;
}

bool Sudoku(queue<pair<int,int> >q){
    if(q.empty())
        return true;
    cout<<q.size()<<endl;
    pair<int,int>p=q.front();
    q.pop();
    for(int k=1;k<=n;k++){
        if(isSafe(p.first,p.second,k)){
            sudoku[p.first][p.second]=k;
            if(Sudoku(q))return true;
            sudoku[p.first][p.second]=0;
        }
    }
    q.push(p);
    return false;
}

void printSol(){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
            cout<<sudoku[i][j]<<" ";
        cout<<endl;
    }
}

int main(){
    queue<pair<int,int> >q;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            if(sudoku[i][j]==0)
                q.push(make_pair(i,j));
    Sudoku(q);
    printSol();
}