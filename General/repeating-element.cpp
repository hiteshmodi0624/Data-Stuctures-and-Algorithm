#include <iostream>
#include <string.h>
#include <math.h>
#include <vector>
#include<numeric>

using namespace std;

int main(){
    int a[]={0,2,1,3,5,4,6,2};
    int n=sizeof(a)/sizeof(a[0]);
    int slow=a[0]+1,fast=a[0]+1;
    do{
        slow=a[slow]+1;
        fast=a[a[fast]+1]+1;
    }while(slow!=fast);
    slow=a[0]+1;
    while(slow!=fast){
        slow=a[slow]+1;
        fast=a[fast]+1;
    }
    cout<<fast-1;
}
 