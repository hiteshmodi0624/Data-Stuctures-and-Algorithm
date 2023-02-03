#include <iostream>
#include <string.h>
#include <math.h>
#include <vector>
#include<numeric>

using namespace std;

int main(){
    int a[]={120,80,40,30,20,50,60};
    // int a[]={2,3,4,5,6,7,8,9,101,323,453,535,654,787,899,0,1};
    int n=sizeof(a)/sizeof(a[0]);
    int result=-1;
    int start=0;
    while(start<=n){
        int mid=(start+n)/2;
        if((mid==0||a[mid-1]<=a[mid])&&(mid==n-1||a[mid+1]<=a[mid])){
            result=mid;
            break;
        }
        else if(mid>0&&a[mid]<a[mid-1])
            n=mid-1;
        else    
            start=mid+1;
    }
    cout<<a[result]<<endl;
    n=sizeof(a)/sizeof(a[0]);
}
 