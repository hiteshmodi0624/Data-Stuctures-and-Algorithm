#include <iostream>
#include <queue> 
#include <vector> 
using namespace std;
struct triplet{
    int x,y,z;
    triplet(int a,int b,int c){
        x=a;
        y=b;
        z=c;
    }
};
struct mycomp{
    bool operator()(triplet t1,triplet t2){
        return t1.x>t2.x;
    }
};
int main(){
    int arr[3][4]={{10,20,30,34},{5,15,23,25},{1,9,11,18}};
    vector<int>res;
    int k=3;
    priority_queue<triplet,vector<triplet>,mycomp>pq;
    for(int i=0;i<k;i++){
        triplet t(arr[i][0],i,0);
        pq.push(t);
    }
    while(!pq.empty()){
        triplet t=pq.top();
        res.push_back(t.x);
        pq.pop();
        if(t.z+1<4){
            triplet t2(arr[t.y][t.z+1],t.y,t.z+1);
            pq.push(t2);
        }
    }
    for(auto x:res)
        cout<<x<<" ";
}
 