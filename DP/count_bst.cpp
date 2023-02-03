#include <iostream>
#include <vector>
using namespace std;
struct bridges{
    int x,y;
};
int bst_dp(int n){
    int dp[n+1];
    dp[0]=1;
    for(int i=1;i<=n;i++){
        dp[i]=0;
        for(int j=1;j<=i;j++)
            dp[i]+=dp[j-1]*dp[i-j];
    }
    return dp[n];
}
int main(){
    int n=5;
    cout<<bst_dp(n);
}