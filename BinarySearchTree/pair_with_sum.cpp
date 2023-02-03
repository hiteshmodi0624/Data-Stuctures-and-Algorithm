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
bool check_sum(Node*root,unordered_set<int>&s,int k){
    if(root==NULL)
        return false;
    if(check_sum(root->left,s,k))
        return true;
    if(s.find(k-root->key)!=s.end())
        return true;
    s.insert(root->key);
    return check_sum(root->right,s,k);
}
int main(){
    Node*bst=NULL;
    int arr[]={23,8,30,15,25,12};
    int n=sizeof(arr)/sizeof(arr[0]);
    for(int i=0;i<n;i++)
        bst=insert(bst,arr[i]);
    unordered_set<int>s;
    cout<<check_sum(bst,s,31);
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