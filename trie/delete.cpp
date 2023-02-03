#include <iostream>
using namespace std;
struct TrieNode {
    TrieNode *child[26];
    bool isEnd;
    TrieNode(){
        isEnd=false;
        for(int i=0;i<26;i++)
            child[i]=NULL;  
    }   
};
void insert(TrieNode*&root,string &key){
    TrieNode *curr=root;
    int i=0;
    for(i=0;i<key.length();i++){
        int index=key[i]-'a';
        if(curr->child[index]==NULL)
            curr->child[index]=new TrieNode();
        curr=curr->child[index];
    }
    curr->isEnd=true;
}

bool search(TrieNode*root,string s){
    TrieNode*curr=root;
    for(char x:s){
        int index=x-'a';
        if(curr->child[index]==NULL)
            return false;
        curr=curr->child[index];
    }
    return curr->isEnd;
        
}
bool isEmpty(TrieNode*root){
    for(int i=0;i<26;i++)
        if(root->child[i]!=NULL)
            return false;
    return true;
}
TrieNode*deletekey(TrieNode*root,string key,int i){
    if(root==NULL)
        return NULL;
    if(i==key.length()){
        root->isEnd=false;
        if(isEmpty(root)){
            delete root;
            root=NULL;
        }
            return root;
    }
    int index=key[i]-'a';
    root->child[index]=deletekey(root->child[index],key,i+1);
    if(isEmpty(root)&&root->isEnd==false){
        delete(root);
        root=NULL;
        return root;
    }
    return root;
}
int main(){
    string dict[]={"an","and","ant","bad","bat","zoo"};
    int n=sizeof(dict)/sizeof(dict[0]);
    TrieNode*t=new TrieNode();
    for(int i=0;i<n;i++)
        insert(t,dict[i]);
    cout<<search(t,dict[0])<<endl;
    deletekey(t,"an",0);
    cout<<search(t,dict[1])<<endl;
}

