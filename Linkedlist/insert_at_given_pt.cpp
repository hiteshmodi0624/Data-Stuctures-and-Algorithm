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
int search(Node *head,int x){
    int pos=1;
    while(head!=NULL){
        if(head->data==x)
            return pos;
        else{
            pos++;
            head=head->next;
        }
        }
    return -1;
}
Node *insert_any_pt(Node *head,int x,int pos=1){
    Node *temp=new Node(x);
    if(pos==1){
        temp->next=head;
        return temp;
    }
    Node *curr=head;
    while(pos-2!=0&&curr!=NULL){
        curr=curr->next;
        pos--;
    }
    if(curr==NULL)
        return head;
    temp->next=curr->next;
    curr->next=temp;
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
    head=insert_any_pt(head,10);
    head=insert_any_pt(head,20);
    head=insert_any_pt(head,30);
    cout<<search(head,20)<<endl;
    head=insert_any_pt(head,15,2);
    printlist(head);
}
 