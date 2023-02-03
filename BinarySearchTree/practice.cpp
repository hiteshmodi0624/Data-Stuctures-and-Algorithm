#include <iostream>
#include <queue>
using namespace std;
struct Node{
    Node*right;
    Node*left;
    int key;
    Node(int x){
        key=x;
        right=left=NULL;
    }
};
void print(Node*root){
    if(root==NULL)
        return;
    queue<Node*>q;
    q.push(root);
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
Node* insert(Node*bst,int x){
    if(bst==NULL)
        return new Node(x);
    if(x>bst->key)
        bst->right=insert(bst->right,x);
    else if(x<bst->key)
        bst->left=insert(bst->left,x);
    return bst;
}
Node* insert_itr(Node*root,int x){
    Node*temp=new Node(x);
    Node*bst=root,*parent=NULL;
    while(bst!=NULL){
        parent=bst;
        if(x>bst->key)
            bst=bst->right;
        else if(x<bst->key)
            bst=bst->left;
        else
            return root;
    }
    if(parent==NULL)
        return temp;
    if(parent->key>x)
        parent->left=temp;
    else 
        parent->right=temp;
    return root;
}
bool searchbst(Node*root,int x){
    if(root==NULL)
        return false;
    if(x==root->key)
        return true;
    if(root->key>x)
        return searchbst(root->left,x);
    else
        return searchbst(root->right,x);
}
bool searchbst_itr(Node*root,int x){
    while(root!=NULL){
        if(root->key==x)
            return true;
        else if(root->key>x)
            root=root->left;
        else
            root=root->right;
    }
    return false;
}
int main(){
    Node*bst=NULL;
    bst=insert_itr(bst,15);
    bst=insert_itr(bst,20);
    bst=insert(bst,5);
    bst=insert(bst,3);
    bst=insert_itr(bst,80);
    bst=insert_itr(bst,16);
    bst=insert_itr(bst,16);
    bst=insert_itr(bst,82);
    bst=insert_itr(bst,83);
    cout<<searchbst_itr(bst,16)<<" ";
    cout<<searchbst_itr(bst,32)<<" ";
    cout<<searchbst(bst,16)<<" ";
    cout<<searchbst(bst,32)<<" "<<endl;
    print(bst);
}
 