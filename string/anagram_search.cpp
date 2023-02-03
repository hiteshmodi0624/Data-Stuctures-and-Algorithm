#include <iostream>
#include <string.h>
#include <unordered_map>
using namespace std;

bool check(int a[],int b[]){
    for(int i=0;i<256;i++)
        if(a[i]!=b[i])
            return false;
    return true;
}
bool checkanagram(string s1,string s2){
    int n=s1.length(),m=s2.length();
    int a[256]={0},b[256]={0};
    for(int i=0;i<m;i++){
        a[s1[i]]++;
        b[s2[i]]++;
    }
    for(int i=m;i<n;i++){
        if(check(a,b))
            return true;
        else {
            a[s1[i]]++;
            a[s1[i-m]]--;
        }
    }
    return false;
}
int main(){
    string s1="geeksforgeeks",s2="frog";
    cout<<checkanagram(s1,s2);
}