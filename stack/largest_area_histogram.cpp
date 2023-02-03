#include <iostream>
#include <stack>
using namespace std;
int largest_area(int a[],int n){
    stack<int>s;
    int next[n];
    int prev[n];
    int res=0;
    for(int i=0;i<n;i++){
        while(s.empty()!=true&&a[i]<=a[s.top()])
            s.pop();
        prev[i]=s.empty()?-1:s.top();
        s.push(i);
    }
    while(s.empty()==false)
        s.pop();
    for(int i=n-1;i>=0;i--){
        while(s.empty()!=true&&a[i]<=a[s.top()])
            s.pop();
        next[i]=s.empty()?n:s.top();
        s.push(i);
    }
    for(int i=0;i<n;i++)
        res=max(res,a[i]*(next[i]-prev[i]-1));
    return res;
}
int largest_area_best(int a[],int n){
    stack<int>s;
    int res=0;
    for(int i=0;i<n;i++){
        while(s.empty()==false&&a[s.top()]>=a[i]){
            int tp=s.top();
            s.pop();
            res=max(res,(a[tp]*(s.empty()?i:i-1-s.top())));
        }
        s.push(i);
    }
    while(s.empty()==false){
        int tp=s.top();
        s.pop();
        res=max(res,(a[tp]*(s.empty()?n:n-1-s.top())));
    }
    return res;
}
int main(){
    int a[]={6,2,5,4,1,5,6};
    int n=sizeof(a)/sizeof(a[0]);
    cout<<largest_area(a,n)<<endl;
    cout<<largest_area_best(a,n);
}
 