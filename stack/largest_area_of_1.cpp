#include <iostream>
#include <stack>
using namespace std;
int n=4;
int largest_area_histogram(int a[],int n){
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
int largest_area(int a[][4]){
    int res=0;
    for(int i=1;i<n;i++){
        for(int j=0;j<n;j++){
            if(a[i][j]==1)
                a[i][j]=a[i-1][j]+1;
        }
        res=max(res,largest_area_histogram(a[i],4));
    }
    return res;
}
int main(){
    int a[][4]={{0,1,1,0},{1,1,1,1},{1,1,1,1},{1,1,0,0}};
    cout<<largest_area(a);
}
 