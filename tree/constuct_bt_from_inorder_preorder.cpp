#include <iostream>
#include<unordered_map>
#include<queue>
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
int x=0;
Node* construct(unordered_map<int,int> m,int pre[],int i,int j){
    int r=m[pre[x]];
    if(r>j||r<i)
        return NULL;
    Node*root=new Node(pre[x++]);
    root->left=construct(m,pre,i,r-1);
    root->right=construct(m,pre,r+1,j);
    return root;
}
void print(Node*root){
    if(root==NULL)
        return;
    print(root->left);
    cout<<root->key<<" ";
    print(root->right);
}
void print_level(Node*root){
    if(root==NULL)
        return;
    queue<Node*>q;
    q.push(root);
    int c=1,temp=0;
    while(!q.empty()){
        int count=q.size();
        while(count--){
            Node*curr=q.front();
            q.pop();
            cout<<curr->key<<" ";
            if(curr->left!=NULL)
                q.push(curr->left);
            if(curr->right!=NULL)
                q.push(curr->right);
        }
        cout<<endl;
    }
}
int main(){
    int in[]={60,40,70,20,80,50,90,10,100,30,110};
    int pre[]={10,20,40,60,70,50,80,90,30,100,110};
    int n=sizeof(in)/sizeof(in[0]);
    unordered_map<int,int>m;
    for(int i=0;i<n;i++)
        m[in[i]]=i;
    // Node*root=construct(in,pre,0,n-1);
    Node*root=construct(m,pre,0,n-1);
    print(root);
    cout<<endl;
    print_level(root);
}
 