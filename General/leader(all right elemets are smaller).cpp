#include <iostream>
#include <string.h>
#include <math.h>
#include <vector>
#include<numeric>


using namespace std;


int main(){
    int n=10;
    int a[]={242,243,23,12,42,43,43,21,34,23};
    int temp=a[n-1];
    cout<<temp<<endl;
    for(int i=n-2;i>=0;i--)
        if (a[i]>temp)
        {
            temp=a[i];
            cout<<a[i]<<endl;
        }
}
