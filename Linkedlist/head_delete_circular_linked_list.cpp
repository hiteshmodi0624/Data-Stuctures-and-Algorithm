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
Node *delete_cl(Node *head){
    if(head==NULL||head->next==head)
        {delete(head);return NULL;}
    Node *temp=head->next;
    head->data=temp->data;
    head->next=temp->next;
    delete(temp);
    return head;
}
void print_cl(Node *head){
    if(head==NULL)
        return;
    Node *temp=head;
    do{
        cout<<temp->data<<" ";
        temp=temp->next;
    }while(temp!=head);
}
Node *insert(Node *head,int n){
    Node *temp=new Node(n);
    if(head==NULL){
        temp->next=temp;
        return temp;    
    }
    else{
        temp->next=head->next;
        head->next=temp;
        swap(temp->data,head->data);
        return temp;
    }
}
int main(){
    Node *head=NULL;
    head=insert(head,10);
    head=insert(head,20);
    head=insert(head,30);
    head=insert(head,40);
    head=insert(head,50);
    head=delete_cl(head);
    print_cl(head);
}
 