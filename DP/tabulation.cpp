#include <iostream>
#include <vector>
using namespace std;


int fibonacci(int x){
    int dp[x];
    dp[0]=0;
    dp[1]=1;
    for(int i=2;i<=x;i++){
        dp[i]=dp[i-1]+dp[i-2];
    }
    return dp[x];
}
int main(){
    int n=6;
    cout<<fibonacci(n);
}
 