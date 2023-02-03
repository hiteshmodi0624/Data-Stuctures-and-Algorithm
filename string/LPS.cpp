#include <iostream>
#include <string.h>
using namespace std;

int longPropPreSuff(string str,int n){
     for(int i=n-1;i>0;i--){
        bool flag=true;
        for(int j=0;j<i&&flag;j++)
            if(str[j]!=str[n-i+j])
                flag=false;
        if(flag==true)
            return i;
     }
     return 0;
}
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
void fillLPS(string str,int* lps){
    for(int i=0;i<str.length();i++)
        lps[i]=longPropPreSuff(str,i+1);
}

int main() 
{ 
    string s="abkraacbkra";
    int lps[s.size()];
    fillLPS(s,lps);
    for(int i=0;i<s.size();i++)
        cout<<lps[i]<<" ";
} 