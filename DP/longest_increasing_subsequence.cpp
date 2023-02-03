#include <iostream>
#include <vector>
using namespace std;

int lis_dp(int arr[],int n){
    int lis[n];
    lis[0]=1;
    int res=lis[0];
    for(int i=1;i<n;i++){
        lis[i]=1;
        for(int j=0;j<i;j++){
            if(arr[i]>arr[j])
                lis[i]=max(lis[i],lis[j]+1);
        }
        res=max(res,lis[i]);
    }
    for(int i=0;i<n;i++)
        cout<<lis[i]<<" ";
    cout<<endl;
    return res;
}
int lis_binaryS(int arr[],int n){
    vector<int>v;
    v.push_back(arr[0]);
    for(int i=1;i<n;i++){
        if(arr[i]>v.back())
            v.push_back(arr[i]);
        else
            *upper_bound(v.begin(),v.end(),arr[i])=arr[i];
    }
    for(auto x:v)
        cout<<x<<" ";
    cout<<endl;
    return v.size();
}
int main(){
    int arr[]={8,100,50,10,12,14,110};
    int n=sizeof(arr)/sizeof(arr[0]);
    cout<<lis_dp(arr,n)<<endl;
    cout<<lis_binaryS(arr,n);
}

 