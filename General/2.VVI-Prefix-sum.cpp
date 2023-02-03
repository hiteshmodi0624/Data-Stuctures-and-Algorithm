#include <iostream>
#include <string.h>
#include <math.h>
#include <vector>
#include<numeric>

using namespace std;
//maximimum repeating number in each of the range beggining with a[i] and ending with b[i]
int main(){
    int a[]={1,2,3},b[]={3,5,7};
    int n=sizeof(a)/sizeof(a[0]);
    vector <int> c(100);
    for(int i=0;i<n;i++){
        c[a[i]]++;
        c[b[i]+1]--;
    }
    int max=0,r;
    for(int i=1;i<b[n-1]+1;i++){
        c[i]+=c[i-1];
        if(max<c[i]){
            max=c[i];
            r=i;
        }
    }
    cout<<r;
}
 