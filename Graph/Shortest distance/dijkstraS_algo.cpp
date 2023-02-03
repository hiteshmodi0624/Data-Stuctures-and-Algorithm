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
        adj[v].push_back(u);
        dist[u][v]=d;
        dist[v][u]=d;
    }
    int distance(int u,int v){
        return dist[u][v];
    }
};
void dijkstra_algo(graph adj){
    int n=adj.size;
    vector<int>dist(n,INT_MAX);
    vector<bool>final(n,false);
    dist[0]=0;
    map<int,int>m;
    int j=0;
    while(n>j++){
        int x=-1;
        for(int i=0;i<n;i++)
            if(!final[i]&&(x==-1||dist[i]<dist[x]))
                x=i;
        final[x]=true;
        for(int y:adj.adj[x])
            dist[y]=min(dist[y],adj.distance(x,y)+dist[x]);
    }
    for(int i=0;i<n;i++)
        cout<<dist[i]<<" ";
}
int main(){
    int n=4;
    graph adj(n);
    adj.addEdge(0,1,50);
    adj.addEdge(0,2,100);
    adj.addEdge(2,3,20);
    adj.addEdge(1,3,200);
    adj.addEdge(1,2,30);
    dijkstra_algo(adj);
}
 