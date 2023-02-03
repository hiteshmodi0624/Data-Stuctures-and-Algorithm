#include <iostream>
#include <string.h>
#include <math.h>
#include <vector>
#include<numeric>
#include<algorithm>

using namespace std;
void countingsort(int a[],int n,int div){
    int count[10];
    for(int i=0;i<10;i++)
        count[i]=0;
    for(int i=0;i<n;i++)
        count[(a[i]/div)%10]++;

    // to get number of elements which are smaller or equal to the given number
    for(int i=1;i<10;i++) 
        count[i]=count[i-1]+count[i];
    
    int output[n];
    for(int i=n-1;i>=0;i--){
        output[count[(a[i]/div)%10]-1]=a[i];
        count[(a[i]/div)%10]--;
    }   
    for(int i=0;i<n;i++)
        a[i]=output[i];
}
void radixsort(int a[],int n){
    int largest=a[0];
    for(int i=1;i<n;i++)
        largest=max(a[i],largest);
    int d=1;
    while(largest/d>0){
        countingsort(a,n,d);
        d=d*10;
    }
}
int main(){
    int arr[]={319,212,6,8,100,50};
    int n=sizeof(arr)/sizeof(arr[0]);
    radixsort(arr,n);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}
 