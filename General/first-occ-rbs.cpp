#include <iostream>
#include <string.h>
#include <math.h>
#include <vector>
#include<numeric>


using namespace std;
int rbs(int a[],int b,int high,int low=0){
    if(low>high)
        return -1;
    int mid=(low+high)/2;
    if(a[mid]==b){
        if(a[mid-1]==b&&mid<=high&&mid>=low){
            return rbs(a,b,mid-1,low);
        }
        else{
            return mid;
        }
        return mid;
    }
    else if(a[mid]>b)
        return rbs(a,b,mid-1,low);
    else
        return rbs(a,b,high,mid+1);
}
int main(){
    int a[]={1,2,3,5,5,5,5,6,9,9,9};
    cout<<rbs(a,5,sizeof(a)/sizeof(a[0])-1);
    return 0;
}