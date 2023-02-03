#include <iostream>
#include <vector>
using namespace std;


int fibonacci(int x,vector<int> &memo){
    if(memo[x]==-1){
        int res;
        if(x==0||x==1)
            res=x;
        else res=fibonacci(x-1,memo)+fibonacci(x-2,memo);
        memo[x]=res;
    }
    return memo[x];
}
int main(){
    int n=6;
    vector<int> memo(n+1,-1);
    cout<<fibonacci(n,memo);
}
 