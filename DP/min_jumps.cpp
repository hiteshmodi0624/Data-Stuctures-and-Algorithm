#include <iostream>
#include <vector>
using namespace std;
int minJumps(int c[],int n){
    if(n==1)
        return 0;
    int res=INT_MAX;
    for(int i=0;i<n-1;i++)
        if(i+c[i]>=n-1){
            int res2=minJumps(c,i+1);
            if(res2!=INT_MAX)
                res=min(res,res2+1);
        }
    return res;
}
int minJumps_dp(int c[],int n){
    int dp[n];
    dp[0]=0;
    for(int i=1;i<n;i++){
        dp[i]=INT_MAX;
        for(int j=0;j<i;j++){
            if(j+c[j]>=i){
                if(dp[j]!=INT_MAX)
                    dp[i]=min(dp[i],dp[j]+1);
            }
        }
    }
    for(int i=0;i<n;i++)
        cout<<dp[i]<<" ";
    return dp[n-1];
}
// int minJumps_dp(int c[],int n){
//     int dp[n];
//     dp[n-1]=0;
//     for(int i=n-2;i>=0;i--){
//         dp[i]=INT_MAX;
//         for(int j=1;j<=c[i];j++){
//             if(i+j<=n-1){
//                 dp[i]=min(dp[i+j]+1,dp[i]);
//             }
//         }
//     }
//     return dp[1];
// }
int main(){
    int c[]={4,1,5,3,1,3,1,1,8};
    int n=sizeof(c)/sizeof(c[0]);
    cout<<minJumps(c,n)<<endl;
    cout<<minJumps_dp(c,n)<<endl;
}