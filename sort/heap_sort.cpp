#include <iostream>
#include <string.h>
#include <math.h>
#include <vector>
#include<numeric>
#include<algorithm>

using namespace std;
void heapify(int a[],int n,int i){
    int largest=i,left=2*i+1,right=2*i+2;
    if(left<n&&a[left]>a[largest]){
        largest=left;
    }
    if(right<n&&a[right]>a[largest]){
        largest=right;
    }
    if(largest!=i){
        swap(a[largest],a[i]);
        heapify(a,n,largest);
    }
}
void buildHeap(int a[],int n){
    for(int i=(n-2)/2;i>=0;i--)
        heapify(a,n,i);
}
void heapSort(int a[],int n){
    buildHeap(a,n);
    for(int i=n-1;i>=1;i--){
        swap(a[0],a[i]);
        heapify(a,i,0);
    }
}
int main(){
    int arr[]={22,36,19,24,23};
    int n=sizeof(arr)/sizeof(arr[0]);
    heapSort(arr,n);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}
 