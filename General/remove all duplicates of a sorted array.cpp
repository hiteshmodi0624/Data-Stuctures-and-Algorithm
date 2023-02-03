#include <iostream>
#include <string.h>
#include <math.h>
#include <vector>
#include<numeric>


using namespace std;


int main(){
    int n=10;
    int a[]={10,10,10,20,30,30,40,50,50,50};
    int j=1;
    for(int i=1;i<n;i++){
        if(a[j-1]!=a[i]){   
            a[j]=a[i];
            j++;
        }
    }
    for(int i=0;i<j;i++)
        cout<<a[i];
}
