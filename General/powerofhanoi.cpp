#include <iostream>
#include <string.h>
#include <math.h>

using namespace std;

int abc(int n,int r){
    if(r==0)
        return 0;
    int y=log2(r&(~(r-1)))+1;
    if(y&1){
        int x=(r-1)%3;
        if((n&1)||x==0)
            x=3-x;
        cout<<"Move "<<y<<" to "<<x<<endl;
    }
    else{
        int x=(r+1)%3;
        if((n&1)||x==0)
            x=3-x;
        cout<<"Move "<<y<<" to "<<x<<endl;
    }
    abc(n,r-1);
    return 0;
}
int main()
{
    int n;
    cin>>n;
    abc(n,pow(2,n)-1);
}