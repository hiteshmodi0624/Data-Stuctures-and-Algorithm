#include <iostream>
#include <string.h>
#include <math.h>
#include <vector>
#include<numeric>
#include<algorithm>

using namespace std;

bool compare(int x,int y){
    return(x%10>y%10);
}
int main(){
    int n=2,m=3;
    int **a;
    a=new int *[m];
    for(int i=0;i<m;i++){
        a[i]=new int[n];
    }
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            a[i][j]=10;
            cout<<a[i][j]<<" ";
        }
    }
    cout<<endl;
    // or
    int *b[m];
    for(int i=0;i<m;i++){
        b[i]=new int[n];
    }
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            b[i][j]=10;
            cout<<b[i][j]<<" ";
        }
    }
    cout<<endl;
    // or
    vector<vector<int> >arr;
    for(int i=0;i<m;i++){
        vector<int> v;
        for(int j=0;j<n;j++)
            v.push_back(10);
        arr.push_back(v);
    }
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            arr[i][j]=10;
            cout<<arr[i][j]<<" ";
        }
    }
}
 