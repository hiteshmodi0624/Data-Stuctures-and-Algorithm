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
void print_left(Node*root,int level=1){
    if(root==NULL)
        return;
    if(maxlevel<level){
        cout<<root->key<<" ";
        maxlevel=level;    
    }
    print_left(root->left,level+1);
    print_left(root->right,level+1);
}
void print_left_itr(Node*root,int level=1){
    if(root==NULL)  
        return;
    queue<Node*>q;
    q.push(root);
    while(!q.empty()){
        int count=q.size();
        cout<<q.front()->key<<" ";
        while(count--){
            Node*temp=q.front();
            q.pop();
            if(temp->left!=NULL)
                q.push(temp->left);
            if(temp->right!=NULL)
                q.push(temp->right);
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
    print_left(root);
    cout<<endl;
    print_left_itr(root);
}
 