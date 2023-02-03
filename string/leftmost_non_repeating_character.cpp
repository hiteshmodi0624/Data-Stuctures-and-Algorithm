#include <iostream>
#include <string.h>
#include <math.h>
#include <vector>
#include <list>
#include<numeric>
#include<algorithm>
#include<unordered_set>
#include<unordered_map>

using namespace std;
int check(string s1,int n, string s2="xyz",int m=0){
    int res=-1;
    int c[256]={0};
    for(int i=n-1;i>=0;i--)
        if(c[s1[i]])
            c[s1[i]]=-1;
        else 
            c[s1[i]]=1;
    for(int i=n-1;i>=0;i--)
        if(c[s1[i]]==1)
            res=i;
    return res;
}
int main(){
    string s1="geeksforgeeks";
    int n=s1.length();
    // string s2="listenr";
    // int m=s2.length();
    cout<<check(s1,s1.length());
    // cout<<check(s1,s1.length(),s2,s2.length());
}
 