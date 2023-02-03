#include <iostream>
#include <string.h>
using namespace std;

// array construction function(part-1)
void fillLPS(string s,int* lps,int n){
    int len=0;
    lps[0]=0;
    int i=1;
    while(i<n)
        if(s[i]==s[len])
            lps[i++]=++len;
        else if(len==0)
            lps[i++]=0;
        else
            len=lps[len-1];
}

void KMP_algo(string s,string s2) 
{ 
    int n=s.length();
    int m=s2.length();
    int lps[m];
    fillLPS(s2,lps,m);
    int i=0,j=0;
    while(i<n){
        if(s2[j]==s[i]){
            i++;
            j++;
        }
        if(j==m){
            cout<<i-j;
            j=lps[j-1];
        }
        else if(i<n&&s2[j]!=s[i]){
            if(j==0)
                i++;
            else
                j=lps[j-1];
        }
    }
} 

int main(){
    KMP_algo("ababcababaad","ab");
}