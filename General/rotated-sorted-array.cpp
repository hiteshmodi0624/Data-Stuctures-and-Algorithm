#include <iostream>
#include <string.h>
#include <math.h>
#include <vector>
#include<numeric>

using namespace std;

int main(){
    int a[]={787,899,0,1,2,3,4,5,6,7,8,9,101,323,453,535,654};
    // int a[]={2,3,4,5,6,7,8,9,101,323,453,535,654,787,899,0,1};
    int n=sizeof(a)/sizeof(a[0]);
    for(int i=0;i<n;i++){
        int b=a[i];
        int result=-1;
        int start=0;
        while(start<=n){
            int mid=(start+n)/2;
            if(a[mid]==b){
                result=mid;
                break;
            }
            else if (a[start]>a[mid]){
                if(a[start]<=b||a[mid]>b)  
                    n=mid-1;
                else
                    start=mid+1;
            }
            else{
                if(a[mid]>b&&b>=a[start])  
                    n=mid-1;
                else
                    start=mid+1;
            }
            // else if((a[mid]>b&&a[start]<=b)||((a[start]<=b||a[mid]>b)&&(a[start]>a[mid]))){
            //     n=mid-1;
            // }
            // else{
            //     start=mid+1;  
            // }
        }
        cout<<result<<endl;
        n=sizeof(a)/sizeof(a[0]);
    }
}
 