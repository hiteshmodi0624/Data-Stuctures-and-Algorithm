#include <iostream>
#include <queue> 
using namespace std;
void ksort(int arr[],int n,int k){
    int i=0;
    priority_queue<int,vector<int>,greater<int> >pq;
    while(i<=k){
        pq.push(arr[i]);
        i++;
    }
    int index=0;
    for(int i=k+1;i<n;i++){
        arr[index++]=pq.top();
        pq.pop();
        pq.push(arr[i]);
    }
    while(!pq.empty()){
        arr[index++]=pq.top();
        pq.pop();
    }
}
int main(){
    int arr[]={9,8,7,18,19,17};
    int n=sizeof(arr)/sizeof(arr[0]);
    int k=2;
    ksort(arr,n,k);
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
}
 