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
void naive(string s1,int n, string s2="xyz",int m=0){
    for(int i=0;i<=n-m;i++){
        int j=0;
        while(s1[i+j]==s2[j]&&j<m)
            j++; 
        if(j==m)
            cout<<i<<" ";
    }
}
void naive_distinct(string s1,int n, string s2="xyz",int m=0){
    for(int i=0;i<=n-m;){
        int j=0;
        while(s1[i+j]==s2[j]&&j<m)
            j++; 
        if(j==m)
            cout<<i<<" ";
        if(j==0)
            i++;
        else 
            i=i+j;
    }
}
int main(){
    string s1="ABCDEFCDE";
    string s2="CDE";
    naive(s1,s1.length(),s2,s2.length());
    naive_distinct(s1,s1.length(),s2,s2.length());
}
 