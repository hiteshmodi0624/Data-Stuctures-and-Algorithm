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
void reverse(string &s,int low,int high){
    while(low<=high){
        swap(s[low],s[high]);
        low++;
        high--;
    }

}
void check(string s1,int n, string s2="xyz",int m=0){
    int start=0;
    for(int i=0;i<n;i++){
        if(s1[i]==' ')
        {
            reverse(s1,start,i-1);
            start=i+1;
        }
    }
    reverse(s1,start,n-1);
    reverse(s1,0,n-1);
    cout<<s1;
}

void mymethod(string s1,int n, string s2="xyz",int m=0){
    int i=n;
    int j=n-1;
    while(i>0){
        do
          j--;
        while(s1[j]!=' '&&j>=0);
        for(int k=j+1;k<i;k++)
            cout<<s1[k];
        cout<<" ";
        i=j;
    }
}
int main(){
    string s1="welcome to gfg";
    int n=s1.length();
    // string s2="listenr";
    // int m=s2.length();
    check(s1,s1.length());
    // cout<<check(s1,s1.length(),s2,s2.length());
}
 