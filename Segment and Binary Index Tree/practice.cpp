#include <iostream>
#include <unordered_map>
using namespace std;
class sTree{
    int *tree;
    int size;
    public:
    sTree(int n){
        tree=new int[4*n];
        size=n;
    }
    int construct(int arr[],int s,int e,int i=0){
        if(s==e){
            tree[i]=arr[s];
            return arr[s];
        }
        int mid=(s+e)/2;
        tree[i]=construct(arr,s,mid,2*i+1)+construct(arr,mid+1,e,2*i+2);
        return tree[i];
    }
    int getSumRec(int s,int r,int ss,int se,int i){
        if(se<s||ss>r)
            return 0;
        if(s<=ss&&r>=se)return tree[i];
        int mid=(ss+se)/2;
        return getSumRec(s,r,ss,mid,2*i+1)+getSumRec(s,r,mid+1,se,2*i+2);
    }
    int getsum(int s,int r){
        return getSumRec(s,r,0,size-1,0);
    }
    void reduce(int index,int diff,int ss,int se,int si){
        if(se<index||ss>index)
            return;
        tree[si]+=diff;
        if (se>ss){
            int mid=(ss+se)/2;
            reduce(index,diff,ss,mid,2*si+1);
            reduce(index,diff,mid+1,se,2*si+2);
        }
    }
    void update(int index,int val){
        int diff=val-getsum(index,index);
        reduce(index,diff,0,size-1,0);
    }
};
int main(){
    int arr[]={10,20,30,40};
    int n=sizeof(arr)/sizeof(arr[0]);
    sTree s(n);
    s.construct(arr,0,n-1);
    cout<<s.getsum(0,2)<<endl;
    s.update(1,50);
    cout<<s.getsum(1,1);
}
 