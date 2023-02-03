#include <iostream>
#include<queue>
using namespace std;
int main(){
    queue<int>q;
    q.push(10);
    q.push(20);
    q.pop();
    q.push(30);
    q.push(40);
    q.push(50);
    cout<<q.size();
    cout<<q.empty()<<endl;
    cout<<q.front();
    cout<<q.back()<<endl;
    q.pop();
    cout<<q.size();
    cout<<q.empty()<<endl;
    cout<<q.front();
    cout<<q.back()<<endl;
    q.pop();
    cout<<q.size();
    cout<<q.empty()<<endl;
    cout<<q.front();
    cout<<q.back()<<endl;
    q.pop();
    cout<<q.size();
    cout<<q.empty()<<endl;
    cout<<q.front();
    cout<<q.back()<<endl;
    cout<<q.size();
    cout<<q.empty()<<endl;
    q.pop();
    cout<<q.front();
    cout<<q.back()<<endl;
    cout<<q.size();
    cout<<q.empty();
}
 