#include <iostream>
#include <unordered_map>
using namespace std;
int maze[3][3]={{1,0,1},{1,1,0},{0,1,1}};
int sol[3][3]={{0,0,0},{0,0,0},{0,0,0}};
int n=3;
bool isSafe(int i,int j){
    return (i<n&&j<n&&maze[i][j]==1);
}
bool solveMaze(int i,int j){
    if(i==n-1&&j==n-1){
        sol[i][j]=1;
        return true;
    }
    if(isSafe(i,j)){
        sol[i][j]=1;
        if(solveMaze(i+1,j))return true;
        if(solveMaze(i,j+1))return true;
        sol[i][j]=0;
    }
    return false;
}
void printSol(){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
            cout<<sol[i][j]<<" ";
        cout<<endl;
    }
}
int main(){
    if(solveMaze(0,0)){
        cout<<1<<endl;
        printSol();
    }
    else{
        cout<<0;
    }
}