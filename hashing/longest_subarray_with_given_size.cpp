#include <iostream>
#include <string.h>
#include <math.h>
#include <vector>
#include <list>
#include<numeric>
#include<unordered_set>
#include<unordered_map>

using namespace std;
int size_longest(int a[],int n,int sum){
    unordered_map<int,int> p;
    int res=0,temp=0;
    p[0]=-1;
    for(int i=0;i<n;i++){
        temp+=a[i];
        if(p.find(temp)==p.end())
            p[temp]=i;
        if(p.find(temp-sum)!=p.end())
            res=max(res,i-p[temp-sum]);
    }
    return res;
}
int main(){
    int a[]={8,3,1,5,-6,6,2,2};
    int n=sizeof(a)/sizeof(a[0]);
    int sum=4;
    cout<<size_longest(a,n,sum);  
}
 