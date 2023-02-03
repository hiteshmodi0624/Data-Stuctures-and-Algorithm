#include <iostream>
#include <deque>
using namespace std;
struct MinMax{
    deque<int>dq;
    void insertMin(int x){
        dq.push_front(x);
    }
    void insertMax(int x){
        dq.push_back(x);
    }
    int getMin(){
        return dq.front();
    }
    int getMax(){
        return dq.back();
    }
    int extractMin(){
        int x=getMin();
        dq.pop_front();
        return x;
    }
    int extractMax(){
        int x=getMax();
        dq.pop_back();
        return x;
    }
};
int main(){
    MinMax m;
    m.insertMin(100);
    m.insertMin(90);
    m.insertMin(80);
    m.insertMin(70);
    m.insertMin(60);
    m.insertMax(150);
    m.insertMax(200);
    m.insertMax(250);
    cout<<m.getMax();
    cout<<m.extractMin();
    cout<<m.getMin();
}
 