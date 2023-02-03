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
    int a[]={1,2,3,4,8};
    int sum=6;
    unordered_set<int> s;
    int n=sizeof(a)/sizeof(a[0]);
    for(int i=0;i<n;i++){
        if(s.find(sum-a[i])!=s.end()){
            cout<<a[i]<<" "<<sum-a[i];
            break;
        }
        else
            s.insert(a[i]);
    }
    
}
 