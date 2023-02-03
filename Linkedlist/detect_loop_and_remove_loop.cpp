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

void remove_loop_if_any(Node *head){
    Node *fast=head;
    Node *slow=head;
    while(fast!=NULL&&fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast)
            break;
    }
    if(slow!=fast)
        return;
    if(slow!=head){
        slow=head;
        while(slow->next!=fast->next){
            slow=slow->next;
            fast=fast->next;
        }
    }
    else{
        while(fast->next!=slow)
            fast=fast->next;
    }
    fast->next=NULL;
}
int length_of_loop(Node *head){
    Node *fast=head;
    Node *slow=head;
    while(fast!=NULL&&fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast)
            break;
    }
    if(slow!=fast)
        return 0;
    int count=1;
    while(slow->next!=fast){
        count++;
        slow=slow->next;
    }
    return count;
}
int main(){
    Node *head=NULL;
    int a[]={23,87,876,6,90,32,78,67};
    int n=sizeof(a)/sizeof(a[0]);
    head=array_insert(a,n);
    remove_loop_if_any(head);
    printll(head);
    head->next->next->next->next->next->next->next->next=head->next->next;
    cout<<length_of_loop(head)<<endl;
    remove_loop_if_any(head);
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