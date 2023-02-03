#include <iostream>
using namespace std;
struct MyStack{
    int *arr;
    int cap;
    int top;
    MyStack(int c){
        cap=c;
        arr=new int[cap];
        top=-1;
    }
    void push(int x){
        if(top==(cap-1)){return;}
        top++;
        arr[top]=x;
    }
    int pop(){
        if(top==-1){return 132131231;}
        int res=arr[top];
        top--;
        return res;
    }
    int peek(){
        if(top==-1){return 132131231;}
        return arr[top];
    }
    int size(){
        return (top+1);
    }
    bool isEmpty(){
        return(top==-1);
    }
};
int main(){
    // empty() push(x) pop() top() size()
    MyStack s(5);
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
 