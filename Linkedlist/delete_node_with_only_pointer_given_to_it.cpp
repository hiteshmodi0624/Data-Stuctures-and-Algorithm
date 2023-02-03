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
void delete_node(Node *head){
    head->data=head->next->data;
    Node*temp=head->next;
    head->next=head->next->next;
    delete(temp);
}
int main(){
    Node *head=NULL;
    int a[]={23,87,876,6,90,32,78,67};
    int n=sizeof(a)/sizeof(a[0]);
    head=array_insert(a,n);
    printll(head);
    delete_node(head->next->next);
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