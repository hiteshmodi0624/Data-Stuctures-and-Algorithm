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
void bfs_print_friends_and_friends_of_friends(vector<int>adj[],int n,int s){
    bool visited[n+1];
    visited[s]=true;
    queue<int>q;
    q.push(s);
    while(!q.empty()){
        int i=q.front();
        q.pop();
        cout<<i<<" ";
        for(int x:adj[i]){
            if(visited[x]==false){
                visited[x]=true;
                q.push(x);
            }
        }
    }
}
int main(){
    int v=4;
    vector<int>adj[v];
    addEdge(adj,0,1);
    addEdge(adj,0,2);
    addEdge(adj,1,2);
    addEdge(adj,1,3);
    addEdge(adj,2,3);
    addEdge(adj,2,4);
    addEdge(adj,3,4);
    printGraph(adj,4);
    cout<<endl;
    bfs_print_friends_and_friends_of_friends(adj,4,0);
}
 