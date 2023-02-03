#include <iostream>
#include <string.h>
#include <math.h>
#include <vector>
#include <list>
#include<numeric>
#include<unordered_set>
#include<unordered_map>

using namespace std;
int main(){
    int a[]={10,20,10,30};
    int b[]={20,10,10,40,90,10,10};
    unordered_set<int> s1(a,a+4);
    s1.insert(b,b+6);
    cout<<s1.size();
}
 