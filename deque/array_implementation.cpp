#include <iostream>
using namespace std;
struct Deque{
    private:
        int *arr;
        int cap,s,size;
    public:
        Deque(int n){
            arr=new int[n];
            cap=n;
            s=0;
            size=0;
        }
        void push_front(int x){
            if(size!=cap){
                s=(s-1+cap)%cap;
                arr[s]=x;
                size++;
            }
        }
        void push_back(int x){
            if(size!=cap){
                arr[(s+size)%cap]=x;
                size++;
            }
        }
        int pop_front(){
            if(size!=0){
                int x=arr[s];
                s=(s+1)%cap;
                size--;
                return x;
            }
            return -1;
        }
        int pop_back(){
            if(size!=0){
                int x=arr[(s+size-1+cap)%cap];
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
                return arr[(s+size-1)%cap];
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
    Deque d(20);
    d.push_front(50);
    d.push_front(40);
    d.push_front(30);
    d.push_front(20);
    d.push_front(10);
    cout<<d.getFront()<<d.getRear()<<endl;
    d.push_back(60);
    cout<<d.getFront()<<d.getRear()<<endl;
    d.pop_front();
    d.pop_back();
    cout<<d.getFront()<<d.getRear()<<endl;
    d.pop_front();
    d.pop_back();
    cout<<d.getFront()<<d.getRear()<<endl;
    d.pop_front();
    d.pop_back();
    d.pop_back();
    cout<<d.getFront()<<d.getRear()<<endl;
    d.push_front(50);
    cout<<d.getFront()<<d.getRear()<<endl;
}
 