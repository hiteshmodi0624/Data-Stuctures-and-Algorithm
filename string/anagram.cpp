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
int  check(string s1,string s2,int n, int q){
    if(n!=q)
        return 0;
    int m[256]={0};
    for(int i=0;i<n;i++)
        m[s1[i]]++;
    for(int i=0;i<n;i++){
        m[s2[i]]--;
        if(m[s2[i]]<0)
            return 0;
    }
    return 1;
}
int main(){
    string s1="listenr",s2="silefnt";
    cout<<check(s1,s2,s1.length(),s2.length());
    string s3="listen",s4="silent";
    cout<<check(s3,s4,s3.length(),s4.length());
}
 