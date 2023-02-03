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
    int arr[]={10,20,30,40,10,20,10,40};
    unordered_map<int,int> m;
    for(int i=0;i<8;i++)
        m[arr[i]]++;
    for(auto it=m.begin();it!=m.end();it++)
        cout<<it->first<<" "<<it->second<<endl;
}
 