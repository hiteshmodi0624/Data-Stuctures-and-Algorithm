#include <iostream>
#include<unordered_map>
#include<queue>
#include<deque>
#include<math.h>
using namespace std;
struct Node{int key;Node*left;Node*right;
    Node(int x){key=x;left=right=NULL;}};
Node* construct(unordered_map<int,int> m,int pre[],int i,int j,int &v1);Node*binary_tree();


int complete_bt_count(Node*root){
    if(root==NULL)
        return 0;
    int lh=0,rh=0;
    Node*curr=root;
    while(curr!=NULL){
        lh++;
        curr=curr->left;
    }
    curr=root;
    while(curr!=NULL){
        rh++;
        curr=curr->right;
    }
    if(lh==rh)
        return pow(2,lh)-1;
    else
        return complete_bt_count(root->left)+complete_bt_count(root->right)+1;
}
int main(){
    
    Node*root=binary_tree();
    cout<<complete_bt_count(root);
}


Node*binary_tree(){
    int in[]={60,40,70,20,80,50,90,10,100,30,110};
    int pre[]={10,20,40,60,70,50,80,90,30,100,110};
    int n=sizeof(in)/sizeof(in[0]);
    unordered_map<int,int>m;
    for(int i=0;i<n;i++)
        m[in[i]]=i;
    int v1=0;
    return construct(m,pre,0,n-1,v1);
}
Node* construct(unordered_map<int,int> m,int pre[],int i,int j,int &v1){
    int r=m[pre[v1]];
    if(r>j||r<i)
        return NULL;
    Node*root=new Node(pre[v1++]);
    root->left=construct(m,pre,i,r-1,v1);
    root->right=construct(m,pre,r+1,j,v1);
    return root;
}