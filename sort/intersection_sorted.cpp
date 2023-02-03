#include <iostream>
#include <string.h>
#include <math.h>
#include <vector>
#include<numeric>
#include<algorithm>

using namespace std;
int main(){
    int a[]={10,12,15,15,30,40};
    int b[]={11,12,15,40};
    int n=sizeof(a)/sizeof(a[0]);
    int m=sizeof(b)/sizeof(b[0]);
    int i=0,j=0;
    while(i<n&&j<m){
        if(a[i]==a[i-1]&&i>0){
            i++;
            continue;
        }
        if(a[i]>b[j]){
            j++;
        }
        else if(a[i]<b[j]){
            i++;
        }
        else{
            cout<<a[i]<<" ";
            i++;
            j++;
        }
    }
}
 