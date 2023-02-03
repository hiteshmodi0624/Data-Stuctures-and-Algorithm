#include <iostream>
#include <string.h>
#include <math.h>
#include <vector>
#include <list>
#include<numeric>
#include<unordered_set>
#include<unordered_map>

using namespace std;
void dis(int a[],int n,int m){
    unordered_map<int,int> p;
    for(int j=0;j<m;j++){
        p[a[j]]++;
    }
    cout<<p.size();
    for(int i=1;i<n-m+1;i++){
        if(--p[a[i-1]]==0)
            p.erase(a[i-1]);
        p[a[i+m-1]]++;
        cout<<p.size();
    }
}
int main(){
    int a[]={10,20,20,10,30,40};
    int n=sizeof(a)/sizeof(a[0]),size=4;
    dis(a,n,size);  
}
 