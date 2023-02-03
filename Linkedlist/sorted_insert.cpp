#include <iostream>
#include <list>

using namespace std;
struct Node{
    int data;
    Node *next;
    Node(int x){
        data=x;
        next=NULL;
    }
};
Node *sortedinsert(Node *head,int n){
    Node *temp2=new Node(n);
    if(head==NULL)
        return temp2;
    if(temp->data>x){
        temp2->next=head;
        return temp2;
    }
    Node* temp=head;
    while(temp->next!=NULL&&temp->next->data<n)
        temp=temp->next;
    temp2->next=temp->next;
    temp->next=temp2;
    return head;
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
}
int main(){
    Node *head=NULL;
    head=insertB(head,30);
    head=insertB(head,20);
    head=insertB(head,10);
    head=sortedinsert(head,95);
    printll(head);
}
 