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
int maxlevel=0;
bool children_sum_prop(Node*root){
    if(root==NULL)  
        return true;
    queue<Node*>q;
    q.push(root);
    while(!q.empty()){
        int s=0,x;
        Node*temp=q.front();
        q.pop();
        x=temp->key;
        if(temp->left==NULL&&temp->right==NULL)
            continue;
        if(temp->left!=NULL){
            s+=temp->left->key;
            q.push(temp->left);
        }
        if(temp->right!=NULL){
            s+=temp->right->key;
            q.push(temp->right);
        }
        if(x!=s)
            return false;
    }
    return true;
}
bool children_sum_prop_rec(Node*root){
    if(root==NULL)  
        return true;
    if(root->left==NULL&&root->right==NULL)
        return true;
    int s=0;
    if(root->left!=NULL)s+=root->left->key;
    if(root->right!=NULL)s+=root->right->key;
    return (s==root->key&&children_sum_prop_rec(root->left)&&children_sum_prop_rec(root->right));
}
int main(){
    Node*root=new Node(5);
    root->left=new Node(3);
    root->right=new Node(2);
    root->left->left=new Node(1);
    root->left->right=new Node(2);
    // root->right->left=new Node(40);
    // root->right->right=new Node(50);
    // root->left->right->left=new Node(50);
    // root->left->right->right=new Node(60);
    // root->left->left->left=new Node(70);
    // root->left->left->right=new Node(80);
    // root->right->right->left=new Node(90);
    // root->left->right->left->right=new Node(50);
    // root->right->right->left->right=new Node(100);
    cout<<children_sum_prop(root);
    cout<<children_sum_prop_rec(root);
}
 