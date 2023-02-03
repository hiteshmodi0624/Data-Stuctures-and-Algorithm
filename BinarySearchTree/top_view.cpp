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
void vertical_sum(Node*root){
    if(root==NULL)
        return;
    map<int,int>m;
    queue<pair<Node*,int> >q;
    q.push(make_pair(root,0));
    while(!q.empty()){
        Node*temp=q.front().first;
        int k=q.front().second;
        q.pop();
        if(m.count(k)==0)
            m[k]=temp->key;
        if(temp->left!=NULL)
            q.push(make_pair(temp->left,k-1));
        if(temp->right!=NULL)
            q.push(make_pair(temp->right,k+1));
    }
    for(auto y:m){
        cout<<y.second<<" ";
    }
}
int main(){
    Node*bst=NULL;
    int arr[]={23,8,30,15,25,12,1,5,6};
    int n=sizeof(arr)/sizeof(arr[0]);
    for(int i=0;i<n;i++)
        bst=insert(bst,arr[i]);
    map<int,vector<int> >m;
    vertical_sum(bst);
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