#include <iostream>
#include <queue>
#include<set>
#include<map>
using namespace std;

struct Node{
    int key;
    Node*left;
    Node*right;
    int lcount;
    Node(int x){
        key=x;
        left=right=NULL;
        lcount=0;
    }
};
Node* insert(Node*bst,int x){
    if(bst==NULL)
        return new Node(x);
    if(x>bst->key)
        bst->right=insert(bst->right,x);
    else if(x<bst->key){
        bst->lcount=bst->lcount+1;
        bst->left=insert(bst->left,x);
    }
    return bst;
}
Node*kth_smallest(Node*root,int k){
    if(root==NULL)
        return NULL;
    int count=root->lcount+1;
    if(count==k)
        return root;
    if(count>k)
        return kth_smallest(root->left,k);
    return kth_smallest(root->right,k-count);
}
int main(){
    Node*s=NULL;
    int arr[]={23,8,30,15,25,12};
    int n=sizeof(arr)/sizeof(arr[0]);
    for(int i=0;i<n;i++)
        s=insert(s,arr[i]);
    Node*k=kth_smallest(s,6);
    cout<<k->key;
}