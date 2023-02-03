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

bool detect_loop(Node *head){
    Node *fast=head;
    Node *slow=head;
    while(fast!=NULL&&fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
        // we take the speed twice because it ensures that the distance between the two elements always increase by 1, thus if the cycle length is n
        // then at certain point the distance between the two will be n, i.e they will be at the same position
        if(slow==fast)
            return true;
    }
    return false;
}
int main(){
    Node *head=NULL;
    int a[]={23,10,11,20,16,22};
    int n=sizeof(a)/sizeof(a[0]);
    head=array_insert(a,n);
    cout<<detect_loop(head);
    head->next->next->next->next->next->next=head->next->next->next;
    cout<<detect_loop(head);
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