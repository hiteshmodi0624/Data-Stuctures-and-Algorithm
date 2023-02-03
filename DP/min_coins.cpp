#include <iostream>
#include <vector>
using namespace std;

int minCoins(int val,int c[],int n){
    if(val==0)
        return 0;
    int res=INT_MAX;
    for(int i=0;i<n;i++){
        if(val-c[i]>=0){
            int res2=minCoins(val-c[i],c,n);
            if(res2!=INT_MAX)
                res=min(res,res2+1);
        }
    }
    return res;
}
int minCoins_dp(int val,int c[],int n){
    int dp[val+1]; 
    dp[0]=0;
    for(int i=1;i<=val;i++){
        dp[i]=INT_MAX;
        for(int j=0;j<n;j++)
            if(i-c[j]>=0)
                if(dp[i-c[j]]!=INT_MAX)
                    dp[i]=min(dp[i],dp[i-c[j]]+1);
    }
    return dp[val];
}
int main(){
    int c[]={9,5,6,1};
    int n=sizeof(c)/sizeof(c[0]);
    int m=11;
    cout<<minCoins(m,c,n)<<endl;
    cout<<minCoins_dp(m,c,n)<<endl;
}