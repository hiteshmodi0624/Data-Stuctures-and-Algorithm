#include <iostream>
#include <vector>
using namespace std;

int knapsack(int v[],int w[],int W,int n){
    if(n==0||W==0)
        return 0;
    if(w[n-1]>W)
        return knapsack(v,w,W,n-1);
    return max(v[n-1]+knapsack(v,w,W-w[n-1],n-1),knapsack(v,w,W,n-1));
}
int knapsack_dp(int v[],int w[],int W,int n){
    int dp[W+1][n+1];
    for(int i=0;i<=W;i++)
        dp[i][0]=0;
    for(int i=0;i<=n;i++)
        dp[0][i]=0;
    for(int i=1;i<=W;i++){
        for(int j=1;j<=n;j++){
            if(w[j-1]>i)
                dp[i][j]=dp[i][j-1];
            else
                dp[i][j]=max(v[j-1]+dp[i-w[j-1]][j-1],dp[i][j-1]);
        }
    }
    return dp[W][n];
}
int main(){
    int v[]={10,40,30,50},w[]={5,4,6,3},W=10;
    int n=sizeof(v)/sizeof(v[0]);
    cout<<knapsack_dp(v,w,W,n)<<endl;
}