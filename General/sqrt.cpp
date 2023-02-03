#include <iostream>
#include <string.h>
#include <math.h>
#include <vector>
#include<numeric>

using namespace std;

int main(){
    int b=48;
    int low=0,high=b;
    int min=-1,max,mid,result;
    while(low<=high){
        int mid=(low+high)/2;
        int ms=mid*mid;
        if(ms==b){
            result=mid;
            break;
        }
        else if(ms>b)
            high=mid-1;
        else{    
            result=mid;
            low=mid+1;
        }
    }
    cout<<result;
}
 