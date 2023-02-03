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
    for (int i=0;i<n-1;i++){
        int smallest=i;
        for(int j=i+1;j<n;j++)
            if(arr[j]<arr[smallest])
                smallest=j;
        swap(arr[i],arr[smallest]);
    }
    for(int i=0;i<n;i++){
        cout<<arr[i]<<endl;
    }
}
 