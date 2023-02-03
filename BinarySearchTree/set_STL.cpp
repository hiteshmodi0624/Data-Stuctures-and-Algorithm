#include <iostream>
#include <queue>
#include<set>
using namespace std;

int main(){
    set<int>s;
    set<int,greater<int> >p;
    s.insert(10);
    s.insert(3);
    s.insert(20);
    s.insert(5);
    p.insert(10);
    p.insert(3);
    p.insert(20);
    p.insert(20);
    
    p.insert(5);
    for(int x:s)
        cout<<x<<" ";
    cout<<endl;
    for(int x:p)
        cout<<x<<" ";
    cout<<endl;
    s.insert(20);
    s.insert(20);
    for(auto it=s.begin();it!=s.end();it++){
        cout<<*it<<" ";
    }
    cout<<endl;
    for(auto it=s.rbegin();it!=s.rend();it++){
        cout<<*it<<" ";
    }
    cout<<endl;
    auto it=s.find(15);
    if(it==s.end())
        cout<<"Not Found";
    else
        cout<<"Found";
    cout<<endl;
    it=s.find(10);
    if(it==s.end())
        cout<<"Not Found";
    else
        cout<<"Found";
    // count only return 0 or 1 as set does not contains duplicates
    cout<<endl<<s.count(20);
    cout<<endl<<s.size();
    s.erase(20);
    cout<<endl<<s.size();
    s.erase(s.find(5),s.end());
    cout<<endl<<s.size();
    s.clear();
    cout<<endl<<s.size();
    s.insert(10);
    s.insert(3);
    s.insert(20);
    s.insert(5);
    it=s.lower_bound(5);
    cout<<endl<<*it;
    it=s.lower_bound(6);
    cout<<endl<<*it<<endl;;
    it=s.lower_bound(25);
    if(it!=s.end())
        cout<<endl<<*it;
    else
        cout<<"greater than largest"<<endl;
    
    it=s.upper_bound(5);
    cout<<*it<<endl;
    it=s.upper_bound(6);
    cout<<*it<<endl;;
    it=s.upper_bound(25);
    if(it!=s.end())
        cout<<endl<<*it;
    else
        cout<<"greater than largest"<<endl;
}