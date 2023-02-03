#include <iostream>
#include <queue>
#include<set>
#include<map>
using namespace std;

int main(){
    set<int>s;
    int arr[]={2,8,30,15,25,12};
    int n=sizeof(arr)/sizeof(arr[0]);
    for(int i=0;i<n;i++){
        auto it=s.lower_bound(arr[i]);
        if(it!=s.end())
            cout<<*it<<" ";
        else
            cout<<-1<<" ";
        s.insert(arr[i]);
    }
}