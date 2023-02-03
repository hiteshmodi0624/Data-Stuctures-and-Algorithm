#include <iostream>
#include <string.h>
#include <math.h>
#include <vector>
#include<numeric>
#include<algorithm>

using namespace std;
int partision(int a[],int l,int h){
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
int kth(int a[],int n, int k){
    int l=0,r=n-1;
    while(l<=r){
        int p=partision(a,l,r);
        if(p==k-1)
            return p;
        else if(p>k-1)
            r=p-1;
        else
            l=p+1;
    }
    return -1;
}
int main(){
    int arr[]={28,22,36,24,25,24,79,24,24};
    int n=sizeof(arr)/sizeof(arr[0]);
    int k=5;
    cout<<arr[kth(arr,n,k)];
}
 