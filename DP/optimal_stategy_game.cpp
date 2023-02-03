#include <iostream>
#include <vector>
using namespace std;
int strategy(int coins[],int j,int i=0){
    if(i+1==j)
        return max(coins[i],coins[j]);
    int x=coins[i]+min(strategy(coins,j-1,i+1),strategy(coins,j,i+2));
    int y=coins[j]+min(strategy(coins,j-1,i+1),strategy(coins,j-2,i));
    return max(x,y);
}
int strategy_dp(int coins[],int n){
    int dp[n][n];
    for(int i=0;i<n-1;i++)
        dp[i][i+1]=max(coins[i],coins[i+1]);
    for(int i=n-1;i>=0;i--)
        for(int j=i+3;j<n;j=j+2){
            dp[i][j]=max(coins[j]+min(dp[i+1][j-1],dp[i][j-2]),coins[i]+min(dp[i+1][j-1],dp[i+2][j]));
    }
    return dp[0][n-1];

}
int main(){
    int coins[]={20,5,4,6,8,3};
    int n=sizeof(coins)/4;
    cout<<strategy_dp(coins,n);
}