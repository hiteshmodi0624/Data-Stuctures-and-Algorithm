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
Node *insert_end(Node *head,int x){
    if(head==NULL){
        head=new Node(x);
        return head;
    }
    Node *temp=head;
    while(temp->next!=NULL)
        temp=temp->next;
    temp->next=new Node(x);
    return head;
}
void printlist(Node *head){
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
    printlist(head);
}
 