#include <iostream>
#include <string.h>
#include <math.h>
#include <vector>
#include<numeric>
#include<algorithm>

using namespace std;
struct range{
    int x,y;
};
int partision(range a[],int l,int h){
    int r=l+rand()/RAND_MAX*(h-l+1);
    int i=l-1,j=h+1,pivot=a[l].x;
    swap(a[r],a[l]);
    while(1){
        do{
            i++;
        }while(a[i].x<pivot);
        do{
            j--;
        }while(a[j].x>pivot);
        if(i>=j)
            return j;
        swap(a[i],a[j]);
    }
}
void qsort(range a[],int l,int h){
    if(l<h){
        int p=partision(a,l,h);
        qsort(a,l,p);
        qsort(a,p+1,h);
    }
}
void merolp(range a[],int n){
    for(int i=0;i<n;i++){
        int r=0,max=a[i].y;
        while((max>=a[i+r+1].x)&&((i+r)<n-1)){
            r++;
            if(max<a[i+r].y){
                max=a[i+r].y;
            }
        }
        cout<<"{"<<a[i].x<<","<<max<<"} ";
        i+=r;
    }
}   
int main(){
    // int a[]={15,-3,-2,18,23,-2,12,43,54,-34,23,-45,-65,90,1,0};
    range a[]={{7,9},{6,10},{4,5},{1,3},{2,4}};
    int n=sizeof(a)/sizeof(a[0]);
    qsort(a,0,n-1);
    for(int i=0;i<n;i++){
        cout<<"{"<<a[i].x<<","<<a[i].y<<"} ";
    }
    cout<<endl;
    merolp(a,n);
}
 