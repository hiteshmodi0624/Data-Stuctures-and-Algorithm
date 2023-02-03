#include <iostream>
#include <queue>
#include<set>
#include<map>
#include<unordered_set>
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

Node* insert(Node*root,int x);
void vertical_sum(Node*root,int k,map<int,int>&m){
    if(root==NULL)
        return;
    vertical_sum(root->left,k-1,m);
    m[k]+=root->key;
    return vertical_sum(root->right,k+1,m);
}
int main(){
    Node*bst=NULL;
    int arr[]={23,8,30,15,25,12};
    int n=sizeof(arr)/sizeof(arr[0]);
    for(int i=0;i<n;i++)
        bst=insert(bst,arr[i]);
    map<int,int>m;
    vertical_sum(bst,0,m);
    for(auto x:m)
        cout<<x.second<<" ";
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