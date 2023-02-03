#include <iostream>
#include <vector>
using namespace std;
int mat_chain(int a[],int i,int j){
    if(i+1==j){
        return 0;
    }
    int res=INT_MAX;
    for(int k=i+1;k<j;k++){
        res=min(res,mat_chain(a,i,k)+mat_chain(a,k,j)+a[i]*a[k]*a[j]);
    }
    return res;
}
int mat_chain_dp(int a[],int n){
    int dp[n][n];
    for(int i=0;i<n;i++)
        dp[i][i+1]=0;
    for(int i=n-1;i>=0;i--){
        for(int j=i+2;j<n;j++){
            dp[i][j]=INT_MAX;
            for(int k=i+1;k<j;k++)
                dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]+a[i]*a[j]*a[k]);
        }
    }
    return dp[0][n-1];
}
int main(){
    int a[]={2,1,3,4};
    int n=sizeof(a)/sizeof(a[0]); 
    cout<<mat_chain(a,0,n-1);
    cout<<mat_chain_dp(a,n);
}
