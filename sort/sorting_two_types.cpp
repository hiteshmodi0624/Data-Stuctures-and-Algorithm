#include <iostream>
#include <string.h>
#include <math.h>
#include <vector>
#include<numeric>
#include<algorithm>

using namespace std;
int partision(int a[],int l,int h){
    int r=l+rand()/RAND_MAX*(h-l+1);
    int i=l-1,j=h+1,pivot=a[l];
    swap(a[r],a[l]);
    while(1){
        do{
            i++;
        }while(a[i]&1);
        do{
            j--;
        }while(!(a[j]&1));
        if(i>=j)
            return 0;
        swap(a[i],a[j]);
    }
}
int main(){
    // int arr[]={15,-3,-2,18,23,-2,12,43,54,-34,23,-45,-65,90,1,0};
    int arr[]={12,43,54,213,52,54,65,34,65,2,324,53,329,43};
    int n=sizeof(arr)/sizeof(arr[0]);
    partision(arr,0,n-1);
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
}
 