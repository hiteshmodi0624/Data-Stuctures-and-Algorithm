#include <iostream>
#include <string.h>
#include <math.h>
#include <vector>
#include <list>
#include<numeric>
#include<algorithm>

using namespace std;

struct myHash{
    int cap,size;
    vector<int> table;
    myHash(int b){
        cap=b;
        size=0;
        for(int i=0;i<b;i++)
            table.push_back(-1);
    }
    void insert(int key){
        if(size==cap)
            return;
        int i=key%cap;
        while(table[i]>-1){
            i=(i+1)%cap;
            if(i==key%cap)
                return;
        }
        table[i]=key;
        size++;
    }
    int search(int key){
        int i=key%cap;
        while(table[i]!=-1){
            if(table[i]==key)
                return i;
            i=(i+1)%cap;
            if(i==key%cap)
                return -1;
        }
        return -1;
    }
    void remove(int key){
        int i=key%cap;
        while(table[i]!=-1){
            if(table[i]==key){
                table[i]=-2;
                size--;
                return;
            }
            i=(i+1)%cap;
            if(i==key%cap)
                return;
        }
        return;
    }
};
int main(){
    myHash mh(7);
    mh.insert(50);
    mh.insert(51);
    mh.insert(49);
    mh.insert(16);
    mh.insert(56);
    mh.insert(15);
    mh.insert(19);
    mh.remove(19);
    cout<<mh.search(49)<<endl;
    cout<<mh.search(19)<<endl;
    cout<<mh.search(56)<<endl;
    cout<<mh.search(51)<<endl;
    return 0;
}
 