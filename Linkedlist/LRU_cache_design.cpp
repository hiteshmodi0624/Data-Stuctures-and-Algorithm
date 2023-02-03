#include <iostream>
#include <list>
#include <vector>
#include <unordered_map>
using namespace std;
struct Node{
    int data;
    Node *next;
    Node *prev;
    Node(int x){
        data=x;
        next=NULL;
        prev=NULL;
    }
};
unordered_map<int,Node*>m;
int cache_size=4;
Node*tail;
Node *insert_begin(Node *head,int x), *array_insert(int a[],int n);
void printll(Node *head);
Node * LRU(int n,Node*head){
    int r=-1;
    if(m.find(n)==m.end()){
        if(m.size()<cache_size){
            head=insert_begin(head,n);
            m[n]=head;
            if(m.size()==1)
                tail=head;
        }
        else{
            Node*temp=tail->prev;
            tail->prev->next=NULL;
            m.erase(tail->data);
            delete(tail);
            head=insert_begin(head,n);
            tail=temp;
            m[n]=head;
        }
    }
    else{
        if(m[n]->next==NULL)
            tail=m[n]->prev;
        m[n]->prev->next=m[n]->next;
        if(m[n]->next!=NULL)
            m[n]->next->prev=m[n]->prev;
        m[n]->prev=NULL;
        m[n]->next=head;
        head->prev=m[n];
        head=m[n];
    }
    return head;
}
int main(){
    Node *head=NULL;
    head=LRU(10,head);printll(head);
    head=LRU(20,head);printll(head);
    head=LRU(10,head);printll(head);
    head=LRU(30,head);printll(head);
    head=LRU(40,head);printll(head);
    head=LRU(50,head);printll(head);
    head=LRU(30,head);printll(head);
    head=LRU(40,head);printll(head);
    head=LRU(60,head);printll(head);
    head=LRU(30,head);printll(head);
}
Node *insert_begin(Node *head,int x){
    if(head==NULL)
        return (new Node(x));
    Node *temp=new Node(x);
    temp->next=head;
    head->prev=temp;
    return temp;
}

void printll(Node *head){
    Node *temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    };
    cout<<endl;
}