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
        adj[v].push_back(u);
    }
    void find_bridge(bool visited[],int i,int low[],int &j,int parent){
        int disc=j;
        visited[i]=true;
        low[i]=j;
        for(int x:adj[i]){
            bool child=false;
            if(visited[x]==false){
                find_bridge(visited,x,low,++j,i);
                child=true;
            }
            if(parent!=x)
                low[i]=min(low[i],low[x]);
            if(low[x]>disc&&child)
                cout<<char(i+'A')<<"-"<<char(x+'A')<<endl;
        }
    }
    void bridge(){
        int n=size,low[n],j=1;
        bool visited[n],root=false;
        for(int i=0;i<n;i++)
            visited[i]=false;
        find_bridge(visited,0,low,j,0);
    }
};
int main(){
    int n=6;
    graph adj(n);
    adj.addEdge(0,1);
    adj.addEdge(0,2);
    adj.addEdge(1,2);
    adj.addEdge(2,3);
    adj.addEdge(3,4);
    adj.addEdge(4,5);
    adj.addEdge(3,5);
    adj.bridge();
}
 