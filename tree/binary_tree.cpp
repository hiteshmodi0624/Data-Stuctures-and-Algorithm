#include <iostream>
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
void print_inorder(Node*root){
    if(root!=NULL){
        print_inorder(root->left);
        cout<<root->key<<" ";
        print_inorder(root->right);
    }
}
void print_preorder(Node*root){
    if(root!=NULL){
        cout<<root->key<<" ";
        print_preorder(root->left);
        print_preorder(root->right);
    }
}
void print_postorder(Node*root){
    if(root!=NULL){
        print_postorder(root->left);
        print_postorder(root->right);
        cout<<root->key<<" ";
    }
}
int main(){
    // degree<=2
    Node*root=new Node(10);
    root->left=new Node(20);
    root->right=new Node(30);
    root->left->left=new Node(40);
    root->left->right=new Node(50);
    print_inorder(root);
    cout<<endl;
    print_preorder(root);
    cout<<endl;
    print_postorder(root);
    
}
 