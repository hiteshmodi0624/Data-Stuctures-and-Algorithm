#include <iostream>
#include <list>

using namespace std;
struct Node{
    int data;
    Node *next;
    Node *prev;
    Node(int x){
        data=x;
        next=NULL;
        prev=NULL;
    }
};
Node *insertB(Node *head,int n){
    if(head==NULL){
        head=new Node(n);
        head->next=head;
        head->prev=head;
        return head;
    }
    Node *temp=new Node(n);
    temp->next=head;
    temp->prev=head->prev;
    head->prev->next=temp;
    head->prev=temp;
    return temp;
}
Node *insertE(Node *head,int n){
    if(head==NULL){
        head=new Node(n);
        head->next=head;
        head->prev=head;
        return head;
    }
    Node *temp=new Node(n);
    temp->next=head;
    temp->prev=head->prev;
    head->prev->next=temp;
    head->prev=temp;
    return head;
}
void printll(Node *head){
    Node *temp=head;
    do{
        cout<<temp->data<<" ";
        temp=temp->next;
    }while(head!=temp);
}
int main(){
    Node *head=NULL;
    head=insertB(head,10);
    head=insertB(head,20);
    head=insertB(head,30);
    head=insertE(head,5);
    printll(head);
}
 