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
Node *reverse(Node *head,int k){
    Node *prev=NULL;
    Node*curr=head;
    int count=0;
    while(curr!=NULL&&count<k){
        Node* next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
        count++;
    }
    if(curr!=NULL)
        head->next=reverse(curr,k);
    return prev;
}
Node *reverse_better(Node *head,int k){
    Node*curr=head,*prevFirst=NULL;
    bool isFirstPass=true;
    while(curr!=NULL){
        Node *first=curr,*prev=NULL;
        int count=0;
        while(curr!=NULL&&count<k){
            Node* next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
            count++;
        }
        if(isFirstPass){
            head=prev;
            isFirstPass=false;
        }
        else{
            prevFirst->next=prev;
        }
        prevFirst=first;
    } 
    return head;
}
int main(){
    Node *head=NULL;
    int a[]={23,10,10,20,20,20,25,30,30,40,40,60};
    int n=sizeof(a)/sizeof(a[0]);
    head=array_insert(a,n);
    printll(head);
    head=reverse(head,4);
    printll(head);
    head=reverse_better(head,4);
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