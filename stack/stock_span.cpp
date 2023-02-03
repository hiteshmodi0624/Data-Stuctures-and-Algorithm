#include <iostream>
#include <stack>
using namespace std;
void stock_span(int a[],int n){
    stack<int>s;
    for(int i=0;i<n;i++){
        while(s.empty()!=true&&a[i]>=a[s.top()])
            s.pop();
        cout<<(s.empty()?i+1:i-s.top())<<" ";
        s.push(i);
    }
}
int main(){
    int a[]={60,10,20,40,35,38,50,70,65};
    int n=sizeof(a)/sizeof(a[0]);
    stock_span(a,n);
}
 