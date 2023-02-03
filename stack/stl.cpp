#include <iostream>
#include <stack>
using namespace std;

int main(){
    stack<int> s;
    cout<<s.empty();
    s.push(10);
    cout<<s.size();
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    s.push(60);
    cout<<s.top();
    s.pop();
    s.pop();
    s.pop();
    s.pop();
    s.pop();
    cout<<s.top();
    s.pop();
    // s.pop();
    // cout<<s.top();
    cout<<s.empty()<<endl;
    s.push(30);
    s.push(50);
    s.push(60);
    while(s.empty()!=true){
        cout<<s.top()<<" ";
        s.pop();
    }
    cout<<s.empty();
}
 