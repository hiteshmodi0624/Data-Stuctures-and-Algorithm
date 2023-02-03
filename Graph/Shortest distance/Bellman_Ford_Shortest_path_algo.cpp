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
    void addEdge(int u,int v,int d){
        adj[u].push_back(v);
        dist[u][v]=d;
    }
    int distance(int u,int v){
        return dist[u][v];
    }
};
void bellman_ford(graph adj){
    int n=adj.size;
    vector<int>dist(n,INT_MAX);
    dist[0]=0;
    for(int j=0;j<n-1;j++){
        for(int i=0;i<n;i++){
            for(auto x:adj.adj[i]){
                if(dist[x]>dist[i]+adj.distance(i,x))
                    dist[x]=dist[i]+adj.distance(i,x);
            }
        }
    }
    for(int i=0;i<n;i++){
        for(auto x:adj.adj[i]){
            if(dist[x]>dist[i]+adj.distance(i,x))
                dist[x]=INT_MIN;
        }
    }
    for(int i=0;i<n;i++)
        cout<<dist[i]<<" ";
}
int main(){
    int n=4;
    graph adj(n);
    adj.addEdge(0,1,1);
    adj.addEdge(0,2,8);
    adj.addEdge(2,3,2);
    adj.addEdge(3,1,3);
    adj.addEdge(1,2,-3);
    // adj.addEdge(1,2,-8);
    bellman_ford(adj);
}