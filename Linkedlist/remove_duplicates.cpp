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
Node *insert_end(Node *head,int x), *array_insert(int a[],int n);
void printll(Node *head);
void removeduplicates(Node *head){
    Node *curr=head;
    while(curr!=NULL&&curr->next!=NULL){
        if(curr->data==curr->next->data){
            Node* temp=curr->next;
            curr->next=curr->next->next;
            delete(temp);
        }
        else
            curr=curr->next;
    }
}
int main(){
    Node *head=NULL;
    int a[]={23,10,10,20,20,20,25,30,30,40,40};
    int n=sizeof(a)/sizeof(a[0]);
    head=array_insert(a,n);
    removeduplicates(head);
    printll(head);
    
}
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
Node *array_insert(int a[],int n){
    Node* head=NULL;
    for(int i=0;i<n;i++)
        head=insert_end(head,a[i]);
    return head;
}
void printll(Node *head){
    Node *temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    };
    cout<<endl;
}