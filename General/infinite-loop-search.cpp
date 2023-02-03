#include <iostream>
#include <string.h>
#include <math.h>
#include <vector>
#include<numeric>

using namespace std;

int main(){
    int a[]={0,1,2,3,4,5,6,7,8,9,101,323,453,535,654,787,899};
    int n=sizeof(a)/sizeof(a[0]);
    int b=1900;
    int result=-1;
    if (b==a[0]){
        result=0;
    }
    else if (a[0]<b){
        for(int i=1;i<n;i=i*2){
            if(a[i]==b){
                result=i;
                break;
            }
            else if (a[i]>b){
                n=i-1;  
                break;
            }
        }
        int start=n/2+1;
        while(start<=n){
            int mid=(start+n)/2;
            if(a[mid]==b){
                result=mid;
                break;
            }
            else if(a[mid]>b)
                n=mid-1;
            else    
                start=mid+1;
        }
    }
    cout<<result;

}
 