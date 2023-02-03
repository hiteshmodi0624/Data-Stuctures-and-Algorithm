#include <iostream>
#include <string.h>
#include <math.h>
#include <vector>
#include<numeric>

using namespace std;

int main(){
    int a[]={3,4,8,-9,20,6};
    int n=sizeof(a)/sizeof(a[0]),temp=0,sum=0,giv=33,i=0;
    int l=2,r=5,x=0;
    int b[n],c[n];
    b[0]=a[0];
    for(int i=0;i<n;i++){
        x+=a[i];
    }
    int pre,pos=a[n-1];
    for(int i=n-2;i>=0;i--){
        pos+=a[i];
        x-=a[i+1];
        if(x==pos)
            cout<<"YES";
        
    }
}
 