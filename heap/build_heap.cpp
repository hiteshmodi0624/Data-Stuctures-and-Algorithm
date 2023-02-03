#include <iostream>

using namespace std;
struct Minheap{
    int *arr;
    int size;
    int cap;
    Minheap(int a[],int n){
        arr=a;
        size=n;
    }
    int left(int i){return (2*i+1);}
    int right(int i){return (2*i+2);}
    int parent(int i){return ((i-1)/2);}
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
    void buildhead(){
        for(int i=(size-2)/2;i>=0;i--){
            minHeapify(i);
        }
        for(int i=0;i<size;i++)
            cout<<arr[i]<<" ";
        }
};
int main(){
    int arr[]={10,5,20,2,4,8};
    Minheap*h=new Minheap(arr,6);
    h->buildhead();
}
 