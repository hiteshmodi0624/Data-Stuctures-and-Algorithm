#include <iostream>
#include <unordered_map>
using namespace std;
int main(){
    string str="abbccddabba";
    int k=3;
    unordered_map<char,int>m;
    int i=0,j=0,res=0,z=1;;
    while(j<str.length()){
        m[str[j]]++;
        if(m.size()>k){
            while(m.size()>k){
                m[str[i]]--;
                if(m[str[i]]==0)
                    m.erase(str[i]);
                i++;
            }
            z=1;
        }
        if(m.size()==k){
            while(str[i]==str[i+1]){
                z++;
                i++;
            }
            res=res+z;
        }
        j++;
}
    cout<<res;
}
 