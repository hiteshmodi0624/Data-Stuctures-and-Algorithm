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
void shortest_distance(vector<int>adj[],int n,int s){
    bool visited[n+1];
    int arr[n];
    for(int i=0;i<n;i++)
        arr[i]=INT_MAX;
    queue<int>q;
    q.push(s);
    visited[s]=true;
    arr[0]=0;
    while(!q.empty()){
        int x=q.front();
        q.pop();
        for(int i:adj[x]){
            if(!visited[i]){
                visited[i]=true;
                q.push(i);
                arr[i]=arr[x]+1;
            }
        }
    }
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
}
int main(){
    int v=7;
    vector<int>adj[v];
    addEdge(adj,0,1);
    addEdge(adj,0,2);
    addEdge(adj,2,6);
    addEdge(adj,6,3);
    addEdge(adj,1,3);
    addEdge(adj,1,4);
    addEdge(adj,4,5);
    
    printGraph(adj,v);
    cout<<endl;
    shortest_distance(adj,v,0);
}
 