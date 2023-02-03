#include <iostream>
#include <vector>
using namespace std;
int min_attempts(int f,int e){
    if(e==1)
        return f;
    if(f==1)
        return 1;
    if(f==0)
        return 0;
    int res=f;
    for(int i=1;i<=f;i++)
        res=min(max(min_attempts(i-1,e-1),min_attempts(f-i,e))+1,res);
    return res;
}
int min_attempts_dp(int f,int e){
    int dp[f+1][e+1];
    for(int i=0;i<=e;i++){
        dp[1][i]=1;
        dp[0][i]=0;
    }
    for(int i=1;i<=f;i++){
        dp[i][1]=i;
        dp[i][0]=0;
    }
    for(int i=2;i<=f;i++){
        for(int j=2;j<=e;j++){
            dp[i][j]=f; 
            for(int k=1;k<=i;k++)
                dp[i][j]=min(max(dp[k-1][j-1],dp[i-k][j])+1,dp[i][j]);
        }
    }
    return dp[f][e];
}
int main(){
    int floors=24;
    int eggs=5;
    cout<<min_attempts_dp(floors,eggs)<<" ";
}