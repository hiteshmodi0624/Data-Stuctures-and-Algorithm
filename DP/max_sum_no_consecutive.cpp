#include <iostream>
#include <vector>
using namespace std;
struct bridges{
    int x,y;
};
// int max_sum(int a[],int n){
//     int dp[n];
//     dp[0]=a[0];
//     dp[1]=a[1];
//     int prev=max(dp[0],dp[1]);
//     for(int i=2;i<n;i++){
//         dp[i]=dp[i-2]+a[i];
//         prev=dp[i-1]=max(dp[i-1],prev);
//     }
//     return max(dp[n-1],dp[n-2]);
// }
int max_sum(int a[],int n){
    int prev_prev=a[0];
    int prev=max(a[0],a[1]);
    int res=prev;
    for(int i=2;i<n;i++){
        res=max(prev,prev_prev+a[i]);
        prev_prev=prev;
        prev=res;
    }
    return res;
}
int main(){
    int a[]={10,5,15,20,2,30};
    int n=sizeof(a)/sizeof(a[0]);
    cout<<max_sum(a,n);
}