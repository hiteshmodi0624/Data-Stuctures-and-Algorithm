#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>
#include <stack>
#include <map>
using namespace std;

void addEdge(vector<int>adj[],int u,int v){
    adj[u].push_back(v);
}
void transpose(vector<int>adj[],int n,vector<int>trans[]){
    for(int i=0;i<n;i++)
        for(int j=0;j<adj[i].size();j++)
            trans[adj[i][j]].push_back(i);
}
void dfsrec(vector<int>adj[],int i,vector<bool>&visited,stack<int>&s){
    visited[i]=true;
    for(int x:adj[i])
        if(visited[x]==false)
            dfsrec(adj,x,visited,s);
    s.push(i);
}
void dfs(vector<int>adj[],int i,vector<bool>&visited){
    cout<<i<<" ";
    visited[i]=true;
    for(int x:adj[i])
        if(visited[x]==false)
            dfs(adj,x,visited);
}
void kosarajuS_algo(vector<int>adj[],int n){
    vector<bool>visited(n,false);
    stack<int>s;
    for(int i=0;i<n;i++)
        if(visited[i]==false)
            dfsrec(adj,i,visited,s);
    vector<bool>visited2(n,false);
    vector<int>trans[n];
    transpose(adj,n,trans);
    while(!s.empty()){
        int i=s.top();
        if(visited2[i]==false){
            dfs(trans,i,visited2);
            cout<<endl;
        }
        s.pop();
    }
}
int main(){
    int n=6;
    vector<int>adj[n];
    addEdge(adj,0,1);
    addEdge(adj,1,2);
    addEdge(adj,2,3);
    addEdge(adj,3,0);
    addEdge(adj,3,4);
    addEdge(adj,4,5);
    addEdge(adj,5,4);
    kosarajuS_algo(adj,n);
}
 