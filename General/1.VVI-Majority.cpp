#include <iostream>
#include <string.h>
#include <math.h>
#include <vector>
#include<numeric>


using namespace std;


int main(){
    int a[]={8,8,3,3,3,3,3,8,8,8,8,8,3};
    int n=sizeof(a)/sizeof(a[0]),temp=0;
    int res=0,count=1;
    for(int i=1;i<n;i++){
        if(a[res]==a[i])
            count++;
        else
            count--;
        if(count==0){
            res=i;
            count=1;
        }
    }
    count=0;
    for(int i=0;i<n;i++){
        if(a[i]==a[res])
            count++;
    }
    if(count>n/2)
        cout<<a[res];
}
 