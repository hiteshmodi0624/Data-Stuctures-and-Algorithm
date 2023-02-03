#include <iostream>
#include <queue>
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
int max_width(Node*root){
    if(root==NULL)
        return 0;
    queue<Node*>q;
    q.push(root);
    int c=1,temp=0;
    int maxi=0;
    while(!q.empty()){
        int count=q.size();
        maxi=max(maxi,count);
        while(count--){
            Node*curr=q.front();
            q.pop();
            if(curr->left!=NULL)
                q.push(curr->left);
            if(curr->right!=NULL)
                q.push(curr->right);
        }
    }
    return maxi;
}
int main(){
    Node*root=new Node(10);
    root->left=new Node(20);
    root->right=new Node(30);
    root->left->left=new Node(40);
    root->left->right=new Node(50);
    root->right->left=new Node(40);
    root->right->right=new Node(50);
    root->left->right->left=new Node(50);
    root->left->right->right=new Node(60);
    root->left->left->left=new Node(70);
    root->left->left->right=new Node(80);
    root->right->right->left=new Node(90);
    root->right->right->right=new Node(110);
    root->right->left->left=new Node(120);
    root->left->right->left->right=new Node(50);
    root->right->right->left->right=new Node(100);
    cout<<max_width(root);
}
 