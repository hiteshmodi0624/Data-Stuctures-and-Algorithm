#include <iostream>
#include <string.h>
#include <math.h>
#include <vector>
#include<numeric>
#include<algorithm>

using namespace std;
int partision(int a[],int l,int h){
    int i=l-1,j=h+1,x=a[h];
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
int main(){
    int arr[]={28,22,36,24,25,24,79,24,24};
    int n=sizeof(arr)/sizeof(arr[0]);
    int z=n-1;
    cout<<partision(arr,0,n-1)<<" ";
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
}
 