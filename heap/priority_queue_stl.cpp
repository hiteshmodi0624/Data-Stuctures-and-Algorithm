#include <iostream>
#include <queue> 
using namespace std;
struct Person{
    int age;
    float a;
    Person(int x,int y){
        age=x;
        a=y;
    }
};
struct myComp{
    bool operator()(Person const &x,Person const &y){
        return x.age>y.age;
    }
};
int main(){
    int arr[]={20,10,30,230};
    int n=sizeof(arr)/sizeof(arr[0]);
    priority_queue<int>pq(arr,arr+n);
    pq.push(220);
    while(!pq.empty()){
        cout<<pq.top()<<" ";
        pq.pop();
    }
    cout<<endl;
    priority_queue<int,vector<int>,greater<int> >pq2;
    pq2.push(20);
    pq2.push(10);
    pq2.push(30);
    pq2.push(230);
    pq2.push(220);
    while(!pq2.empty()){
        cout<<pq2.top()<<" ";
        pq2.pop();
    }
    Person p1(10,3);
    Person p2(9,4);
    priority_queue<Person,vector<Person>,myComp>pq3;
    pq3.push(p1);
    pq3.push(p2);
    cout<<pq3.top().age;
}
 