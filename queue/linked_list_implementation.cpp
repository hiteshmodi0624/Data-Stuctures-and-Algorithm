#include <iostream>
using namespace std;
struct Node{
    int data;
    Node*next;
    Node(int x){
        data=x;
        next=NULL;
    }
};
struct MyQueue{
    Node*head,*rear;
    int size;
    MyQueue(){
        size=0;
        rear=NULL;
    }
    void enque(int x){
        Node*temp=new Node(x);
        if(size==0){
            head=temp;
            rear=head;
        }
        else{
            rear->next=temp;
            rear=temp;
        }
        size++;
    }
    int deque(){
        if(size!=0){
            Node*temp=head;
            int x=temp->data;
            head=head->next;
            delete(temp);
            size--;
            return x;
        }
        return -1;
    }
    int getFront(){
        if(size!=0)
            return head->data;
        return -1;
    }
    int getRear(){
        if(size!=0)
            return rear->data;
        return -1;
    }
    bool isEmpty(){
        return (size==0?true:false);
    }
    int Qsize(){
        return size;
    }
};
int main(){
    MyQueue q;
    q.enque(20);
    cout<<q.deque()<<endl;
    q.enque(30);
    q.enque(40);
    q.enque(50);
    q.enque(60);
    q.enque(70);
    q.enque(80);
    cout<<q.getFront()<<" "<<q.getRear()<<" "<<q.isEmpty()<<endl;
    cout<<q.deque();
    cout<<q.getFront()<<" "<<q.getRear()<<" "<<q.isEmpty()<<endl;
    cout<<q.deque();
    cout<<q.getFront()<<" "<<q.getRear()<<" "<<q.isEmpty()<<endl;
    cout<<q.deque();
    cout<<q.getFront()<<" "<<q.getRear()<<" "<<q.isEmpty()<<endl;
    cout<<q.deque();
    cout<<q.getFront()<<" "<<q.getRear()<<" "<<q.isEmpty()<<endl;
    cout<<q.deque();
    cout<<q.getFront()<<" "<<q.getRear()<<" "<<q.isEmpty()<<endl;
    cout<<q.deque();
    cout<<q.getFront()<<" "<<q.getRear()<<" "<<q.isEmpty()<<endl;
}
 