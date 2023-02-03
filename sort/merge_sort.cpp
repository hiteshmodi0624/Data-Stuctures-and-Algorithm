#include <iostream>
#include <string.h>
#include <math.h>
#include <vector>
#include<numeric>
#include<algorithm>

using namespace std;
void merge(int a[],int l,int m,int r){
    int n1=m-l+1, n2=r-m;
    int right[n1],left[n2];
    for(int i=0;i<n1;i++)
        right[i]=a[l+i];
    for(int i=0;i<n2;i++)
        left[i]=a[m+1+i];
    int i=0,j=0,k=l;
    while(i<n1&&j<n2){
        if(right[i]>left[j]){
            a[k]=left[j];
            j++;
        }
        else{
            a[k]=right[i];
            i++;
        }
        k++;
    }
    while(j<n2){
        a[k]=left[j];
        j++;
        k++;
    }
    while(i<n1){
        a[k]=right[i];
        i++;
        k++;
    }
}
void mergesort(int a[],int l,int r){
    if(l<r){
        int mid=l+(r-l)/2;
        mergesort(a,l,mid);
        mergesort(a,mid+1,r);
        merge(a,l,mid,r);
    }
}
int main(){
    int a[]={2,8,9,10,15};
    int n=sizeof(a)/sizeof(a[0]);
    mergesort(a,0,n-1);
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
}
 