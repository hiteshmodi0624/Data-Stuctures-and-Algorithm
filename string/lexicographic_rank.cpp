#include <iostream>
#include <string.h>
#include <unordered_map>
using namespace std;

unsigned int factorial(unsigned int n)
{
    if(n==0)
        return 1;
    int i=n, fact=1;
    while (n/i!=n)
    {
        fact=fact*i;
        i--;
    }
    return fact;
}
int lrank(string s){
    int n=s.length();
    int f=factorial(n);
    int count[256]={0};
    int res=1;
    for(int i=0;i<n;i++)
        count[s[i]]++;
    for(int i=1;i<256;i++)
        count[i]+=count[i-1];
    // through this we get the number of sizes smaller than the each string
    for(int i=0;i<n-1;i++){
        f=f/(n-i);
        res=res+count[s[i]-1]*f;
        for(int j=s[i];j<256;j++)
            count[j]--; 
    }
    return res;
}
int main(){
    string s="string";
    cout<<lrank(s);
}