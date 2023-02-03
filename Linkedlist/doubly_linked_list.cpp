#include <iostream>
#include <list>

using namespace std;
struct Node{
    int data;
    Node *prev;
    Node *next;
    Node(int x){
        data=x;
        next=NULL;
        prev=NULL;
    }
};

int main(){
    Node *head=new Node(10);
    head->next=new Node(20);
    head->next->next=new Node(30);
    head->prev=head;
    head->next->prev=head->next;
}
 