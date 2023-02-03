#include <iostream>
#include <string.h>
#include <math.h>
#include <vector>
#include <list>
#include<numeric>
#include<algorithm>

using namespace std;

struct myHash{
    int BUCKET;
    list<int>*table;
    myHash(int b){
        BUCKET=b;
        table=new list<int>[b];
    }
    void insert(int key){
        int i=key%BUCKET;
        table[i].push_back(key);
    }
    bool search(int key){
        int i=key%BUCKET;
        list<int>::iterator  ta= table[i].begin();
        for(int x=0;x<table[i].size();x++){
            if(*ta==key)
                return true;
            advance(ta,1);
        }
        return false;
    }
    void remove(int key){
        int i=key%BUCKET;
        table[i].remove(key);
    }
};
int main(){
    myHash mh(7);
    mh.insert(29);
    mh.insert(20);
    mh.insert(43);
    mh.insert(32);
    mh.remove(32);
    cout<<mh.search(29)<<endl;
    cout<<mh.search(43)<<endl;
    cout<<mh.search(40)<<endl;
    cout<<mh.search(32)<<endl;
    return 0;
}
 