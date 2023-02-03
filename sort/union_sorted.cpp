#include <iostream>
#include <string.h>
#include <math.h>
#include <vector>
#include<numeric>
#include<algorithm>

using namespace std;
int main(){
    int b[]={3,5,8};
    int a[]={2,8,9,10,15,16,16,16};
    int n=sizeof(a)/sizeof(a[0]);
    int m=sizeof(b)/sizeof(b[0]);
    int i=0,j=0;
    while(i<n&&j<m){
        while(a[i]==a[i-1]&&i>0){
            i++;
            continue;
        }
        while(b[j]==b[j-1]&&j>0){
            j++;
            continue;
        }
        if(i>=n&&j>=m)
            break;
        if(a[i]>b[j]){
            cout<<b[j]<<" ";
            j++;
        }
        else if(a[i]<b[j]){
            cout<<a[i]<<" ";
            i++;
        }
        else{
            cout<<a[i]<<" ";
            i++;
            j++;
        }
    }
    while(i<n){
        if(a[i]==a[i-1]&&i>0){
            i++;
            continue;
        }
        cout<<a[i]<<" ";
        i++;
    }
    while(j<m){
        if(b[j]==b[j-1]&&j>0){
            j++;
            continue;
        }
        cout<<b[j]<<" ";
        j++;
    }
}
 