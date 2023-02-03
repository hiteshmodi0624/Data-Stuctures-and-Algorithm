#include <iostream>
#include <list>
#include <vector>
#include <unordered_set>
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
void even_odd(Node *head){
    Node *j=head;
    for(Node *i=head;i!=NULL;i=i->next){
        if(i->data%2==0){
            swap(i->data,j->data);
            j=j->next;
        }
    }
}
Node*segregate(Node * head){
    Node *es=NULL,*ee=NULL,*os=NULL,*oe=NULL;
    for(Node *i=head;i!=NULL;i=i->next){
        int x=i->data;
        if(x%2==0){
            if(es==NULL){
                es=i;
                ee=es;
            }
            else{
                ee->next=i;
                ee=ee->next;
            }
        }
        else{
            if(os==NULL){
                os=i;
                oe=os;
            }
            else{
                oe->next=i;
                oe=oe->next;
            }
        }
    }
    if(os==NULL||es==NULL)
        return head;
    ee->next=os;
    oe->next=NULL;
    return es;
}
int main(){
    Node *head=NULL;
    int a[]={17,15,8,12,10,5,4 };
    int n=sizeof(a)/sizeof(a[0]);
    head=array_insert(a,n);
    printll(head);
    even_odd(head);
    printll(head);
    Node *seg= segregate(head);
    printll(seg);
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