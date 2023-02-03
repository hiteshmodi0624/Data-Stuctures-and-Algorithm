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
    int arr[]={10,20,30,40,10,20,10,40};
    unordered_set<int> s(arr,arr+8);
    cout<<s.size();
}
 