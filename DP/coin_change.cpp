#include <iostream>
#include <vector>
using namespace std;

int posibilities(int coins[],int sum,int n){
    if(sum==0)return 1;
    if(n==0)return 0;
    int res=posibilities(coins,sum,n-1);
    if(sum>=coins[n-1])
        res+=posibilities(coins,sum-coins[n-1],n);
    return res;
}

int posibilities_dp(int coins[],int sum,int n){
    int dp[sum+1][n+1];
    for(int i=0;i<sum+1;i++)
        dp[i][0]=0;
    for(int i=0;i<n+1;i++)
        dp[0][i]=1;
    for(int i=1;i<=sum;i++)
        for(int j=1;j<=n;j++){
            dp[i][j]=dp[i][j-1];
            if(coins[j-1]<=i)
                dp[i][j]+=dp[i-coins[j-1]][j];
        }
    return dp[sum][n];
}

int main(){
    int coins[]={2,5,3,6};
    int sum=10;
    int n=sizeof(coins)/sizeof(coins[0]);
    cout<<posibilities(coins,sum,n);
    cout<<posibilities_dp(coins,sum,n);
}

 