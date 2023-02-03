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
Node *insert_end(Node *head,int n){
    if(head==NULL)
        return (new Node(n));
    Node *temp=head;
    while(temp->next!=NULL)
        temp=temp->next;
    temp->next=new Node(n);
    temp->next->prev=temp;
    return head;
}
void print_dl(Node *head){
    while(head!=NULL){
        cout<<head->data<<" ";
        head=head->next;
    }
}
void print_dl_reverse(Node *head){
    while(head!=NULL){
        cout<<head->data<<" ";
        head=head->prev;
    }
}
int main(){
    Node *head=NULL;
    head=insert_end(head,10);
    head=insert_end(head,20);
    head=insert_end(head,30);
    print_dl(head);
    cout<<endl;
    print_dl_reverse(head->next->next);
}
 