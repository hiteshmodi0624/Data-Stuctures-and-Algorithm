#include <iostream>
#include <vector>
using namespace std;

int lis_dp(int arr[],int n){
    int lis[n];
    lis[0]=1;
    int res=1;
    for(int i=1;i<n;i++){
        lis[i]=1;
        for(int j=0;j<i;j++){
            if(arr[i]>arr[j])
                lis[i]=max(lis[i],lis[j]+1); 
        }
    }
    int lisr[n];
    lisr[n-1]=1;
    for(int i=n-2;i>=0;i--){
        lisr[i]=1;
        for(int j=n-1;j>=i;j--){
            if(arr[i]>arr[j])
                lisr[i]=max(lisr[i],lisr[j]+1);
        }
    }
    for(int i=0;i<n;i++)
        res=max(res,lis[i]+lisr[i]-1);
    return res;
}
int lis_binaryS(int arr[],int n){
    vector<int>v,v2;
    v.push_back(arr[0]);
    v2.push_back(arr[n-1]);
    int res=0;
    for(int i=1;i<n;i++){
        if(arr[i]>v.back())
            v.push_back(arr[i]);
        else
            *upper_bound(v.begin(),v.end(),arr[i])=arr[i];
        if(arr[n-1-i]>v2.back())
            v2.push_back(arr[n-1-i]);
        else
            *upper_bound(v2.begin(),v2.end(),arr[n-1-i])=arr[n-1-i];
        int x=v2.size()+v.size()-1;
        res=max(res,x);
    }
    return res;
}
int main(){
    int arr[]={12,11,40,5,3,1};
    int n=sizeof(arr)/sizeof(arr[0]);
    cout<<lis_binaryS(arr,n)<<endl;
}

 