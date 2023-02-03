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
int balanced_tree_check(Node*root){
    if(root==NULL)return 0;
    int lh=balanced_tree_check(root->left);
    if(lh==-1)return -1;
    int rh=balanced_tree_check(root->right);
    if(rh==-1)return -1;
    if(abs(lh-rh)>1)return -1;
    else return max(lh,rh)+1;
}
int main(){
    Node*root=new Node(10);
    root->left=new Node(20);
    root->right=new Node(30);
    root->left->left=new Node(40);
    root->left->right=new Node(50);
    root->right->left=new Node(40);
    root->right->right=new Node(50);
    root->left->left->left=new Node(70);
    root->left->left->right=new Node(80);
    root->left->right->left=new Node(50);
    root->left->right->right=new Node(60);
    root->right->right->left=new Node(90);
    root->left->right->left->right=new Node(50);
    root->right->right->left->right=new Node(100);

    if(balanced_tree_check(root)==-1)
        cout<<"False";
    else    
        cout<<"True";
}
 