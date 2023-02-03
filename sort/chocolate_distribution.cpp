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
    swap(a[r],a[l]);
    while(1){
        int i=l-1,j=h+1,x=a[l];
        while(1){
            do{
                i++;
            }while(a[i]<x);
            do{
                j--;
            }while(a[j]>x);
            if(i>=j)
                return j;
            swap(a[i],a[j]);
        }
    }
}
void qsort(int a[],int l,int h){
    if(l<h){
        int p=partition(a,l,h);
        qsort(a,l,p);
        qsort(a,p+1,h);
    }
}
int main(){
    int arr[]={7,3,2,4,9,12,56};
    int n=sizeof(arr)/sizeof(arr[0]);
    qsort(arr,0,n-1);   
    int m=3,shortest=arr[m-1]-arr[0];
    for(int i=1;i+m-1<n;i++){
        if((arr[i+m-1]-arr[i])<shortest)
            shortest=arr[i+m-1]-arr[i];
    }
    cout<<shortest;
}
 