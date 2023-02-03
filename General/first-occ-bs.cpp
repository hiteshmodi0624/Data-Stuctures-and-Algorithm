#include <iostream>
#include <string.h>
#include <math.h>
#include <vector>
#include<numeric>


using namespace std;

int main(){
    int a[]={1,2,3,4,4,5,5,5,5,5};
    int n=sizeof(a)/sizeof(a[0]);
    int b=5;
    int result=-1;
    int low=0;
    int high=n-1;
    while(low<=high){
        int mid=(low+high)/2;
        if(a[mid]==b){
            if(a[mid-1]==b&&mid<=high&&mid>=low){
                high=mid-1;
            }
            else{
                result=mid;
                break;
            }
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