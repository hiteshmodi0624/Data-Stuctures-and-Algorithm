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
    int errorpos(){
        int i=0;
        while(i<size&&arr[i]<arr[left(i)]&&arr[i]<arr[right(i)])
            i++;
        return i;
    }
    void minHeapify(int i){
        int sm=i;
        while(1){
            int l=left(i),r=right(i);
            if(l<size&&arr[l]<arr[i])
                sm=l;
            if(r<size&&arr[r]<arr[sm])
                sm=r;
            if(sm!=i){
                swap(arr[i],arr[sm]);
                i=sm;
            }
            else break;
        }
    }
    int extractMin(){
        if(size==0)
            return INT_MAX;
        if(size==1)
            return arr[0];
        swap(arr[0],arr[size-1]);
        size--;
        minHeapify(0);
        return arr[size];
    }
    void decreaseKey(int i,int x){
        arr[i]=x;
        while(i!=0&&arr[i]<arr[parent(i)]){
            swap(arr[i],arr[parent(i)]);
            i=parent(i);
        }
    }
    void delete(int i){
        
    }
};
int main(){
    Minheap*h=new Minheap(10);
    h->insert(20);
    h->insert(25);
    h->insert(30);
    h->insert(35);
    h->insert(40);
    h->insert(80);
    h->insert(32);
    h->insert(100);
    h->insert(70);
    h->insert(60);
    for(int j=0;j<h->size;j++)
        cout<<h->arr[j]<<" ";
    cout<<endl;
    h->decreaseKey(3,2);
    for(int j=0;j<h->size;j++)
        cout<<h->arr[j]<<" ";
    cout<<endl;
}
 