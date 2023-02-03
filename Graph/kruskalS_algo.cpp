#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>
#include <stack>
#include <map>
using namespace std;
struct Edge{
    int src,dest,wt;
};
Edge create(int s,int d,int w){
    Edge e;
    e.src=s;
    e.wt=w;
    e.dest=d;
    return e;
}
bool myCmp(Edge e1,Edge e2){
    return e1.wt<e2.wt;
}
int main(){
    int n=7;
    Edge e[n];
    e[0]=create(0,1,10);
    e[1]=create(0,2,8);
    e[2]=create(1,2,5);
    e[3]=create(2,3,4);
    e[4]=create(1,3,3);
    e[5]=create(2,4,12);
    e[6]=create(3,4,15);
    sort(e,e+n,myCmp);
    vector<bool>visited(n,false);
    int res=0,x=0;
    int i=0;
    while(x!=n-1&&i<n){
        if(visited[e[i].dest]==false||visited[e[i].src]==false){
            visited[e[i].dest]=true;
            visited[e[i].src]=true;
            res+=e[i].wt;
            x++;
        }
        i++;
    }
    cout<<res;
}
 