#include <iostream>
using namespace std;
struct MyQueue{
    private:
        int *arr;
        int cap,s,size;
    public:
        MyQueue(int n){
            arr=new int[n];
            cap=n;
            s=0;
            size=0;
        }
        void enque(int x){
            if(size!=cap){
                arr[(s+size)%cap]=x;
                size++;
            }
        }
        int deque(){
            if(size!=0){
                int x=arr[s];
                s=(s+1)%cap;
                size--;
                return x;
            }
            return -1;
        }
        int getFront(){
            if(size!=0)
                return arr[s];
            return -1;
        }
        int getRear(){
            if(size!=0)
                return arr[(s+size)%cap-1];
            return -1;
        }
        bool isFull(){
            return (size==cap?true:false);
        }
        bool isEmpty(){
            return (size==0?true:false);
        }
        int Qsize(){
            return size;
        }
};
int main(){
    MyQueue q(5);
    q.enque(20);
    cout<<q.deque()<<endl;
    q.enque(30);
    q.enque(40);
    q.enque(50);
    q.enque(60);
    q.enque(70);
    q.enque(80);
    cout<<q.getFront()<<" "<<q.getRear()<<" "<<q.isFull()<<" "<<q.isEmpty()<<endl;
    cout<<q.deque();
    cout<<q.getFront()<<" "<<q.getRear()<<" "<<q.isFull()<<" "<<q.isEmpty()<<endl;
    cout<<q.deque();
    cout<<q.getFront()<<" "<<q.getRear()<<" "<<q.isFull()<<" "<<q.isEmpty()<<endl;
    cout<<q.deque();
    cout<<q.getFront()<<" "<<q.getRear()<<" "<<q.isFull()<<" "<<q.isEmpty()<<endl;
    cout<<q.deque();
    cout<<q.getFront()<<" "<<q.getRear()<<" "<<q.isFull()<<" "<<q.isEmpty()<<endl;
    cout<<q.deque();
    cout<<q.getFront()<<" "<<q.getRear()<<" "<<q.isFull()<<" "<<q.isEmpty()<<endl;
    cout<<q.deque();
    cout<<q.getFront()<<" "<<q.getRear()<<" "<<q.isFull()<<" "<<q.isEmpty()<<endl;
}
 