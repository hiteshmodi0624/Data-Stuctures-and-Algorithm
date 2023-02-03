#include <iostream>
#include<unordered_map>
#include<queue>
#include<deque>
#include<stack>
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
Node* construct(unordered_map<int,int> m,int pre[],int i,int j);Node*binary_tree();
void print_level(Node*root){
    if(root==NULL)
        return;
    stack<Node*>s1,s2;
    s2.push(root);
    while(!s1.empty()||!s2.empty()){
        while(!s1.empty()){
            Node*curr=s1.top();
            s1.pop();
            cout<<curr->key<<" ";
            if(curr->right!=NULL)
                s2.push(curr->right);
            if(curr->left!=NULL)
                s2.push(curr->left);
        }
        cout<<endl;
        while(!s2.empty()){
            Node*curr=s2.top();
            s2.pop();
            cout<<curr->key<<" ";
            if(curr->left!=NULL)
                s1.push(curr->left);
            if(curr->right!=NULL)
                s1.push(curr->right);
        }
        cout<<endl;
    }
}



int main(){
    Node*root=binary_tree();
    print_level(root);
}
int g=0;
Node* construct(unordered_map<int,int> m,int pre[],int i,int j){
    int r=m[pre[g]];
    if(r>j||r<i)
        return NULL;
    Node*root=new Node(pre[g++]);
    root->left=construct(m,pre,i,r-1);
    root->right=construct(m,pre,r+1,j);
    return root;
}
Node*binary_tree(){
    int in[]={60,40,70,20,140,80,50,90,150,10,100,120,30,130,110};
    int pre[]={10,20,40,60,70,50,80,140,90,150,30,100,120,110,130};
    int n=sizeof(in)/sizeof(in[0]);
    unordered_map<int,int>m;
    for(int i=0;i<n;i++)
        m[in[i]]=i;
    return construct(m,pre,0,n-1);
}