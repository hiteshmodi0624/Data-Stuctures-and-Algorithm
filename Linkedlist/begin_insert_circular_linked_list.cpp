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
        return head;
    }
}
int main(){
    Node *head=NULL;
    head=insert(head,10);
    head=insert(head,20);
    head=insert(head,30);
    print_cl(head);
}
 