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
void printmiddle(Node *head){
    if(head==NULL)
        return;
    Node *curr=head;
    Node *curr2=head;
    while(curr2!=NULL&&curr2->next!=NULL){
        curr=curr->next;
        curr2=curr2->next->next;
    }
    cout<<curr->data<<endl;
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
    head=insertB(head,30);
    head=insertB(head,20);
    head=insertB(head,10);
    head=insertB(head,334);
    head=insertB(head,230);
    head=insertB(head,120);
    head=insertB(head,330);
    head=insertB(head,6);
    printmiddle(head);
    printll(head);
    head=insertB(head,6);
    printmiddle(head);
    printll(head);
}
 