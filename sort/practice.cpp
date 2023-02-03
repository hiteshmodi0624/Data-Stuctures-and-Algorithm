#include <iostream>
#include <string.h>
#include <math.h>
#include <vector>
#include<numeric>
#include<algorithm>

using namespace std;

void cycle_sort_distint(int arr[],int n){
    int w=0;
    for(int cs=0;cs<n-1;cs++){
        int itm=arr[cs];
        int pos=cs;
        for(int i=cs+1;i<n;i++)
            if(arr[i]<itm)
                pos++;
        if(pos==cs)
            continue;
        while(itm==arr[pos])
            pos+=1;
        if(pos!=cs){
            swap(itm,arr[pos]);
            w++;
        }
        while(pos!=cs){
            pos=cs;
            for(int i=cs+1;i<n;i++)
                if(arr[i]<itm)
                    pos++;
            while(itm==arr[pos])
                pos+=1;
            if(itm!=arr[pos]){
                swap(itm,arr[pos]);
                w++;
            }
        }
    }
}
int main(){
    int arr[]={15,12,14,54,21,7,18,18};
    int n=sizeof(arr)/sizeof(arr[0]);
    cycle_sort_distint(arr,n);
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
}
 