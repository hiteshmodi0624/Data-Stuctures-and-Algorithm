#include <iostream>
#include <string.h>
#include <math.h>
#include <vector>
#include<numeric>
#include<algorithm>

using namespace std;

int merge(int a[],int low, int mid,int high){
    int n1=mid-low+1,n2=high-mid;
    int right[n1],left[n2];
    for(int i=0;i<n1;i++)
        left[i]=a[low+i];
    for(int i=0;i<n2;i++)
        right[i]=a[mid+i+1];
    int i=0,j=0,k=low,res=0;
    while(i<n1&&j<n2){
        if(left[i]<=right[j]){
            a[k]=left[i];
            i++;
        }
        else{
            a[k]=right[j];
            j++;
            res=res+n1-i;
        }
        k++;
    }
    while(i<n1){
        a[k]=left[i];
        k++;
        i++;
    }
    while(j<n2){
        a[k]=right[j];
        k++;
        j++;
    }
    return res;
}
int mergeSort(int a[],int l,int r){
    int res=0;
    if(r>l){
        int m=l+(r-l)/2;
        res+=mergeSort(a,l,m);
        res+=mergeSort(a,m+1,r);
        res+=merge(a,l,m,r);
    }
    return res;
}
int main(){
    int a[]={70,15,20,9,30,40};
    int n=sizeof(a)/sizeof(a[0]);
    int res=mergeSort(a,0,n-1);
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
    cout<<res;
}
 