#include <iostream>
#include <string.h>
#include <math.h>
#include <vector>
#include<numeric>


using namespace std;

int abc(int n[],int l,int x){
    if(x<0){
        if(l==0)
            return 1;
        return 0;
    }
    return abc(n,l,x-1)+abc(n,l-(n[x]),x-1);
}
int main(){
    int n[]={1,2,3,4,5,6,7,8,9,10,11},k=12;
    cout<<abc(n,k,sizeof(n)/sizeof(n[0]));
}
