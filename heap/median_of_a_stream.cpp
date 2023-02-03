#include <iostream>
#include <queue> 
#include <vector> 
using namespace std;
int main(){
    int arr[]={25,7,10,15,20};
    int n=sizeof(arr)/sizeof(arr[0]);
    priority_queue<int>pq1;
    priority_queue<int,vector<int>,greater<int> >pq2;
    cout<<arr[0]<<" ";
    pq1.push(min(arr[0],arr[1]));
    pq2.push(max(arr[0],arr[1]));
    cout<<(arr[0]+arr[1])/2<<" ";
    for(int i=2;i<n;i++){
        if(pq2.top()>arr[i]){
            if(pq1.size()==pq2.size()){
                pq1.push(arr[i]);
                cout<<pq1.top()<<" ";
            }
            else{
                pq2.push(pq1.top());
                pq1.pop();
                pq1.push(arr[i]);
                cout<<(pq1.top()+pq2.top())/2<<" ";
            }
        }
        else if(pq1.size()==pq2.size()){
            pq1.push(pq2.top());
            pq2.pop();
            pq2.push(arr[i]);
            cout<<pq1.top()<<" ";
        }
        else{
            pq1.push(pq2.top());
            pq2.pop();
            pq2.push(arr[i]);
            pq2.push(pq1.top());
            pq1.pop();
            cout<<(pq1.top()+pq2.top())/2<<" ";
        }
    }
}
 