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
bool cycle_detect_DFS(vector<int>adj[],int s,bool visited[],int parent){
    visited[s]=true;
    for(int x:adj[s])
        if((visited[x]==false)){
            if(cycle_detect_DFS(adj,x,visited,s))
                return true;
        }
        else if(x!=parent)
            return true;
    return false;
}
bool cycle_detect_DFS_main(vector<int>adj[],int n){
    bool visited[n];
    for(int i=0;i<n;i++){
        if(visited[i]==false)
            if(cycle_detect_DFS(adj,i,visited,-1))
                return true;
    }
}
bool cycle_detect(vector<int>adj[],int n){
    bool visited[n+1];
    visited[0]=true;
    for(int i=0;i<n;i++){
        int x=0;
        for(int j:adj[i]){
            if(visited[j]==true)
                x++;
            else
                visited[j]=true;
            if(x>1)
                return true;
        }
    }
    return false;
}
int main(){
    int v=8;
    vector<int>adj[v];
    addEdge(adj,0,2);
    addEdge(adj,2,3);
    addEdge(adj,1,4);
    addEdge(adj,1,5);
    addEdge(adj,4,5);
    addEdge(adj,6,7);
    printGraph(adj,v);
    cout<<endl;
    cout<<cycle_detect(adj,v);
    cout<<cycle_detect_DFS_main(adj,v);
}
 