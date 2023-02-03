#include <iostream>
#include<queue>
using namespace std;
struct Stack{
    queue<int>q1,q2;
    int top(){
        return q1.front();
    }
    int size(){
        return q1.size();
    }
    int pop(){
        int x=q1.front();
        q1.pop();
        return x;
    }
    void push(int x){
        if(q1.size()==0)
            q1.push(x);
        else{
            while(!q1.empty()){
                q2.push(q1.front());
                q1.pop();
            }
            q1.push(x);
            while(!q2.empty()){
                q1.push(q2.front());
                q2.pop();
            }
        }
    }
};
int main(){
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    cout<<s.pop();
    cout<<s.top();
    cout<<s.size();
    s.push(50);
    s.push(60);
    cout<<s.pop();
    cout<<s.top();
    cout<<s.size();
}
 