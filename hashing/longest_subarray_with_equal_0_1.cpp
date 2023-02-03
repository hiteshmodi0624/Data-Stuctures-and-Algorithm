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
    unordered_map<int,int> p;
    int res=0,temp=0;
    p[0]=-1;
    for(int i=0;i<n;i++){
        if(a[i]==0)
            temp+=-1;
        else
            temp+=1;
        if(p.find(temp)!=p.end())
            res=max(res,i-p[temp]);
        else{
            p[temp]=i;
        }
    }
    return res;
}
int main(){
    int a[]={0,1,1,0,1,1,1,1,0,0,0};
    int n=sizeof(a)/sizeof(a[0]);
    cout<<size_longest(a,n);  
}
 