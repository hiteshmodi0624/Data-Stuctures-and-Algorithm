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
int prefixhelper(TrieNode*root){
    int res=0;
    for(int i=0;i<26;i++)
        if(root->child[i]!=NULL)
            res+=prefixhelper(root->child[i]);
    if(root->isEnd==true){
        return res+1;
    }
    return res;
}
int prefixcount(TrieNode*root,string s){
    TrieNode*curr=root;
    for(char x:s){
        int index=x-'a';
        if(curr->child[index]==NULL)
            return 0;
        curr=curr->child[index];
    }
    return prefixhelper(curr);
        
}
int main(){
    string dict[]={"bad","bat","geek","geeks","caat","cut","zoo","germany"};
    int n=sizeof(dict)/sizeof(dict[0]);
    TrieNode*t=new TrieNode();
    for(int i=0;i<n;i++)
        insert(t,dict[i]);
    cout<<search(t,dict[0])<<endl;
    cout<<prefixcount(t,"ge");
}

