#include <iostream>
#include <queue> 
using namespace std;
int main(){
    int arr[]={1,12,5,111,200};
    int k=3;
    int n=sizeof(arr)/sizeof(arr[0]);
    priority_queue<int,vector<int>,greater<int> >pq;
    for(int i=0;i<k;i++)
        pq.push(arr[i]);
    for(int i=0;i<n;i++){
        if(arr[i]>pq.top()){
            pq.pop();
            pq.push(arr[i]);
        }
    }
    while(!pq.empty()){
        cout<<pq.top()<<" ";
        pq.pop();
    }

}
 