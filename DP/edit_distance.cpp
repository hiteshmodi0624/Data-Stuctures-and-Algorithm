#include <iostream>
#include <vector>
using namespace std;
int ed(string s1,string s2,int n,int m){
    if(n==0)return m;
    if(m==0)return n;
    if(s1[n-1]==s2[m-1])
        return ed(s1,s2,n-1,m-1);
    else
        return 1+min(ed(s1,s2,n-1,m-1),min(ed(s1,s2,n,m-1),ed(s1,s2,n-1,m)));
}
int ed_dp(string s1,string s2){
    int n=s1.length();int m=s2.length();
    int dp[n+1][m+1];
    for(int i=0;i<=n;i++)
        dp[i][0]=i;
    for(int i=0;i<=m;i++)
        dp[0][i]=i;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++){
            if(s1[i-1]==s2[j-1])
                dp[i][j]=dp[i-1][j-1];
            else
                dp[i][j]=min(min(dp[i-1][j-1],dp[i][j-1]),dp[i-1][j])+1;
        }
    return dp[n][m];
}

int main(){
    string s1="saturday",s2="sunday";
    cout<<ed(s1,s2,s1.length(),s2.length());
    cout<<ed_dp(s1,s2);
}

 