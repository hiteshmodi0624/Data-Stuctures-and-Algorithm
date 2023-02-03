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
int ceil(Node*root,int x){
    if(root==NULL)
        return -1;
    int res=-1;
    while(root!=NULL){
        if(x>root->key)
            root=root->right;
        else if(x<root->key){
            res=root->key;
            root=root->left;
        }
        else
            return x;
    }
    return res;
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
    bst=insert(bst,10);
    bst=insert(bst,15);
    bst=insert(bst,5);
    bst=insert(bst,12);
    bst=insert(bst,30);
    cout<<ceil(bst,90)<<endl;
    print(bst);
}
 