#include <iostream>
#include <string.h>
#include <math.h>
#include <vector>
#include<numeric>
#include<algorithm>
// CPP program to illustrate using 
// std :: upper_bound with arrays
using namespace std;
  
// Main Function
int min(int a[],int n){
    int min=a[0];
    for(int i=1;i<n;i++)
        if(a[i]<min){
            min=a[i];
        }
    return min;
}
int main()
{
    int gloves[]={5,2,3};
    int n = sizeof(gloves)/sizeof(gloves[0]);
    int total=20,count=0;
    for(int i=0;i<n;i++){
        count+=gloves[i];
    }
    cout<<count+1<<endl;
    cout<<total-min(gloves,n)+1;

}