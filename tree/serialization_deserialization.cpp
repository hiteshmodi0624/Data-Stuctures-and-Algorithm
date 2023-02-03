#include <iostream>
#include<unordered_map>
#include<queue>
#include<deque>
#include<math.h>
using namespace std;
struct Node{int key;Node*left;Node*right;
    Node(int x){key=x;left=right=NULL;}};
Node* construct(unordered_map<int,int> m,int pre[],int i,int j,int &v1);Node*binary_tree();


void serialize(Node*root,vector<int>&a){
    if(root==NULL){
        a.push_back(-1);
        return;
    }
    a.push_back(root->key);
    serialize(root->left,a);
    serialize(root->right,a);
}
Node*deserialize(vector<int>a,int &i){
    if(i==a.size())return NULL;
    int x=a[i];
    i++;
    if(x==-1)
        return NULL;
    Node*root=new Node(x);
    root->left=deserialize(a,i);
    root->right=deserialize(a,i);
    return root;
}
int main(){
    
    Node*root=binary_tree();
    vector<int>a;
    serialize(root,a);
    for(auto x:a)
        cout<<x<<" ";
    cout<<endl;
    int y=0;
    Node*root2=deserialize(a,y);
    vector<int>b;
    serialize(root2,b);
    for(auto x:b)
        cout<<x<<" ";
}


Node*binary_tree(){
    int in[]={60,40,70,20,80,50,90,10,100,30};
    int pre[]={10,20,40,60,70,50,80,90,30,100};
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