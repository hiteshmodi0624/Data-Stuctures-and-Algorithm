#include <iostream>
#include<unordered_map>
#include<queue>
#include<deque>
#include<stack>
using namespace std;
struct Node{int key;Node*left;Node*right;
    Node(int x){key=x;left=right=NULL;}};
Node* construct(unordered_map<int,int> m,int pre[],int i,int j);Node*binary_tree();



Node* LCA(Node*head,int a,int b){
    if(head==NULL)
        return NULL;
    if(head->key==a||head->key==b)
        return head;
    Node* l=LCA(head->left,a,b);
    Node* r=LCA(head->right,a,b);
    if(l!=NULL&&r!=NULL)
        return head;
    return (l==NULL)?r:l;
}
int main(){
    Node*root=binary_tree();
    cout<<LCA(root,120,110)->key;
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
int v1=0;
Node* construct(unordered_map<int,int> m,int pre[],int i,int j){
    int r=m[pre[v1]];
    if(r>j||r<i)
        return NULL;
    Node*root=new Node(pre[v1++]);
    root->left=construct(m,pre,i,r-1);
    root->right=construct(m,pre,r+1,j);
    return root;
}