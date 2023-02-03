#include <iostream>
#include<unordered_map>
#include<queue>
#include<deque>
#include<stack>
using namespace std;
struct Node{int key;Node*left;Node*right;
    Node(int x){key=x;left=right=NULL;}};
Node*deserialize(int a[],int &i,int n);

void inorder_itr(Node*root){
    if(root==NULL)
        return;
    stack<Node*>s;
    while(s.size()!=0||root!=NULL){
        while(root!=NULL){
            s.push(root);
            root=root->left;
        }
        root=s.top();
        s.pop();
        cout<<root->key<<" ";
        root=root->right;
    }
}
int main(){
    int a[]={10,20,40,60,-1,-1,70,-1,-1,50,80,-1,-1,90,-1,-1,30,100,-1,-1,-1};
    // int in[]={60,40,70,20,80,50,90,10,100,30};
    int n=sizeof(a)/sizeof(a[0]);
    int pq=0;
    Node*root=deserialize(a,pq,n);
    inorder_itr(root);
}

Node*deserialize(int a[],int &i,int n){
    if(i==n)return NULL;
    int x=a[i];
    i++;
    if(x==-1)
        return NULL;
    Node*root=new Node(x);
    root->left=deserialize(a,i,n);
    root->right=deserialize(a,i,n);
    return root;
}