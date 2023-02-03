#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>
#include <stack>
#include <map>
using namespace std;
struct graph{
    vector<int>*dist,*adj;
    int size;
    graph(int n){
        adj=new vector<int>[n];
        dist=new vector<int>[n];
        for(int i=0;i<n;i++)
            dist[i]=*new vector<int>(n);
        size=n;
    }
    void addEdge(int u,int v){
        adj[u].push_back(v);
    }
    void ap_fill(bool visited[],int i,int disc[],int low[],int &j,int parent,bool ancestor[]){
        visited[i]=true;
        ancestor[i]=true;
        disc[i]=low[i]=j;
        for(int x:adj[i]){
            bool child=false;
            if(visited[x]==false){
                ap_fill(visited,x,disc,low,++j,i,ancestor);
                child=true;
            }
            if(parent!=x){
                if(low[i]>low[x]&&ancestor[low[x]-1]==true)
                    low[i]=low[x];
            }
        }
        ancestor[i]=false;
    }
};
void dfs(bool visited[],int disc[],int low[],int i,graph adj,stack<int>&s){
    visited[i]=true;
    s.push(i);
    for(int x:adj.adj[i]){
        if(visited[x]==false)
            dfs(visited,disc,low,x,adj,s);
    }
    if(low[i]==disc[i]){
        while(s.top()!=i){
            int t=s.top();
            s.pop(); 
            cout<<t<<" ";
        }
        cout<<s.top()<<" ";
        s.pop();
        cout<<endl;
    }
}
void strongly_connected_components(graph adj){
    int n=adj.size;
    int disc[n],low[n];
    int j=1;
    bool visited[n],ancestor[n];
    for(int i=0;i<n;i++)
        visited[i]=ancestor[i]=false;
    adj.ap_fill(visited,0,disc,low,j,0,ancestor);
    for(int i=0;i<n;i++)
        cout<<i<<" "<<low[i]<<" "<<disc[i]<<endl;
    for(int i=0;i<n;i++)
        visited[i]=false;
    stack<int>s;
    dfs(visited,disc,low,0,adj,s);
}
int main(){
    int n=5;
    graph adj(n);
    adj.addEdge(0,1);
    adj.addEdge(0,2);
    adj.addEdge(2,1);
    adj.addEdge(2,3);
    adj.addEdge(3,4);
    adj.addEdge(4,2);
    strongly_connected_components(adj);
}
 