#include <iostream>
#include <string.h>
#include <math.h>
#include <vector>
#include<numeric>
#include<algorithm>

using namespace std;
int partition(int a[],int l,int h){
    int r=rand()/RAND_MAX;
    r=l+r*(h-l);
    swap(a[r],a[h]);
    int pivot=a[h];
    int i=l-1;
    for(int j=l;j<h;j++){
        if(a[j]<pivot){
            i++;
            swap(a[i],a[j]);
        }
    }
    swap(a[i+1],a[h]);
    return i+1;
}
void qsort(int a[],int l,int h){
    if(l<h){
        int p=partition(a,l,h);
        qsort(a,l,p-1);
        qsort(a,p+1,h);
    }
}
int main(){
    int arr[]={70,60,35,40,30,31,35};
    int n=sizeof(arr)/sizeof(arr[0]);
    qsort(arr,0,n-1);
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
}
 