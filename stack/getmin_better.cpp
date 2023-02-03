#include <iostream>
#include <stack>
#include <vector>
using namespace std;
struct Mystack{
    // all elements are positive
    stack<int>s;
    int min;
    void push(int x){
        if(s.empty()){
            min=x;
            s.push(x);
        }
        else if(x<=min){
            s.push(2*x-min);
            min=x;
        }
        else
            s.push(x);
    }
    void pop(){
        if(s.top()<=min){
            min=2*min-s.top();
        }
        s.pop();
    }
    int getmin(){
        return min;
    }
    int peek(){
        if(s.top()<=min)
            return min;
        return s.top();
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
 