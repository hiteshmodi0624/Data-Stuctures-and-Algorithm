#include <iostream>
#include <string.h>
#include <math.h>
#include <vector>
#include<numeric>
#include<algorithm>

using namespace std;

int main(){
    int arr[]={4,5,6};
    int brr[]={1,2,3,4,5,6,6,15};
    int n=sizeof(arr)/sizeof(arr[0]);
    int m=sizeof(brr)/sizeof(brr[0]);
    int i=0;
    int j=0;
    while(i<n&&j<m){
        if(arr[i]>brr[j]){
            cout<<brr[j]<<" ";
            j++;
        }
        else{
            cout<<arr[i]<<" ";
            i++;
        }
    }
    while(j<m){
        cout<<brr[j]<<" ";
        j++;
    }
    while(i<n){
        cout<<arr[i]<<" ";
        i++;
    }
}
 