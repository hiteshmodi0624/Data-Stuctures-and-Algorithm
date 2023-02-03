#include <iostream>
#include <string.h>
#include <math.h>
#include <vector>
#include <list>
#include<numeric>
#include<unordered_set>
#include<unordered_map>

using namespace std;
int main(){
    int a[]={10,20,10,30};
    int b[]={20,10,10,40};
    int res=0;
    int n=sizeof(a)/sizeof(a[0]);
    int m=sizeof(b)/sizeof(b[0]);
    unordered_set<int> s(a,a+n);
    for(int i=0;i<m;i++){
        if(s.find(b[i])!=s.end()){
            res++;
            s.erase(b[i]);
        }
    }
    cout<<res;
}
 