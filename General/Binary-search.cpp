#include <iostream>
#include <string.h>
#include <math.h>
#include <vector>
#include<numeric>


using namespace std;

int main(){
    int a[]={10,10};
    int n=sizeof(a)/sizeof(a[0]);
    int b=10;
    int result=-1;
    int low=0;
    int high=n-1;
    while(low<=high){
        int mid=(low+high)/2;
        if(a[mid]==b){
            result=mid;
            break;
        }
        else if(a[mid]>b){
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    cout<<result;
    return 0;
}