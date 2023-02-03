#include <iostream>
#include <list>
#include <vector>

using namespace std;
struct Node{
    int data;
    Node *next;
    Node(int x){
        data=x;
        next=NULL;
    }
};
Node *reverse(Node *head,Node* prev){
    if(head==NULL)
        return prev;
    Node*res=reverse(head->next,head);
    head->next=prev;
    return res;
}
Node *reverse2(Node *head){
    if(head==NULL)
        return NULL;
    if(head->next==NULL)
        return head;
    Node* temp=reverse2(head->next);
    head->next->next=head;
    head->next=NULL;
    return temp;
}
Node *insertB(Node *head,int n){
    if(head==NULL){
        head=new Node(n);
        return head;
    }
    Node *temp=new Node(n);
    temp->next=head;
    return temp;
}
void printll(Node *head){
    Node *temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    };
    cout<<endl;
}
int main(){
    Node *head=NULL;
    head=insertB(head,10);
    head=insertB(head,20);
    head=insertB(head,20);
    head=insertB(head,30);
    head=insertB(head,30);
    head=insertB(head,30);
    head=insertB(head,40);
    head=insertB(head,40);
    printll(head);
    // head=reverse(head,NULL);
    head=reverse2(head);
    printll(head);
    
}
 