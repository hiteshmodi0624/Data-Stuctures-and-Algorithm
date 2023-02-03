#include <iostream>
#include <string.h>
#include <math.h>
#include <vector>
#include<numeric>
#include<algorithm>

using namespace std;

int main(){
    const int r=4,c=5;
    int a[r][c]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
    if(r==1){
        for(int i=0;i<c;i++)
            cout<<a[0][i]<<" ";
    }
    else if(c==1){
        for(int i=0;i<r;i++)
            cout<<a[i][0]<<" ";
    }
    else{
        for(int j=0;j<c;j++)
                cout<<a[0][j]<<" ";
        for(int j=1;j<r;j++)
                cout<<a[j][c-1]<<" ";
        for(int j=c-2;j>=0;j--)
                cout<<a[r-1][j]<<" ";
        for(int j=r-2;j>0 ;j--)
                cout<<a[j][0]<<" ";
    }
}
 