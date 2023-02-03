#include <iostream>
#include <stack>
#include <vector>
using namespace std;
bool check(char a,char b){
    if(b=='^')
        return true;
    if(a=='^'||a=='*'||a=='/'||b=='+'||b=='-')
        return false;
    else
        return true;
}
string topostflix(string a){
    string res="";
    stack<char>s;
    for(char x:a){
        if((x>='a'&&x<='z')||(x>='1'&&x<='9')||(x>='A'&&x<='Z'))
            res=res+x;
        else if (x=='(')
            s.push(x);
        else if (x==')'){
            while(s.top()!='('){
                res=res+s.top();
                s.pop();
            }
            s.pop();
        }
        else{
            if(s.empty()||s.top()=='('||check(s.top(),x))
                s.push(x);
            else{
                while(s.empty()==false&&s.top()!='('&&check(s.top(),x)==0){
                    res=res+s.top();
                    s.pop();
                }
                s.push(x);
            }
        }
    }
    while(s.empty()==false){
        res+=s.top();
        s.pop();
    }
    return res;
}
int main(){
    string inflix="x^y/(5+z*x)+2";
    cout<<inflix<<endl;
    cout<<topostflix(inflix);
}
 