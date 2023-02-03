#include <iostream>
#include <string.h>
#include <math.h>
#include <vector>
#include<numeric>
#include<algorithm>

using namespace std;

int main(){
    int a[]={10,15,20,11,30,40};
    int n=sizeof(a)/sizeof(a[0]);
    int b[n];
    int x=(n-1)/2+1;
    int low=0,mid=x,high=n-1;
    int i=0;
    while((low<x)&&(mid<n)){
        if(a[low]>a[mid]){
            b[i]=a[mid];
            mid++;
        }
        else{
            b[i]=a[low];
            low++;
        }
        i++;
    }
    while(low<x){
        b[i]=a[low];
        low++;
        i++;
    }
    while(mid<n){
        b[i]=a[mid];
        mid++;
        i++;
    }
    for(int j=0;j<n;j++){
        a[j]=b[j];
        cout<<a[j]<<" ";
    }

}
 