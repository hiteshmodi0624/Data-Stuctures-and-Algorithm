#include <iostream>
#include <string.h>
using namespace std;


bool checkrotations(string s1,string s2){
    return (((s1+s1).find(s2)!=string::npos)&&s1.length()==s2.length());
}
int main(){
    string s1="abab",s2="baba";
    cout<<checkrotations(s1,s2);
}