#include <iostream>
#include <string.h>
#include <math.h>
#include <vector>
#include<numeric>
#include<algorithm>

using namespace std;
int partision(int a[],int l,int h){
    int r=l+rand()/RAND_MAX*(h-l+1);
    int i=l-1,j=h+1,x=a[l];
    swap(a[r],a[l]);
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
void qsort(int a[],int l, int h){
    if(l<h){
        int p=partision(a,l,h);
        qsort(a,l,p); 
        qsort(a,p+1,h); 
    }
}
int main(){
    int arr[]={28,22,36,24,25,24,79,24,24,1,2,43,65,909};
    int n=sizeof(arr)/sizeof(arr[0]);
    qsort(arr,0,n-1);
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
}
 