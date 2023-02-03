#include <iostream>
#include <string.h>
#include <math.h>
#include <vector>
#include <list>
#include<numeric>
#include<algorithm>

using namespace std;
int BUCKET;
vector<int> table(7);
int h1(int key){
    int m=7;
    return key%m;
}
int h2(int key){
    int m=6;
    return m-key%m;
}
void doubleHashingInsert(int key){ 
    int m=7;
    // if(table.size()==m)
    //     return;
    int probe=h1(key),offset=h2(key);
    int ref=-1;
    while(table[probe]>0&&(ref!=probe)){
        if(ref==-1)
            ref=probe;
        probe=(probe+offset)%m;
    }
    table[probe]=key;
}
bool search(int key){
    int m=7;
    int probe=h1(key),offset=h2(key);
    int ref=-1;
    while(table[probe]!=key&&(ref!=probe)){
        if(ref==-1)
            ref=probe;
        probe=(probe+offset)%m;
    }
    if(table[probe]==key)
        return true;
    else    
        return false;
}
void deletee(int key){
    int m=7;
    int probe=h1(key),offset=h2(key);
    int ref=-1;
    while(table[probe]!=key&&(ref!=probe)){
        if(ref==-1)
            ref=probe;
        probe=(probe+offset)%m;
    }
    if(table[probe]==key)
        table[probe]=-2;
    else    
        return;
}
int main(){
    doubleHashingInsert(49);
    doubleHashingInsert(63);
    doubleHashingInsert(42);
    deletee(42);
    doubleHashingInsert(56);
    doubleHashingInsert(52);
    doubleHashingInsert(54);
    doubleHashingInsert(48);
    cout<<search(63)<<endl;
    cout<<search(30)<<endl;
    for(int i=0;i<7;i++)
        cout<<table[i]<<endl;
    return 0;
}
 