#include <iostream>
#include <deque>
using namespace std;
void max_all_subarray(int a[],int k,int n){
    deque<int>dq;
    for(int i=0;i<k-1;i++){
        while(!dq.empty()&&a[dq.back()]<=a[i])
            dq.pop_back();
        dq.push_back(i);
    }
    
    for(int i=k-1;i<n;i++){
        while(!dq.empty()&&i-dq.front()>=k)
            dq.pop_front();
        while(!dq.empty()&&a[dq.back()]<=a[i])
            dq.pop_back();
        dq.push_back(i);
        cout<<a[dq.front()]<<" ";
    }
}
int main(){
    int arr[]={10,8,5,12,15,7,6};
    int k=3;
    int n=sizeof(arr)/sizeof(arr[0]);
    max_all_subarray(arr,k,n);
}
 