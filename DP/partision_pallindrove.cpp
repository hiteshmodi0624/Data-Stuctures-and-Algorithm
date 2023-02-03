#include <iostream>
#include <vector>
using namespace std;
bool isPallindrove(string s,int l,int j){
    for(int i=l;i<=(j+l)/2;i++)
        if(s[i]!=s[j+l-i])
            return false;
    return true;
}
int minPartision(string s,int i,int j){
    if(isPallindrove(s,i,j))
        return 0;
    int res=INT_MAX;
    for(int k=i;k<j;k++)
        res=(min(res,minPartision(s,k+1,j)+minPartision(s,i,k)+1));
    return res;
}
int minPartision_dp(string s){
    int n=s.length();
    int dp[n][n];
    bool isPal[n][n];
    for(int i=0;i<n;i++){
        dp[i][i]=0;
        isPal[i][i]=true;
    }
    for(int i=n-1;i>=0;i--){
        for(int j=i+1;j<n;j++){
            if(s[i]==s[j]&&(isPal[i+1][j-1]||j-i==1)){
                isPal[i][j]=true;
                dp[i][j]=0;
            }
            else{
                isPal[i][j]=false;
                dp[i][j]=INT_MAX;
                for(int k=i;k<j;k++)
                    dp[i][j]=min(dp[i][j],dp[k+1][j]+dp[i][k]+1);
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++)
            cout<<dp[i][j]<<" ";cout<<endl;}
    return dp[0][n-1];
}
int main(){
    string s="geek";
    cout<<minPartision_dp(s);
}