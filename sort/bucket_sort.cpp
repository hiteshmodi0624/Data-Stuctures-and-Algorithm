#include <iostream>
#include <string.h>
#include <math.h>
#include <vector>
#include<numeric>
#include<algorithm>

using namespace std;
void bucketsort(int a[],int n,int k){
    int maxi=a[0];
    for(int i=1;i<n;i++)
        maxi=max(maxi,a[i]);
    maxi++;
    vector<int>bkt[k];
    for(int i=0;i<n;i++){
        int bi=(k*a[i])/maxi;
        bkt[bi].push_back(a[i]);
    }
    for(int i=0;i<k;i++)
        sort(bkt[i].begin(),bkt[i].end());
    int index=0;
    for(int i=0;i<k;i++)
        for(int j=0;j<bkt[i].size();j++)
            a[index++]=bkt[i][j];
}
int main(){
    int arr[]={10,30,54,23,54,12,89,54,75,99};
    int k=5;
    int n=sizeof(arr)/sizeof(arr[0]);
    bucketsort(arr,n,k);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}
 