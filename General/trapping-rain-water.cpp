#include <iostream>
#include <string.h>
#include <math.h>
#include <vector>
#include<numeric>


using namespace std;


int main(){
    int n=7;
    int a[]={3,1,5,3,6,1,0};
    int l[n],r[n],total=0;
    l[0]=a[0];
    for(int i=1;i<n;i++)
        l[i]=max(l[i-1],a[i]);
    r[n-1]=a[n-1];
    for(int i=n-2;i>=0;i--)
        r[i]=max(r[i+1],a[i]);
    for(int i=1;i<n-1;i++)
        total=total+min(r[i],l[i])-a[i];
    cout<<total;
}
 