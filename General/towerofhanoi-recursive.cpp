#include <iostream>
#include <string.h>
#include <math.h>

using namespace std;

int abc(int n,char a,char b,char c){
    if(n==1){
        cout<<"Move Disk "<<n<<" from "<<a<<" to "<<c<<"\n";
        return 0;
    }
    abc(n-1,a,c,b);
    cout<<"Move Disk "<<n<<" from "<<a<<" to "<<c<<"\n";
    abc(n-1,b,a,c);
}
int main()
{
    int n;
    cin>>n;
    abc(n,'A','B','C');
}