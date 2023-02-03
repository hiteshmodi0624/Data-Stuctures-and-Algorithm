#include <iostream>
#include <string.h>
#include <math.h>
#include <vector>
#include<numeric>
#include<algorithm>

using namespace std;
void sort_three(int a[],int l,int h){
    int r=l+rand()/RAND_MAX*(h-l+1);
    int pivot=a[l],mid=0;
    swap(a[r],a[l]);
    while(mid<=h){
        if(a[mid]<7){
            swap(a[mid],a[l]);
            mid++;
            l++;
        }
        else if(a[mid]>=7&&a[mid]<=21){
            mid++;
        }
        else{
            swap(a[mid],a[h]);
            h--;
        }
    }
}
int main(){
    // int a[]={15,-3,-2,18,23,-2,12,43,54,-34,23,-45,-65,90,1,0};
    int a[]={10,5,6,3,20,9,40};
    int n=sizeof(a)/sizeof(a[0]);
    sort_three(a,0,n-1);
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
}
 