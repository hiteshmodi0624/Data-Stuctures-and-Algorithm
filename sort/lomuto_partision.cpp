#include <iostream>
#include <string.h>
#include <math.h>
#include <vector>
#include<numeric>
#include<algorithm>

using namespace std;

int partision(int a[],int l,int h){
    swap(a[h],a[h]);
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
int main(){
    int arr[]={8,4,7,9,3,10,5};
    int n=sizeof(arr)/sizeof(arr[0]);
    cout<<partision(arr,0,n-1)<<" ";
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
}
 