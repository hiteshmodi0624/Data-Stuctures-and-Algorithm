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
Node*pre=NULL;
Node*head;
Node* to_d_ll(Node*root){
    if(root==NULL)
        return NULL;
    to_d_ll(root->left);
    pre!=NULL?pre->right=root:head=root;
    root->left=pre;
    pre=root;
    to_d_ll(root->right);
    return head;
}
void print_ll(Node*head){
    Node*temp;
    while(head!=NULL){
        cout<<head->key<<" ";
        temp=head;
        head=head->right;
    }
    cout<<endl;
    while(temp!=NULL){
        cout<<temp->key<<" ";
        temp=temp->left;
    }
}
int main(){
    Node*root=new Node(10);
    root->left=new Node(5);
    root->right=new Node(20);
    root->right->left=new Node(30);
    root->right->right=new Node(35);
    // root->right->left=new Node(40);
    // root->right->right=new Node(50);
    // root->left->right->left=new Node(50);
    // root->left->right->right=new Node(60);
    // root->left->left=new Node(70);
    // root->left->left->right=new Node(80);
    // root->right->right->left=new Node(90);
    // root->right->right->right=new Node(110);
    // root->right->left->left=new Node(120);
    // root->left->right->left->right=new Node(50);
    // root->right->right->left->right=new Node(100);
    root=to_d_ll(root);
    print_ll(root);
}
 