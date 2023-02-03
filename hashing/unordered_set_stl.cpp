#include <iostream>
#include <string.h>
#include <math.h>
#include <vector>
#include <list>
#include<numeric>
#include<unordered_set>

using namespace std;
int main(){
    unordered_set<int> s;
    //use of s.begin(),s.end(),s.insert(y),s.size(),s.clear(),s.find(),s.count(),s.
    s.erase(50);
    s.insert(60);
    s.insert(70);
    s.insert(80);
    s.erase(50);
    s.erase(s.begin(),s.end());
    s.insert(10);
    s.insert(30);
    s.insert(20);
    s.insert(40);
    s.insert(40); //duplicates are not created
    int y=60;
    if(s.find(y)==s.end()){
        cout<<"NOT FOUND"<<endl;
    }
    else{
        cout<<"FOUND "<<*s.find(y)<<endl;
    }
    for(auto it=s.begin();it!=s.end();it++)
        cout<<(*it)<<" ";
    cout<<endl<<"SIZE:"<<s.size()<<endl;
    cout<<s.count(10)<<endl;
    cout<<s.count(60);
    s.clear();
    cout<<endl<<"SIZE after clear:"<<s.size()<<endl;
    return 0;
}
 