#include <iostream>
#include <string.h>
#include <math.h>
#include <vector>
#include<numeric>

using namespace std;

int main(){
    int a[]={10,20,20,20,20,20,20,20,20,30,30,30,30,30,30};
    int n=sizeof(a)/sizeof(a[0]),b=20;
    int low=0,high=n-1;
    int min=-1,max,mid;
    while(low<=high){
        int mid=(low+high)/2;
        if(a[mid]==b){
            if(a[mid-1]==b&&mid<=high&&mid>=low){
                high=mid-1;
            }
            else{
                min=mid;
                break;
            }
        }
        else if(a[mid]>b)
            high=mid-1;
        else    
            low=mid+1;
    }
    if(min==-1)
        cout<<0;
    else{
        low=0,high=n-1;
        while(low<=high){
            int mid=(low+high)/2;
            if(a[mid]==b){
                if(a[mid+1]==b&&mid<=high&&mid>=low){
                    low=mid+1;
                }
                else{
                    max=mid;
                    break;
                }
            }
            else if(a[mid]>b)
                high=mid-1;
            else    
                low=mid+1;
        }
        cout<<max-min+1;
    }
    return 0;
}
 