#include <iostream>
#include<queue>
#include<stack>
using namespace std;
void reverse_itr(queue<int> &q){
    stack<int>s;
    int n=q.size();
    while(!q.empty()){
        s.push(q.front());
        q.pop();
    }
    while(!s.empty()){
        q.push(s.top());
        s.pop();
    }
}
void reverse_rec(queue<int> &q){
    if(q.empty())
        return;
    int x=q.front();
    q.pop();
    reverse_rec(q);
    q.push(x);
}
int main(){
    queue<int>q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    cout<<q.front()<<q.back()<<endl;
    reverse_rec(q);
    cout<<q.front()<<q.back()<<endl;
    reverse_itr(q);
    cout<<q.front()<<q.back();
}
 