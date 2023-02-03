#include <iostream>
#include <string.h>
#include <math.h>
#include <vector>
#include<numeric>
#include<algorithm>

using namespace std;

int partision(int a[],int l,int h,int x){
    int b[h-l+1],r=l;
    for(int i=l;i<=h;i++){
        if(a[i]<a[x]){
            b[r]=a[i];
            r++;
        }
    }
    for(int i=l;i<=h;i++){
        if(a[i]==a[x]){
            b[r]=a[i];
            r++;
        }
    }
    int y=l+r-1;
    for(int i=l;i<=h;i++){
        if(a[i]>a[x]){
            b[r]=a[i];
            r++;
        }
    }
    for(int i=0;i<=h;i++){
        a[i]=b[i];
    }
    return y;
}
int main(){
    int arr[]={78,22,36,24,25,24,79,24,24};
    int n=sizeof(arr)/sizeof(arr[0]);
    int z=3;
    cout<<partision(arr,0,n-1,z)<<" ";
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
}
 