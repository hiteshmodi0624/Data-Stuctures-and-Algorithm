#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>
using namespace std;
void addEdge(vector<int>adj[],int u,int v,int indegree[]){
    adj[u].push_back(v);
    indegree[v]++;
}

bool cycleDetect(vector<int>adj[],int n,int indegree[]){
    queue<int>q;
    for(int i=0;i<n;i++)
        if(indegree[i]==0)
            q.push(i);
    int count=0;
    while(!q.empty()){
        int t=q.front();
        q.pop();
        for(int x:adj[t]){
            indegree[x]--;
            if(indegree[x]==0)
                q.push(x);
        }
        count++;
    }
    if(count!=n)
        return true;
    return false;
}
int main(){
    int n=5;
    vector<int>adj[n];
    int indegree[n];
    for(int i=0;i<n;i++)
        indegree[i]=0;
    addEdge(adj,0,2,indegree);
    addEdge(adj,3,0,indegree);
    addEdge(adj,2,3,indegree);
    addEdge(adj,1,3,indegree);
    addEdge(adj,1,4,indegree);
    cout<<cycleDetect(adj,n,indegree);
}
 