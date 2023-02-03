#include <iostream>
#include <string.h>
#include <math.h>
#include <vector>
#include<numeric>
#include<algorithm>

using namespace std;

int main(){
    const int r=3,c=3;
    int a[r][c]={1,2,3,4,5,6,7,8,9};
    for(int i=0;i<r;i++){
        for(int j=i+1;j<c;j++){
            swap(a[i][j],a[j][i]);
        }
    }
    for(int i=0;i<r/2;i++){
        for(int j=0;j<c;j++){
            swap(a[i][j],a[r-i][j]);
        }
    }
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cout<<a[i][j]<<" ";
        }
    }
}
 