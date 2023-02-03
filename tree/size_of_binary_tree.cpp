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
int size_of_tree(Node*root){
    if(root==NULL)
        return 0;
    return size_of_tree(root->left)+size_of_tree(root->right)+1;
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
    root->left->right->left->right=new Node(50);
    root->right->right->left->right=new Node(100);
    cout<<size_of_tree(root);
}
 