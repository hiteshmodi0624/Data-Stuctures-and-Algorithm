#include <iostream>
#include <string.h>
#include <math.h>
#include <vector>
#include<numeric>

using namespace std;

int main(){
    int b[]={10,20,30,40,50};
    int a[]={45,70,80,90,100};
    int n=sizeof(a)/sizeof(a[0]);
    int m=sizeof(b)/sizeof(b[0]);
    int median=(m+n+1)/2;
    int i1,i2;
    if(m+n&1){
        i1=(n+1)/2-1;
        i2=median-i1;
    }
    else{
        i2=(n+1)/2-1;
        i1=median-i2;
    }
    while(a[i1-1]>b[i2]||a[i1]<b[i2-1]){
        if(i1*i2==0)
            break;
        else if(a[i1-1]>b[i2]){
            i1-=1;
            i2+=1;
        }
        else{
            i2-=1;
            i1+=1;
        }
    } 
        if(a[i1-1]>b[i2-1])
            median=a[i1-1];
        else
            median=b[i2-1];
        if((m+n)&1){
            if(a[i1-1]>b[i2-1])
                cout<<median;
            else
                cout<<median;
        }
        else{
            if(a[i1]>b[i2])
                cout<<(median+b[i2])/2;
            else
                cout<<(median+a[i1])/2;
        }
    
    
}
 