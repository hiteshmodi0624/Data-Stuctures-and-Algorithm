#include <iostream>
#include <string.h>
#include <math.h>
#include <vector>
#include<numeric>


using namespace std;


int main(){
    int a[]={8,-4,3,-5,4};
    int n=sizeof(a)/sizeof(a[0]),temp=a[0],mini=a[0],r=0,curr=a[0]; 
    for(int i=0;i<n;i++){
        mini=min(mini,a[i]);
        if(mini==a[i])
            r=i;
    }
    for(int i=1;i<n;i++){
        curr=max(a[i],a[i]+curr);
        temp=max(temp,curr);
    }
    int temp2=a[r];
    for(int i=r+1;(i%n)!=r;i++){
        a[i%n]=max(a[i%n],a[i%n]+a[(i-1)%n]);
        temp2=max(temp2,a[i%n]);
    }
    cout<<max(temp,temp2);
}
 