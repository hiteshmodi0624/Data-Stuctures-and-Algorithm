#include <iostream>
#include <stack>
#include <vector>
using namespace std;
struct Mystack{
    stack<int>as,ms;
    void push(int x){
        ms.push(x);
        if(as.empty()||as.top()>=ms.top())
            as.push(x);
    }
    void pop(){
        if(ms.top()==as.top())
            as.pop();
        ms.pop();
    }
    int getmin(){
        return as.top();
    }
};
int main(){
    Mystack s;
    s.push(12);
    cout<<s.getmin()<<" ";
    s.push(55);
    cout<<s.getmin()<<" ";
    s.push(42);
    cout<<s.getmin()<<" ";
    s.push(7);
    cout<<s.getmin()<<" ";
    s.push(43);
    cout<<s.getmin()<<" ";
    s.push(2);
    cout<<s.getmin()<<" ";
    s.push(6);
    cout<<s.getmin()<<" ";
    s.pop();
    cout<<s.getmin()<<" ";
    s.pop();
    cout<<s.getmin()<<" ";
    s.pop();
    cout<<s.getmin()<<" ";
    s.pop();
    cout<<s.getmin()<<" ";
    s.pop();
    cout<<s.getmin()<<" ";
}
 