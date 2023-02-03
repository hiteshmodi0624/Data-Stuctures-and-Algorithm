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
bool check_if_bst(Node*root,int min=INT_MIN,int max=INT_MAX){
    if(root==NULL)
        return true;
    int x=root->key;
    return x>min&&x<max&&check_if_bst(root->left,min,x)&&check_if_bst(root->right,x,max);
}
bool check_if_bst_2(Node*root,int &x){
    if(root==NULL)
        return true;
    if(check_if_bst_2(root->left,x)==false)
        return false;
    if(root->key<=x)
        return false;
    x=root->key;
    return check_if_bst_2(root->right,x);
    
};
Node* insert(Node*root,int x);
int main(){
    Node*s=NULL;
    int arr[]={23,8,30,15,25,12};
    int n=sizeof(arr)/sizeof(arr[0]);
    for(int i=0;i<n;i++)
        s=insert(s,arr[i]);
    cout<<check_if_bst(s);
    int x=INT16_MIN;
    cout<<check_if_bst_2(s,x);
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