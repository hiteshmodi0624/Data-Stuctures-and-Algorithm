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
        }while(a[i]<pivot);
        do{
            j--;
        }while(a[j]>pivot);
        if(i>=j)
            return j;
        swap(a[i],a[j]);
    }
}
void qsort(int a[],int l,int h){
    if(l<h){
        int p=partision(a,l,h);
        qsort(a,l,p);
        qsort(a,p+1,h);
    }
}
int maxguest(int a[],int d[],int n){
    int i=0,j=0,res=0,curr=0;
    while(i<n){
        if(a[i]<=d[j]){
            curr++;
            i++;
        }
        else{
            curr--;
            j++;
        }
        res=max(res,curr);
    }
    return res;
}   
int main(){
    // int a[]={15,-3,-2,18,23,-2,12,43,54,-34,23,-45,-65,90,1,0};
    int a[]={900,940,950,1100,1500,1800};
    int d[]={910,1200,1120,1130,1900,2000};
    int n=sizeof(a)/sizeof(a[0]);
    qsort(a,0,n-1);
    qsort(d,0,n-1);
    cout<<maxguest(a,d,n);
}
 