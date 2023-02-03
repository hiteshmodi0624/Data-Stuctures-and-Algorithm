#include <iostream>
#include <vector>
using namespace std;
struct Node{
    int data;
    Node*next;
    Node(int x){
        data=x;
        next=NULL;
    }
};
struct MyStack{
    Node*a;
    int n;
    MyStack(){
        a=NULL;
        n=0;
    }
    void push(int x){
        n++;
        Node*temp=new Node(x);
        temp->next=a;
        a=temp;
    }
    int pop(){
        if(a==NULL)
            return -1;
        n--;
        int res=a->data;
        Node*temp=a;
        a=a->next;
        delete(temp);
        return res;
    }
    int peek(){
        if(n==0)
            return -1;
        return a->data;
    }
    int size(){
        return n;
    }
    bool isEmpty(){
        return (a==NULL);
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
    s.pop();
    s.pop();
    s.pop();
    s.pop();
    cout<<s.peek();
    s.pop();
    cout<<s.peek();
    cout<<s.isEmpty();
    s.push(50);
    s.push(60);
    cout<<s.peek();
}
 