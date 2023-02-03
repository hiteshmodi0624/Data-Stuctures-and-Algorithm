#include <iostream>
#include <string.h>
#include <math.h>
#include <vector>
#include<numeric>


using namespace std;


int main(){
    int a[3]={10,2,11};
    int max=0,smax=-1;
    for(int i=0;i<3;i++){
        if(a[i]>a[max]){
                smax=max;
                max=i;
        }
        else if(a[i]!=a[max])
            if(a[i]>a[smax]||smax==-1)
                smax=i;
    }
        cout<<smax;
}
