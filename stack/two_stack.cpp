#include <iostream>
#include <stack>
using namespace std;

struct TwoStack{
    int cap,top1,top2,*arr;
    TwoStack(int x){
        cap=x;
        top1=-1;
        top2=x;
        arr=new int[x];
    }
    void push1(int x){if(top1<top2-1){top1++;arr[top1]=x;}}
    void push2(int x){if(top1<top2-1){top2--;arr[top2]=x;}}
    void pop1(){if(top1>=0){top1--;}}
    void pop2(){if(top2<cap){top2++;}}
    int peek1(){if(top1>=0){return arr[top1];}}
    int peek2(){if(top2<cap){return arr[top2];}}
    bool empty(){return(top1==-1&&top2==cap);}
    int size(){return(top1+1+(cap-top2));}
};
int main(){
    TwoStack s(10);
    s.push1(20);
    s.push1(30);
    s.push1(40);
    s.push2(5);
    s.push2(10);
    s.push2(15);
    s.pop1();
    s.pop2();
    cout<<s.peek1();
    cout<<s.peek2();
}
 