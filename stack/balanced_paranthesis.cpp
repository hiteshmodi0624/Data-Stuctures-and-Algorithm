#include <iostream>
#include <stack>
using namespace std;

int main(){
    string str="([])";
    stack<char> s;
    for(char x:str){
        if(x=='('||x=='{'||x=='[')
            s.push(x);
        else if(s.empty()){
            s.push(x);
            break;
        }
        else if(!((s.top()=='{'&&x=='}')||(s.top()=='['&&x==']')||(s.top()=='('&&x==')')))
            break;
        else
            s.pop();
    }
    if(s.empty())
        cout<<"Balanced";
    else    
        cout<<"Unbalanced";
}
 