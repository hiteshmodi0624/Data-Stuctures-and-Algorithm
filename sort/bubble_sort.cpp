#include <iostream>
#include <string.h>
#include <math.h>
#include <vector>
#include<numeric>
#include<algorithm>

using namespace std;

bool compare(int x,int y){
    return(x%10>y%10);
}
int main(){
    int arr[]={22,36,19,24,23};
    int n=sizeof(arr)/sizeof(arr[0]);
    for (int i=n-1;i>0;i--){
        int swapped=false;
        for(int j=0;j!=i;j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
                swapped=true;
            }
        }
        if(!swapped){
            break;
        }
    }
    for(int i=0;i<n;i++){
        cout<<arr[i]<<endl;
    }
}
 