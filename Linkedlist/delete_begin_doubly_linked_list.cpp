#include <iostream>
#include <list>

using namespace std;
struct Node{
    int data;
    Node *prev;
    Node *next;
    Node(int x){
        data=x;
        next=NULL;
        prev=NULL;
    }
};
Node *insert_begin(Node *head,int n){
    if(head==NULL)
        return (new Node(n));
    Node *temp=new Node(n);
    temp->next=head;
    head->prev=temp;
    return temp;
}
Node *delete_dl(Node *head){
    if(head==NULL||head->next==NULL){
        delete head;
        return NULL;
    }
    Node *temp=head->next;
    delete head;
    temp->prev=NULL;
    return temp;
}
void print_dl(Node *head){
    while(head!=NULL){
        cout<<head->data<<" ";
        head=head->next;
    }
}
int main(){
    Node *head=NULL;
    head=insert_begin(head,10);
    head=insert_begin(head,20);
    head=insert_begin(head,30);
    head=delete_dl(head);
    print_dl(head);
    
}
 