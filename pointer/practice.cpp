#include <iostream>

using namespace std;

int main(){
    int i=10;
    int * p=&i;
    cout<<i<<endl<<&i<<endl<<p<<endl<<*p<<endl;
    cout<<sizeof(p)<<endl;
    i++;
    cout<<i<<endl;
    cout<<*p<<endl;
    (*p)++;
    cout<<i<<endl;
    cout<<*p<<endl;

    int a[3]={1,2,3};
    cout<<a<<endl;
    cout<<&a[0]<<endl;
    cout<<a[0]<<endl;
    cout<<*a<<endl;
    cout<<*(a+1)<<endl;
    cout<<0[a];
}