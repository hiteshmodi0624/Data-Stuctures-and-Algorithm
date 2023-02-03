#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
bool isSafe(int row,int col,vector<vector<int> >sol,int N){
    for(int i=0;i<col;i++)
        if(sol[row][i])
            return false;
    for(int i=row,j=col;i>=0&&j>=0;i--,j--)
        if(sol[i][j])
            return false;
    for(int i=row,j=col;i<N&&j>=0;i++,j--)
        if(sol[i][j])
            return false;
    return true;
    
}
bool NQueen(int N,vector<vector<int> >&sol,int col){
    if(col==N)
        return true;
    for(int i=0;i<N;i++){
        if(isSafe(i,col,sol,N)){
            sol[i][col]=1;
            if(NQueen(N,sol,col+1))
                return true;
            sol[i][col]=0;
        }
    }
    return false;
}
void printSol(vector<vector<int> >sol,int N){
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++)
            cout<<sol[i][j]<<" ";
        cout<<endl;
    }
}
int main(){
    int N=4;
    vector<vector<int> >sol(N,vector<int>(N,0));
    if(NQueen(N,sol,0)){
        printSol(sol,N);
    }
    else{
        cout<<0;
    }
}