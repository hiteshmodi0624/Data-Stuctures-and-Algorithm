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
int main(){
    char str[]="geeksforgeeks";
    int count[26]={0};
    for (int i=0;i<strlen(str);i++)
        count[str[i]-'a']++;
    for(int i=0;i<26;i++){
        if(count[i])
            cout<<char(i+'a')<<":"<<count[i]<<" ";
    }
    cout<<endl;
    
    char s[]="gfg";
    // string s[0]=g, s[1]=f, s[2]=g, s[3]=\0, always double quote is used(""). 
    cout<<s<<sizeof(s);
    char s2[]={'g','f','g'};
    // s[0]=g, s[1]=f, s[2]=g, s[3] can we anything, thus it have multiple outputs depending on your compiler. always double quote is used(''). 
    cout<<s2<<sizeof(s2);
    // use s3 instead of s2 for better output
    char s3[]={'g','f','g','\0'};
    cout<<endl;

    char a[]="abcd";
    char b[]="abca";
    cout<<strcmp(a,a)<<strcmp(b,a)<<strcmp(a,b);
    // -3 as d-a=3.
    cout<<endl;

    // b="abcd"; will generate error, thus we use
    strcpy(b,"abcd");
    cout<<strcmp(a,a)<<strcmp(b,a)<<strcmp(a,b);
}
 