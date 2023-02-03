#include <iostream>
#include <queue> 
using namespace std;
int main(){
    int arr[]={10,15,7,3,4};
    int k=2;
    int x=8;
    int n=sizeof(arr)/sizeof(arr[0]);
    priority_queue<pair<int,int> >pq;
    for(int i=0;i<k;i++)
        pq.push(make_pair(abs(arr[i]-x),i));
    for(int i=0;i<n;i++){
        int diff=abs(arr[i]-x);
        if(diff<pq.top().first){
            pq.pop(); 
            pq.push(make_pair(diff,i));
        }
    }
    while(!pq.empty()){
        cout<<arr[pq.top().second]<<" ";
        pq.pop();
    }

}
 