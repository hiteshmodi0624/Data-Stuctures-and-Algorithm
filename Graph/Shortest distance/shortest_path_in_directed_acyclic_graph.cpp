#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>
#include <stack>
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
void shortest_distance(graph adj,int i,vector<int>&distance){
    for(int x:adj.adj[i]){
        distance[x]=min(distance[x],distance[i]+adj.distance(i,x));
        shortest_distance(adj,x,distance);
    }
}

void toplogical_sorting(vector<int>adj[],int i,bool visited[],stack<int>&s){
    visited[i]=true;
    for(int x:adj[i])
        if(visited[x]==false)
            toplogical_sorting(adj,x,visited,s);
    s.push(i);
}
void shortest_distance_using_topological_sort(graph adj,int source){
    int n=adj.size;
    bool visited[n];
    for(int i=0;i<n;i++)
        visited[i]=false;
    stack<int>s;
    toplogical_sorting(adj.adj,source,visited,s);
    vector<int>distance(n,INT_MAX);
    distance[source]=0;
    while(!s.empty()){
        int t=s.top();
        s.pop();
        for(int x:adj.adj[t])
            distance[x]=min(distance[x],distance[t]+adj.distance(t,x));
    }
    for(int x:distance)
        cout<<x<<" ";
}
int main(){
    int n=6;
    graph adj(n);
    int source=0;
    adj.addEdge(0,1,2);
    adj.addEdge(0,4,1);
    adj.addEdge(1,2,3);
    adj.addEdge(2,3,6);
    adj.addEdge(4,2,6);
    adj.addEdge(4,5,4);
    adj.addEdge(5,3,1);
    vector<int>distance(n,INT_MAX);
    distance[source]=0;
    shortest_distance(adj,source,distance);
    for(int x:distance)
        cout<<x<<" ";
    cout<<endl;
    shortest_distance_using_topological_sort(adj,source);
}
 