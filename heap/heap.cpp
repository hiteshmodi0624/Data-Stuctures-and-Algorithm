#include <iostream>

using namespace std;
struct Minheap{
    int *arr;
    int size;
    int cap;
    Minheap(int n){
        cap=n;
        arr=new int[n];
        size=0;
    }
    int left(int i){return (2*i+1);}
    int right(int i){return (2*i+2);}
    int parent(int i){return ((i-1)/2);}
    void insert(int x){
        if(size==cap)return;
        arr[size]=x;
        int i=size;
        while(i&&arr[parent(i)]>x){
            swap(arr[parent(i)],arr[i]);
            i=parent(i);
        }
        size++;
    }
};
int main(){
    Minheap*h=new Minheap(10);
    h->insert(10);
    h->insert(50);
    h->insert(100);
    h->insert(20);
    h->insert(15);
    h->insert(40);
    h->insert(25);
    h->insert(1);
    for(int i=0;i<8;i++)
        cout<<h->arr[i]<<" ";
}
 