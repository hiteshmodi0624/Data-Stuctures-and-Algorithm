#include <iostream>
#include<unordered_map>
#include<queue>
#include<deque>
#include<stack>
using namespace std;
struct Node{int key;Node*left;Node*right;
    Node(int x){key=x;left=right=NULL;}};
Node* construct(unordered_map<int,int> m,int pre[],int i,int j,int &v1);Node*binary_tree();

int burn(Node*head,int a,int &dist,int &res){
    if(head==NULL)
        return 0;
    if(head->key==a)
        {dist=0;return 1;}
    int ldist=-1,rdist=-1;
    int l=burn(head->left,a,ldist,res);
    int r=burn(head->right,a,rdist,res);
    if(ldist!=-1){
        dist=ldist+1;
        res=max(res,dist+r);
    }
    if(rdist!=-1){
        dist=rdist+1;
        res=max(res,dist+l);
    }
    return max(l,r)+1;
}
int main(){
    Node*root=binary_tree();
    int dist=-1,res=0;
    burn(root,70,dist,res);
    cout<<res;
    dist=-1;
    burn(root,130,dist,res);
    cout<<res;
}


Node*binary_tree(){
    int in[]={60,40,70,20,140,80,50,90,150,10,100,120,30,130,110};
    int pre[]={10,20,40,60,70,50,80,140,90,150,30,100,120,110,130};
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