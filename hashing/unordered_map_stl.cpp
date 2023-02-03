#include <iostream>
#include <string.h>
#include <math.h>
#include <vector>
#include <list>
#include<numeric>
#include<unordered_map>

using namespace std;
int main(){
    unordered_map<string,int> m;
    //use of s.begin(),s.end(),s.insert(y),s.size(),s.clear(),s.find(),s.count(),s.
    m["gfg"]=60;
    m["abc"]=20;
    m.insert(make_pair("xyz",89));
    for(auto x=m.begin();x!=m.end();x++)
        cout<<x->first<<" "<<x->second<<endl;
    if(m.find("abc")==m.end()){
        cout<<"NOT FOUND"<<endl;
    }
    else{
        cout<<"FOUND "<<m.find("abc")->second<<endl;
    }
    cout<<m.count("abc");
    cout<<m.count("def");
    cout<<m.size();
    m.erase("gfg");
    m.erase(m.begin());
    m.erase(m.begin(),m.end());
    cout<<m.size();


}
 