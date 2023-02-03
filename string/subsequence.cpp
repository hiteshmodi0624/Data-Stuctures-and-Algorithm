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
bool check(string &s2,string s1="abcde",int n=5,int m=3){
    if (m==0)
        return true;
    if (n==0)
        return false;
    if(s1[n-1]==s2[m-1])
        return check(s2,s1,n-1,m-1);
    else
        return check(s2,s1,n-1,m);
}
bool check2(string s2){
    string s1="abcde";
    int j=0;
    int m=s2.length();
    int n=s1.length();
    for(int i=0;i<n&&j<m;i++)
        if(s1[i]==s2[j])
            j++;
    return j==m;
}
int main(){
    string s2="aed";
    cout<<check(s2);
    cout<<check2(s2);
    s2="ade";
    cout<<check(s2);
    cout<<check2(s2);

}
 