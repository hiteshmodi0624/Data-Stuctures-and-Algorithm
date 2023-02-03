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

bool detect_loop2(Node *head){
    // destroys the linked list
    Node *temp,*temp2;
    while(head!=NULL){
        temp2=head->next;
        if(temp2==temp)
            return true;
        head->next=temp;
        head=temp2;
    }
    return false;
}
bool detect_loop(Node *head){
    unordered_set<Node*>p;
    
    for(Node *temp=head;temp!=NULL;temp=temp->next){
        if(p.find(temp)!=p.end())
            return true;
        p.insert(temp);
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