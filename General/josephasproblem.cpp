#include <iostream>
#include <string.h>
#include <math.h>

using namespace std;

int abc(int n,int k){
    if(n==1)
        return 0;
    
    return (abc(n-1,k)+k)%n;
}
int main()
{
    int n,k;
    cout<<abc(1,1);
}
