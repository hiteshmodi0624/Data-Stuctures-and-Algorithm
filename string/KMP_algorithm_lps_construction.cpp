#include <iostream>
#include <string.h>
using namespace std;

// array construction function(part-1)
void fillLPS(string s,int* lps,int n){
    int len=0;
    lps[0]=0;
    for(int i=1;i<n;i++){
        if(s[i]==s[len])
            lps[i]=++len;
        else if(len==0)
            lps[i]=0;
        else{
            len=lps[len-1];
            i--;
            // so that the loop does not increment
        }
    }
}

int main() 
{ 
    string s="aaabaaaac";
    int n=s.length();
    int lps[n];
    fillLPS(s,lps,n);
    for(int i=0;i<n;i++)
        cout<<lps[i]<<" ";
} 