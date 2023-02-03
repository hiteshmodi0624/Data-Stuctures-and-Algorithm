#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>
using namespace std;
void addEdge(vector<int>adj[],int u,int v){
    adj[u].push_back(v);
}
void printGraph(vector<int>adj[],int n){
    for(int i=0;i<n;i++){
        for(int x:adj[i])
            cout<<x<<" ";
        cout<<endl;
    }
}
bool cycle_detect(vector<int>adj[],int s,bool visited[],bool ancestor[]){
    visited[s]=true;
    ancestor[s]=true;
    for(int x:adj[s]){
        if(visited[x]==false&&cycle_detect(adj,x,visited,ancestor))
            return true;
        else if(ancestor[x]==true)
            return true; 
    }
    ancestor[s]=false;
    return false;
}
bool cycle_detect_DFS(vector<int>adj[],int n){
    bool visited[n],ancestor[n];
    for(int i=0;i<n;i++){
        if(visited[i]==false){
            if(cycle_detect(adj,i,visited,ancestor))
                return true;
        }
    }
    return false;
}
int main(){
    int v=6;
    vector<int>adj[v];
    addEdge(adj,1,0);
    addEdge(adj,0,2);
    addEdge(adj,2,3);
    addEdge(adj,4,1);
    addEdge(adj,3,4);
    addEdge(adj,4,5);
    printGraph(adj,v);
    cout<<endl;
    cout<<cycle_detect_DFS(adj,v);
}
 