#include <iostream>
#include <vector>
using namespace std;

int msis_(int arr[],int n){
    int msis[n];
    int res=arr[0];
    msis[0]=arr[0];
    for(int i=1;i<n;i++){
        msis[i]=arr[i];
        for(int j=0;j<i;j++){
            if(arr[i]>arr[j]){
                msis[i]=max(msis[j]+arr[i],msis[i]);
            }
        }
        res=max(res,msis[i]);
    }
    for(int i=0;i<n;i++)
        cout<<msis[i]<<" ";
    cout<<endl;
    return res;
}
int main(){
    int arr[]={8,100,50,10,12,14,110};
    int n=sizeof(arr)/sizeof(arr[0]);
    cout<<msis_(arr,n)<<endl;
}

 