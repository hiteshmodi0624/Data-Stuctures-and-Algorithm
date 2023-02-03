#include <iostream>
#include <stack>
using namespace std;
void stock_span(int a[],int n){
    stack<int>s,s2;
    for(int i=n-1;i>=0;i--){
        while(s.empty()!=true&&a[i]>=s.top())
            s.pop();
        s2.push(s.empty()?-1:s.top());
        s.push(a[i]);
    }
    while(s2.empty()==false){
        cout<<s2.top()<<" ";
        s2.pop();
    }
}
int main(){
    int a[]={5,15,10,8,6,12,9,18};
    int n=sizeof(a)/sizeof(a[0]);
    stock_span(a,n);
}
 