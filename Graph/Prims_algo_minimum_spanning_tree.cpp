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
int miminum_spanning_tree(graph adj){
    int n=adj.size;
    int res=0;
    bool selected[n];
    for(int i=0;i<n;i++)
        selected[i]=false;
    vector<int>key(n,INT_MAX);
    key[0]=0;
    for(int i=0;i<n;i++){
        int u=-1;
        for(int j=0;j<n;j++)
            if(!selected[j]&&(u==-1||key[j]<key[u]))
                u=i;
        selected[u]=true;
        res+=key[u];
        for(int j=0;j<n;j++){
            if(adj.distance(u,j)!=0&&!selected[j])
                key[j]=min(key[j],adj.distance(u,j));
        }
    }
    return res;
}
int miminum_spanning_tree_2(graph adj){
    int n=adj.size;
    map<int,int>m;
    vector<int>v;
    v.push_back(0);
    int res=0;
    int x=0;
    bool selected[n];
    for(int i=0;i<n;i++)
        selected[i]=false;
    while(--n){
        selected[x]=true;
        for(int y:adj.adj[x])
            if(selected[y]==false)
                m[adj.distance(x,y)]=y;
        auto top=m.begin();
        while(selected[top->second])
            top=m.erase(top);
        res+=top->first;
        x=top->second;
        m.erase(top->first);
    }
    return res;
}
int main(){
    int n=4;
    graph adj(n);
    adj.addEdge(0,1,5);
    adj.addEdge(0,2,8);
    adj.addEdge(2,3,20);
    adj.addEdge(1,3,15);
    adj.addEdge(1,2,10);
    cout<<miminum_spanning_tree(adj);
    cout<<miminum_spanning_tree_2(adj);
}
 