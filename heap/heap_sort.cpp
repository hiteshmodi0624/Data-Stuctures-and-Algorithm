#include <iostream>

using namespace std;
struct Maxheap{
    int *arr;
    int size;
    int cap;
    Maxheap(int a[],int n){
        arr=a;
        size=n;
    }
    int left(int i){return (2*i+1);}
    int right(int i){return (2*i+2);}
    int parent(int i){return ((i-1)/2);}
    void maxHeapify(int i){
        int sm=i;
        while(1){
            int l=left(i),r=right(i);
            if(l<size&&arr[l]>arr[i])
                sm=l;
            if(r<size&&arr[r]> arr[sm])
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
            maxHeapify(i);
        }
    }
    void sortD(){
        int n=size;
        while(--size>=0){
            swap(arr[0],arr[size]);
            maxHeapify(0);
        }
        size=n;
        for(int i=0;i<size;i++)
            cout<<arr[i]<<" ";
    }
};
int main(){
    int arr[]={10,5,20,2,4,8};
    Maxheap*h=new Maxheap(arr,6);
    h->buildhead();
    h->sortD();
}
 