#include <iostream>
#include <string.h>
#include <math.h>
#include <vector>
#include<numeric>


using namespace std;

int abc(string a,int j=0,string curr=""){
    if(a.length()==0){
        cout<<curr<<endl;
        return 0;
    }
    for(int i=0;i<a.length();i++){
        string b = a.substr(0,i) + a.substr(i+1);
        abc(b,i,curr+a[i]);
    }
    return 0;
}
int main(){
    string a="ABCD";
    abc(a);
}
