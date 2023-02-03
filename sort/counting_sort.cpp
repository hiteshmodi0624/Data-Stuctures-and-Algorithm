#include <iostream>
#include <string.h>
#include <math.h>
#include <vector>
#include<numeric>
#include<algorithm>

using namespace std;
void countingsort(int a[],int n,int k){
    int count[k];
    for(int i=0;i<k;i++)
        count[i]=0;
    for(int i=0;i<n;i++)
        count[a[i]]++;
    for(int i=1;i<k;i++) 
        count[i]=count[i-1]+count[i];
    // to get number of elements which are smaller or equal to the given number
    int output[n];
    for(int i=n-1;i>=0;i--){
        output[count[a[i]]-1]=a[i];
        count[a[i]]--;
    }   
    for(int i=0;i<n;i++)
        a[i]=output[i];
}
int main(){
    int arr[]={1,4,4,1,0,1};
    int n=sizeof(arr)/sizeof(arr[0]);
    countingsort(arr,n,5);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}
 