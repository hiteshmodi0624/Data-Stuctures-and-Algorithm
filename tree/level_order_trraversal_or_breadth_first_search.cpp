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
void level_order_print_with_endl(Node*root){
    if(root==NULL)
        return;
    queue<Node*>q;
    q.push(root);
    q.push(NULL);
    while(q.size()>1){
        Node*curr=q.front();
        q.pop();
        if(curr==NULL){
            q.push(NULL);
            cout<<endl;
            continue;
        }
        cout<<curr->key<<" ";
        if(curr->left!=NULL)
            q.push(curr->left);
        if(curr->right!=NULL)
            q.push(curr->right);
    }
}
void level_order_print_with_endl2(Node*root){
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
void level_order_print_with_endl_own(Node*root){
    if(root==NULL)
        return;
    queue<Node*>q;
    q.push(root);
    int c=1,temp=0;
    while(!q.empty()){
        Node*curr=q.front();
        q.pop();
        cout<<curr->key<<" ";
        if(!(--c))cout<<endl;
        if(curr->left!=NULL){
            q.push(curr->left);
            temp++;
        }
        if(curr->right!=NULL){
            q.push(curr->right);
            temp++;
        }
        if(!c){
            c=temp;
            temp=0;
        }
    }
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
    level_order_print_with_endl(root);
    cout<<endl;
    cout<<endl;
    level_order_print_with_endl2(root);
    cout<<endl;
    level_order_print_with_endl_own(root);
}
 