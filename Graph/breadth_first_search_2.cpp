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
void bfs_print_friends_and_friends_of_friends_of_s(vector<int>adj[],int s,bool visited[]){
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
void bfs_print_all_from_disconnected(vector<int>adj[],int n){
    bool visited[n+1];
    int s=0;
    for(int i=0;i<n;i++){
        if(visited[i]==false){
            bfs_print_friends_and_friends_of_friends_of_s(adj,i,visited);
            s++;
        }
    }
    cout<<endl<<s<<" connected componets";
}
int main(){
    int v=7;
    vector<int>adj[v];
    addEdge(adj,0,1);
    addEdge(adj,0,2);
    addEdge(adj,1,3);
    addEdge(adj,2,3);
    addEdge(adj,4,5);
    addEdge(adj,4,6);
    addEdge(adj,5,6);
    printGraph(adj,4);
    cout<<endl;
    bfs_print_all_from_disconnected(adj,v);
}
 