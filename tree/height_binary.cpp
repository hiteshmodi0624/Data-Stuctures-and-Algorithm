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
int height(Node*root){
    if(root==NULL)
        return 0;
    return max(height(root->left),height(root->right))+1;
}
int main(){
    // degree<=2
    Node*root=new Node(10);
    root->left=new Node(20);
    root->right=new Node(30);
    root->left->left=new Node(40);
    root->left->right=new Node(50);
    root->right->left=new Node(40);
    root->right->right=new Node(50);
    root->left->right->left=new Node(50);
    root->left->right->left->right=new Node(50);
    cout<<height(root);
    
}
 