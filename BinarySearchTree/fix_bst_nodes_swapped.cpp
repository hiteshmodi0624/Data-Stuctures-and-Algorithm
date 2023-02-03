#include <iostream>
#include <queue>
#include<set>
#include<map>
using namespace std;

struct Node{
    int key;
    Node*left;
    Node*right;
    Node(int x){
        key=x;
        left=right=NULL;
    }
};
bool check_if_bst(Node*root,int min=INT_MIN,int max=INT_MAX);
Node* insert(Node*root,int x);

void fix_helper(Node*root,Node*&first,Node*&second,Node*&pre){
    if(root==NULL)
        return;
    fix_helper(root->left,first,second,pre);
    if(prev!=NULL&&root->key<=pre->key){
        if(first==NULL)
            first=pre;
        second=root;
    }
    pre=root;
    fix_helper(root->right,first,second,pre);
}
void fix_2_swapped_nodes(Node*root){
    Node* first=NULL,*second=NULL,*pre=NULL;
    fix_helper(root,first,second,pre);
    swap(first->key,second->key);
}

int main(){
    Node*s=NULL;
    int arr[]={23,8,30,15,25,12};
    int n=sizeof(arr)/sizeof(arr[0]);
    for(int i=0;i<n;i++)
        s=insert(s,arr[i]);
    s->right->key=s->left->right->key;
    s->left->right->key=30;
    cout<<check_if_bst(s);
     Node* first=NULL,*second=NULL,*pre=new Node(INT_MIN);
    fix_2_swapped_nodes(s);
    cout<<check_if_bst(s);
}
Node* insert(Node*root,int x){
    if(root==NULL)
        return new Node(x);
    if(x>root->key)
        root->right=insert(root->right,x);
    else if(x<root->key){
        root->left=insert(root->left,x);
    }
    return root;
}
bool check_if_bst(Node*root,int min,int max){
    if(root==NULL)
        return true;
    int x=root->key;
    return x>min&&x<max&&check_if_bst(root->left,min,x)&&check_if_bst(root->right,x,max);
}