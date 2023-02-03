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
    string s="aabba";
    int x=1;
    int n=s.length();
    for(int i=0;i<=n/2;i++)
        if(s[i]!=s[n-i-1]){
            x--;
            break;
        }
    if(x)
        cout<<"yes";
    else    
        cout<<"no";
}
 