#include <iostream>
#include<queue>
#include<stack>
using namespace std;
void generate_no_with_5_6(string a,string b,int n){
    queue<string>q;
    q.push(a);
    q.push(b);
    while(n--){
        cout<<q.front()<<" ";
        string x=q.front();
        q.pop();
        q.push(x+a);
        q.push(x+b);
    }
}
int main(){
    generate_no_with_5_6("5","6",10);
}
 