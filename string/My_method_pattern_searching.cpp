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
void rabin_karp(string s1,int n, string s2="xyz",int m=0){
    unordered_set<string>p;
    p.insert(s2);
    for(int i=0;i<=n-m;i++)
        if(p.find(s1.substr(i,m))!=p.end())
            cout<<i<<" ";
}
int main(){
    string s1="ABCDEFCDE";
    string s2="CDE";
    rabin_karp(s1,s1.length(),s2,s2.length());
}
 