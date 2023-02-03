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
Node *insert_beginning(Node *head,int x){
    Node *y=new Node(x);
    y->next=head;
    return y;
}
void printlist(Node *head){
    while(head!=NULL){
        cout<<head->data<<" ";
        head=head->next;
    }
}
int main(){
    Node *head=NULL;
    head=insert_beginning(head,10);
    head=insert_beginning(head,20);
    head=insert_beginning(head,30);
    printlist(head);
}
 