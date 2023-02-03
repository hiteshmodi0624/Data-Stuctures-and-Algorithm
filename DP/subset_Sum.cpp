#include <iostream>
#include <vector>
using namespace std;
int subSet_sum(int a[],int n,int sum){
    if(n==0)
        return (sum==0)?1:0;
    return subSet_sum(a,n-1,sum-a[n-1])+subSet_sum(a,n-1,sum);
}
int subSet_sum_dp(int a[],int n,int sum){
    int dp[n+1][sum+1];
    for(int i=0;i<=sum;i++)
        dp[0][i]=0;
    for(int i=0;i<=n;i++)
        dp[i][0]=1;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=sum;j++){
            if(j-a[i-1]>=0)
                dp[i][j]=dp[i-1][j-a[i-1]]+dp[i-1][j];
            else
                dp[i][j]=dp[i-1][j];
        }
    for(int i=0;i<=n;i++){
        for(int j=0;j<=sum;j++)
            if(dp[i][j]>1)
                cout<<i<<" "<<j<<endl;
    cout<<endl;}
    return dp[n][sum];
}
int main(){
    int a[]={478 ,757 ,314, 471, 729, 100, 459, 618};
    int n=sizeof(a)/sizeof(a[0]);
    cout<<subSet_sum_dp(a,n,3926);
}
