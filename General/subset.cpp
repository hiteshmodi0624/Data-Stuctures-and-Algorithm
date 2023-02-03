#include <iostream>
#include <string.h>
#include <math.h>
#include <vector>
#include<numeric>


using namespace std;

int abc(string a,int i=0,string curr=""){
    if(i==a.length()){
        cout<<curr<<endl;
        return 0;
    }
    abc(a,i+1,curr);
    abc(a,i+1,curr+a[i]);
    return 0;
}
int main(){
    string a="ABC";
    abc(a);
}
