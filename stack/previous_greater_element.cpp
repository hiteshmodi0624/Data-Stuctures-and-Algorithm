#include <bits/stdc++.h>
using namespace std;

void stock_span(int a[],int n){
    stack<int>s;
    for(int i=0;i<n;i++){
        while(s.empty()!=true&&a[i]>=s.top())
            s.pop();
        cout<<(s.empty()?-1:s.top())<<" ";
        s.push(a[i]);
    }
}
int main(){
    int a[]={20,30,10,5,55};
    int n=sizeof(a)/sizeof(a[0]);
    stock_span(a,n);
}