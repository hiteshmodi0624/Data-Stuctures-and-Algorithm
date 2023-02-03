#include <iostream>
#include <string.h>
#include <math.h>
#include <vector>
#include<numeric>
#include<algorithm>

using namespace std;
const int r=3,c=5;
int main(){
    int a[r][c]={5,10,20,30,40,1,2,3,4,6,11,13,15,17,19};
    int min=a[0][0],max=a[0][c-1];
    for(int i=1;i<r;i++){
        if(a[i][0]<min){
            min=a[i][0];
        }
        if(a[i][c-1]<min){
            max=a[i][0];
        }
    }
    int pos=(r*c+1)/2;
    while(min<max){
        int mid=(min+max)/2;
        int midPos=0;
        for(int i=0;i<r;i++)
            midPos+=upper_bound(a[i],a[i]+c,mid)-a[i];
        if(midPos<pos)
            min=mid+1;
        else
            max=mid;
    }
    cout<<min;
}
 