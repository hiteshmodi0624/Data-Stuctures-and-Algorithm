#include <iostream>
#include <string.h>
#include <math.h>
#include <vector>
#include<numeric>
#include<algorithm>

using namespace std;
const int r=4,c=4;
int main(){
    int a[r][c]={10,20,30,40,15,25,35,45,27,29,37,48,32,33,39,50};
    int x=3;
    int i=0,j=c-1;
    while(i<r&&j>=0){
        if(x==a[i][j]){
            cout<<i<<j;
            return 0;
        }
        else if(x>a[i][j])
            i++;
        else
            j--;
    }
    cout<<-1;
}
 