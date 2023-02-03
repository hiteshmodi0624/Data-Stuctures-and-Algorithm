#include <iostream>
#include <string.h>

using namespace std;
int d=256;
int q=101;
void rabin_karp(string s1,int n, string s2="xyz",int m=0){
    int h=1;
    for(int i=1;i<m;i++)
        h=h*d%q;
    int req=0,temp=0,j=0;
    while(j<m){
        req=((s2[j])+req*d)%q;
        temp=((s1[j])+temp*d)%q;
        j++;
    }
    for(int i=0;i<=n-m;i++){
        if(temp==req){
            int k=0;
            while(s1[i+k]==s2[k]&&k<m)k++;
            if(k==m)cout<<i<<" ";
        }
        if(i<n-m)
            temp=(d*(temp-(s1[i])*h)+(s1[i+m]))%q;
        if(temp<0)temp=temp+q;
    }
}
int main(){
    string s1="abdabcdbda";
    string s2="bda";
    rabin_karp(s1,s1.length(),s2,s2.length());
}
 