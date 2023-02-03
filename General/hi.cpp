#include<iostream>
using namespace std;

struct array{
    int A[10];
    int size;
    int length;
};
void display(struct array *arr){
    cout<<"elements are ";
    for(int i=0;i<arr->length;i++){
        cout<<arr->A[i]<<" ";
    }
}

int C[10];
struct array* merge(struct array *arr1,struct array *arr2){
    int i=0,j=0,k=0;
    struct array *arr3= new struct array[10];
    while(i<arr1->length && j<arr2->length){
        if(arr1->A[i]<arr2->A[j]){
        arr3->A[k++]=arr1->A[i++];
       // k++;
      //  i++;
        }
        else
        arr3->A[k++]=arr2->A[j++];
      //  k++;
     //  j++;
    }
    for(;i<arr1->length;i++){
     arr3->A[k++]=arr1->A[i];
    // k++;
    }

    for(;j<arr2->length;j++){
    arr3->A[k++]=arr2->A[j];
  //  k++;
    }

   arr3->length=arr1->length+arr2->length;
   arr3->size=10;
   return arr3;
}
int main()
{
    struct array arr1={{1,3,5,7,9},10,5};
    struct array arr2={{2,4,6,8,10},10,5};
   // struct array arr1={{1,2,3,4,5},5,5};
  //  struct array arr2={{6,7,8,9,10},5,5};
    struct array *arr3;
   arr3=merge(&arr1,&arr2);
   display(arr3);


    
    return 0;
}