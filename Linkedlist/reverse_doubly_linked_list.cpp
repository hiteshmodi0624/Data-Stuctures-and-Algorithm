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
Node *reverse_list(Node *head){
    if(head==NULL||head->next==NULL)
        return head;
    Node *curr=head,*temp=NULL;
    while(curr!=NULL){
        temp=curr->prev;
        curr->prev=curr->next;
        curr->next=temp;
        curr=curr->prev;
    }
    return temp->prev;
}
Node *insert_end(Node *head,int n){
    if(head==NULL)
        return (new Node(n));
    Node *curr=head;
    while(curr->next!=NULL)
        curr=curr->next;
    curr->next=new Node(n);
    curr->next->prev=curr;
    return head;
}
void print_dl(Node *head){
    while(head!=NULL){
        cout<<head->data<<" ";
        head=head->next;
    }
}
int main(){
    Node *head=NULL;
    head=insert_end(head,10);
    head=insert_end(head,20);
    head=insert_end(head,30);
    print_dl(head);
    cout<<endl;
    head=reverse_list(head);
    print_dl(head);
}
 