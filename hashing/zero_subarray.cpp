#include <iostream>
#include <string.h>
#include <math.h>
#include <vector>
#include <list>
#include<numeric>
#include<unordered_set>
#include<unordered_map>

using namespace std;
bool check(int a[],int n){
    int sum=0;
    unordered_set<int> s;
    for(int i=0 ;i<n;i++){
        sum+=a[i];
        if(s.find(sum)!=s.end()||sum==0){
            return true;
        }
        s.insert(sum);
    }
    return false;
}
int main(){
    int a[]={5,-6,1,8};
    int n=sizeof(a)/sizeof(a[0]);
    cout<<check(a,n);  
}
 