#include <iostream>
#include <string.h>
#include <math.h>
#include <vector>
#include<numeric>


using namespace std;


int main(){
    int a[]={1,2,-3,4};
    int n=sizeof(a)/sizeof(a[0]),temp=a[0],mini=a[0],r=0,curr=a[0]; 
    for(int i=0;i<n;i++){
        mini=min(mini,a[i]);
        if(mini==a[i])
            r=i;
    }
    int temp2=a[r],curr2=a[r];
    for(int i=1;i<n;i++){
        curr=max(a[i],a[i]+curr);
        temp=max(temp,curr);
        curr2=max(a[(i+r)%n],a[(i+r)%n]+curr2);
        temp2=max(temp2,curr2);
    }
    cout<<max(temp,temp2);
}
 