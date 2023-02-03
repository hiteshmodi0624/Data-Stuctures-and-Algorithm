#include <iostream>
#include <string.h>
#include <math.h>
#include <vector>
#include<numeric>

using namespace std;

int main(){
    int a[]={1,4,20,3,10,22};
    int n=sizeof(a)/sizeof(a[0]),temp=0,sum=0,giv=33,i=0;
    int l=2,r=5;
    for(int i=1;i<n;i++){
        a[i]=a[i]+a[i-1];
    }
    if(l!=0)
        cout<<a[r]-a[l-1];
    else
        cout<<a[r];
    
}
 