#include <iostream>
#include <string.h>
#include <math.h>
#include <vector>
#include<numeric>

using namespace std;

int main(){
    int a[]={1,2,1,3,4,3,3};
    int n=sizeof(a)/sizeof(a[0]),temp=0,sum=0,giv=33,i=0;
    for(int j=0;j<n;j++){
        sum+=a[j];
        while(sum>giv){
            sum-=a[i];
            i++;
        }
        if(sum==giv)
            cout<<"YES";
    }
}
 