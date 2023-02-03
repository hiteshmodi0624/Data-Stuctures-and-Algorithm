#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>
using namespace std;
void addEdge(vector<int>adj[],int u,int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}
void printGraph(vector<int>adj[],int n){
    for(int i=0;i<n;i++){
        for(int x:adj[i])
            cout<<x<<" ";
        cout<<endl;
    }
}
void dfs(vector<int>adj[],int x,bool visited[]){
    visited[x]=true;
    cout<<x<<" ";
    for(int i:adj[x]){
        if(visited[i]==false)
            dfs(adj,i,visited);
    }
}
void dfs_disconnected(vector<int>adj[],int n){
    bool visited[n+1];
    int count=0;
    for(int i=0;i<n;i++){
        if(visited[i]==false){
            dfs(adj,i,visited);
            count++;
        }
    }
    cout<<endl<<"No of disconnected graphs="<<count;
}
int main(){
    int v=8;
    vector<int>adj[v];
    addEdge(adj,0,1);
    addEdge(adj,0,2);
    addEdge(adj,2,3);
    addEdge(adj,1,3);
    addEdge(adj,1,4);
    addEdge(adj,4,5);
    addEdge(adj,6,7);
    printGraph(adj,v);
    cout<<endl;
    dfs_disconnected(adj,v);
}
 