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
void print_dist_k(Node*root,int k){
    if(root==NULL)
        return;
    if(k==0){
        cout<<root->key<<" ";
        return;
    }
    print_dist_k(root->left,k-1);
    print_dist_k(root->right,k-1);
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
    root->left->right->right=new Node(60);
    root->left->left->left=new Node(70);
    root->left->left->right=new Node(80);
    root->right->right->left=new Node(90);
    root->left->right->left->right=new Node(50);
    root->right->right->left->right=new Node(100);
    print_dist_k(root,3);
    
}
 