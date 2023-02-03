#include <iostream>
#include <list>
#include <vector>
#include <unordered_map>
using namespace std;
struct Node{
    int data;
    Node *next;
    Node *random;
    Node(int x){
        data=x;
        next=NULL;
        random=NULL;
    }
};
Node *insert_end(Node *head,int x), *array_insert(int a[],int n);
void printll(Node *head);
Node * clonell(Node *head){
    unordered_map<Node*,Node*>m;
    Node*head2=new Node(head->data);
    m[head]=head2;
    Node*temp=head,*temp2=head2;
    while(temp->next!=NULL){
        temp2->next=new Node(temp->next->data);
        m[temp->next]=temp2->next;
        temp2=temp2->next;
        temp=temp->next;
    }
    temp=head;temp2=head2;
    while(temp!=NULL){
        temp2->random=m[temp->random];
        temp2=temp2->next;
        temp=temp->next;
    }
    return head2;
}
Node *clonell2(Node *head){
    for(Node*i=head;i!=NULL;){
        Node *temp=i->next;
        i->next=new Node(i->data);
        i->next->next=temp;
        i=temp;
    }
    for(Node*i=head;i!=NULL;i=i->next->next){
        if(i->random!=NULL)
            i->next->random=i->random->next;
        else    
            i->next->random=NULL;
    }
    Node*temp=head->next;
    for(Node*i=head;i!=NULL;i=i->next){
        if(i->next->next==NULL){
            i->next=NULL;
            break;
        }
        Node *j=i->next;
        i->next=j->next;
        j->next=j->next->next;
    }
    
    return temp;
}
void printRandom(Node*head){
    for(Node*temp=head;temp!=NULL;temp=temp->next)
        cout<<temp->random->data<<" ";
    cout<<endl;
}
int main(){
    Node *head=NULL;
    int a[]={10,5,20,15,20};
    int n=sizeof(a)/sizeof(a[0]);
    head=array_insert(a,n);
    head->random=head->next->next;
    head->next->random=head->next->next->next;
    head->next->next->random=head;
    head->next->next->next->random=head->next->next;
    head->next->next->next->next->random=head->next->next->next;
    printll(head);
    printRandom(head);
    Node* head2=clonell2(head); 
    printll(head2);
    printll(head);
    printRandom(head2);
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