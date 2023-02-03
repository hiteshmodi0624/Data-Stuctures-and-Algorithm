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
    void ap_fill(bool visited[],int i,int disc[],int low[],int &j,int parent,bool ap[]){
        visited[i]=true;
        disc[i]=low[i]=j;
        int child=0;
        for(int x:adj[i]){
            if(x==parent)
                continue;
            if(visited[x]==false){
                child++;
                ap_fill(visited,x,disc,low,++j,i,ap);
                low[i]=min(low[i],low[x]);
                if(low[x]>=disc[i]&&parent!=-1)
                    ap[i]=true;
            }
            else
                low[i]=min(low[i],disc[x]);
        }
        if(parent==-1&&child>1)
            ap[i]=true;
    }
    void articulation_point(){
        int n=size,disc[n],low[n],j=1;
        bool visited[n],ap[n],root=false;
        for(int i=0;i<n;i++)
            visited[i]=ap[i]=false;
        ap_fill(visited,0,disc,low,j,0,ap);
        for(int i=0;i<n;i++)
            if(ap[i]==true)
                cout<<i<<" ";
    }
};
int main(){
    int n=8;
    graph adj(n);
    adj.addEdge(0,1);
    adj.addEdge(0,7);
    adj.addEdge(1,2);
    adj.addEdge(2,3);
    adj.addEdge(0,3);
    adj.addEdge(1,4);
    adj.addEdge(5,4);
    adj.addEdge(5,6);
    adj.addEdge(6,4);
    adj.articulation_point();
}
 