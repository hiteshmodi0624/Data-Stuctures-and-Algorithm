#include <iostream>
#include <string.h>
#include <math.h>
#include <vector>
#include<numeric>
#include<algorithm>

using namespace std;
const int r=5,c=5;
void print(int a[r][c],int l){
        if(r==1){
        for(int i=0;i<c;i++)
            cout<<a[0][i]<<" ";
    }
    else if(c==1){
        for(int i=0;i<r;i++)
            cout<<a[i][0]<<" ";
    }
    else{
        for(int j=l;j<c-l;j++)
                cout<<a[l][j]<<" ";
        for(int j=l+1;j<r-l;j++)
                cout<<a[j][c-1-l]<<" ";
        for(int j=c-2-l;j>=l;j--)
                cout<<a[r-1-l][j]<<" ";
        for(int j=r-2-l;j>l ;j--)
                cout<<a[j][l]<<" ";
    }
}
int main(){
    int a[r][c]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25};
    int x=r,y=c,l=0;
    while(x>0&&y>0){
        print(a,l);
        l++;
        x-=2;
        y-=2;
    }

}
 