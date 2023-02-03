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
Node* merge_sorted(Node * head,Node * head2){
    Node* temp=head,*temp2=head2;
    Node* res,*reshead;
    if(temp==NULL)return temp2;
    if(temp2==NULL)return temp;
    if(temp->data>temp2->data){
        res=temp2;
        temp2=temp2->next;
        res->next=NULL;
    }
    else{
        res=temp;
        temp=temp->next;
        res->next=NULL;
    }
    reshead=res;
    while(temp!=NULL&&temp2!=NULL){
        if(temp->data>temp2->data){
            res->next=temp2;
            temp2=temp2->next;
            res=res->next;
        }
        else{
            res->next=temp;
            temp=temp->next;
            res=res->next;
        }
    }
    if(temp!=NULL){
        res->next=temp;
    }
    else{
        res->next=temp2;
    }
    return reshead;
}
int main(){
    Node *head=NULL,*head2=NULL;
    int a[]={40,50,60,70,80,90};
    int b[]={34,35,56,59,60,74};
    int n=sizeof(a)/sizeof(a[0]);
    int m=sizeof(b)/sizeof(a[0]);
    head=array_insert(a,n);
    head2=array_insert(b,m);
    head=merge_sorted(head,head2);
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