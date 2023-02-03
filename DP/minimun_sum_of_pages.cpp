#include <iostream>
#include <vector>
using namespace std;

int minPages(int p[],int k,int n){
    if(n==0)
        return INT_MIN;
    if(k==1){
        int res=0;
        for(int i=0;i<n;i++)
            res+=p[i];
        return res;
    }
    int sum=0,res=INT_MAX;
    for(int i=n-1;i>=0;i--){
        sum+=p[i];
        res=min(res,max(sum,minPages(p,k-1,i)));
    }
    return res;
}
int minPages_dp(int p[],int n,int k){
    int dp[n+1][k+1];
    int res=0;
    for(int j=1;j<=n;j++){
        res+=p[j-1];
        dp[j][1]=res;
    }

    for(int j=2;j<=k;j++){
        for(int i=n;i>0;i--){    
            int sum=0;
            dp[i][j]=INT_MAX;
            for(int l=i-1;l>=0;l--){
                sum+=p[l];
                dp[i][j]=min(dp[i][j],max(sum,dp[l][j-1]));
            }
        }
    }
    return dp[n][k];
}
int main(){
    int pages[]={10,20,30,40};
    int k=2;
    int n=sizeof(pages)/sizeof(pages[0]);
    cout<<minPages(pages,k,n)<<endl;
    cout<<minPages_dp(pages,n,k);
}