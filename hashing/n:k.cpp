#include <iostream>
#include <string.h>
#include <math.h>
#include <vector>
#include <list>
#include<numeric>
#include<unordered_set>
#include<unordered_map>

using namespace std;
void one_method_nk(int a[],int n,int k){
    unordered_map<int,int> p;
    for(int j=0;j<n;j++)
        p[a[j]]++;
    for(auto x:p){
        if(x.second>n/k)
            cout<<x.first<<" ";
    }
}
void two_method_nk(int a[],int n,int k){
    // maximum number of the values in the output cannot be more than k-1
    unordered_map<int,int> p;
    for(int i=0;i<n;i++){
        if(p.find(a[i])!=p.end())
            p[a[i]]++;
        else if(p.size()<k-1)
            p[a[i]]++;
        else{
            for(auto x:p){
                x.second--;
                if(x.second==0)
                    p.erase(x.first);
            }
        }
    }
    for(auto x:p){
        int z=0;
        for(int i=0;i<n;i++){
            if(a[i]==x.first)
                z++;
        }
            if(z>n/k)
            cout<<x.first<<" ";
    }
}
int main(){
    int a[]={30,10,20,20,10,20,30,30};
    int n=sizeof(a)/sizeof(a[0]),k=4;
    one_method_nk(a,n,k);  
    cout<<endl;
    two_method_nk(a,n,k);  
}
 