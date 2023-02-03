#include <iostream>
#include <vector>
using namespace std;

int maxCut(int n,int a,int b,int c){
    if(n<0)
        return -2;
    if(n==0)
        return 0;
    return max(max(maxCut(n-a,a,b,c),maxCut(n-b,a,b,c)),maxCut(n-c,a,b,c))+1;
}
int maxCut_dp(int n,int a,int b,int c){
    int dp[n+1];
    dp[0]=0;
    for(int i=1;i<=n;i++){
        dp[i]=-1;
        if(i-a>=0)dp[i]=max(dp[i],dp[i-a]);
        if(i-b>=0)dp[i]=max(dp[i],dp[i-b]);
        if(i-c>=0)dp[i]=max(dp[i],dp[i-c]);
        if(dp[i]!=-1)
            dp[i]++;
    }
    return dp[n];
}
int main(){
    int a=5,b=2,c=3;
    int n=25;
    cout<<maxCut(n,a,b,c)<<endl;
    cout<<maxCut_dp(n,a,b,c);
}