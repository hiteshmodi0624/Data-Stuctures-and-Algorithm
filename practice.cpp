#include <iostream>
using namespace std;
 
void func(int &x,int z,int &y){
    if(x<z*z)
        return;
    func(x,z+1,y);
    if(x<=0)
        return;
    y=y+x/(z*z);
    x=x-(x/(z*z))*(z*z);
}
int main()
{
    int x=7;
    int res=0;
    func(x,1,res);
    cout<<res;
}