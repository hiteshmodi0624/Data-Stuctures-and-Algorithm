#include <iostream>
#include <queue>
#include<map>
using namespace std;

int main(){
    map<int,int>m;
    map<int,int,greater<int> >p;
    m[10]=20;
    m[2]=23;
    m[6]=4;
    m[20]=50;
    p[10]=20;
    p[2]=23;
    p[6]=4;
    p[20]=50;
    m[20]=90;
    // m[40]=90; if already not there it will create reference and store it.
    m.at(10)=90;
    // m.insert({1,12});
    // m.at(40)=90; if already not there it will throw error
    for(auto x:m)
        cout<<x.first<<" "<<x.second<<endl;
    cout<<endl;
    for(auto x:p)
        cout<<x.first<<" "<<x.second<<endl;
    cout<<endl;
    for(auto it=m.begin();it!=m.end();it++)
        cout<<(*it).first<<" "<<(*it).second<<endl;
    if(!p.empty())
        cout<<"True"<<endl;
    p.clear();
    cout<<p.size()<<endl;
    if(m.find(20)!=m.end()){
        cout<<"Found"<<endl;
    }
    for(auto it=m.find(6);it!=m.end();it++)
        cout<<(*it).first<<" "<<(*it).second<<endl;
    cout<<m.count(20)<<endl;
    cout<<m.count(21)<<endl;
    cout<<(*m.lower_bound(2)).second<<endl;
    cout<<(*m.lower_bound(1)).second<<endl;
    cout<<(*m.upper_bound(2)).second<<endl;
    cout<<(*m.upper_bound(1)).second<<endl;
    cout<<m.size()<<endl;
    cout<<endl;
    for(auto x:m)
        cout<<x.first<<" "<<x.second<<endl;
    m.erase(2);
    cout<<m.size()<<endl;
    m.erase(m.find(6),m.find(10));
    cout<<m.size()<<endl;
    m.erase(m.begin(),m.end());
    cout<<m.size()<<endl;
}