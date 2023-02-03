#include <iostream>
#include <string.h>
#include <math.h>
#include <vector>
#include<numeric>


using namespace std;

int abc(string a,int j=0){
    if(j==a.length()-1){
        cout<<a<<endl;
        return 0;
    }
    for(int i=j;i<a.length();i++){
        swap(a[i],a[j]);
        abc(a,j+1);
        swap(a[j],a[i]);
    }
    return 0;
}
int main(){
    string a="ABC";
    abc(a);
}
//write a code to swap two numbers
