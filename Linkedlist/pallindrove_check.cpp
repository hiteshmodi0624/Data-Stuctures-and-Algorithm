#include <iostream>
#include <list>
#include <vector>
#include <unordered_set>
using namespace std;
struct Node{
    char data;
    Node *next;
    Node(char x){
        data=x;
        next=NULL;
    }
};
Node *insert_end(Node *head,int x), *array_insert(string a,int n);
void printll(Node *head);
Node *reverse(Node *head,Node* prev){
    if(head==NULL)
        return prev;
    Node*res=reverse(head->next,head);
    head->next=prev;
    return res;
}
bool pallindrove_check(Node * head){
    if(head==NULL)
        return true;
    Node*fast=head,*slow=head;
    while(fast->next!=NULL&&fast->next->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
    }
    slow->next=reverse(slow->next,NULL);
    Node*i=slow->next;
    while(i!=NULL){
        if(i->data!=head->data){
            slow->next=reverse(slow->next,NULL);
            return false;
        }
        i=i->next;
        head=head->next;
    }
    slow->next=reverse(slow->next,NULL);
    return true;
}
int main(){
    Node *head=NULL;
    string a="RABBAR";
    int n=a.length();
    head=array_insert(a,n);
    printll(head);
    cout<<pallindrove_check(head);
}
Node *insert_end(Node *head,char x){
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
Node *array_insert(string a,int n){
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