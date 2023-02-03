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
Node* insert(Node*bst,int x){
    if(bst==NULL)
        return new Node(x);
    if(x>bst->key)
        bst->right=insert(bst->right,x);
    else if(x<bst->key)
        bst->left=insert(bst->left,x);
    return bst;
}
Node* getsuccessor(Node*root){
    Node*curr=root->right;
    while(curr!=NULL&&curr->left!=NULL){
        curr=curr->left;
    }
    return curr;
}
Node*delNode(Node*root,int x){
    if(root==NULL)
        return NULL;
    if(root->key>x)
        root->left=delNode(root->left,x);
    else if(root->key<x)
        root->right=delNode(root->right,x);
    else{
        if(root->left==NULL){
            Node*temp=root->right;
            delete(root);
            return temp;
        }
        if(root->right==NULL){
            Node*temp=root->left;
            delete(root);
            return temp;
        }
        else{
            Node*succ=getsuccessor(root);
            root->key=succ->key;
            root->right=delNode(root->right,succ->key);
        }
    }
    return root;
}

Node*delNode_itr(Node*root,int x){
    Node*curr=root,*dn;
    if(curr==NULL)
        return NULL;
    while(curr!=NULL){
        if(curr->key==x)
            break;
        else if(curr->key>x){
            if(curr->left->key==x)
                break;
            curr=curr->left;
        }
        else{
            if(curr->right->key==x)
                break;
            curr=curr->right;
        }
    }

}
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
int main(){
    Node*bst=NULL;
    bst=insert(bst,50);

    bst=insert(bst,30);
    bst=insert(bst,70);

    bst=insert(bst,40);
    bst=insert(bst,60);
    bst=insert(bst,80);
    bst=delNode(bst,50);
    print(bst);
}
 