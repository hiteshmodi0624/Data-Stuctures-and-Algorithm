#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>
#include <stack>
using namespace std;
void addEdge(vector<int>adj[],int u,int v,int indegree[]){
    adj[u].push_back(v);
    indegree[v]++;
}

void topological_sorting(vector<int>adj[],int n,int indegree[]){
    bool visited[n];
    queue<int>q;
    for(int i=0;i<n;i++)
        if(indegree[i]==0)
            q.push(i);
    while(!q.empty()){
        int t=q.front();
        q.pop();
        cout<<t<<" ";
        for(int x:adj[t]){
            indegree[x]--;
            if(indegree[x]==0)
                q.push(x);
        }
    }
}
void toplogical_sorting_2(vector<int>adj[],int i,bool visited[],stack<int>&s){
    visited[i]=true;
    for(int x:adj[i])
        if(visited[x]==false)
            toplogical_sorting_2(adj,x,visited,s);
    s.push(i);
}
void topological_sorting_2_main(vector<int>adj[],int n){
    bool visited[n];
    stack<int>s;
    for(int i=0;i<n;i++)
        if(visited[i]==false)
            toplogical_sorting_2(adj,i,visited,s);
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
}
int main(){
    int n=5;
    vector<int>adj[n];
    int indegree[n];
    for(int i=0;i<n;i++)
        indegree[i]=0;
    addEdge(adj,0,2,indegree);
    addEdge(adj,0,3,indegree);
    addEdge(adj,3,2,indegree);
    addEdge(adj,1,3,indegree);
    addEdge(adj,1,4,indegree);
    // topological_sorting only works in acyclic graphs.
    topological_sorting(adj,n,indegree);
    cout<<endl;
    topological_sorting_2_main(adj,n);
    
    
}
 