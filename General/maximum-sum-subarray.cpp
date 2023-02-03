#include <iostream>
#include <string.h>
#include <math.h>
#include <vector>
#include<numeric>


using namespace std;


int main(){
    int a[]={2,-1,5,-2,6};
    int n=sizeof(a)/sizeof(a[0]),temp=a[0]; 

    for(int i=1;i<n;i++){
        a[i]=max(a[i],a[i]+a[i-1]);
        temp=max(temp,a[i]);
    }
    cout<<temp;
}
 