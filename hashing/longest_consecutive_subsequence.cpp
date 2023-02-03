#include <iostream>
#include <string.h>
#include <math.h>
#include <vector>
#include <list>
#include<numeric>
#include<unordered_set>
#include<unordered_map>

using namespace std;
int size_longest(int a[],int n){
    unordered_set<int> p;
    int res=1;
    for(int i=0;i<n;i++)
        p.insert(a[i]);
    for(auto it=p.begin();it!=p.end();it++){
        if(p.find(*it-1)==p.end()){
            int y=1;
            while(p.find(*it+y)!=p.end())
                y++;
            res=max(res,y);
        }
    }
    return res;
}
int main(){
    int a[]={1,3,4,3,3,2,9,10};
    int n=sizeof(a)/sizeof(a[0]);
    cout<<size_longest(a,n);  
}
 