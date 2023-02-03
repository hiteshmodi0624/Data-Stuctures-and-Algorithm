#include <iostream>
#include <vector>
using namespace std;
struct MyStack{
    vector<int>a;
    void push(int x){
        a.push_back(x);
    }
    int pop(){
        int res=a.back();
        a.pop_back();
        return res;
    }
    int peek(){
        return a.back();
    }
    int size(){
        return a.size();
    }
    bool isEmpty(){
        return a.empty();
    }
};
int main(){
    // empty() push(x) pop() top() size()
    MyStack s;
    cout<<s.isEmpty();
    s.push(10);
    cout<<s.size();
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    s.push(60);
    cout<<s.peek();
    s.pop();
    cout<<s.peek();
    cout<<s.isEmpty();
}
 