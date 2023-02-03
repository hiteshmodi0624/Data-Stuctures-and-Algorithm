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
int intersection(Node * head,Node * head2){
    Node* temp=head;
    unordered_set<Node*>p;
    while(temp!=NULL){
        p.insert(temp);
        temp=temp->next;
    }
    while(head2!=NULL&&p.find(head2)==p.end())
        head2=head2->next;
    if(head2!=NULL)
        return head2->data;
    else     
        return -1;
}
int intersection2(Node* head,Node * head2){
    Node* temp=head,*temp2=head2;
    int count=0,count2=0;
    while(temp!=NULL){
        count++;
        temp=temp->next;
    }
    while(temp2!=NULL){
        count2++;
        temp2=temp2->next;
    }
    if(count>count2){
        count=count-count2;
        while((count--)>0)
            head=head->next;
    }
    else{
        count=count2-count;
        while((count--)>0)
            head2=head2->next;
    }
    while(head!=NULL&&head2!=NULL){
        if(head==head2)
            return head->data;
        head=head->next;
        head2=head2->next;
    }
    return -1;
}
int main(){
    Node *head=NULL,*head2=NULL;
    int a[]={17,15,8,12,10,5,4};
    int b[]={23,14};
    int n=sizeof(a)/sizeof(a[0]);
    int m=sizeof(b)/sizeof(a[0]);
    head=array_insert(a,n);
    head2=array_insert(b,m);
    head2->next->next=head->next->next->next;
    printll(head);
    printll(head2);
    cout<<intersection(head,head2)<<endl;
    cout<<intersection2(head,head2);
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