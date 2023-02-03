#include <iostream>
#include <string.h>
#include <vector>
using namespace std;

int length(string s){
    int n=s.length(),j=0,res=0;
    vector<int>prev(256,-1);

    for(int i=0;i<n;i++){
        j=max(j,prev[s[i]]+1);
        int maxend=i-j+1;
        res=max(res,maxend);
        prev[s[i]]=i;
    }
    return res;
}
int main(){
    string s="abcadbd";
    cout<<length(s);
}