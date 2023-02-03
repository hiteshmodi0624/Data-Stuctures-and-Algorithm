#include <iostream>
#include <queue> 
using namespace std;
int main(){
    int arr[]={1,12,5,111,200};
    int sum=18;
    int n=sizeof(arr)/sizeof(arr[0]);
    priority_queue<int,vector<int>,greater<int> >pq(arr,arr+n);
    int res=0;
    while(!pq.empty()&&sum>=pq.top()){
        res++;
        sum-=pq.top();
        pq.pop();
    }
    cout<<res;
}
 