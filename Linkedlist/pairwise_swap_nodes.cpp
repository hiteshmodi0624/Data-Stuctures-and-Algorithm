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
Node * pairwiseSwap(Node *head){
    if(head==NULL||head->next==NULL)
        return head;
    Node*temp=head;
    head=head->next;
    while(temp!=NULL&&temp->next!=NULL){
        Node*temp2=temp->next;
        Node*temp3=temp->next->next;
        if(temp3!=NULL&&temp3->next!=NULL)
            temp->next=temp3->next;
        else
            temp->next=temp3;
        temp2->next=temp;
        temp=temp3;
    }
    return head;
}
int main(){
    Node *head=NULL,*head2=NULL;
    int a[]={17,15,8,12,10,5,4};
    int n=sizeof(a)/sizeof(a[0]);
    head=array_insert(a,n);
    printll(head);
    head=pairwiseSwap(head);
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